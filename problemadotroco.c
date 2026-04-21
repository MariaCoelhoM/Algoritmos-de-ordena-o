#include <stdio.h>

void troco(int C[], int n, int valor) {
    int S[100];      // Conjunto solução (armazenará as moedas escolhidas)
    int s_idx = 0;   // Índice para o conjunto S
    int soma = 0;    // Soma atual
    int i = 0;       // Índice para percorrer as moedas em C

    // Enquanto houver moedas e a soma for menor que o valor
    while (i < n && soma < valor) {
        int m = C[i]; // Pega a moeda de maior valor disponível

        if (soma + m <= valor) {
            soma = soma + m;
            S[s_idx] = m; // S <- S U {m}
            s_idx++;
        } else {
            i++; // C <- C - {m} (Passa para a próxima moeda menor)
        }
    }

    // Verificação final
    if (soma == valor) {
        printf("Solucao encontrada: ");
        for (int j = 0; j < s_idx; j++) {
            printf("%d ", S[j]);
        }
        printf("\n");
    } else {
        printf("Não encontrei a solucao\n");
    }
}

int main() {
    // Exemplo: Moedas disponíveis (deve estar em ordem decrescente)
    int moedas[] = {100, 50, 25, 10, 5, 1};
    int n = sizeof(moedas) / sizeof(moedas[0]);
    int valor_desejado = 87;

    printf("Calculando troco para %d:\n", valor_desejado);
    troco(moedas, n, valor_desejado);

    return 0;
}