#include <stdio.h>

// Função de troca 
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função Particiona 
int particiona(int A[], int p, int r) {
    int pivo = A[p]; // Escolhe o primeiro elemento como pivo
    int i = p - 1;
    int j = r + 1;
    
    while (1) {
        do {
            j--;
        } while (A[j] > pivo);
        
        do {
            i++;
        } while (A[i] < pivo);
        
        if (i < j) {
            troca(&A[i], &A[j]);
        } else {
            return j; // Retorna o ponto de partição q
        }
    }
}

// Implementação baseada no pseudocódigo do professor
void quickSort(int A[], int p, int r) {
    if (p < r) {
        int q = particiona(A, p, r);
        quickSort(A, p, q);
        quickSort(A, q + 1, r);
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
    int A[] = {15, 10, 8, 20, 12, 5, 2, 30};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Array original: \n");
    imprimirArray(A, n);

    quickSort(A, 0, n - 1);

    printf("Array ordenado: \n");
    imprimirArray(A, n);

    return 0;
}