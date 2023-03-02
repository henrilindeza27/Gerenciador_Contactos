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
        fprintf(file, "\nNome: %s\nTelemovel: %s\nEmail: %s\n", atual->nome, atual->telefone, atual->email);
        fprintf(file, "══════════════════════════════════════");
        atual = atual->next;
    }
    puts("Contactos exportados com sucesso!");
    getchar();
    fclose(file);
    
}