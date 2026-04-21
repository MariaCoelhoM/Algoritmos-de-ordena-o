#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um item
typedef struct {
    int id;
    double peso;
    double valor;
    double razao; // valor / peso
} Item;

// Função para comparar dois itens (usada no qsort para ordenar decrescente)
int comparar(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    if (itemB->razao > itemA->razao) return 1;
    if (itemB->razao < itemA->razao) return -1;
    return 0;
}

void mochilaFracionaria(Item itens[], int n, double W) {
    double x[n]; // Vetor para armazenar quanto de cada item levamos
    for (int j = 0; j < n; j++) x[j] = 0; // Inicializa com zero

    // 1. Calcular razão e ordenar (Ganancioso: maior razão primeiro)
    for (int i = 0; i < n; i++) {
        itens[i].razao = itens[i].valor / itens[i].peso;
    }
    qsort(itens, n, sizeof(Item), comparar);

    double pesoAtual = W;
    int i = 0;

    // 3. Enquanto houver itens e a mochila não estiver cheia
    while (i < n && pesoAtual > 0) {
        if (itens[i].peso <= pesoAtual) {
            // 5. Coloca o objeto inteiro
            x[i] = 1.0;
            pesoAtual -= itens[i].peso;
        } else {
            // 8. Coloca apenas a fração do objeto
            x[i] = pesoAtual / itens[i].peso;
            pesoAtual = 0;
        }
        i++;
    }

    // Exibição dos resultados
    printf("Itens selecionados (proporcao):\n");
    double valorTotal = 0;
    for (int j = 0; j < i; j++) {
        if (x[j] > 0) {
            printf("Item ID %d: %.2f%% levado\n", itens[j].id, x[j] * 100);
            valorTotal += x[j] * itens[j].valor;
        }
    }
    printf("Valor total na mochila: %.2f\n", valorTotal);
}

int main() {
    double capacidade = 50.0;
    Item itens[] = {
        {1, 10, 60, 0}, // Item 1: peso 10, valor 60 (razao 6)
        {2, 20, 100, 0}, // Item 2: peso 20, valor 100 (razao 5)
        {3, 30, 120, 0}  // Item 3: peso 30, valor 120 (razao 4)
    };
    int n = sizeof(itens) / sizeof(itens[0]);

    mochilaFracionaria(itens, n, capacidade);

    return 0;
}