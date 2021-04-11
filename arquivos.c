#include <stdio.h>
#include <stdlib.h>
#include "contato.h"

void criarContato(struct contato c1) {
	FILE *arquivo = fopen("contatos.txt","a");
	
	if (arquivo != NULL) {
		c1.id = getID() + 1;
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
        printf("ID: %i \nNome: %s \nTelefone: %d \nEmail: %s\n\n", c1.id, c1.nome, c1.telefone, c1.email);
    }
    
    fclose(arquivo);
}


void deletarContato(int id){
	FILE *arquivo = fopen("contatos.txt","r");
	
    struct contato c1;
    
    if (arquivo != NULL) {
    	FILE *arquivo_aux = fopen("contatos_aux.txt","a");
    	rewind(arquivo);
        
        while(!feof(arquivo)){
        	fscanf(arquivo,"%i %s %d %s ",&c1.id, &c1.nome, &c1.telefone, &c1.email);
        	if(c1.id != id){
         		fprintf(arquivo_aux, "%i %s %i %s \n",c1.id, c1.nome, c1.telefone, c1.email);
			}
        }
        
    	fclose(arquivo_aux);
    	fclose(arquivo);
    	remove("contatos.txt");
    	rename("contatos_aux.txt", "contatos.txt");
	}
	else {
		fclose(arquivo);
		printf("------- Agenda de contatos -------\n\n");
		printf("    Nenhum contato Salvo.\n\n\n");
	}
}


int getID() {
	FILE *arquivo = fopen("contatos.txt","r");
    
    struct contato c1;
    
	if (arquivo != NULL) {
		
		while(!feof(arquivo)){
			fscanf(arquivo,"%i %s %d %s ",&c1.id, &c1.nome, &c1.telefone, &c1.email);
		}
		
		if(feof(arquivo)){
			int greatestId = c1.id;
			fclose(arquivo);
			return greatestId;
		}
	}
	else {
		fclose(arquivo);
		return 0;
	}
}
