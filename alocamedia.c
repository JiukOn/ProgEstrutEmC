#include <stdio.h>
#include <stdlib.h>

void* aloca_dinamicamente(int tamanho) {
    return malloc(tamanho);
}

int main() {
    int *numeros = NULL;
    int *menores = NULL;
    int *maiores = NULL;
    int count = 0, menor_count = 0, maior_count = 0;
    float soma = 0.0, media;
    char continuar = 'S';
    int num;

    // Entrada de números
    while (continuar == 'S' || continuar == 's') {
        printf("Digite um numero: ");
        scanf("%d", &num);

        // Realocando espaço para armazenar o novo número
        numeros = (int*)realloc(numeros, (count + 1) * sizeof(int));
        numeros[count] = num;
        soma += num;
        count++;

        printf("Deseja continuar? (S/N): ");
        scanf(" %c", &continuar);
    }

    // Calculando a média
    media = soma / count;
    printf("\nA média é: %.2f\n", media);

    // Alocando espaço e separando os números
    for (int i = 0; i < count; i++) {
        if (numeros[i] < media) {
            menores = (int*)realloc(menores, (menor_count + 1) * sizeof(int));
            menores[menor_count] = numeros[i];
            menor_count++;
        } else if (numeros[i] > media) {
            maiores = (int*)realloc(maiores, (maior_count + 1) * sizeof(int));
            maiores[maior_count] = numeros[i];
            maior_count++;
        }
    }

    // Exibindo números menores que a média
    printf("Números menores que a média:\n");
    for (int i = 0; i < menor_count; i++) {
        printf("%d ", menores[i]);
    }
    printf("\n");

    // Exibindo números maiores que a média
    printf("Números maiores que a média:\n");
    for (int i = 0; i < maior_count; i++) {
        printf("%d ", maiores[i]);
    }
    printf("\n");

    // Liberando memória alocada
    free(numeros);
    free(menores);
    free(maiores);

    return 0;
}
