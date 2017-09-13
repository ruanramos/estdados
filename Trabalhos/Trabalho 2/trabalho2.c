#include <stdio.h>
#include <stdlib.h>

int numDeps[128];
int tasksPrecedence[128][128];

int topo;
int pilha[128];

void empilha(int t) {
    pilha[topo++] = t;
}

int desempilha() {
    return pilha[--topo];
}
    
int main() 
{
    while (1) {
        int n, m;
        scanf("%d" "%d", &n, &m);
        if (n == 0 && m == 0) break;
        
        for (int i = 0; i < n; i++) {
            numDeps[i] = 0;
            for (int j = 0; j < n; j++) {
                tasksPrecedence[i][j] = 0;
            }
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            a--; b--;
            tasksPrecedence[a][b] = 1;
            numDeps[b]++;
        }
        
        topo = 0;
        for (int i = 0; i < n; i++) {
            if (numDeps[i] == 0) {
                empilha(i);
            }
        }
        
        while (topo != 0) {
            int t = desempilha();
            printf("%d ", t + 1);
            for (int j = 0; j < n; j++) {
                if(tasksPrecedence[t][j] == 1) {
                    numDeps[j]--;
                    if(numDeps[j] == 0) {
                        empilha(j);
                    }
                }
            }
        }
        printf("\n");
    }
    
    return 0;
}