#include "libmain.h"

void	cleanScrean(void)
{
	system("clear");
}

void	cleanBuffer(void)
{
	while (getchar() != '\n')
		;
}

int	check_maior_email(Contato *head)
{
	Contato	*atual;
	size_t	maior;

	atual = head;
	maior = strlen(atual->email);
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

int	verificar_telemovel(char *telemovel)
{
	int	i;

	i = 0;
	if (strlen(telemovel) == 9)
	{
		while (telemovel[i] >= '0' && telemovel[i] <= '9')
			i++;
		if (i == 9)
			return (0);
	}
	return (1);
}

int	verificar_vazio(char *name)
{
	int	i;

	i = 0;
	if (name[i] == '\0')
		return (1);
	return (0);
}

int	verif_mail(char *email)
{
	char *prefix = "@gmail.com";
	int i = 0;
	int j = 0;

	while (email[i])
	{
		if (email[i] == prefix[0])
		{
			while (email[i + j] == prefix[j] && ((email[i + j]) && (prefix[j])))
				j++;
		}
		i++;
	}
	if ((int)strlen(prefix) == j)
		return (0);
	return (1);
}