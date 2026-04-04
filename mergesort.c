#include <stdio.h>
#include <stdlib.h>

// Função que combina duas metades ordenadas
void merge(int A[], int p, int q, int r) {
    int i, j, k;
    int n1 = q - p + 1; // Tamanho da metade esquerda
    int n2 = r - q;     // Tamanho da metade direita

    // Cria arrays temporários
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    // Copia os dados para os arrays temporários L e R
    for (i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    // Intercala os arrays temporários de volta em A[p..r]
    i = 0; // Índice inicial do primeiro subarray
    j = 0; // Índice inicial do segundo subarray
    k = p; // Índice inicial do array intercalado
    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

// Função principal do Merge Sort
void mergeSort(int A[], int p, int r) {
    if (p < r) {
        int q = p + (r - p) / 2;

        // Recursão: Divide a primeira e a segunda metade
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);

        // Intercala as metades ordenadas
        merge(A, p, q, r);
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
    int A[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Array original: \n");
    imprimirArray(A, n);

    mergeSort(A, 0, n - 1);

    printf("Array ordenado: \n");
    imprimirArray(A, n);

    return 0;
}