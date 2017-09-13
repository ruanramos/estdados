#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <vector>

using namespace std;

// função que faz o merge das metades do vetor
void merge(vector<int>& V, int inicio, int meio, int fim) {
    int *temp, p1, p2, tamanho, i, j, k;
    // finais dos vetores 1 e 2
    int fim1 = 0, fim2 = 0;
    // tamanho do vetor após o merge
    tamanho = fim - inicio + 1;
    // ponteiros para os dois vetores que serão combinados
    p1 = inicio;
    p2 = meio + 1;
    // vetor combinado
    temp = (int*) malloc(tamanho * sizeof(int));
    
    if(temp != NULL) {
        for(i = 0; i < tamanho; i++) {
            // combina os vetores ordenado
            if(!fim1 && !fim2) {
                if(V[p1] < V[p2]) {
                    temp[i] = V[p1++];
                } else {
                    temp[i] = V[p2++];
                }
                // vetor acabou?
                if(p1 > meio) {
                    fim1 = 1;
                }
                if(p2 > fim) {
                    fim2 = 1;
                }
            } else {
                // copia o que sobrar
                if(!fim1) {
                    temp[i] = V[p1++];
                } else {
                    temp[i] = V[p2++];
                }
            }
        }
        // copia temp para o vetor original
        for(j = 0, k = inicio; j < tamanho; j++, k++) {
            V[k] = temp[j];
        }
    }
    free(temp);
}

void merge_sort(vector<int>& V, int inicio, int fim) {
    int meio;
    if(inicio < fim) {
        meio = (inicio + fim) / 2;
        // chama a função para as duas metades
        merge_sort(V, inicio, meio);
        merge_sort(V, meio + 1, fim);
        // combina as duas metades
        merge(V, inicio, meio, fim);
    }
}

int particiona(vector<int>& V, int inicio, int final) {
    int esq = inicio;
    int dir = final;
    int pivo = V[rand() % (final - inicio) + inicio];
    while(esq < dir) {
        // avança posição da esquerda
        while(V[esq] < pivo) {
            esq++;
        }
        // recua posição da direita
        while(V[dir] > pivo) {
            dir --;
        }
        // troca esquerda e direita
        if(esq < dir) {
            int aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
        }
    }
    return dir;
}

void quick_sort(vector<int>& V, int inicio, int fim) {
    int pivo;
    if(fim > inicio) {
        // separa os dados em duas partições
        pivo = particiona(V, inicio, fim);
        // chama a função para as duas metades
        quick_sort(V, inicio, pivo - 1);
        quick_sort(V, pivo + 1, fim);
    }
}

int main(int argc, char **argv) {
    srand(time(NULL));
    
    int a;
    vector<int> v;
    while (scanf("%d", &a) == 1) {
        v.push_back(a);
    }
    
    if (strcmp(argv[1], "-q") == 0) {
        quick_sort(v, 0, v.size()-1);
    } else {
        merge_sort(v, 0, v.size()-1);
    }
    
    for (int i = 0; i < (int) v.size(); i++) {
        printf("%d\n", v[i]);
    }
    
    return 0;
}