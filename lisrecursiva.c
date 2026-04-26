#include <stdio.h>

// Array de exemplo e seu tamanho
int num[] = {10, 22, 9, 33, 21, 50, 41, 60};
int n = 8;

// Função auxiliar para comparar valores
int max(int a, int b) {
    return (a > b) ? a : b;
}

// LIS(i) - Solução recursiva
int LIS(int i) {
    // 1 se i = 0
    if (i == 0) {
        // 2 retorne 1
        return 1;
    } 
    // 3 senão
    else {
        // 4 maior = 1
        int maior = 1;
        // 5 para j = 0 até i-1 (ajustado para C, pois j deve ser anterior a i)
        for (int j = 0; j < i; j++) {
            // 6 se num[j] < num[i]
            if (num[j] < num[i]) {
                // 7 maior = max(maior, LIS(j) + 1)
                maior = max(maior, LIS(j) + 1);
            }
        }
        // 8 retorne maior
        return maior;
    }
}

// subsequencia crescente mais longa(num, n)
int maior_subsequencia_crescente(int num[], int n) {
    // 1 maior = 1
    int maior_global = 1;
    // 2 para i = 1 até n-1 (em C, o array vai de 0 a n-1)
    for (int i = 0; i < n; i++) {
        // 3 maior = max(maior, LIS(i))
        maior_global = max(maior_global, LIS(i));
    }
    // 4 retorne maior
    return maior_global;
}

int main() {
    int resultado = maior_subsequencia_crescente(num, n);
    
    printf("Comprimento da Maior Subsequencia Crescente (LIS): %d\n", resultado);
    
    return 0;
}