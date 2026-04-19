#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QElapsedTimer>
#include <QInputDialog>
#include <vector>
#include <map>
#include <functional>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sort = new SORT();

    // Criar e adicionar QAction para "Comparar Todos"
    QAction *actionCompararTodos = new QAction("Comparar Todos", this);
    this->menuBar()->addAction(actionCompararTodos);  // Corrigido: menuBar() é método de QMainWindow
    connect(actionCompararTodos, &QAction::triggered, this, &MainWindow::on_actionCompararTodos_triggered);
}

MainWindow::~MainWindow() {
    delete ui;
    delete sort;
}

// --- AUXILIARES ---

QVector<int> MainWindow::obterCopiaVetorAtual() {
    int tam = sort->n;
    if (tam <= 0) return QVector<int>();

    QVector<int> v(tam);
    for(int i = 0; i < tam; i++) {
        if(tam == 20)      v[i] = sort->vet20[i];
        else if(tam == 50) v[i] = sort->vet50[i];
        else if(tam == 100)v[i] = sort->vet100[i];
        else               v[i] = sort->vetPontos[i];
    }
    return v;
}

void MainWindow::prepararGraficoGenerico(std::function<void(int*, int)> algoritmo, long &trocas, long &comparacoes) {
    // Adicionar verificação de erro: se algoritmo for inválido, retorne
    if (!algoritmo) return;

    QVector<double> x(NUMERO_INTERACOES_GRAFICO), y(NUMERO_INTERACOES_GRAFICO);

    for(int i = 0, tam = 10; i < NUMERO_INTERACOES_GRAFICO; i++, tam += 10) {
        std::vector<int> v(tam);
        sort->posicoes(tam); // Gera novos dados aleatórios para este tamanho

        for(int k=0; k < tam; k++) v[k] = sort->vetPontos[k];

        trocas = 0;
        comparacoes = 0;

        algoritmo(v.data(), tam);

        x[i] = tam;
        y[i] = static_cast<double>(trocas + comparacoes);
    }
    showGraph(x, y);
}

void MainWindow::showGraph(const QVector<double>& x, const QVector<double>& y) {
    ui->customPlot->clearGraphs();
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);

    ui->customPlot->xAxis->setLabel("Tamanho do Vetor");
    ui->customPlot->yAxis->setLabel("Esforço (Trocas + Comp)");

    ui->customPlot->rescaleAxes();
    ui->customPlot->replot();
}

// --- SLOTS: CONFIGURAÇÃO DE DADOS ---

void MainWindow::on_action20_Posicoes_triggered()  { sort->inicio(); sort->posicoes20(); }
void MainWindow::on_action50_Posicoes_triggered()  { sort->inicio(); sort->posicoes50(); }
void MainWindow::on_action100_Posicoes_triggered() { sort->inicio(); sort->posicoes100(); }

void MainWindow::on_actionDigite_o_valor_desejado_triggered() {
    bool ok;
    int n = QInputDialog::getInt(this, "Vetor Personalizado", "Tamanho (0-10000):", 25, 0, 10000, 1, &ok);
    if(ok) {
        sort->inicio();
        sort->posicoes(n);
    }
}

// --- SLOTS: EXECUÇÃO SIMPLES (BOTÕES DE ORDENAR) ---

