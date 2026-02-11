#ifndef HEADER_H
#define HEADER_H

typedef struct Produto{
    char nome [128];
    double preco;
    int durabilidade;
    double cpw;
    struct Produto * prox;   
} Produto;

typedef struct {
    char nome [128];
    double salario;
    float margem;
} Perfil;

void exibirMenu();

void le_produto(Produto *prod);

void ConfPerfil(Perfil *p);

int validarmargem(float perc);

void CalcularCPW(Produto * p);

int economia(double valor, double economia, int meses);

void parcelamento(Perfil p, Produto * prod);


#endif
