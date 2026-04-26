#include <stdio.h>

// Função auxiliar para encontrar o maior valor
int max(int a, int b) {
    return (a > b) ? a : b;
}

int maior_subsequencia_crescente(int num[], int n) {
    int L[n];
    int maior = 0;

    // 1 para i = 0 até n-1 (ajustado para C)
    for (int i = 0; i < n; i++) {
        // 2 L[i] = 1
        L[i] = 1;
    }

    // 3 maior = 0 (ou 1, já que o mínimo de uma LIS é o próprio elemento)
    maior = 0;

    // 4 para i = 0 até n-1
    for (int i = 0; i < n; i++) {
        // 5 para j = 0 até i-1
        for (int j = 0; j < i; j++) {
            // 6 se num[j] < num[i]
            if (num[j] < num[i]) {
                // 7 L[i] = max(L[i], L[j] + 1)
                L[i] = max(L[i], L[j] + 1);
            }
        }
        // 8 maior = max(maior, L[i])
        maior = max(maior, L[i]);
    }

    // 9 retorne maior
    return maior;
}

int main() {
    int num[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(num) / sizeof(num[0]);

    int resultado = maior_subsequencia_crescente(num, n);

    printf("Comprimento da LIS (Bottom-Up): %d\n", resultado);

    return 0;
}