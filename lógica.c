#include <stdio.h>
#include <string.h>  // Inclusão da biblioteca para usar strcmp

// Definindo a estrutura Carta
struct Carta {
    char estado[3];               // Estado (2 letras)
    char codigo[10];              // Código da carta
    char nome[50];                // Nome da cidade
    int populacao;                // População
    float area;                   // Área
    float pib;                    // PIB
    int pontos_turisticos;        // Número de pontos turísticos
    float densidade_populacional; // Densidade populacional (calculado)
    float pib_per_capita;         // PIB per capita (calculado)
};

// Função para calcular a densidade populacional
float calcular_densidade_populacional(int populacao, float area) {
    return populacao / area;
}

// Função para calcular o PIB per capita
float calcular_pib_per_capita(float pib, int populacao) {
    return pib / populacao;
}

// Função para comparar dois atributos e determinar o vencedor
void comparar_cartas(struct Carta carta1, struct Carta carta2, const char* atributo) {
    printf("Comparacao de cartas (Atributo: %s):\n", atributo);

    if (strcmp(atributo, "populacao") == 0) {
        printf("Carta 1 - %s (%s): %d\n", carta1.nome, carta1.estado, carta1.populacao);
        printf("Carta 2 - %s (%s): %d\n", carta2.nome, carta2.estado, carta2.populacao);

        if (carta1.populacao > carta2.populacao) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
        } else if (carta1.populacao < carta2.populacao) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (strcmp(atributo, "area") == 0) {
        printf("Carta 1 - %s (%s): %.2f\n", carta1.nome, carta1.estado, carta1.area);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.nome, carta2.estado, carta2.area);

        if (carta1.area > carta2.area) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
        } else if (carta1.area < carta2.area) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (strcmp(atributo, "pib") == 0) {
        printf("Carta 1 - %s (%s): %.2f\n", carta1.nome, carta1.estado, carta1.pib);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.nome, carta2.estado, carta2.pib);

        if (carta1.pib > carta2.pib) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
        } else if (carta1.pib < carta2.pib) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (strcmp(atributo, "densidade_populacional") == 0) {
        printf("Carta 1 - %s (%s): %.2f\n", carta1.nome, carta1.estado, carta1.densidade_populacional);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.nome, carta2.estado, carta2.densidade_populacional);

        if (carta1.densidade_populacional < carta2.densidade_populacional) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
        } else if (carta1.densidade_populacional > carta2.densidade_populacional) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
    else if (strcmp(atributo, "pib_per_capita") == 0) {
        printf("Carta 1 - %s (%s): %.2f\n", carta1.nome, carta1.estado, carta1.pib_per_capita);
        printf("Carta 2 - %s (%s): %.2f\n", carta2.nome, carta2.estado, carta2.pib_per_capita);

        if (carta1.pib_per_capita > carta2.pib_per_capita) {
            printf("Resultado: Carta 1 (%s) venceu!\n", carta1.nome);
        } else if (carta1.pib_per_capita < carta2.pib_per_capita) {
            printf("Resultado: Carta 2 (%s) venceu!\n", carta2.nome);
        } else {
            printf("Resultado: Empate!\n");
        }
    }
}

int main() {
    // Criando as duas cartas com os dados predefinidos
    struct Carta carta1 = {
        "SP", "C001", "Sao Paulo", 12300000, 1521.11, 650000, 100,
        0, 0
    };
    struct Carta carta2 = {
        "RJ", "C002", "Rio de Janeiro", 6000000, 1182.3, 350000, 150,
        0, 0
    };

    // Calculando a densidade populacional e o PIB per capita
    carta1.densidade_populacional = calcular_densidade_populacional(carta1.populacao, carta1.area);
    carta1.pib_per_capita = calcular_pib_per_capita(carta1.pib, carta1.populacao);

    carta2.densidade_populacional = calcular_densidade_populacional(carta2.populacao, carta2.area);
    carta2.pib_per_capita = calcular_pib_per_capita(carta2.pib, carta2.populacao);

    // Escolha do atributo para comparação (aqui estamos comparando "populacao")
    const char* atributo_para_comparar = "populacao";  // Alterar para "area", "pib", "densidade_populacional", ou "pib_per_capita"
    
    // Comparando as cartas
    comparar_cartas(carta1, carta2, atributo_para_comparar);

    return 0;
}