void MainWindow::executeSort(const QString& algorithmName) {
    auto v = obterCopiaVetorAtual();
    if (v.isEmpty()) {
        // Adicionar mensagem de erro: "Vetor vazio, configure dados primeiro."
        return;
    }
    if (algorithmName == "Cocktail") {
        sort->comparaCocktail = 0; sort->trocaCocktail = 0;
        QElapsedTimer t; t.start();
        sort->cocktail(v.data(), v.size());
        sort->tempoCocktail = t.nsecsElapsed();
    } else if (algorithmName == "Selection") {
        sort->comparaSelection = 0; sort->trocaSelection = 0;
        QElapsedTimer t; t.start();
        sort->selection(v.data(), v.size());
        sort->tempoSelection = t.nsecsElapsed();
    } else if (algorithmName == "Insertion") {
        sort->comparaInsertion = 0; sort->trocaInsertion = 0;
        QElapsedTimer t; t.start();
        sort->insertion(v.data(), v.size());
        sort->tempoInsertion = t.nsecsElapsed();
    } else if (algorithmName == "Bubble") {
        sort->comparaBubble = 0; sort->trocaBubble = 0;
        QElapsedTimer t; t.start();
        sort->bubble(v.data(), v.size());
        sort->tempoBubble = t.nsecsElapsed();
    } else if (algorithmName == "Shell") {
        sort->comparaShell = 0; sort->trocaShell = 0;
        QElapsedTimer t; t.start();
        sort->shell(v.data(), v.size());
        sort->tempoShel = t.nsecsElapsed();
    } else if (algorithmName == "Merge") {
        sort->comparaMerge = 0; sort->trocaMerge = 0;
        QElapsedTimer t; t.start();
        sort->merge(v.data(), 0, v.size() - 1);
        sort->tempoMerge = t.nsecsElapsed();
    } else if (algorithmName == "Quick") {
        sort->comparaQuick = 0; sort->trocaQuick = 0;
        QElapsedTimer t; t.start();
        sort->quick(v.data(), 0, v.size() - 1);
        sort->tempoQuick = t.nsecsElapsed();
    }
}

void MainWindow::on_actionCocktail_triggered() { executeSort("Cocktail"); }
void MainWindow::on_actionSelection_triggered() { executeSort("Selection"); }
void MainWindow::on_actionInsertion_triggered() { executeSort("Insertion"); }
void MainWindow::on_actionBubble_triggered() { executeSort("Bubble"); }
void MainWindow::on_actionShell_triggered() { executeSort("Shell"); }
void MainWindow::on_actionMerge_triggered() { executeSort("Merge"); }
void MainWindow::on_actionQuick_triggered() { executeSort("Quick"); }

// --- SLOTS: GRÁFICOS (VERSÃO 2) ---

void MainWindow::on_actionCocktail_2_triggered() {
    prepararGraficoGenerico([this](int* v, int n){ sort->cocktail(v, n); }, sort->trocaCocktail, sort->comparaCocktail);
}

void MainWindow::on_actionSelection_2_triggered() {
    prepararGraficoGenerico([this](int* v, int n){ sort->selection(v, n); }, sort->trocaSelection, sort->comparaSelection);
}

void MainWindow::on_actionInsertion_2_triggered() {
    prepararGraficoGenerico([this](int* v, int n){ sort->insertion(v, n); }, sort->trocaInsertion, sort->comparaInsertion);
}

void MainWindow::on_actionBubble_2_triggered() {
    prepararGraficoGenerico([this](int* v, int n){ sort->bubble(v, n); }, sort->trocaBubble, sort->comparaBubble);
}

void MainWindow::on_actionShell_2_triggered() {
    prepararGraficoGenerico([this](int* v, int n){ sort->shell(v, n); }, sort->trocaShell, sort->comparaShell);
}

void MainWindow::on_actionMerge_2_triggered() {
    prepararGraficoGenerico([this](int* v, int n){ sort->merge(v, 0, n - 1); }, sort->trocaMerge, sort->comparaMerge);
}

void MainWindow::on_actionQuick_2_triggered() {
    prepararGraficoGenerico([this](int* v, int n){ sort->quick(v, 0, n - 1); }, sort->trocaQuick, sort->comparaQuick);
}

// --- ATUALIZAÇÃO DA INTERFACE ---

