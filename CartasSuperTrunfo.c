#include <stdio.h>

#define PAIS_ESTADOS 8
#define ESTADOS_CIDADE 4

// Definindo a estrutura Cidade
typedef struct {
    char codigo[20];
    int populacao;
    double area;
    double pib;
    int pontos_turisticos;
} Cidade;

// Função para inserir dados de uma cidade
void supertrunfo(Cidade *cidade) {
    printf("\nInsira o código da cidade (Ex: A01): ");
    scanf("%s", cidade->codigo);

    printf("Insira a população: ");
    scanf("%d", &cidade->populacao);

    printf("Insira a área: ");
    scanf("%lf", &cidade->area);

    printf("Insira o PIB: ");
    scanf("%lf", &cidade->pib);

    printf("Insira o número de pontos turísticos: ");
    scanf("%d", &cidade->pontos_turisticos);
}

// Função para exibir os dados de uma cidade
void exibirCidade(Cidade cidade) {
    printf("Código: %s\n", cidade.codigo);
    printf("População: %d\n", cidade.populacao);
    printf("Área: %.2f\n", cidade.area);
    printf("PIB: %.2f\n", cidade.pib);
    printf("Número de pontos turísticos: %d\n", cidade.pontos_turisticos);
}

int main() {
    Cidade estados[PAIS_ESTADOS][ESTADOS_CIDADE];
    int i, j;

    // Cadastro das cidades
    for (i = 0; i < PAIS_ESTADOS; i++) {
        for (j = 0; j < ESTADOS_CIDADE; j++) {
            printf("\nCadastrando cidade %d do estado %c:\n", j + 1, 'A' + i);
            supertrunfo(&estados[i][j]);
        }
    }

    // Exibição das cidades cadastradas
    printf("\nCidades cadastradas:\n");
    for (i = 0; i < PAIS_ESTADOS; i++) {
        for (j = 0; j < ESTADOS_CIDADE; j++) {
            printf("\nEstado %c, Cidade %d:\n", 'A' + i, j + 1);
            exibirCidade(estados[i][j]);
        }
    }

    return 0;
}
