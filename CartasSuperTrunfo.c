#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[20];
    char codigo[10];
    char nome[30];
    int populacao;
    double area;
    double pib;
    int pontos_turisticos;
} CartaCidade;

// Função para cadastrar uma carta
void cadastrarCarta(CartaCidade *carta) {
    printf("Insira o estado: ");
    scanf("%s", carta->estado);

    printf("Insira o código da carta: ");
    scanf("%s", carta->codigo);

    printf("Insira o nome da cidade: ");
    scanf("%s", carta->nome);

    printf("Insira a população: ");
    scanf("%d", &carta->populacao);

    printf("Insira a área: ");
    scanf("%lf", &carta->area);

    printf("Insira o PIB: ");
    scanf("%lf", &carta->pib);

    printf("Insira o número de pontos turísticos: ");
    scanf("%d", &carta->pontos_turisticos);
}

// Função para exibir os dados de uma carta
void exibirCarta(CartaCidade carta) {
    printf("\nEstado: %s\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome: %s\n", carta.nome);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f\n", carta.area);
    printf("PIB: %.2f\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontos_turisticos);
}

// Função para comparar duas cartas
void compararCartas(CartaCidade carta1, CartaCidade carta2, char atributo) {
    if (atributo == 'p') {
        if (carta1.populacao > carta2.populacao) {
            printf("\nCarta 1 vence pela população.\n");
        } else if (carta1.populacao < carta2.populacao) {
            printf("\nCarta 2 vence pela população.\n");
        } else {
            printf("\nEmpate pela população.\n");
        }
    } else if (atributo == 'a') {
        if (carta1.area > carta2.area) {
            printf("\nCarta 1 vence pela área.\n");
        } else if (carta1.area < carta2.area) {
            printf("\nCarta 2 vence pela área.\n");
        } else {
            printf("\nEmpate pela área.\n");
        }
    } else if (atributo == 'b') {
        if (carta1.pib > carta2.pib) {
            printf("\nCarta 1 vence pelo PIB.\n");
        } else if (carta1.pib < carta2.pib) {
            printf("\nCarta 2 vence pelo PIB.\n");
        } else {
            printf("\nEmpate pelo PIB.\n");
        }
    } else if (atributo == 'd') {
        double densidade1 = carta1.populacao / carta1.area;
        double densidade2 = carta2.populacao / carta2.area;
        if (densidade1 < densidade2) {
            printf("\nCarta 1 vence pela densidade populacional.\n");
        } else if (densidade1 > densidade2) {
            printf("\nCarta 2 vence pela densidade populacional.\n");
        } else {
            printf("\nEmpate pela densidade populacional.\n");
        }
    }
}

int main() {
    CartaCidade carta1, carta2;
    char atributo;

    printf("Cadastro da Carta 1:\n");
    cadastrarCarta(&carta1);
    exibirCarta(carta1);

    printf("\nCadastro da Carta 2:\n");
    cadastrarCarta(&carta2);
    exibirCarta(carta2);

    printf("\nEscolha um atributo para comparação (p = população, a = área, b = PIB, d = densidade populacional): ");
    scanf(" %c", &atributo);

    compararCartas(carta1, carta2, atributo);

    return 0;
}
