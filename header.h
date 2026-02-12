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

void menu();

Produto* excluir(Produto* lista, int valor);

void mostrarLista(Produto* lista);

void exibirMenu();

void leProduto(Produto *prod);

void ConfPerfil(Perfil *p);

int validarmargem(float perc);

void CalcularCPW(Produto *p);

int economia(double valor, double economia, int meses);

void parcelamento(Perfil *p, Produto * prod);

void alocarPerfil(Perfil **p);

void alocarItem(Produto **prod);

int contarItens(Produto *prod);

void removerItem(Produto **prod);

void limparLista(Produto **prod);

#endif
