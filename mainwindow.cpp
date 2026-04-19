#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QElapsedTimer>
#include <QInputDialog>
#include <vector>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sort = new SORT();
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

void MainWindow::on_actionCocktail_triggered() {
    auto v = obterCopiaVetorAtual();
    sort->comparaCocktail = 0; sort->trocaCocktail = 0;
    QElapsedTimer t; t.start();
    sort->cocktail(v.data(), v.size());
    sort->tempoCocktail = t.nsecsElapsed();
}

void MainWindow::on_actionSelection_triggered() {
    auto v = obterCopiaVetorAtual();
    sort->comparaSelection = 0; sort->trocaSelection = 0;
    QElapsedTimer t; t.start();
    sort->selection(v.data(), v.size());
    sort->tempoSelection = t.nsecsElapsed();
}

void MainWindow::on_actionInsertion_triggered() {
    auto v = obterCopiaVetorAtual();
    sort->comparaInsertion = 0; sort->trocaInsertion = 0;
    QElapsedTimer t; t.start();
    sort->insertion(v.data(), v.size());
    sort->tempoInsertion = t.nsecsElapsed();
}

void MainWindow::on_actionBubble_triggered() {
    auto v = obterCopiaVetorAtual();
    sort->comparaBubble = 0; sort->trocaBubble = 0;
    QElapsedTimer t; t.start();
    sort->bubble(v.data(), v.size());
    sort->tempoBubble = t.nsecsElapsed();
}

void MainWindow::on_actionShell_triggered() {
    auto v = obterCopiaVetorAtual();
    sort->comparaShell = 0; sort->trocaShell = 0;
    QElapsedTimer t; t.start();
    sort->shell(v.data(), v.size());
    sort->tempoShel = t.nsecsElapsed();
}

void MainWindow::on_actionMerge_triggered() {
    auto v = obterCopiaVetorAtual();
    sort->comparaMerge = 0; sort->trocaMerge = 0;
    QElapsedTimer t; t.start();
    sort->merge(v.data(), 0, v.size() - 1);
    sort->tempoMerge = t.nsecsElapsed();
}

void MainWindow::on_actionQuick_triggered() {
    auto v = obterCopiaVetorAtual();
    sort->comparaQuick = 0; sort->trocaQuick = 0;
    QElapsedTimer t; t.start();
    sort->quick(v.data(), 0, v.size() - 1);
    sort->tempoQuick = t.nsecsElapsed();
}

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
    // Cocktail
    ui->cocktailCompare->setNum(static_cast<int>(sort->comparaCocktail));
    ui->cocktailChanges->setNum(static_cast<int>(sort->trocaCocktail));
    ui->cocktailTime->setNum(static_cast<int>(sort->tempoCocktail / 100));

    // Selection
    ui->selectionCompare->setNum(static_cast<int>(sort->comparaSelection));
    ui->selectionChanges->setNum(static_cast<int>(sort->trocaSelection));
    ui->selectionTime->setNum(static_cast<int>(sort->tempoSelection / 100));

    // Insertion
    ui->insertionCompare->setNum(static_cast<int>(sort->comparaInsertion));
    ui->insertionChanges->setNum(static_cast<int>(sort->trocaInsertion));
    ui->insertionTime->setNum(static_cast<int>(sort->tempoInsertion / 100));

    // Bubble
    ui->label_19->setNum(static_cast<int>(sort->comparaBubble));
    ui->label_20->setNum(static_cast<int>(sort->trocaBubble));
    ui->label_21->setNum(static_cast<int>(sort->tempoBubble / 100));

    // Merge
    ui->label_22->setNum(static_cast<int>(sort->comparaMerge));
    ui->label_23->setNum(static_cast<int>(sort->trocaMerge));
    ui->label_24->setNum(static_cast<int>(sort->tempoMerge / 100));

    // Quick
    ui->label_25->setNum(static_cast<int>(sort->comparaQuick));
    ui->label_26->setNum(static_cast<int>(sort->trocaQuick));
    ui->label_27->setNum(static_cast<int>(sort->tempoQuick / 100));

    // Shell
    ui->label_31->setNum(static_cast<int>(sort->comparaShell));
    ui->label_30->setNum(static_cast<int>(sort->trocaShell));
    ui->label_29->setNum(static_cast<int>(sort->tempoShel / 100));
}
