#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sort.h"
#include <stdlib.h>// necessário p/ as funções rand() e srand()
#include <time.h>//necessário p/ função time()
#include <QElapsedTimer>
#include <QInputDialog>
#include "qcustomplot.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    sort = new SORT();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete sort;
}

void MainWindow::on_action20_Posicoes_triggered()
{
    sort->inicio();
    sort->posicoes20();
}

void MainWindow::on_action50_Posicoes_triggered()
{
    sort->inicio();
    sort->posicoes50();
}

void MainWindow::on_action100_Posicoes_triggered()
{
    sort->inicio();
    sort->posicoes100();
}

void MainWindow::on_actionCocktail_triggered()
{
    int vet[sort->n];
    for(int i=0;i<sort->n;i++){
        if(sort->n==20)
            vet[i]=sort->vet20[i];
        else if(sort->n==50)
            vet[i]=sort->vet50[i];
        else if(sort->n==100)
            vet[i]=sort->vet100[i];
        else
            vet[i]=sort->vetPontos[i];
    }

    sort->trocaCocktail=0;
    sort->comparaCocktail=0;
    QElapsedTimer timer;
    timer.start();
    sort->cocktail(vet, sort->n);
    sort->tempoCocktail = timer.nsecsElapsed();

    // printf("\nCocktail\n");

    // for(int i = 0; i<sort->n;i++){
    //     printf("%d\t", vet[i]);
    // }
    // printf("\ntrocas: %d\ncomparacoes: %d\ntempo: %d\n", sort->trocaCocktail, sort->comparaCocktail, sort->tempoCocktail);
}

void MainWindow::on_actionSelection_triggered()
{
    int vet[sort->n];
    for(int i=0;i<sort->n;i++){
        if(sort->n==20)
            vet[i]=sort->vet20[i];
        else if(sort->n==50)
            vet[i]=sort->vet50[i];
        else if(sort->n==100)
            vet[i]=sort->vet100[i];
        else
            vet[i]=sort->vetPontos[i];
    }
    sort->trocaSelection=0;
    sort->comparaSelection=0;
    QElapsedTimer timer;
    timer.start();
    sort->selection(vet, sort->n);
    sort->tempoSelection = timer.nsecsElapsed();

    // printf("\nSelection\n");

    // for(int i = 0; i<sort->n;i++){
    //     printf("%d\t", vet[i]);
    // }
    // printf("\ntrocas: %d\ncomparacoes: %d\ntempo: %d\n", sort->trocaSelection, sort->comparaSelection, sort->tempoSelection);
}

void MainWindow::on_actionInsertion_triggered()
{
    int vet[sort->n];
    for(int i=0;i<sort->n;i++){
        if(sort->n==20)
            vet[i]=sort->vet20[i];
        else if(sort->n==50)
            vet[i]=sort->vet50[i];
        else if(sort->n==100)
            vet[i]=sort->vet100[i];
        else
            vet[i]=sort->vetPontos[i];
    }
    sort->trocaInsertion=0;
    sort->comparaInsertion=0;
    QElapsedTimer timer;
    timer.start();
    sort->insertion(vet, sort->n);
    sort->tempoInsertion = timer.nsecsElapsed();

    // printf("\nInsertion\n");

    // for(int i = 0; i<sort->n;i++){
    //     printf("%d\t", vet[i]);
    // }
    // printf("\ntrocas: %d\ncomparacoes: %d\ntempo: %d\n", sort->trocaInsertion, sort->comparaInsertion, sort->tempoInsertion);
}

void MainWindow::on_actionBubble_triggered()
{
    int vet[sort->n];
    for(int i=0;i<sort->n;i++){
        if(sort->n==20)
            vet[i]=sort->vet20[i];
        else if(sort->n==50)
            vet[i]=sort->vet50[i];
        else if(sort->n==100)
            vet[i]=sort->vet100[i];
        else
            vet[i]=sort->vetPontos[i];
    }
    sort->trocaBubble=0;
    sort->comparaBubble=0;
    QElapsedTimer timer;
    timer.start();
    sort->bubble(vet, sort->n);
    sort->tempoBubble = timer.nsecsElapsed();

    // printf("\nBubble\n");

    // for(int i = 0; i<sort->n;i++){
    //     printf("%d\t", vet[i]);
    // }
    // printf("\ntrocas: %d\ncomparacoes: %d\ntempo: %d\n", sort->trocaBubble, sort->comparaBubble, sort->tempoBubble);
}

