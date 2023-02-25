#include "libmain.h"

Contato	*criar_node_contato(char *nome, char *telefone, char *email)
{
	Contato	*novo_contato;

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
		return ;
	novo_contato = criar_node_contato(nome, telefone, email);
	if (*head == NULL)
		*head = novo_contato;
	else
	{
		atual = *head;
		while (atual->next != NULL)
			atual = atual->next;
		atual->next = novo_contato;
	}
}

void	remover_contato(Contato **head, char *nome)
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
		printf("Contato não encontrado: %s\n", nome);
		exit (1);
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

	atual = *head;
	size = check_maior_email(atual);
	while (atual != 0)
	{
		print_lista_contatos(atual->nome, atual->telefone, atual->email, size);
		atual = atual->next;
	}
}

int	check_maior_email(Contato *head)
{
	Contato *atual = head;
	size_t maior = strlen(atual->email);

	while (atual != 0)
	{
		if ((strlen(atual->email)) > maior)
		{
			maior = strlen(atual->email);
		}
		atual = atual->next;
	}

	return (maior);
}