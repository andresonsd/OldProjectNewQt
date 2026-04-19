#include "sort.h"
#include <cstdlib>
#include <ctime>
#include <algorithm> // Para std::swap
#include <vector>

SORT::SORT() {
    n = 0;
    inicio();
}

SORT::~SORT() {}

void SORT::inicio() {
    comparaBubble = comparaCocktail = comparaInsertion = comparaMerge = comparaQuick = comparaSelection = comparaShell = 0;
    trocaBubble = trocaCocktail = trocaInsertion = trocaMerge = trocaQuick = trocaSelection = trocaShell = 0;
    tempoBubble = tempoCocktail = tempoInsertion = tempoMerge = tempoQuick = tempoSelection = tempoShel = 0;
}

void SORT::posicoes(int n_val) {
    this->n = n_val;
    srand(time(NULL));
    for(int i = 0; i < n_val && i < 10000; i++)
        vetPontos[i] = rand() % 1000;
}

void SORT::posicoes20() {
    n = 20;
    srand(time(NULL));
    for(int i = 0; i < 20; i++) vet20[i] = rand() % 50;
}

void SORT::posicoes50() {
    n = 50;
    srand(time(NULL));
    for(int i = 0; i < 50; i++) vet50[i] = rand() % 150;
}

void SORT::posicoes100() {
    n = 100;
    srand(time(NULL));
    for(int i = 0; i < 100; i++) vet100[i] = rand() % 300;
}

// --- ALGORITMOS ---

void SORT::cocktail(int vet[], int n) {
    bool trocou = true;
    int ini = 0, fim = n - 1;
    while(trocou) {
        trocou = false;
        for(int i = ini; i < fim; i++) {
            comparaCocktail++;
            if(vet[i] > vet[i+1]) {
                std::swap(vet[i], vet[i+1]);
                trocaCocktail++;
                trocou = true;
            }
        }
        if(!trocou) break;
        trocou = false;
        fim--;
        for(int i = fim - 1; i >= ini; i--) {
            comparaCocktail++;
            if(vet[i] > vet[i+1]) {
                std::swap(vet[i], vet[i+1]);
                trocaCocktail++;
                trocou = true;
            }
        }
        ini++;
    }
}

void SORT::selection(int vet[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            comparaSelection++;
            if(vet[j] < vet[menor]) menor = j;
        }
        std::swap(vet[i], vet[menor]);
        trocaSelection++;
    }
}

void SORT::insertion(int vet[], int n) {
    for (int i = 1; i < n; i++) {
        int j = i;
        while (j > 0) {
            comparaInsertion++;
            if (vet[j-1] > vet[j]) {
                std::swap(vet[j-1], vet[j]);
                trocaInsertion++;
                j--;
            } else break;
        }
    }
}

void SORT::bubble(int vet[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = n - 1; j > i; j--) {
            comparaBubble++;
            if(vet[j] < vet[j-1]) {
                std::swap(vet[j], vet[j-1]);
                trocaBubble++;
            }
        }
    }
}

void SORT::shell(int vet[], int n) {
    for (int h = n / 2; h > 0; h /= 2) {
        for (int i = h; i < n; i++) {
            int temp = vet[i];
            int j;
            for (j = i; j >= h; j -= h) {
                comparaShell++;
                if(vet[j - h] > temp) {
                    vet[j] = vet[j - h];
                    trocaShell++;
                } else break;
            }
            vet[j] = temp;
        }
    }
}

void SORT::merge(int vet[], int p, int r) {
    if (p < r) {
        int q = p + (r - p) / 2;
        merge(vet, p, q);
        merge(vet, q + 1, r);
        mergeIntercala(vet, p, q, r);
    }
}

void SORT::mergeIntercala(int vet[], int p, int q, int r) {
    int tam = r - p + 1;
    std::vector<int> aux(tam);
    int i = p, j = q + 1, k = 0;
    while(i <= q && j <= r) {
        comparaMerge++;
        if(vet[i] <= vet[j]) aux[k++] = vet[i++];
        else aux[k++] = vet[j++];
        trocaMerge++;
    }
    while(i <= q) { aux[k++] = vet[i++]; trocaMerge++; }
    while(j <= r) { aux[k++] = vet[j++]; trocaMerge++; }
    for(i = 0; i < tam; i++) vet[p + i] = aux[i];
}

void SORT::quick(int vet[], int ini, int fim) {
    int i = ini, j = fim;
    int pivo = vet[(ini + fim) / 2];
    while (i <= j) {
        while (vet[i] < pivo) i++;
        while (vet[j] > pivo) j--;
        if (i <= j) {
            std::swap(vet[i], vet[j]);
            trocaQuick++;
            i++; j--;
        }
    }
    comparaQuick++;
    if (ini < j) quick(vet, ini, j);
    if (i < fim) quick(vet, i, fim);
}