void MainWindow::on_pushButton_clicked() {
    // Tornar dinâmico: Usar um mapa local
    std::map<QString, std::tuple<QLabel*, QLabel*, QLabel*, long, long, long long>> uiElements = {
        {"Cocktail", {ui->cocktailCompare, ui->cocktailChanges, ui->cocktailTime, sort->comparaCocktail, sort->trocaCocktail, sort->tempoCocktail}},
        {"Selection", {ui->selectionCompare, ui->selectionChanges, ui->selectionTime, sort->comparaSelection, sort->trocaSelection, sort->tempoSelection}},
        {"Insertion", {ui->insertionCompare, ui->insertionChanges, ui->insertionTime, sort->comparaInsertion, sort->trocaInsertion, sort->tempoInsertion}},
        {"Bubble", {ui->label_19, ui->label_20, ui->label_21, sort->comparaBubble, sort->trocaBubble, sort->tempoBubble}},
        {"Merge", {ui->label_22, ui->label_23, ui->label_24, sort->comparaMerge, sort->trocaMerge, sort->tempoMerge}},
        {"Quick", {ui->label_25, ui->label_26, ui->label_27, sort->comparaQuick, sort->trocaQuick, sort->tempoQuick}},
        {"Shell", {ui->label_31, ui->label_30, ui->label_29, sort->comparaShell, sort->trocaShell, sort->tempoShel}}
    };
    for (auto& [name, elements] : uiElements) {
        auto [compLabel, trocaLabel, timeLabel, comp, troca, tempo] = elements;
        compLabel->setNum(static_cast<int>(comp));
        trocaLabel->setNum(static_cast<int>(troca));
        timeLabel->setNum(static_cast<int>(tempo / 100));  // Use 100 diretamente, já que TEMPO_DIVISOR foi removido
    }
}

// Novo slot: Comparar todos os algoritmos ao mesmo tempo
void MainWindow::on_actionCompararTodos_triggered() {
    auto vOriginal = obterCopiaVetorAtual();
    if (vOriginal.isEmpty()) {
        // Mensagem de erro: exiba um QMessageBox ou QLabel temporário
        // QMessageBox::warning(this, "Erro", "Vetor vazio, configure dados primeiro.");
        return;
    }

    // Lista de algoritmos para executar
    QStringList algorithms = {"Cocktail", "Selection", "Insertion", "Bubble", "Shell", "Merge", "Quick"};

    for (const QString& algo : algorithms) {
        // Cópia do vetor para cada algoritmo (para não interferir)
        QVector<int> v = vOriginal;
        if (algo == "Cocktail") {
            sort->comparaCocktail = 0; sort->trocaCocktail = 0;
            QElapsedTimer t; t.start();
            sort->cocktail(v.data(), v.size());
            sort->tempoCocktail = t.nsecsElapsed();
        } else if (algo == "Selection") {
            sort->comparaSelection = 0; sort->trocaSelection = 0;
            QElapsedTimer t; t.start();
            sort->selection(v.data(), v.size());
            sort->tempoSelection = t.nsecsElapsed();
        } else if (algo == "Insertion") {
            sort->comparaInsertion = 0; sort->trocaInsertion = 0;
            QElapsedTimer t; t.start();
            sort->insertion(v.data(), v.size());
            sort->tempoInsertion = t.nsecsElapsed();
        } else if (algo == "Bubble") {
            sort->comparaBubble = 0; sort->trocaBubble = 0;
            QElapsedTimer t; t.start();
            sort->bubble(v.data(), v.size());
            sort->tempoBubble = t.nsecsElapsed();
        } else if (algo == "Shell") {
            sort->comparaShell = 0; sort->trocaShell = 0;
            QElapsedTimer t; t.start();
            sort->shell(v.data(), v.size());
            sort->tempoShel = t.nsecsElapsed();
        } else if (algo == "Merge") {
            sort->comparaMerge = 0; sort->trocaMerge = 0;
            QElapsedTimer t; t.start();
            sort->merge(v.data(), 0, v.size() - 1);
            sort->tempoMerge = t.nsecsElapsed();
        } else if (algo == "Quick") {
            sort->comparaQuick = 0; sort->trocaQuick = 0;
            QElapsedTimer t; t.start();
            sort->quick(v.data(), 0, v.size() - 1);
            sort->tempoQuick = t.nsecsElapsed();
        }
    }

    // Atualizar a UI com todos os resultados
    on_pushButton_clicked();
}
