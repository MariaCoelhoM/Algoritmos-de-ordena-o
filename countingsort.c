#include <stdio.h>
#include <stdlib.h>

// A = Array original, B = Array de saída, n = tamanho de A, k = valor máximo
void countingSort(int A[], int B[], int n, int k) {
    int *C = (int *)calloc(k + 1, sizeof(int));

    // 3 para j = 1 até n faça
    for (int j = 0; j < n; j++) {
        C[A[j]] = C[A[j]] + 1;
    }

    // 6 para i = 2 até k faça
    for (int i = 1; i <= k; i++) {
        C[i] = C[i] + C[i - 1];
    }

    // 9 para j = n até 1 faça 
    for (int j = n - 1; j >= 0; j--) {
        B[C[A[j]] - 1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    }

    free(C);
}

void imprimirArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int A[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(A) / sizeof(A[0]);
    int B[n]; // Array para o resultado
    
    // Encontrar o maior valor (k) no array
    int k = A[0];
    for(int i = 1; i < n; i++) if(A[i] > k) k = A[i];

    printf("Array original: ");
    imprimirArray(A, n);

    countingSort(A, B, n, k);

    printf("Array ordenado: ");
    imprimirArray(B, n);

    return 0;
}