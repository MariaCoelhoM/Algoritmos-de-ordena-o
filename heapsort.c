#include <stdio.h>

// Função de troca
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// m = tamanho atual do heap, i = índice que deve descer
void desceHeap(int A[], int m, int i) {
    int maior = i;
    int esquerda = 2 * i;     // Filho à esquerda
    int direita = 2 * i + 1; // Filho à direita

    // Se o filho da esquerda é maior que a raiz
    if (esquerda <= m && A[esquerda - 1] > A[maior - 1])
        maior = esquerda;

    // Se o filho da direita é maior que o maior até agora
    if (direita <= m && A[direita - 1] > A[maior - 1])
        maior = direita;

    // Se o maior não é a raiz
    if (maior != i) {
        troca(&A[i - 1], &A[maior - 1]);
        desceHeap(A, m, maior);
    }
}

// 1 Constroi-Heap(A)
void constroiHeap(int A[], int n) {
    for (int i = n / 2; i >= 1; i--) {
        desceHeap(A, n, i);
    }
}

// Implementação baseada no pseudocódigo do professor
void heapSort(int A[], int n) {
    constroiHeap(A, n);

    // 2 para i = n até 2
    for (int i = n; i >= 2; i--) {
        // 3 faça A[1] ↔ A[i]
        troca(&A[0], &A[i - 1]);

        // 4 Desce-Heap(A, i-1, 1)
        desceHeap(A, i - 1, 1);
    }
}

// Função auxiliar para imprimir o array
void imprimirArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Array original: \n");
    imprimirArray(A, n);

    heapSort(A, n);

    printf("Array ordenado: \n");
    imprimirArray(A, n);

    return 0;
}