#include "libmain.h"

void export_contatos(Contato *head, char *name_file)
{
    FILE *file;
    Contato *atual = head;
    file = fopen(name_file, "w");

    if(!file || !atual)
    {
        puts("Ocorreu um erro na exportação do ficheiro");
        puts("(Talvez contactos vazios)");
        getchar();
        return;
    }

    while (atual)
    {
        fprintf(file, "%s %s %s\n", atual->nome, atual->telefone, atual->email);
        atual = atual->next;
    }
    puts("Contactos exportados com sucesso!");
    getchar();
    fclose(file);
    
}

void import_contactos(Contato **head, char *name_file)
{
    FILE *file;
    char *linha = NULL;
    char *nome = NULL;
    char *email = NULL;
    char *telemovel = NULL;

    file = fopen(name_file, "r");
    if(!file)
    {
        puts("Ocorreu um erro na importação do ficheiro");
        getchar();
        return ;
    }
    remover_todos_contactos(head);
    while(getline(&linha, &(size_t){0}, file) != -1)
    {
        if(sscanf(linha, "%ms %ms %ms\n", &nome, &telemovel, &email) !=3)
            puts("Formato de linha inválido");
        else
            adicionar_contato(head, nome, telemovel, email);
        
        free(nome);
        free(email);
        free(telemovel);
    }
    fclose(file);   
    free(linha);     
}