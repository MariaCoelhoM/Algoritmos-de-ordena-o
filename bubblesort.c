#include <stdio.h>

//Função de troca 
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Implementação baseada no pseudocódigo do professor
void bubbleSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (A[j] > A[j + 1]) {
                troca(&A[j], &A[j + 1]);
            }
        }
    }
}

//Função auxiliar para imprimir o array
void imprimirArray(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Array original: \n");
    imprimirArray(A, n);

    bubbleSort(A, n);

    printf("Array ordenado: \n");
    imprimirArray(A, n);

    return 0;
}