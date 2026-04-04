#include <stdio.h>
#include <stdlib.h>

// Estrutura para os nós da lista encadeada
struct No {
    float dado;
    struct No *proximo;
};

// 6 faça Insertion-Sort(B[i]) para cada balde
struct No* insertionSortLista(struct No* lista) {
    if (!lista || !lista->proximo) return lista;

    struct No* ordenado = NULL;
    struct No* atual = lista;

    while (atual != NULL) {
        struct No* proximo = atual->proximo;
        
        // Insere na lista ordenada
        if (!ordenado || ordenado->dado >= atual->dado) {
            atual->proximo = ordenado;
            ordenado = atual;
        } else {
            struct No* temp = ordenado;
            while (temp->proximo != NULL && temp->proximo->dado < atual->dado) {
                temp = temp->proximo;
            }
            atual->proximo = temp->proximo;
            temp->proximo = atual;
        }
        atual = proximo;
    }
    return ordenado;
}

// Implementação baseada no pseudocódigo do professor
void bucketSort(float A[], int n) {
    struct No **B = (struct No **)malloc(n * sizeof(struct No *));
    for (int i = 0; i < n; i++) B[i] = NULL;

    for (int i = 0; i < n; i++) {
        struct No* novoNo = (struct No*)malloc(sizeof(struct No));
        novoNo->dado = A[i];
        
        int indiceBalde = (int)(n * A[i]); // floor(n * A[i])
        
        novoNo->proximo = B[indiceBalde];
        B[indiceBalde] = novoNo;
    }

    for (int i = 0; i < n; i++) {
        B[i] = insertionSortLista(B[i]);
    }

    int indiceA = 0;
    for (int i = 0; i < n; i++) {
        struct No* atual = B[i];
        while (atual != NULL) {
            A[indiceA++] = atual->dado;
            struct No* aux = atual;
            atual = atual->proximo;
            free(aux); // Limpa a memória
        }
    }
    free(B);
}

void imprimirArray(float A[], int n) {
    for (int i = 0; i < n; i++) printf("%.2f ", A[i]);
    printf("\n");
}

int main() {
    float A[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Array original: ");
    imprimirArray(A, n);

    bucketSort(A, n);

    printf("Array ordenado: ");
    imprimirArray(A, n);

    return 0;
}