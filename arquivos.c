#include <stdio.h>
#include <stdlib.h>
#include "contato.h"

void criarContato(struct contato c1) {
	FILE *arquivo = fopen("contatos.txt","a");
	
	if (arquivo != NULL) {
		c1.id = getID();
		int retorno = fprintf(arquivo, "%i %s %i %s\n", c1.id, c1.nome, c1.telefone, c1.email);
		
		
		if (retorno == EOF) {
			printf("Erro na gravação do arquivo.");
		}
		fclose(arquivo);
		
	} else {
		printf("Erro na criação do arquivo.\n");
	}
}


void listarContatos() {
	FILE *arquivo = fopen("contatos.txt","r");
	
    struct contato c1;

    while(!feof(arquivo)){
        fscanf(arquivo,"%i %s %d %s ", &c1.id, &c1.nome, &c1.telefone, &c1.email);
        printf("Nome: %s \nTelefone: %d \nEmail: %s\n\n", c1.nome, c1.telefone, c1.email);
    }
    
    fclose(arquivo);
}


int getID(){
	FILE *arquivo = fopen("contatos.txt","r");
    
    struct contato c1;
    
	if (arquivo != NULL){
		
		while(!feof(arquivo)){
			fscanf(arquivo,"%i %s %d %s ",&c1.id, &c1.nome, &c1.telefone, &c1.email);
		}
		if(feof(arquivo)){
			int id = c1.id+1;
			fclose(arquivo);
			return id;
		}
	}
	else {
		fclose(arquivo);
		return 0;
	}
}
