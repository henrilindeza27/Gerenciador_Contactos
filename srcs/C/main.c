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
			cleanScrean();
			puts("╔══════════════════════╗");
			puts("║  ADICIONAR CONTACTO  ║");
			puts("╚══════════════════════╝");
			
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
			printf("\n");
			adicionar_contato(&list, nome, telefone, email);
			cleanBuffer();
			break ;

		case 2:
			cleanBuffer();
			buffsize = 0;
			cleanScrean();
			puts("Contactos guardados:");
			if(!list)
			{	puts("Nenhum contacto a remover");
				getchar();
			}
			else
			{	print_nome_contactos(list);
				printf("\nNome de contacto a remover: ");
				getline(&nome, &buffsize, stdin);
				nome[strcspn(nome, "\n")] = '\0';
				printf("\n");
				remover_contato(&list, nome);
			}
			break ;

		case 3:
			printf("\n");
			export_contatos(list,"contactos.txt");
			getchar();
			break;
		case 4:
			printf("\n");
			import_contactos(&list, "contactos.txt");
			getchar();
			break;
		case 5:
			cleanBuffer();
			cleanScrean();
			puts("CONTACTOS");
			if(list == NULL)
				puts("Sem contactos");
			else
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