#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include <functional> // Necessário para passar funções como parâmetro
#include "sort.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // --- Slots de Configuração de Dados ---
    void on_action20_Posicoes_triggered();
    void on_action50_Posicoes_triggered();
    void on_action100_Posicoes_triggered();
    void on_actionDigite_o_valor_desejado_triggered();

    // --- Slots de Execução Simples ---
    // Agrupamos logicamente para facilitar a leitura
    void on_actionBubble_triggered();
    void on_actionSelection_triggered();
    void on_actionInsertion_triggered();
    void on_actionCocktail_triggered();
    void on_actionShell_triggered();
    void on_actionMerge_triggered();
    void on_actionQuick_triggered();

    // --- Slots de Gráficos (Versão 2) ---
    void on_actionBubble_2_triggered();
    void on_actionSelection_2_triggered();
    void on_actionInsertion_2_triggered();
    void on_actionCocktail_2_triggered();
    void on_actionShell_2_triggered();
    void on_actionMerge_2_triggered();
    void on_actionQuick_2_triggered();

    // --- Interface ---
    void on_pushButton_clicked(); // Atualiza Labels

private:
    // --- Métodos Auxiliares (O segredo da limpeza) ---

    // Mostra o gráfico no QCustomPlot
    void showGraph(const QVector<double>& x, const QVector<double>& y);

    // Função mestre que gera dados para qualquer gráfico de algoritmo
    // Recebe uma função que aceita (int*, int) e os contadores de referência
    void prepararGraficoGenerico(std::function<void(int*, int)> algoritmo,
                                 long &trocas, long &comparacoes);

    // Obtém uma cópia do vetor selecionado no momento (20, 50, 100 ou custom)
    QVector<int> obterCopiaVetorAtual();

    Ui::MainWindow *ui;
    SORT *sort;
};

#endif // MAINWINDOW_H
