#include <stdlib.h>
#include <stdio.h>
#include "contato.h"

void criarContato(struct contato c1);
void listarContatos();

void limparTela();
void limpar_buffer();

int main() {
	char escolha;
	
	while (1) {
		printf("--- Agenda de contatos ---\n\n");
		printf("1. Listar contatos\n");
		printf("2. Criar contato\n");
		printf("3. Sair\n\n");
		limpar_buffer();
		scanf("%c", &escolha);
		
		if (escolha == '1') {
			//system("cls");
			limparTela();
			listarContatos();
			system("pause");
		}
		else if (escolha == '2') {
			limparTela();
			printf("Informe os dados do novo contato:\n");
			struct contato c1;
			
			//char nome[50];
			printf("Nome: ");
			limpar_buffer();
			scanf("%s", &c1.nome);
			
			//int telefone;
			printf("Telefone: ");
			limpar_buffer();
			scanf("%i", &c1.telefone);
			
			printf("Email: ");
			limpar_buffer();
			scanf("%s", &c1.email);
			
			criarContato(c1);
		}
		else if (escolha == '3') {
			exit(0);
		}
		limparTela();
	}
	
	return 0;
}


void criarContato(struct contato c1) {
	FILE *arquivo = fopen("contatos.txt","a");
	
	if (arquivo != NULL) {
		int retorno = fprintf(arquivo, "%s %i\n", c1.nome, c1.telefone);
		
		
		if (retorno == EOF) {
			printf("Erro na grava��o do arquivo.");
		}
		fclose(arquivo);
		
	} else {
		printf("Erro na cria��o do arquivo.\n");
	}
}


void listarContatos() {
	FILE *arquivo = fopen("contatos.txt","r");
	
    struct contato c1;

    while(!feof(arquivo)){
        fscanf(arquivo,"%s %d ", &c1.nome, &c1.telefone);
        printf("Nome: %s \nTelefone: %d\n\n", c1.nome, c1.telefone);
    }
    
    fclose(arquivo);
}


void limparTela() {
	#ifdef __WIN32__
    	system("cls");
	#endif

	#ifdef __linux__
		system("clear");
	#endif
}


void limpar_buffer() {
   #ifdef __WIN32__
      fflush(stdin);
   #endif

   #ifdef __linux__
      __fpurge(stdin);
   #endif
}
