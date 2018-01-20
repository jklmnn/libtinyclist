
#include <stdlib.h>
#include <string.h>

#include "list.h"

list_t list_new(void)
{
    list_t l = malloc(sizeof(struct list_s));
    l->next = 0;
    l->content = malloc(0);
    l->size = 0;
    l->head = l;
    return l;
}

list_t list_append(list_t l, void* c, size_t s)
{
    if(!(l && c))
        return 0;

    list_t head = l->head;
    
    while(l->next)
        l = l->next;
    l->next = malloc(sizeof(struct list_s));
    l = l->next;
    
    l->next = 0;
    l->head = head;
    l->size = s;
    l->content = malloc(s);
    memcpy(l->content, c, s);
    
    return l;
}

void list_remove(list_t l, list_t e)
{
    if(!(l && e))
        return;

    while(l->next){
        if(e == l->next){
            
            l->next = l->next->next;
            
            free(e->content);
            free(e);

            if(!l->next)
                return;
        }
        l = l->next;
    }
}

list_t list_find(list_t l, void* c, size_t s)
{
    if(!(l && c))
        return 0;

    while(l->next){
        if(l->next->size >= s && !memcmp(l->next->content, c, s))
            return l->next;
        l = l->next;
    }

    return 0;
}

list_t list_foreach(list_t l, int(*func)(list_t*, size_t, void*), void *arg)
{
    if(!(l && func))
        return 0;

    while(l->next){
        if(func(&(l->next), l->size, arg))
            return l->next;
        l = l->next;
    }

    return 0;
}

size_t list_length(list_t l)
{
    size_t len = 0;
    if(!l)
        return 0;

    while(l->next){
        ++len;
        l = l->next;
    }
    return len;
}

void list_delete(list_t list)
{
    if(list){
        list_delete(list->next);
        free(list->content);
        free(list);
    }
}
