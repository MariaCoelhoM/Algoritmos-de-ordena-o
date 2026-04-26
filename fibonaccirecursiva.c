#include <stdio.h>

// Implementação baseada no pseudocódigo fornecido
int fib(int n) {
    // 1 se n = 0 ou n = 1
    if (n == 0 || n == 1) {
        // 2 retorne n
        return n;
    } 
    // 3 senão
    else {
        // 4 retorne fib(n - 1) + fib(n - 2)
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    int numero = 10; // Exemplo: calcular o 10º termo
    
    printf("O Fibonacci de %d e: %d\n", numero, fib(numero));
    
    return 0;
}