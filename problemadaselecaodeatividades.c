#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma atividade
typedef struct {
    int id;    // Identificador original da atividade
    int s;     // Tempo de início (start)
    int t;     // Tempo de término (finish)
} Atividade;

// Função de comparação para ordenar pelo tempo de término (t) crescente
int comparar(const void *a, const void *b) {
    Atividade *atA = (Atividade *)a;
    Atividade *atB = (Atividade *)b;
    return (atA->t - atB->t);
}

void selecionaAtividades(Atividade atividades[], int n) {
    // 1. Ordene s e t de tal forma que t[1] <= t[2] <= ... <= t[n]
    qsort(atividades, n, sizeof(Atividade), comparar);

    int A[n];    // Vetor para armazenar os IDs das atividades selecionadas
    int a_idx = 0;

    // 2. A <- {1} (Em C, o primeiro índice é 0)
    A[a_idx++] = atividades[0].id;
    
    // 3. j <- 1 (Índice da última atividade selecionada)
    int j = 0;

    // 4. para i = 2 até n
    for (int i = 1; i < n; i++) {
        // 5. faça se si >= tj (Início da atual >= Término da última selecionada)
        if (atividades[i].s >= atividades[j].t) {
            // 6. então A <- A U {i}
            A[a_idx++] = atividades[i].id;
            // 7. j <- i
            j = i;
        }
    }

    // 8. retorne A (Exibindo o conjunto de atividades)
    printf("Atividades selecionadas (IDs originais): ");
    for (int k = 0; k < a_idx; k++) {
        printf("%d ", A[k]);
    }
    printf("\nTotal de atividades: %d\n", a_idx);
}

int main() {
    // Exemplo de atividades (ID, Início, Término)
    // Note que elas não precisam estar ordenadas aqui, o código fará isso.
    Atividade lista[] = {
        {1, 1, 4}, {2, 3, 5}, {3, 0, 6}, {4, 5, 7}, 
        {5, 3, 9}, {6, 5, 9}, {7, 6, 10}, {8, 8, 11}, 
        {9, 8, 12}, {10, 2, 14}, {11, 12, 16}
    };
    int n = sizeof(lista) / sizeof(lista[0]);

    printf("Processando selecao de atividades...\n");
    selecionaAtividades(lista, n);

    return 0;
}