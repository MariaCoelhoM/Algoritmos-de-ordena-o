#include <stdio.h>

// Implementação baseada no pseudocódigo do professor
void insertionSort(int A[], int n) {
    for (int j = 1; j < n; j++) {
        
        // 3 chave ← A[j]
        int chave = A[j];
        
        // 4 i ← j − 1
        int i = j - 1;
        
        while (i >= 0 && A[i] > chave) {
            
            A[i + 1] = A[i];
            i = i - 1;
        }
        
        A[i + 1] = chave;
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
    int A[] = {12, 11, 13, 5, 6};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Array original: \n");
    imprimirArray(A, n);

    insertionSort(A, n);

    printf("Array ordenado: \n");
    imprimirArray(A, n);

    return 0;
}