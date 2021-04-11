#include <stdlib.h>
#include <stdio.h>

#include "contato.h"
#include "arquivos.h"

void limparTela();
void limparBuffer();
void pausa();

int main() {
	char escolha;
	
	while (1) {
		printf("--- Agenda de contatos ---\n\n");
		printf("1. Listar contatos\n");
		printf("2. Criar contato\n");
		printf("3. Deletar contato\n");
		printf("4. Editar contato\n");
		printf("5. Sair\n\n");
		limparBuffer();
		scanf("%c", &escolha);
		limparTela();
		
		// -- Listar contatos -- //
		if (escolha == '1') {
			listarContatos();

			printf("Pressione Enter para continuar ");
			pausa();
			limparTela();
		}
		
		// -- Criar contato -- //
		else if (escolha == '2') {
			limparTela();
			
			printf("Informe os dados do novo contato:\n");
			struct contato c1;

			printf("Nome: ");
			limparBuffer();
			scanf("%s", &c1.nome);

			printf("Telefone: ");
			limparBuffer();
			scanf("%i", &c1.telefone);
			
			printf("Email: ");
			limparBuffer();
			scanf("%s", &c1.email);
			
			int sucesso = criarContato(c1);
			//sucesso == 1 ? printf("sucesso") : printf("fracasso"); // Validar contato
			
			limparTela();
		}
		
		// -- Deletar contato -- //
		else if (escolha == '3') {
			limparTela();
			
			listarContatos();
			
			int id;
        	printf("\nInforme o ID do contato que quer excluir: \n");
        	scanf("%i",&id);
        	
        	limparTela();
        	
			int sucesso = deletarContato(id);
			//sucesso == 1 ? printf("sucesso") : printf("fracasso"); // Validar deleção
			
			if (sucesso == 1) {
				printf("Contato deletado com sucesso!\n\n");
			}
			else {
				printf("ID incorreto! Nenhum contato foi excluído.\n\n");
			}
			
			printf("Pressione Enter para continuar ");
			pausa();
			limparTela();
		}
		
		// -- Sair -- //
		else if (escolha == '4') {
			listarContatos();
			printf("\nInforme o ID do contato que quer editar: \n");
			int id;
			scanf("%i",&id);
			limparBuffer();
        	limparTela();
        	
			int sucesso = editarContato(id);
			
			if (sucesso == 1) {
				printf("Contato deletado com sucesso!\n\n");
			}
			else {
				printf("ID incorreto! Nenhum contato foi excluído.\n\n");
			}
			
			printf("Pressione Enter para continuar ");
			pausa();
			limparTela();
		}
		else if (escolha == '5') {
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


void pausa() {
	limparBuffer();
	char pausa = getchar();
}
