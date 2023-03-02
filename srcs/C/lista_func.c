#include "libmain.h"

Contato	*criar_node_contato(char *nome, char *telefone, char *email)
{
	Contato	*novo_contato;

	novo_contato = NULL;
	novo_contato = (Contato *)malloc(sizeof(Contato));
	if (novo_contato == NULL)
		exit(1);
	novo_contato->nome = (char *)malloc(strlen(nome) + 1);
	if (novo_contato->nome == NULL)
		exit(1);
	strcpy(novo_contato->nome, nome);
	novo_contato->telefone = (char *)malloc(strlen(telefone) + 1);
	if (novo_contato->telefone == NULL)
		exit(1);
	strcpy(novo_contato->telefone, telefone);
	novo_contato->email = (char *)malloc(strlen(email) + 1);
	if (novo_contato->email == NULL)
		exit(1);
	strcpy(novo_contato->email, email);
	novo_contato->next = NULL;
	return (novo_contato);
}

void	adicionar_contato(Contato **head, char *nome, char *telefone,
		char *email)
{
	Contato	*novo_contato;
	Contato	*atual;

	if (verficar_repetido(*head, nome))
	{
		puts("Contacto com o nome repetido!");
		puts("Não foi possível adicionar");
		return ;
	}
	else if (verificar_vazio(nome) || verificar_vazio(email))
	{
		puts("Nome ou email vazio");
		puts("Não foi possível adicionar");
		return ;
	}
	else if (verif_mail(email))
	{
		puts("Email precisa de ser *(@gmail.com)");
		return ;
	}
	else if (verificar_telemovel(telefone))
	{
		puts("Telemovel inválido!");
		puts("Não foi possível adicionar");
		return ;
	}
	novo_contato = criar_node_contato(nome, telefone, email);
	if (*head == NULL)
	{
		*head = novo_contato;
		puts("Contacto adicionado com sucesso!");
	}
	else
	{
		atual = *head;
		while (atual->next != NULL)
			atual = atual->next;
		atual->next = novo_contato;
		puts("Contacto adicionado com sucesso!");
	}
}

int	remover_contato(Contato **head, char *nome)
{
	Contato	*atual;
	Contato	*anterior;

	atual = *head;
	anterior = NULL;
	while (atual != NULL && strcmp(atual->nome, nome) != 0)
	{
		anterior = atual;
		atual = atual->next;
	}
	// Caso o nome não seja encontrado
	if (atual == NULL)
	{
		printf("Contacto (%s) não encontrado\n", nome);
		getchar();
		return (1);
	}
	/*Atualiza a lista para ficar a apontar corretamente após a eliminação do contacto.
      A primeira condição verifica se é o 1º elemento da lista,
	a 2º condição e caso seja
      um elemento que não o 1º
    */
	if (anterior == NULL)
		*head = atual->next;
	else
		anterior->next = atual->next;
	free(atual->nome);
	free(atual->email);
	free(atual->telefone);
	free(atual);
	puts("Contacto removido com sucesso!");
	getchar();
	return (0);
}

int	verficar_repetido(Contato *head, char *nome)
{
	Contato	*atual;

	atual = head;
	while (atual != 0 && strcmp(atual->nome, nome) != 0)
		atual = atual->next;
	if (atual == NULL)
		return (0);
	else
		return (1);
}

void	mostrar_contato(Contato **head)
{
	Contato	*atual;
	int		size;
	int		mE;
	int		mN;

	atual = *head;
	mE = check_maior_email(atual);
	mN = check_maior_nome(atual);
	if (mE >= mN)
		size = mE;
	else
		size = mN;
	while (atual != 0)
	{
		print_lista_contatos(atual->nome, atual->telefone, atual->email, size);
		atual = atual->next;
	}
}
