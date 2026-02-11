#include<stdio.h>
#include <locale.h>
#include<stdlib.h>
#include "header.h"

void exibirMenu() {
    printf("\n");
    printf(" ██████╗ ██╗      ██████╗ ███████╗███████╗██╗   ██╗\n");
    printf("██╔════╝ ██║     ██╔═══██╗██╔════╝██╔════╝╚██╗ ██╔╝\n");
    printf("██║  ███╗██║     ██║   ██║███████╗███████╗ ╚████╔╝ \n");
    printf("██║   ██║██║     ██║   ██║╚════██║╚════██║  ╚██╔╝  \n");
    printf("╚██████╔╝███████╗╚██████╔╝███████║███████║   ██║   \n");
    printf(" ╚═════╝ ╚══════╝ ╚═════╝ ╚══════╝╚══════╝   ╚═╝   \n\n");
    
    printf("           [ M E N U   P R I N C I P A L ]\n");
    printf(" ───────────────────────────────────────────────────\n");
    printf("  ║  1 ➔ CADASTRAR PERFIL                         ║\n");
    printf("  ║  2 ➔ CADASTRAR PRODUTO                        ║\n");
    printf("  ║  3 ➔ ANALISAR COMPRA                          ║\n");
    printf("  ║  4 ➔ EXIBIR LISTA DE PRODUTOS                 ║\n");
    printf("  ║  5 ➔ EXCLUIR PRODUTO                          ║\n");
    printf("  ║  0 ➔ SAIR                                     ║\n");
    printf(" ───────────────────────────────────────────────────\n");
    printf("  >> SELECIONE O COMANDO: ");
}

Produto* excluir(Produto* lista) {
    Produto *atual = lista;
    Produto *anterior = NULL;
    int indice=1;
    int valor;

    mostrarLista(prod);

    printf("QUAL O INDICE DO PRODUTO QUE DESEJA EXCLUIR?");
    scanf("%d", &valor); 
    while (atual != NULL && indice != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) {
        return lista;
    }

    if (anterior == NULL) {
        lista = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    free(atual);

    return lista;
}

void mostrarLista(Produto* lista) {
    Produto *atual = lista;

    if (atual == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }

    printf("PRODUTOS DA LISTA:\n");
    while (atual != NULL) {
        int indice=1;
        printf("[%d]: %s\tR$%.2lf\tDurabilidade: %d\n", indice, atual->nome, atual->preco, atual->durabilidade);
        atual = atual->proximo;
        indice++;
    }
    printf("NULL\n");
}

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
void le_produto(Produto *prod){
    printf("DIGITE O NOME DO PRODUTO: ");
    scanf("%[^\n]",prod->nome); 
    printf("\nDIGITE O PRECO: ");
    scanf("%lf", &prod->preco);
    printf("\nQUANTO TEMPO ESSE PRODUTO GERALMENTE DURA COM VOCE?"); //considerando que a durabilidade é em dias
    scanf("%d", &prod->durabilidade);
    CalcularCPW(prod); // corrigir no gemini
    printf("\nPRODUTO CADASTRADO COM SUCESSO, AMIGA!\n");
    
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

int economia(double valor, double economias, int tempo){ //DUDA EXPLICA PA NOIS
    if(valor<=0){
        return tempo;
    }
    else{
        return(economia(valor-economias, economias, ++tempo));
    }
}

void parcelamento(Perfil p, Produto * prod){
    double limite =p.salario *(p.margem/100.00);
    int parcelas;
    double valorParcelas;

    printf("\n-------ANÁLISE DE CRÉDITO-------\n");
    printf("PRODUTO: %s | PREÇO: %.2lf\n", prod->nome,prod->preco);
    printf("SUA VERBA PARA MIMOS: %.2lf\n", limite);

    if(prod->preco<limite){
        printf("COMPRA APROVADÍSSIMA!! ARRASOU GAROTA, NEM AFETOU SEU LIMITE DE %.2lf\n", limite);
    }
    else{
        parcelas=(prod->preco/limite)+1;
        valorParcelas=prod->preco/parcelas;
        int mesesEconomia=0;
        printf("SUA ANÁLISE FOI CONCLUÍDA!\n Esse valor ultrapassa seu limite, Temos duas opções para você: \n (1) Sugerimos parcelar em %d de %.2lf \n", parcelas,valorParcelas);

        mesesEconomia=economia(prod->preco, limite, 0);
        printf("(2) Sugerimos guardar seu limite de %.2lf todo mês durante %d meses e comprar A VISTA!\n", limite, mesesEconomia);

        if(parcelas<=prod->durabilidade){
            printf("E um bônus? Você termina de pagar enquanto ainda usa o produto\n");
        }else{
            ("Compra arriscada!!!! O pagamento dura %d meses mas o produto só dura %d meses.\n REPENSE!\n", parcelas, prod->durabilidade);
        }
    }
}