void MainWindow::on_actionMerge_triggered()
{

    int vet[sort->n];
    for(int i=0;i<sort->n;i++){
        if(sort->n==20)
            vet[i]=sort->vet20[i];
        else if(sort->n==50)
            vet[i]=sort->vet50[i];
        else if(sort->n==100)
            vet[i]=sort->vet100[i];
        else
            vet[i]=sort->vetPontos[i];
    }
    sort->trocaMerge=0;
    sort->comparaMerge=0;
    QElapsedTimer timer;
    timer.start();
    sort->merge(vet,0,sort->n);
    sort->tempoMerge = timer.nsecsElapsed();

    // printf("Merge\n");
    // for(int i=0;i<sort->n;i++){
    //     printf("%d\t", vet[i]);
    // }
    // printf("\n\ntrocas: %d\ncomparacoes: %d\ntempo %d\n", sort->trocaMerge, sort->comparaMerge,sort->tempoMerge);
}

void MainWindow::on_actionQuick_triggered()
{
    int vet[sort->n];
    for(int i=0;i<sort->n;i++){
        if(sort->n==20)
            vet[i]=sort->vet20[i];
        else if(sort->n==50)
            vet[i]=sort->vet50[i];
        else if(sort->n==100)
            vet[i]=sort->vet100[i];
        else
            vet[i]=sort->vetPontos[i];
    }

    sort->trocaQuick=0;
    sort->comparaQuick=0;
    QElapsedTimer timer;
    timer.start();
    sort->quick(vet,0, sort->n);
    sort->tempoQuick = timer.nsecsElapsed();

    // printf("Quick\n");
    // for(int i=0;i<sort->n;i++){
    //     printf("%d\t", vet[i]);
    // }
    // printf("\n\ntrocas: %d\ncomparacoes: %d\ntempo: %d\n", sort->trocaQuick, sort->comparaQuick, sort->tempoQuick);

}

void MainWindow::on_actionShell_triggered()
{
    int vet[sort->n];
    for(int i=0;i<sort->n;i++){
        if(sort->n==20)
            vet[i]=sort->vet20[i];
        else if(sort->n==50)
            vet[i]=sort->vet50[i];
        else if(sort->n==100)
            vet[i]=sort->vet100[i];
        else
            vet[i]=sort->vetPontos[i];
    }
    sort->trocaShell=0;
    sort->comparaShell=0;
    QElapsedTimer timer;
    timer.start();
    sort->shell(vet, sort->n);
    sort->tempoShel = timer.nsecsElapsed();

    // printf("\nShell\n");

    // for(int i = 0; i<sort->n;i++){
    //     printf("%d\t", vet[i]);
    // }
    // printf("\ntrocas: %d\ncomparacoes: %d\ntempo: %d\n", sort->trocaShell, sort->comparaShell, sort->tempoShel);
}

 void MainWindow::on_actionCocktail_2_triggered()
{
    for(int i=0; i<NUMERO_INTERACOES_GRAFICO;i++)
        sort->pontos[i]=0;

    for(int i=0, j=10; i<NUMERO_INTERACOES_GRAFICO;i++, j+=10){

        int vet[j];

        //printf("\n%d\t", j);

        sort->posicoes(j);

        for(int k=0;k<j;k++)
            vet[k]=sort->vetPontos[k];

        sort->trocaCocktail=0;
        sort->comparaCocktail=0;
        sort->cocktail(vet, j);
        sort->pontos[i]=(sort->trocaCocktail+sort->comparaCocktail);

    }
    int vet[NUMERO_INTERACOES_GRAFICO];

    for(int i=0; i<NUMERO_INTERACOES_GRAFICO;i++)
        vet[i]=0;

    vet[0]=10;

    for(int i = 1; i< NUMERO_INTERACOES_GRAFICO; i++)
        vet[i]=vet[i-1]+10;

    QVector<double> x(NUMERO_INTERACOES_GRAFICO), y(NUMERO_INTERACOES_GRAFICO);
    for (int i=0; i<NUMERO_INTERACOES_GRAFICO; ++i)
    {
      x[i] = vet[i];
      y[i] = sort->pontos[i];
    }

    showGraph(x, y);
}

