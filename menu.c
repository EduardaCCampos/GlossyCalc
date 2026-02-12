#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void menu(){
  int op;
  Perfil *p=NULL;
  Produto *prod=NULL;
  
  do{
    
    exibirMenu();
    scanf("%d", &op);
    switch(op){
      case 1:
        alocarPerfil(&p);  
        break;
    
      case 2:
        alocarItem(&prod);
        break;
       
      case 3:
        parcelamento(p, prod);
        break;
      
      case 4:
        mostrarLista(prod);
        break;

      case 5:
        removerItem(&prod);  
        break;

      default:
        if(op!=0) printf("COMANDO INVALIDO!\n");
        break;
    }
  }while(op!=0);
  
  limparLista(&prod);
  free(p);
}
