#include <stdio.h>
#include<stdlib.h>
#include "header.h"

void menu(){
  int op;
  Perfil p;
  Produto prod;
  
  do{
    
    exibirMenu();
    scanf("%d", &op)
    switch(op){
      case 1:
        alocarPerfil(*p);  
        validarmargem(p->margem);
        break;
    
      case 2:
        alocarItem(*prod);
        break;
       
      case 3:
        parcelamento(p, prod);
        break;
      
      case 4:
        mostrarLista(prod);
        break;

      case 5:
        excluir(prod);  
        break;

      default:
        if(op!=0) printf("COMANDO INVALIDO!\n");
        break;
    }
  }while(op!=0);
  
  limparLista(*prod);
  free(p);
}
