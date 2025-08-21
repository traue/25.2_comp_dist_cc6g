#include <stdio.h>

int main() {

    int nAlunos;
    
    float media;

    printf("\nQts alunos: ");
    scanf("%d", &nAlunos);
    int idades[nAlunos];
    
    float soma = 0;
    printf("\n\nQtd de alunos a ler: %d", nAlunos);

    for (int i = 0; i < nAlunos; i++) {
        printf("\nInforme a idade do %dº aluno: ", (i + 1));
        scanf("%d", &idades[i]);
        soma += idades[i];
    }

    media = soma / nAlunos;

    printf("\n\nIdades lidas: ");

    for (int i = 0; i < nAlunos; i++) {
        printf("%d, ", idades[i]);
    }

    printf("\nMédia das idades: %f", media);

    return 0;
}