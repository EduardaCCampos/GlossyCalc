#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
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
    printf("  ║  1 ➔ CADASTRAR PRODUTO                        ║\n");
    printf("  ║  2 ➔ VIZUALIZAR PERFIL                        ║\n");
    printf("  ║  3 ➔ ANALISAR COMPRA                          ║\n");
    printf("  ║  4 ➔ EXIBIR LISTA DE PRODUTOS                 ║\n");
    printf("  ║  5 ➔ EXCLUIR PRODUTO                          ║\n");
    printf("  ║  0 ➔ SAIR                                     ║\n");
    printf(" ───────────────────────────────────────────────────\n");
    printf("  >> SELECIONE O COMANDO: ");
}

void mostrarLista(Produto* lista) {
    Produto *atual = lista;

    if (atual == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }

    printf("PRODUTOS DA LISTA:\n");
    int indice=1;
    while (atual != NULL) {
        printf("[%d]: %s \tR$%.2lf \tDurabilidade: %d meses\n", indice, atual->nome, atual->preco, atual->durabilidade);
        atual = atual->prox;
        indice++;
    }
    printf("Fim da lista!\n");
}

void ConfPerfil(Perfil *p){
    printf("\nDIGITE SEU NOME: ");
    scanf(" %[^\n]",p->nome);

    printf("DIGITE SEU SALÁRIO: ");
    scanf("%lf", &p->salario);

    do{
        printf("QUAL A %% DO SEU SALÁRIO DEDICADA PARA MIMOS? ");
        scanf("%f",&p->margem);
    }while (validarmargem(p->margem)==0);

    printf("Perfil de %s configurado com sucesso!\n", p->nome);
}

void leProduto(Produto *prod){
    printf("DIGITE O NOME DO PRODUTO: ");
    scanf(" %[^\n]",prod->nome); 
    printf("DIGITE O PRECO: ");
    scanf("%lf", &prod->preco);
    printf("QUANTOS MESES ESSE PRODUTO GERALMENTE DURA COM VOCE? "); //considerando que a durabilidade é em meses
    scanf("%d", &prod->durabilidade);
    CalcularCPW(prod); 
    printf("PRODUTO CADASTRADO COM SUCESSO, AMIGA!\n");
}

int validarmargem(float perc){
    if(perc<=0.0){
        printf("\nQUE ISSO AMIGA! Você precisa de pelo menos 1% para brilhar! Tente novamente\n");
        return 0;
    }

    if(perc>50.00){
        printf("\nAH NÃO AMIGA, AÍ TAMBÉM NÃO!\n");
        printf("Seu consultor financeiro recomenda abaixar essa margem! Sua econômia vai entrar em colapso!\n");
        return 0;
    }
    if(perc>20.00){
    printf("\nOUSADA!!! Mais que isso seria viver no limite\n");
    }
    else{
        printf("MARGEM SALARIAL APROVADA!\n");
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

void alocarPerfil(Perfil **p) {
    if(*p != NULL) {
        printf("Um perfil já foi criado! Não foi possível criar outro!\n");
        return;
    }
    
    Perfil *novo = (Perfil*)malloc(sizeof(Perfil));
    
    if(novo==NULL){
        // captura o erro de alocação de memória!
        printf("Alocação falhou!\n");
        return;
    }
    else{
        ConfPerfil(novo);
        *p = novo;
    }
}

void alocarItem(Produto **prod) {
    Produto *novo = (Produto*)malloc(sizeof(Produto));
    
    if(novo==NULL){
        // captura o erro de alocação de memória!
        printf("Alocação falhou!\n");
        return;
    }
    else{
        getchar();
        leProduto(novo); 
        novo->prox = NULL;
        
        if (*prod == NULL) {
        *prod = novo; 
        }
        else {
            Produto *aux = *prod;
            
            while(aux->prox != NULL) aux = aux->prox;
            aux->prox = novo;
        }
    }
}

int contarItens(Produto *prod) {
    int i=0;
    Produto *aux = prod;
    while(aux!=NULL) {
        i++;
        aux = aux->prox;
    }
    return i;
}

void removerItem(Produto **prod) {
    int i, tam, indice;
    
    mostrarLista(*prod);
    printf("Insira a posição do item que você deseja remover das suas compras: ");
    scanf("%d", &indice);
    printf("\n");
    
    Produto *aux = *prod;
    Produto *remover = NULL;
    tam = contarItens(*prod);
    
    if (*prod == NULL) {
        printf("Lista vazia!\n");
        return;
    }
    
    if (indice<1 || indice>tam) {
        printf("ERRO: O indice %d nao existe! A lista tem %d itens.\n", indice, tam);
        return;
    }
    
    if (indice==1){
        remover = *prod;
        *prod = (*prod)->prox;
    }
    else {
        for(i=1; aux!=NULL && i<indice-1; i++){
            aux = aux->prox;
        }
        remover = aux->prox;
        aux->prox = remover->prox;
    }
    free(remover);
    printf("Item removido da lista!\n");
}

void limparLista(Produto **prod) {
    Produto *aux = *prod;
    Produto *proxProd;

    while (aux != NULL) {
        proxProd = aux->prox; 
        free(aux);
        aux = proxProd;
    }
    
    *prod = NULL;
}

void analisarCompra(Perfil *p, Produto *prod){
    double limite = p->salario *(p->margem/100.00);
    Produto *aux = prod;
    int parcelas, indice, i;
    double valorParcelas;

    printf("\n-------ANÁLISE DE CRÉDITO-------\n");
    mostrarLista(prod);
    printf("Selecione o item que você quer analisar: ");
    scanf("%d", &indice);
    
    for(i=1; i<indice; i++){
        aux = aux->prox;
    }
    
    printf("\nPRODUTO: %s | PREÇO: %.2lf\n", aux->nome, aux->preco);
    printf("SUA VERBA PARA MIMOS: %.2lf\n", limite);

    if(aux->preco<limite){
        printf("COMPRA APROVADÍSSIMA!! ARRASOU GAROTA, NEM AFETOU SEU LIMITE DE %.2lf\n", limite);
    }
    else{
        parcelas = (aux->preco/limite)+1;
        valorParcelas = aux->preco/parcelas;
        int mesesEconomia = 0;
        printf("SUA ANÁLISE FOI CONCLUÍDA!\nEsse valor ultrapassa seu limite, temos duas opções para você:\n(1) Sugerimos parcelar em %d de %.2lf \n", parcelas,valorParcelas);

        mesesEconomia=economia(aux->preco, limite, 0);
        printf("(2) Sugerimos guardar seu limite de %.2lf todo mês durante %d meses e comprar A VISTA!\n", limite, mesesEconomia);

        if(parcelas<=aux->durabilidade){
            printf("E um bônus? Você termina de pagar enquanto ainda usa o produto!\n");
        }
        else{
            ("Compra arriscada!!!! O pagamento dura %d meses mas o produto só dura %d meses.\n REPENSE!\n", parcelas, aux->durabilidade);
        }
    }
}

void mostrarPerfil(Perfil *p){
    if(p==NULL)
    {
        printf("NENHUM PERFIL CADASTRADO!\n");
        return;
    }
    else{
    printf("NOME: %s\n", p->nome);
    printf("SALARIO: %.2lf\n", p->salario);
    printf("PORCENTAGEM DESTINADA AOS MIMOS: %.1f%%\n", p->margem);
    }
    
}
