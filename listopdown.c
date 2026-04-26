#include <stdio.h>

#define MAX 100

// Variáveis globais conforme a lógica do problema
int num[] = {10, 22, 9, 33, 21, 50, 41, 60};
int L[MAX]; // Array de memória (memoization)

// Função auxiliar max
int max(int a, int b) {
    return (a > b) ? a : b;
}

// LIS(i) - Versão com Programação Dinâmica (Top-Down)
int LIS(int i) {
    // 1 se L[i] != -1 (caso já calculado)
    if (L[i] != -1) {
        // 2 retorne L[i]
        return L[i];
    }
    
    // 3 senão se i = 0
    if (i == 0) {
        // 4 retorne L[i] = 1
        return L[i] = 1;
    } 
    // 5 senão
    else {
        // 6 maior = 1
        int maior = 1;
        // 7 para j = 0 até i-1 (anteriores a i)
        for (int j = 0; j < i; j++) {
            // 8 se num[j] < num[i]
            if (num[j] < num[i]) {
                // 9 maior = max(maior, LIS(j) + 1)
                maior = max(maior, LIS(j) + 1);
            }
        }
        // 10 retorne L[i] = maior
        return L[i] = maior;
    }
}

// subsequencia crescente mais longa(num, n)
int maior_subsequencia_crescente(int n) {
    // 1 maior = 1
    int maior_global = 1;
    
    // 2 para i = 0 até n-1 (ajuste para índices em C)
    for (int i = 0; i < n; i++) {
        // 3 maior = max(maior, LIS(i))
        maior_global = max(maior_global, LIS(i));
    }
    // 4 retorne maior
    return maior_global;
}

int main() {
    int n_elementos = sizeof(num) / sizeof(num[0]);

    // Inicializa o array de memória com -1
    for (int i = 0; i < MAX; i++) {
        L[i] = -1;
    }

    int resultado = maior_subsequencia_crescente(n_elementos);
    
    printf("Comprimento da LIS (Top-Down): %d\n", resultado);
    
    return 0;
}