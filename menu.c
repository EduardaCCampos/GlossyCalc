#include <stdio.h>
#include<stdlib.h>
#include "header.h"

void menu(){
  int op;
  Perfil p;
  Produto prod
  do{
   Perfil *p=(Perfil*)malloc(sizeof(Perfil));
   Produto prod= (Produto*)malloc(sizeof(Produto));
    exibirMenu();
    scanf("%d", &op)
    switch(op){
      case 1:
        ConfPerfil(p);
        validarmargem(p->margem);
        break;
      case 2:
        le_produto(prod);
        break;
       
      case 3:
        parcelamento(p, prod);
        break;
      case 4:
        mostrarLista(prod);
        break;

      case 5:
        excluir(prod, indice); // PEGAR FUNÇÃO DE INDICE DA SARAH 
        break;

      default:
        if(op!=0) printf("COMANDO INVALIDO!\n");
        break;
    
    }
  }while(op!=0);
  free(p);
  free(prod)


}
