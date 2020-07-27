#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void calculaMedia();
void verificaEquivalencia();

int main() {
    int op;
    do {
    printf("Escolha qual função será chamada:\n1: converte de º para radiano\n2: calcular valor médio\n3: verificar equivalencia\n0: quit\n");
    scanf("%d", &op);
    
    switch(op) {
        case 1:
            printf("Digite o valor do angulo em pi\n");
            float pi;
            scanf("%f", &pi);
            printf("Seu valor em radianos é %.8f\n", pi*0.01745329252);
            printf("-----------------------------------\nDigite algum número para reiniciar\n");
            scanf("%f", &pi);
            break;
        case 2:
            calculaMedia();
            break;
        case 3:
            verificaEquivalencia();
            break;
    }
    
    } while(op != 0);

    return 0;
}

void calculaMedia() {
    int N;
    printf("Digite o numero de medidas\n");
    scanf("%d", &N);

    float *vetor = (float *) malloc(N * sizeof(float));
  
    // Lê os N valores
    for (int i = 0; i < N; i++) {
        printf("Digite o valor para a posicao %d do vetor\n", i+1);
        scanf("%f",&vetor[i]);
    }

    // Cálculo do valor médio
    float soma = 0;
    for(int i = 0; i < N; i++)
        soma+= vetor[i];
    float vMedio = soma/N;
    printf("Valor médio : %.8f\n", vMedio);

    // Cálculo do desvio médio
    float somaMedio = 0;
    for(int i = 0; i < N; i++) {
        float abs = vetor[i]-vMedio;
        if(abs < 0)
            abs*=-1;
        somaMedio+=abs;
    }
    printf("Desvio medio : %.8f (não recomendado)\n", somaMedio/N);
    
    // Cálculo do desvio padrão
    float somaPadrao = 0;
    for(int i = 0; i < N; i++) {
        float quadrado = vetor[i] - vMedio;
        somaPadrao+=quadrado*quadrado;
    }
    double raiz = somaPadrao/(N-1);
    printf("Sqrt = %lf\n", sqrt(raiz));
    printf("Desvio padrão : sqrt(%.8f)\n", somaPadrao/(N-1));

    int pi;
    printf("-----------------------------------\nDigite algum número para reiniciar\n");
    scanf("%d", &pi);
    free(vetor);
}

void verificaEquivalencia() {
    float A, eA, B, eB;
    printf("Digite o primeiro elemento e seu erro\n");
    scanf("%f %f", &A, &eA);

    printf("Digite o segundo elemento e seu erro\n");
    scanf("%f %f", &B, &eB);

    float diferenca = A - B;
    if(diferenca < 0)
        diferenca*=-1;
    
    if(diferenca < 2*(eA+eB))
        printf("Resultados equivalentes entre si\n");
    
    else if(diferenca > 3*(eA+eB))
        printf("Resultados não-equivalentes\n");
    else
        printf("Nada a concluir\n");
    
    int pi;
    printf("-----------------------------------\nDigite algum número para reiniciar\n");
    scanf("%d", &pi);
}