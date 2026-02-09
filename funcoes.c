#include<stdio.h>
#include<stdlib.h>
#include "header.h"


void ConfPerfil(Perfil *p){
    printf("\nDIGITE SEU NOME: ");
    scanf(" %[^\n]",p->nome);

    printf("\nDIGITE SEU SALÁRIO: ");
    scanf("%lf", &p->salario);

    do{
        printf("\nQUANTOS % DO SEU SALÁRIO É DEDICADO A MIMOS?");
        scanf("%f",&p->margem);
    }while (validarmargem(p->margem)==0);

    printf("\n Perfil de %s configurado com sucesso!\n", p->nome);
}

int validarmargem(float perc){
    if(perc<=0.0){
        printf("QUE ISSO AMIGA! Você precisa de pelo menos 1% para brilhar! Tente novamente\n");
        return 0;
    }

    if(perc>50.00){
        printf("AH NÃO AMIGA, AÍ TAMBÉM NÃO!\n");
        printf("Seu consultor financeiro recomenda abaixar essa margem! Sua econômia vai entrar em colapso!!!!!\n");
        return 0;
    }
    if(perc>20.00){
    printf("OUSADA!!! Mais que isso seria viver no limite\n");
    }
    else{
        printf("MARGEM APROVADA!\n");
    }

    return 1;
}

void CalcularCPW(Produto * p){
    float cpw=0;
    cpw= p->preco/p->durabilidade;
    p->cpw=cpw;
}