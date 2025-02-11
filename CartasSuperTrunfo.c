


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definindo a estrutura de uma carta
typedef struct {
    char cidade[50];
    char pessoa[50];
    float pib_per_capita;
} Carta;

// Função para exibir uma carta
void exibirCarta(Carta carta) {
    printf("Cidade: %s\n", carta.cidade);
    printf("Pessoa: %s\n", carta.pessoa);
    printf("PIB per capita: %.2f\n", carta.pib_per_capita);
}

// Função para comparar as cartas com base na categoria escolhida
int compararCartas(Carta carta1, Carta carta2, int categoria) {
    switch(categoria) {
        case 1: // Comparar pelo nome da cidade (ordem alfabética)
            return strcmp(carta1.cidade, carta2.cidade);
        case 2: // Comparar pela pessoa (ordem alfabética)
            return strcmp(carta1.pessoa, carta2.pessoa);
        case 3: // Comparar pelo PIB per capita
            if (carta1.pib_per_capita > carta2.pib_per_capita) {
                return 1;  // carta1 ganha
            } else if (carta1.pib_per_capita < carta2.pib_per_capita) {
                return -1; // carta2 ganha
            } else {
                return 0;  // empate
            }
        default:
            printf("Categoria inválida!\n");
            return 0;
    }
}

int main() {
    // Criando algumas cartas de exemplo
    Carta cartas[] = {
        {"São Paulo", "Paulo Coelho", 14600.50},
        {"Rio de Janeiro", "Ayrton Senna", 12000.20},
        {"Brasília", "Oscar Niemeyer", 24000.10},
        {"Salvador", "Dorival Caymmi", 13500.30},
        {"Fortaleza", "Ceará", 15000.00}
    };

    int totalCartas = sizeof(cartas) / sizeof(cartas[0]);
    int jogador1Cartas = totalCartas, jogador2Cartas = totalCartas;
    int escolhaCategoria, resultado;

    printf("Bem-vindo ao Super Trunfo - Versão C!\n");
    printf("O jogo terá categorias: 1 - Cidade, 2 - Pessoa, 3 - PIB per capita.\n");

    // Jogo
    while (jogador1Cartas > 0 && jogador2Cartas > 0) {
        printf("\nJogador 1 - Sua carta:\n");
        exibirCarta(cartas[rand() % jogador1Cartas]); // Exibe uma carta aleatória
        printf("\nJogador 2 - Sua carta:\n");
        exibirCarta(cartas[rand() % jogador2Cartas]); // Exibe uma carta aleatória

        // Jogador escolhe a categoria para comparar
        printf("\nEscolha a categoria para comparação (1 - Cidade, 2 - Pessoa, 3 - PIB per capita): ");
        scanf("%d", &escolhaCategoria);

        // Comparando as cartas com base na categoria
        resultado = compararCartas(cartas[rand() % jogador1Cartas], cartas[rand() % jogador2Cartas], escolhaCategoria);

        if (resultado > 0) {
            printf("\nJogador 1 ganhou a rodada!\n");
            jogador2Cartas--;  // Remove uma carta do jogador 2
        } else if (resultado < 0) {
            printf("\nJogador 2 ganhou a rodada!\n");
            jogador1Cartas--;  // Remove uma carta do jogador 1
        } else {
            printf("\nEmpate! Ninguém ganhou essa rodada.\n");
        }

        // Verificar quem ganhou
        if (jogador1Cartas == 0) {
            printf("\nJogador 2 venceu o jogo!\n");
            break;
        } else if (jogador2Cartas == 0) {
            printf("\nJogador 1 venceu o jogo!\n");
            break;
        }
    }

    return 0;
}




