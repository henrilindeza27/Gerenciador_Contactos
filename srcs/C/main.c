#include "libmain.h"

int main()
{
    Contato *list = NULL;

    adicionar_contato(&list,"Isabel Verissimo","932852275", "isabverisimo@gmail.com");
    adicionar_contato(&list,"Seixo Paulo","932145685", "amilcar@gmail.com");
    adicionar_contato(&list,"Henrique Verissimo","932022785", "henrilindeza27@gmail.com");
    adicionar_contato(&list,"Henrique rtrtr","932022785", "henrilinbgfnfhfhhfnhndeza27@gmail.com");

    mostrar_contato(&list);
    remover_contato(&list,"Henrique rtrtr");
    puts("++++++++++++++++++++++++++++++++++++");
    mostrar_contato(&list);
    return 0;



}