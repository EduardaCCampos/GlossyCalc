#ifndef HEADER_H
#define HEADER_H

typedef struct Produto{
    char nome [128];
    double preco;
    int durabilidade;
    double cpw;
    struct Produto * prox;
    
} Produto;

typedef struct 
{
    char nome [128];
    double salario;
    float margem;
}Perfil;

void ConfPerfil(Perfil *p);

int validarmargem(float perc);

void CalcularCPW(Produto * p);

void parcelamento(Perfil p, Produto * prod);

int economia(double valor, double economia, int meses);

#endif