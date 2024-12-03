#include<stdio.h>
#include "sort.h"
#include <stdlib.h>// necessário p/ as funções rand() e srand()
#include <time.h>//necessário p/ função time()


SORT::SORT(){}

SORT::~SORT(){}

void SORT::posicoes(int n){

    srand(time(NULL));

    for(int i=0;i<n;i++)
        vetPontos[i]=rand()%1000;

    for(int i=0;i<20;i++)
        vet20[i]=0;

    for(int i=0;i<50;i++)
        vet50[i]=0;

    for(int i=0;i<100;i++)
        vet100[i]=0;
}

void SORT::inicio(){
    comparaBubble=comparaCocktail=comparaInsertion=comparaMerge=comparaQuick=comparaSelection=comparaShell=0;
    trocaBubble=trocaCocktail=trocaInsertion=trocaMerge=trocaQuick=trocaSelection=trocaShell=0;
    tempoBubble=tempoCocktail=tempoInsertion=tempoMerge=tempoQuick=tempoSelection=tempoShel=0;
}

void SORT::posicoes20(){

    n=20;

    srand(time(NULL));

    for(int i=0;i<20;i++)
    {
        vet20[i]=rand()%50;
    }

    for(int i=0;i<50;i++)
    {
        vet50[i]=0;
    }

    for(int i=0;i<100;i++)
    {
        vet100[i]=0;
    }
}

void SORT::posicoes50(){

    n=50;

    for(int i=0;i<20;i++)
        vet20[i]=0;

    for(int i=0;i<50;i++)
        vet50[i]=rand()%150;

    for(int i=0;i<100;i++)
        vet100[i]=0;
}

void SORT::posicoes100(){

    n=100;

    for(int i=0;i<20;i++)
        vet20[i]=0;

    for(int i=0;i<50;i++)
        vet50[i]=0;

    for(int i=0;i<100;i++)
        vet100[i]=rand()%300;
}

void SORT::cocktail(int vet[],int n){

    int i=0, fim=0, ini=0, aux=0;

    bool verif = false;
    fim = n-1;
    while(verif == false && ini < fim){
        verif = true;
        for(i = ini; i< fim; i++){
            comparaCocktail++;
            if(vet[i] > vet[i+1]){
                aux = vet[i];
                vet[i]=vet[i+1];
                vet[i+1] = aux;
                trocaCocktail++;
                verif = false;
            }
        }
        fim--;
        for(i=fim;i>ini;i--){
            if(vet[i]<vet[i-1]){
                aux = vet[i];
                vet[i] = vet[i-1];
                vet[i-1] = aux;
                trocaCocktail++;
                verif = false;
            }
            comparaCocktail++;
        }
        ini++;
    }
}

void SORT::selection(int vet[],int n){

    for (int i = 0; i < (n-1); i++){
        int menor = i;
        for (int j = (i+1); j < n; j++){
            comparaSelection++;
            if(vet[j] < vet[menor])
                menor = j;
        }
        int aux = vet[i];
        vet[i] = vet[menor];
        vet[menor] = aux;
        trocaSelection++;
    }
}

void SORT::insertion(int vet[],int n){

    for (int i = 1; i < n; i++) {
        int j = i;
        comparaInsertion++;
        while ((j > 0) && (vet[j - 1] > vet[j])) {
            if(vet[j-1]>vet[j])
                comparaInsertion++;
            int aux = vet[j - 1];
            vet[j - 1] = vet[j];
            vet[j] = aux;
            j--;

        trocaInsertion++;
        }
    }
}

void SORT::bubble(int vet[], int n){

    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            comparaBubble++;
            if(vet[j]<vet[j-1]){
                int aux=vet[j];
                vet[j]=vet[j-1];
                vet[j-1]=aux;
                trocaBubble++;
            }
        }
    }
}

void SORT::shell(int vet[], int n){

    int h = n;
    do{
        h = (h + 1)/2;
        for (int i =0; i < (n - h); i++){
            comparaShell++;
            if (vet[i + h] < vet[i]){
                int aux = vet[i+h];
                vet[i + h] = vet[i];
                vet[i] = aux;
                trocaShell++;
            }
        }
    }while(h > 1);
}

void SORT::merge(int vet[], int p, int r){
    if (p < r) {
        int q = (r+p)/2;

        merge(vet, p, q);
        merge(vet, q+1, r);
        sort(vet, p, q, r);
    }
}

void SORT::sort(int vet[], int p, int q, int r) {
    int com1 = p, com2 = q+1, aux = 0, tam = r-p+1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= q && com2 <= r){
        comparaMerge++;
        if(vet[com1] < vet[com2]) {
            vetAux[aux] = vet[com1];
            com1++;
        } else {
            vetAux[aux] = vet[com2];
            com2++;
        }
        trocaMerge++;
        aux++;
    }

    while(com1 <= q){  //Caso ainda haja elementos na primeira metade
        vetAux[aux] = vet[com1];
        aux++;
        com1++;
        trocaMerge++;
    }

    while(com2 <= r) {   //Caso ainda haja elementos na segunda metade
        vetAux[aux] = vet[com2];
        aux++;
        com2++;
        trocaMerge++;
    }

    for(aux = p; aux <= r; aux++){    //Move os elementos de volta para o vet original
        vet[aux] = vetAux[aux-p];
    }

    free(vetAux);
}

void SORT::quick(int vet[], int ini, int n){

    int i=ini, j=n-1, pivo=vet[(ini + n) / 2];
    while(i <= j){
        while(vet[i] < pivo && i < n){
            i++;
        }
        while(vet[j] > pivo && j > ini){
            j--;
        }
        if(i <= j){
            int aux = vet[i];
            vet[i] = vet[j];
            vet[j] = aux;
            i++;
            j--;
            trocaQuick++;
        }
    }
    comparaQuick++;
    if(j > ini)
        quick(vet, ini, j+1);
    if(i < n)
        quick(vet, i, n);
}

