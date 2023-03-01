#include "libmain.h"

int	Menu(void)
{
	int	op;

	printf("╔════════════════════════════════╗\n");
	printf("╠════════════  MENU  ════════════╣\n");
	printf("║- [1] Adicionar contacto        ║\n");
	printf("║- [2] Eliminar contacto         ║\n");
	printf("║- [3] Exportar contactos        ║\n");
	printf("║- [4] Importar contactos        ║\n");
	printf("║- [5] Ver contactos             ║\n");
	printf("║- [6] Sair                      ║\n");
	printf("╚════════════════════════════════╝\n");
	printf(" Selecione a opção que deseja --> ");
	while (scanf("%d", &op) != 1 || !(op >= 1 && op <= 6))
	{
		printf("Opção inválida, por favor digite uma opção válida -> ");
		//Seguintes scanf servem para limpar o buffer e descartar entradas inválidas
		scanf("%*[^\n]");
		scanf("%*c");
	}
	return (op);
}

void	print_lista_contatos(char *nome, char *telefone, char *email, int size)
{
	int sizemax = size + 16;
	int sizemaxcpy = sizemax;

	//Printar a 1º linha
	printf("╔");
	while(sizemaxcpy--)
		printf("═");
	printf("╗\n");

	//Printar o nome sem desconfigurar o "menu"
	sizemaxcpy = sizemax - (strlen(nome)+8);
	printf("║- Nome: %s", nome);
	while(sizemaxcpy--)
		printf(" ");
	printf("║\n");

	//Printar o email sem desconfigurar o "menu"
	sizemaxcpy = sizemax - (strlen(email)+9);
	printf("║- Email: %s", email);
	while(sizemaxcpy--)
		printf(" ");
	printf("║\n");

	//Printar o email sem desconfigurar o "menu"
	sizemaxcpy = sizemax - 26;
	printf("║- Telefone: +351 %s", telefone);
	while(sizemaxcpy--)
		printf(" ");
	printf("║\n");


	//Printar última linha
	sizemaxcpy = sizemax;
	printf("╚");
	while(sizemaxcpy--)
		printf("═");
	printf("╝\n");

}