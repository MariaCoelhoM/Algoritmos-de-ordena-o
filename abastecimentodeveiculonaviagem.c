#include <stdio.h>

void algoritmoCaminhoneiro(int p[], int n, int C) {
    int S[100];         // Conjunto de paradas selecionadas (índices ou quilometragens)
    int s_idx = 0;      // Contador para o conjunto S
    int ultima_parada = p[0]; // ultima_parada = 0 (considerando p[0] como km 0)

    // 3. para i = 2 até n faça (em C, usamos índices de 1 até n-1)
    for (int i = 1; i < n; i++) {
        // 4. se pi - ultima_parada > C então
        if (p[i] - ultima_parada > C) {
            
            // 5. ultima_parada = pi-1
            ultima_parada = p[i - 1];
            
            // 6. S <- S U (i - 1)
            S[s_idx++] = p[i - 1]; // Armazenando a quilometragem do posto
            
            // Verificação: se o posto anterior ainda estiver longe demais para a autonomia
            if (p[i] - ultima_parada > C) {
                printf("Impossivel completar a viagem! Distancia entre postos maior que a capacidade.\n");
                return;
            }
        }
    }

    // 7. retorne S (Exibindo as paradas)
    if (s_idx == 0) {
        printf("Nao foi necessario abastecer para chegar ao destino.\n");
    } else {
        printf("Paradas necessarias nos postos (km): ");
        for (int j = 0; j < s_idx; j++) {
            printf("%d ", S[j]);
        }
        printf("\nTotal de paradas: %d\n", s_idx);
    }
}

int main() {
    // Exemplo: Postos nos km 0, 200, 375, 550, 750, 950. Tanque para 400km.
    int postos[] = {0, 200, 375, 550, 750, 950};
    int n = sizeof(postos) / sizeof(postos[0]);
    int capacidade = 400;

    printf("Iniciando viagem com autonomia de %d km...\n", capacidade);
    algoritmoCaminhoneiro(postos, n, capacidade);

    return 0;
}