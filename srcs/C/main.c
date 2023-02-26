#include "libmain.h"

int	main(void)
{
	Contato *list = NULL;
	size_t buffsize = 0;
	int op_menu;
	char *nome = NULL;
	char *email = NULL;
	char *telefone = NULL;

	do
	{
		cleanScrean();
		switch (op_menu = Menu())
		{
		case 1:

			cleanBuffer();

			puts("");
			printf("Nome de contacto: ");
			getline(&nome, &buffsize, stdin);
			nome[strcspn(nome, "\n")] = '\0';
			buffsize = 0;

			printf("Email de contacto: ");
			getline(&email, &buffsize, stdin);
			email[strcspn(email, "\n")] = '\0';
			buffsize = 0;

			printf("Telefone de contacto: ");
			getline(&telefone, &buffsize, stdin);
			telefone[strcspn(telefone, "\n")] = '\0';

			buffsize = 0;
	
			adicionar_contato(&list, nome, telefone, email);
			cleanBuffer();
			free(nome);
			free(email);
			free(telefone);
			break ;

		case 2:
			cleanBuffer();
			buffsize = 0;
			printf("Nome de contacto a remover: ");
			getline(&nome, &buffsize, stdin);
			nome[strcspn(nome, "\n")] = '\0';
			remover_contato(&list, nome);
			free(nome);
			break ;

		case 3:
			break;
		case 4:
			break;
		case 5:
			cleanBuffer();
			cleanScrean();
			puts("CONTACTOS");
			mostrar_contato(&list);
			getchar();
			break ;
		default:
			break ;
		}
		cleanScrean();
	} while (op_menu != 6);

	return (0);
}