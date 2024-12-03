#ifndef SORT_H
#define SORT_H

#define NUMERO_INTERACOES_GRAFICO 100

class SORT{

public:
    SORT();
    ~SORT();

    //escolhas possiveis de tamanho de vetor
    void posicoes20();
    void posicoes50();
    void posicoes100();
    void posicoes(int);

    //metodos de ordenação a serem comparados
    void cocktail(int[], int);
    void selection(int[], int);
    void insertion(int[], int);
    void bubble(int[], int);
    void shell(int[], int);
    void merge(int[], int, int);
    void sort(int[], int, int,int);
    void quick(int[], int, int);
    void inicio();

    int n;
    int comparaCocktail, trocaCocktail;//valores obtidos a partir do metodo Cocktail Sort
    int comparaSelection, trocaSelection;//valores obtidos a partir do metodo Selection Sort
    int comparaInsertion, trocaInsertion;//valores obtidos a partir do metodo Insertion Sort
    int comparaBubble, trocaBubble;//valores obtidos a partir do metodo Bubble Sort
    int comparaShell, trocaShell;//valores obtidos a partir do metodo Shell Sort
    int comparaMerge, trocaMerge;//valores obtidos a partir do metodo Merge Sort
    int comparaQuick, trocaQuick;//valores obtidos a partir do metodo Quick Sort
    int vet20[20], vet50[50], vet100[100];//vetores de valores que podem ser escolhidos
    int tempoCocktail, tempoSelection, tempoInsertion, tempoBubble, tempoShel, tempoMerge, tempoQuick;
    int vetPontos[10000];
    int pontos[NUMERO_INTERACOES_GRAFICO];

};

#endif // SORT_H