void MainWindow::on_actionSelection_2_triggered()
{
    for(int i=0; i<10;i++)
        sort->pontos[i]=0;

    for(int i=0, j=10; i<10;i++, j+=10){

        int vet[j];

        sort->posicoes(j);

        for(int k=0;k<j;k++)
            vet[k]=sort->vetPontos[k];

        sort->trocaSelection=0;
        sort->comparaSelection=0;
        sort->selection(vet, j);
        sort->pontos[i]=(sort->trocaSelection+sort->comparaSelection);
    }int vet[10];

    for(int i=0; i<10;i++)
        vet[i]=0;

    vet[0]=10;

    for(int i = 1; i< 10; i++)
        vet[i]=vet[i-1]+10;

    QVector<double> x(10), y(10);
    for (int i=0; i<10; ++i)
    {
      x[i] = vet[i];
      y[i] = sort->pontos[i];
    }

    showGraph(x, y);
}

void MainWindow::on_actionInsertion_2_triggered()
{
    for(int i=0; i<NUMERO_INTERACOES_GRAFICO;i++)
        sort->pontos[i]=0;

    for(int i=0, j=10; i<NUMERO_INTERACOES_GRAFICO;i++, j+=10){

        int vet[j];

        sort->posicoes(j);

        for(int k=0;k<j;k++)
            vet[k]=sort->vetPontos[k];

        sort->trocaInsertion=0;
        sort->comparaInsertion=0;
        sort->insertion(vet, j);
        sort->pontos[i]=(sort->trocaInsertion+sort->comparaInsertion);
    }
    int vet[NUMERO_INTERACOES_GRAFICO];

    for(int i=0; i<NUMERO_INTERACOES_GRAFICO;i++)
        vet[i]=0;

    vet[0]=10;

    for(int i = 1; i< NUMERO_INTERACOES_GRAFICO; i++)
        vet[i]=vet[i-1]+10;

    QVector<double> x(NUMERO_INTERACOES_GRAFICO), y(NUMERO_INTERACOES_GRAFICO);
    for (int i=0; i<NUMERO_INTERACOES_GRAFICO; ++i)
    {
      x[i] = vet[i];
      y[i] = sort->pontos[i];
    }

    showGraph(x, y);

}

void MainWindow::on_actionBubble_2_triggered()
{
    for(int i=0; i<NUMERO_INTERACOES_GRAFICO;i++)
        sort->pontos[i]=0;

    for(int i=0, j=10; i<NUMERO_INTERACOES_GRAFICO;i++, j+=10){

        int vet[j];

        sort->posicoes(j);

        for(int k=0;k<j;k++)
            vet[k]=sort->vetPontos[k];

        sort->trocaBubble=0;
        sort->comparaBubble=0;
        sort->bubble(vet, j);
        sort->pontos[i]=(sort->trocaBubble+sort->comparaBubble);
    }
    int vet[NUMERO_INTERACOES_GRAFICO];

    for(int i=0; i<NUMERO_INTERACOES_GRAFICO;i++)
        vet[i]=0;

    vet[0]=10;

    for(int i = 1; i< NUMERO_INTERACOES_GRAFICO; i++)
        vet[i]=vet[i-1]+10;

    QVector<double> x(NUMERO_INTERACOES_GRAFICO), y(NUMERO_INTERACOES_GRAFICO);
    for (int i=0; i<NUMERO_INTERACOES_GRAFICO; ++i)
    {
      x[i] = vet[i];
      y[i] = sort->pontos[i];
    }

    showGraph(x, y);
}

void MainWindow::on_actionShell_2_triggered()
{
    for(int i=0; i<NUMERO_INTERACOES_GRAFICO;i++)
        sort->pontos[i]=0;

    for(int i=0, j=10; i<NUMERO_INTERACOES_GRAFICO;i++, j+=10){

        int vet[j];

        sort->posicoes(j);

        for(int k=0;k<j;k++)
            vet[k]=sort->vetPontos[k];

        sort->trocaShell=0;
        sort->comparaShell=0;
        sort->shell(vet, j);
        sort->pontos[i]=(sort->trocaShell+sort->comparaShell);
    }
    int vet[NUMERO_INTERACOES_GRAFICO];

    for(int i=0; i<NUMERO_INTERACOES_GRAFICO;i++)
        vet[i]=0;

    vet[0]=10;

    for(int i = 1; i< NUMERO_INTERACOES_GRAFICO; i++)
        vet[i]=vet[i-1]+10;

    QVector<double> x(NUMERO_INTERACOES_GRAFICO), y(NUMERO_INTERACOES_GRAFICO);
    for (int i=0; i<NUMERO_INTERACOES_GRAFICO; ++i)
    {
      x[i] = vet[i];
      y[i] = sort->pontos[i];
    }

    showGraph(x, y);

}

