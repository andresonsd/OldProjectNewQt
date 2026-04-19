#ifndef SORT_H
#define SORT_H

#include <vector>

const int NUMERO_INTERACOES_GRAFICO = 100;

class SORT {
public:
    SORT();
    ~SORT();

    // Configuração de dados
    void inicio();
    void posicoes(int n);
    void posicoes20();
    void posicoes50();
    void posicoes100();

    // Algoritmos
    void cocktail(int vet[], int n);
    void selection(int vet[], int n);
    void insertion(int vet[], int n);
    void bubble(int vet[], int n);
    void shell(int vet[], int n);
    void merge(int vet[], int p, int r); // Chamada principal
    void quick(int vet[], int ini, int fim);

    // Atributos de controle
    int n;

    // Contadores (usando long para evitar overflow)
    long comparaCocktail, trocaCocktail, tempoCocktail;
    long comparaSelection, trocaSelection, tempoSelection;
    long comparaInsertion, trocaInsertion, tempoInsertion;
    long comparaBubble,    trocaBubble,    tempoBubble;
    long comparaShell,     trocaShell,     tempoShel; // Mantido 'tempoShel' p/ compatibilidade UI
    long comparaMerge,     trocaMerge,     tempoMerge;
    long comparaQuick,     trocaQuick,     tempoQuick;

    // Vetores de dados
    int vet20[20], vet50[50], vet100[100], vetPontos[10000];
    int pontos[NUMERO_INTERACOES_GRAFICO];

private:
    // Auxiliar do Merge
    void mergeIntercala(int vet[], int p, int q, int r);
};

#endif // SORT_H
