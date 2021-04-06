#include <stdlib.h>
#include <stdio.h>
#include "contato.h"

void criarContato(struct contato c1);
void listarContatos();

void limparTela();
void limparBuffer();


int main() {
	char escolha;
	
	while (1) {
		printf("--- Agenda de contatos ---\n\n");
		printf("1. Listar contatos\n");
		printf("2. Criar contato\n");
		printf("3. Sair\n\n");
		limparBuffer();
		scanf("%c", &escolha);
		limparTela();
		
		if (escolha == '1') {
			listarContatos();
			
			limparBuffer();
			printf("Pressione Enter para continuar ");
			char pause = getchar();
			limparTela();
		}
		else if (escolha == '2') {
			limparTela();
			
			printf("Informe os dados do novo contato:\n");
			struct contato c1;
			
			//char nome[50];
			printf("Nome: ");
			limparBuffer();
			scanf("%s", &c1.nome);
			
			//int telefone;
			printf("Telefone: ");
			limparBuffer();
			scanf("%i", &c1.telefone);
			
			printf("Email: ");
			limparBuffer();
			scanf("%s", &c1.email);
			
			criarContato(c1);
			limparTela();
		}
		else if (escolha == '3') {
			limparTela();
			exit(0);
		}
	}
	
	return 0;
}


void criarContato(struct contato c1) {
	FILE *arquivo = fopen("contatos.txt","a");
	
	if (arquivo != NULL) {
		int retorno = fprintf(arquivo, "%s %i %s\n", c1.nome, c1.telefone, c1.email);
		
		
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
        fscanf(arquivo,"%s %d %s ", &c1.nome, &c1.telefone, &c1.email);
        printf("Nome: %s \nTelefone: %d \nEmail: %s\n\n", c1.nome, c1.telefone, c1.email);
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


void limparBuffer() {
   #ifdef __WIN32__
      fflush(stdin);
   #endif

   #ifdef __linux__
      __fpurge(stdin);
   #endif
}
