#include <stdio.h>
#include <stdlib.h>

void alocar_pares(int **pares, int *tamanho, int valor) {
    (*tamanho)++;
    *pares = realloc(*pares, (*tamanho) * sizeof(int)); // Realoca espaço para os pares
    if (*pares == NULL) {
        printf("Erro na alocação de memoria\n");
        exit(1);
    }
    (*pares)[(*tamanho) - 1] = valor;
}

float calcular_media(int *pares, int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += pares[i];
    }
    return (float)soma / tamanho;
}

void dividir_grupos(int *pares, int tamanho, float media) {
    printf("Valores maiores que a media:\n");
    for (int i = 0; i < tamanho; i++) {
        if (pares[i] > media) {
            printf("%d ", pares[i]);
        }
    }
    printf("\nValores menores que a media:\n");
    for (int i = 0; i < tamanho; i++) {
        if (pares[i] < media) {
            printf("%d ", pares[i]);
        }
    }
    printf("\n");
}

int main() {
    int *numeros = NULL; // Ponteiro para os números inseridos
    int qtd_numeros = 0, num1, num2;
    char continuar;
    
    do {
        qtd_numeros++;
        numeros = realloc(numeros, qtd_numeros * sizeof(int)); // Realoca memória para novo número
        if (numeros == NULL) {
            printf("Erro na alocaçao de memoria\n");
            exit(1);
        }
        
        printf("Digite um numero: ");
        scanf("%d", &numeros[qtd_numeros - 1]);
        
        printf("Deseja continuar (S/N)? ");
        scanf(" %c", &continuar);
        
    } while (continuar == 'S' || continuar == 's');
    
    // Alocação dinâmica dos resultados pares das subtrações
    int *pares = NULL;
    int qtd_pares = 0;
    
    for (int i = 0; i < qtd_numeros - 1; i += 2) {
        num1 = numeros[i];
        num2 = numeros[i + 1];
        int subtracao = num1 - num2;
        
        if (subtracao % 2 == 0) { // Se o resultado for par
            alocar_pares(&pares, &qtd_pares, subtracao);
        }
    }
    
    // Cálculo da média dos pares
    if (qtd_pares > 0) {
        float media = calcular_media(pares, qtd_pares);
        printf("Media dos valores pares: %.2f\n", media);
        
        // Divisão dos valores em grupos
        dividir_grupos(pares, qtd_pares, media);
    } else {
        printf("Nenhuma subtracao resultou em um numero par.\n");
    }
    
    // Liberar memória alocada
    free(numeros);
    free(pares);
    
    return 0;
}
