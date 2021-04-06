#include <stdlib.h>
#include <stdio.h>

#include "contato.h"
#include "arquivos.h"

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
