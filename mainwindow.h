#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sort.h"
#include "qcustomplot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_action20_Posicoes_triggered();

    void on_action50_Posicoes_triggered();

    void on_action100_Posicoes_triggered();

    void on_actionCocktail_triggered();

    void on_actionCocktail_2_triggered();

    void on_actionSelection_triggered();

    void on_actionSelection_2_triggered();

    void on_actionInsertion_triggered();

    void on_actionInsertion_2_triggered();

    void on_actionBubble_triggered();

    void on_actionMerge_triggered();

    void on_actionQuick_triggered();

    void on_actionShell_triggered();

    void on_actionBubble_2_triggered();

    void on_actionShell_2_triggered();

    void on_actionMerge_2_triggered();

    void on_actionQuick_2_triggered();

    void on_pushButton_clicked();

    void on_actionDigite_o_valor_desejado_triggered();

    void showGraph(QVector<double> x, QVector<double> y);

private:
    Ui::MainWindow *ui;
    SORT *sort;
};

#endif // MAINWINDOW_H
