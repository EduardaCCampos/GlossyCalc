#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void menu(){
  int op;
  Perfil *p=NULL;
  Produto *prod=NULL;
  
  printf("\n");
    printf(" ██████╗ ██╗      ██████╗ ███████╗███████╗██╗   ██╗\n");
    printf("██╔════╝ ██║     ██╔═══██╗██╔════╝██╔════╝╚██╗ ██╔╝\n");
    printf("██║  ███╗██║     ██║   ██║███████╗███████╗ ╚████╔╝ \n");
    printf("██║   ██║██║     ██║   ██║╚════██║╚════██║  ╚██╔╝  \n");
    printf("╚██████╔╝███████╗╚██████╔╝███████║███████║   ██║   \n");
    printf(" ╚═════╝ ╚══════╝ ╚═════╝ ╚══════╝╚══════╝   ╚═╝   \n\n");
    
    printf("SEJA BEM VINDA!!!\nPRIMEIRO, VAMOS CONFIGURAR O SEU PERFIL!\n");
    alocarPerfil(&p);
  
  do{
    
    exibirMenu();
    scanf("%d", &op);
    switch(op){
      case 1:
        alocarItem(&prod);
        break;
    
      case 2:
        mostrarPerfil(p);
        break;
       
      case 3:
        analisarCompra(p, prod);
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
