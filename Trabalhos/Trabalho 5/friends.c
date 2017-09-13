#include <stdio.h>
#include <stdlib.h>

int grupo[32000];
int tam[32000];

int find(int a) {
    if (a == grupo[a]) {
        return a;
    }
    
    return grupo[a] = find(grupo[a]);
}

void une(int a, int b) {
    grupo[find(b)] = find(a);
}
    
int main() 
{
    int tests;
    scanf("%d", &tests);
    
    while (tests--) {
        int n, m;
        scanf("%d %d", &n, &m);
        
        for (int i = 0; i < n; i++) {
            grupo[i] = i;
        }
        
        for (int i = 0; i < m; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            
            a--; b--;
            une(a, b);
        }
        
        int maior = 0;
        for (int i = 0; i < n; i++) {
            tam[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            int r = find(i);
            tam[r]++;
            if (tam[r] > maior) {
                maior = tam[r];
            }
        }
        
        printf("%d\n", maior);
    }
    
    return 0;
}