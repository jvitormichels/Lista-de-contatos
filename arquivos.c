#include <stdio.h>
#include <stdlib.h>
#include "contato.h"

int criarContato(struct contato c1) {
	FILE *arquivo = fopen("contatos.txt","a");
	
	int resultado;
	if (arquivo != NULL) {
		c1.id = getID() + 1;
		int retorno = fprintf(arquivo, "%i %s %i %s\n", c1.id, c1.nome, c1.telefone, c1.email);

		if (retorno == EOF) {
			// Fracasso na grava??o
			resultado = 0;
		}
		else {
			// Sucesso na grava??o
			resultado = 1;
		}
		fclose(arquivo);
		
	} else {
		// Fracasso no acesso ao arquivo
		resultado = 0;
	}
	return resultado;
}


void listarContatos() {
	FILE *arquivo = fopen("contatos.txt","r");
	
	if (arquivo != NULL) {
		struct contato c1;
	    while(!feof(arquivo)){
	        fscanf(arquivo,"%i %s %d %s ", &c1.id, &c1.nome, &c1.telefone, &c1.email);
	        printf("ID: %i \nNome: %s \nTelefone: %d \nEmail: %s\n\n", c1.id, c1.nome, c1.telefone, c1.email);
	    }
	}
	else {
		printf("N?o existem contatos para listar!\n\n");
	}
    
    fclose(arquivo);
}


int deletarContato(int id){
	FILE *arquivo = fopen("contatos.txt","r");
	
    struct contato c1;
    int resultado;
    if (arquivo != NULL) {
    	FILE *arquivo_aux = fopen("contatos_aux.txt","a");
    	rewind(arquivo);
        
        while(!feof(arquivo)){
        	fscanf(arquivo,"%i %s %d %s ",&c1.id, &c1.nome, &c1.telefone, &c1.email);
        	if(c1.id == id){
        		resultado = 1;
         		continue;
			}
			fprintf(arquivo_aux, "%i %s %i %s \n",c1.id, c1.nome, c1.telefone, c1.email);
        }
        
    	fclose(arquivo_aux);
    	fclose(arquivo);
    	remove("contatos.txt");
    	rename("contatos_aux.txt", "contatos.txt");
	}
	else {
		fclose(arquivo);
		resultado = 0;
	}
	
	return resultado;
}


int editarContato(int id){
	FILE *arquivo = fopen("contatos.txt","r");
	
    struct contato c1;
    int resultado;
    if (arquivo != NULL) {
    	FILE *arquivo_aux = fopen("contatos_aux.txt","a");
    	rewind(arquivo);
        
        while(!feof(arquivo)){
        	fscanf(arquivo,"%i %s %d %s ",&c1.id, &c1.nome, &c1.telefone, &c1.email);
        	
        	if(c1.id == id){
        		resultado = 1;
				printf("Qual informação gostaria de editar?\n1. Nome\n2. Telefone\n3. E-mail\n");
				char info;
				scanf("%c", &info);
				fflush(stdin);
				switch (info)
				{
				case '1':
					printf("Insira o nome atualizada!");
					scanf("%s", &c1.nome);
					break;

				case '2':
					printf("Insira o telefone atualizado!");
					scanf("%i", &c1.telefone);
					break;

				case '3':
					printf("Insira o e-mail!");
					scanf("%s", &c1.email);
					break;
				}
			}
			fprintf(arquivo_aux, "%i %s %i %s \n",c1.id, c1.nome, c1.telefone, c1.email);
        }
        
    	fclose(arquivo_aux);
    	fclose(arquivo);
    	remove("contatos.txt");
    	rename("contatos_aux.txt", "contatos.txt");
	}
	else {
		fclose(arquivo);
		resultado = 0;
	}
	
	return resultado;
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
