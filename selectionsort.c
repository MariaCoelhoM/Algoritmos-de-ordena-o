#include <stdio.h>

// Implementação baseada no pseudocódigo do professor
void selectionSort(int A[], int n) {
    for (int i = 0; i < n - 1; i++) {
        
        // 2 min = i
        int min = i;
        // 3 para j = i + 1 até n faça
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[min]) {
                min = j;
            }
        }
        
        // 6 A[i] ↔ A[min] 
        if (min != i) {
            int temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
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
    int A[] = {64, 25, 12, 22, 11};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Array original: \n");
    imprimirArray(A, n);

    selectionSort(A, n);

    printf("Array ordenado: \n");
    imprimirArray(A, n);

    return 0;
}