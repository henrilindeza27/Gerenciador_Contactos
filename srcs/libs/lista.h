#ifndef LISTA_H
# define LISTA_H

typedef struct contato Contato;

struct contato
{
	char	*nome;
	char	*telefone;
	char	*email;
	Contato	*next;

};

Contato		*criar_node_contato(char *nome, char *telefone, char *email);
void		adicionar_contato(Contato **head, char *nome, char *telefone, char *email);
void		remover_contato(Contato **head, char *nome);
int			verficar_repetido(Contato *head, char *nome);
int			check_maior_email(Contato *head);

void	mostrar_contato(Contato **head);

#endif