void MainWindow::on_actionMerge_2_triggered()
{
    for(int i=0; i<NUMERO_INTERACOES_GRAFICO;i++)
        sort->pontos[i]=0;

    for(int i=0, j=10; i<NUMERO_INTERACOES_GRAFICO;i++, j+=10){

        int vet[j];

        sort->posicoes(j);

        for(int k=0;k<j;k++)
            vet[k]=sort->vetPontos[k];

        sort->trocaMerge=0;
        sort->comparaMerge=0;
        sort->merge(vet,0,j);
        sort->pontos[i]=(sort->trocaMerge+sort->comparaMerge);
    }
    int vet[NUMERO_INTERACOES_GRAFICO];

    for(int i=0; i<NUMERO_INTERACOES_GRAFICO;i++)
        vet[i]=0;

    vet[0]=10;

    for(int i = 1; i< NUMERO_INTERACOES_GRAFICO; i++)
        vet[i]=vet[i-1]+10;

    QVector<double> x(NUMERO_INTERACOES_GRAFICO), y(NUMERO_INTERACOES_GRAFICO);
    for (int i=0; i<NUMERO_INTERACOES_GRAFICO; ++i)
    {
      x[i] = vet[i];
      y[i] = sort->pontos[i];
    }

    showGraph(x, y);

}

void MainWindow::on_actionQuick_2_triggered()
{
    for(int i=0; i<NUMERO_INTERACOES_GRAFICO;i++)
    {
        sort->pontos[i]=0;
    }

    for(int i=0, j=10; i<NUMERO_INTERACOES_GRAFICO;i++, j+=10)
    {
        int vet[j];

        sort->posicoes(j);

        for(int k=0;k<j;k++)
            vet[k]=sort->vetPontos[k];

        sort->trocaQuick=0;
        sort->comparaQuick=0;
        sort->quick(vet,0,j);
        sort->pontos[i]=(sort->trocaQuick+sort->comparaQuick);
    }
    int vet[NUMERO_INTERACOES_GRAFICO];

    for(int i=0; i<NUMERO_INTERACOES_GRAFICO;i++)
    {
        vet[i]=0;
    }

    vet[0]=10;

    for(int i = 1; i< NUMERO_INTERACOES_GRAFICO; i++)
    {
        vet[i]=vet[i-1]+10;
    }

    QVector<double> x(NUMERO_INTERACOES_GRAFICO), y(NUMERO_INTERACOES_GRAFICO);
    for (int i=0; i<NUMERO_INTERACOES_GRAFICO; ++i)
    {
      x[i] = vet[i];
      y[i] = sort->pontos[i];
    }

    showGraph(x, y);
}

void MainWindow::on_pushButton_clicked()
{
    ui->label_10->setNum(sort->comparaCocktail);
    ui->label_11->setNum(sort->trocaCocktail);
    ui->label_12->setNum(sort->tempoCocktail);

    ui->label_13->setNum(sort->comparaSelection);
    ui->label_14->setNum(sort->trocaSelection);
    ui->label_15->setNum(sort->tempoSelection);

    ui->label_16->setNum(sort->comparaInsertion);
    ui->label_17->setNum(sort->trocaInsertion);
    ui->label_18->setNum(sort->tempoInsertion);

    ui->label_19->setNum(sort->comparaBubble);
    ui->label_20->setNum(sort->trocaBubble);
    ui->label_21->setNum(sort->tempoBubble);

    ui->label_22->setNum(sort->comparaMerge);
    ui->label_23->setNum(sort->trocaMerge);
    ui->label_24->setNum(sort->tempoMerge);

    ui->label_25->setNum(sort->comparaQuick);
    ui->label_26->setNum(sort->trocaQuick);
    ui->label_27->setNum(sort->tempoQuick);

    ui->label_31->setNum(sort->comparaShell);
    ui->label_30->setNum(sort->trocaShell);
    ui->label_29->setNum(sort->tempoShel);
}

void MainWindow::on_actionDigite_o_valor_desejado_triggered()
{
    bool ok;
    int n = QInputDialog::getInt(this, tr("Escolha do Vetor"),tr("Digite a quantidade desejada até 10000:"), 25, 0, 10000, 1, &ok);

    sort->n=n;
    sort->inicio();
    sort->posicoes(sort->n);
}

void MainWindow::showGraph(QVector<double> x, QVector<double> y)
{
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);

    ui->customPlot->xAxis->setLabel("Numero de Posições no Vetor");
    ui->customPlot->yAxis->setLabel("Numero de Iterações");

    ui->customPlot->xAxis->setRange(0, NUMERO_INTERACOES_GRAFICO);
    ui->customPlot->yAxis->setRange(0, 7000);
    ui->customPlot->replot();

}


