#include <stdio.h>
#include <stdlib.h>

// 5. Estrutura para Alocar-No()
typedef struct No {
    char caractere;
    int frequencia;
    struct No *esq, *dir;
} No;

// Função auxiliar para criar um novo nó
No* criarNo(char car, int freq) {
    No* novo = (No*)malloc(sizeof(No));
    novo->caractere = car;
    novo->frequencia = freq;
    novo->esq = novo->dir = NULL;
    return novo;
}

// Função simples para ordenar os nós por frequência (simulando a fila de prioridade Q)
void ordenarFila(No** Q, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (Q[i]->frequencia > Q[j]->frequencia) {
                No* temp = Q[i];
                Q[i] = Q[j];
                Q[j] = temp;
            }
        }
    }
}

// Algoritmo de Huffman(C)
No* huffman(char caracteres[], int frequencias[], int n) {
    // 1. Q <- C (Criando a fila inicial com os nós folha)
    No** Q = (No**)malloc(n * sizeof(No*));
    for (int i = 0; i < n; i++) {
        Q[i] = criarNo(caracteres[i], frequencias[i]);
    }

    int tamanhoAtual = n;

    // 2. para i = 1 até |C| - 1 faça
    for (int i = 0; i < n - 1; i++) {
        // Ordena para garantir que os dois primeiros sejam os mínimos
        ordenarFila(Q, tamanhoAtual);

        // 3. x <- Extrai-Min(Q)
        No* x = Q[0];
        // 4. y <- Extrai-Min(Q)
        No* y = Q[1];

        // 5. z <- Alocar-No()
        // 8. f[z] <- f[x] + f[y] ('$' representa um nó interno)
        No* z = criarNo('$', x->frequencia + y->frequencia);

        // 6. esq[z] <- x
        z->esq = x;
        // 7. dir[z] <- y
        z->dir = y;

        // 9. Insere(Q, z) - Removemos x e y e colocamos z no lugar
        Q[0] = z;
        for (int j = 1; j < tamanhoAtual - 1; j++) {
            Q[j] = Q[j + 1];
        }
        tamanhoAtual--;
    }

    // 10. retorne Extrai-min(Q)
    No* raiz = Q[0];
    free(Q);
    return raiz;
}

// Função auxiliar para imprimir os códigos (para testar)
void imprimirCodigos(No* raiz, int arr[], int topo) {
    if (raiz->esq) {
        arr[topo] = 0;
        imprimirCodigos(raiz->esq, arr, topo + 1);
    }
    if (raiz->dir) {
        arr[topo] = 1;
        imprimirCodigos(raiz->dir, arr, topo + 1);
    }
    if (!raiz->esq && !raiz->dir) {
        printf("  %c: ", raiz->caractere);
        for (int i = 0; i < topo; i++) printf("%d", arr[i]);
        printf("\n");
    }
}

int main() {
    char car[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int n = sizeof(car) / sizeof(car[0]);

    printf("Construindo Arvore de Huffman...\n");
    No* raiz = huffman(car, freq, n);

    printf("Codigos gerados:\n");
    int arr[100], topo = 0;
    imprimirCodigos(raiz, arr, topo);

    return 0;
}