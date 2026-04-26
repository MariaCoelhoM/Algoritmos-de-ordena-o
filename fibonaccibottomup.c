#include <stdio.h>

// Função que implementa o Fibonacci Bottom-Up
long long fib(int n) {
    // Caso base para evitar problemas com arrays de tamanho 0 ou 1
    if (n == 0) return 0;
    if (n == 1) return 1;

    // Criamos um array para armazenar os cálculos
    long long f[n + 1];

    // 1 f[0] = 0
    f[0] = 0;
    // 2 f[1] = 1
    f[1] = 1;

    // 3 para i = 2 até n
    for (int i = 2; i <= n; i++) {
        // 4 f[i] = f[i − 1] + f[i − 2]
        f[i] = f[i - 1] + f[i - 2];
    }

    // 5 retorne f[n]
    return f[n];
}

int main() {
    int n = 60; // Exemplo de valor alto

    printf("Fibonacci de %d (Bottom-Up): %lld\n", n, fib(n));

    return 0;
}