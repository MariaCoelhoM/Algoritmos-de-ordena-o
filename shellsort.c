#include <stdio.h>

// Implementação baseada no pseudocódigo do professor
void shellSort(int A[], int n) {
    int h = n / 2;
    
    // 2 enquanto h > 0 faça
    while (h > 0) {
        
        // 3 para j = h até n faça
        for (int j = h; j < n; j++) {
            
            // 4 chave ← A[j]
            int chave = A[j];
            int i = j;
            while (i >= h && A[i - h] > chave) {
                A[i] = A[i - h];
                i = i - h;
            }
            
            A[i] = chave;
        }
        
        h = h / 2;
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
    int A[] = {12, 34, 54, 2, 3, 45, 1, 8};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Array original: \n");
    imprimirArray(A, n);

    shellSort(A, n);

    printf("Array ordenado: \n");
    imprimirArray(A, n);

    return 0;
}