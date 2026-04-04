#include <stdio.h>
#include <stdlib.h>

// Função para encontrar o maior valor e determinar 'd'
int obterMax(int A[], int n) {
    int max = A[0];
    for (int i = 1; i < n; i++)
        if (A[i] > max) max = A[i];
    return max;
}

void countingSortPorDigito(int A[], int n, int exp) {
    int B[n]; // array de saída
    int C[10] = {0}; // base 10 (0 a 9)

    // Armazena a contagem de ocorrências do dígito atual 
    for (int j = 0; j < n; j++) {
        C[(A[j] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        C[i] += C[i - 1];
    }

    // Constrói o array de saída B
    for (int j = n - 1; j >= 0; j--) {
        B[C[(A[j] / exp) % 10] - 1] = A[j];
        C[(A[j] / exp) % 10]--;
    }

    // Copia o array B para A, para que A contenha os números ordenados pelo dígito atual
    for (int i = 0; i < n; i++) {
        A[i] = B[i];
    }
}

// Implementação baseada no pseudocódigo do professor
void radixSort(int A[], int n) {
    int m = obterMax(A, n);

    for (int exp = 1; m / exp > 0; exp *= 10) {
        // 2 ordena A[1..n] pelo n-ésimo dígito com um algarismo estável
        countingSortPorDigito(A, n, exp);
    }
}

void imprimirArray(int A[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", A[i]);
    printf("\n");
}

int main() {
    int A[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Array original: ");
    imprimirArray(A, n);

    radixSort(A, n);

    printf("Array ordenado: ");
    imprimirArray(A, n);

    return 0;
}