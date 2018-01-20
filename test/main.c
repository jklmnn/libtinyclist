#include <stdio.h>
#include <list.h>

int print(list_t *content, unsigned __attribute__((unused))size, void *delim){
    printf("%c%d", *(char*)delim, *(int*)((*content)->content));
    return 0;
}

int main(void)
{
    int x = 0, y = 1, z = 2;
    char delim = ' ';

    printf("init list\n");
    const list_t list = list_new();

    printf("append x\n");
    list_append(list, &x, sizeof(int));

    printf("append y\n");
    list_append(list, &y, sizeof(int));

    printf("append z\n");
    list_append(list, &z, sizeof(int));
    
    printf("print content ...");
    list_foreach(list->head, &print, (void*)&delim);
    printf("\n");

    printf("list of size %u\n", list_length(list));

    printf("delete y\n");
    list_t y_ptr= list_find(list, &y, sizeof(int));
    list_remove(list, y_ptr);

    printf("print resulting values ...");
    list_foreach(list->head, &print, (void*)&delim);
    printf("\n");
    
    printf("list of size %u\n", list_length(list));
    
    printf("delete list\n");
    list_delete(list);

    return 0;
}
