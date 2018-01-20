
#ifndef _LIST_H_
#define _LIST_H_

#include <stddef.h>

typedef struct list_s *list_t;

struct list_s {
    void *content;
    size_t size;
    struct list_s *head;
    struct list_s *next;
};

list_t list_new(void);
list_t list_append(list_t, void*, size_t);
void list_remove(list_t, list_t);
list_t list_find(list_t, void*, size_t);
list_t list_foreach(list_t, int(*)(list_t*, size_t, void*), void*);
size_t list_length(list_t);
void list_delete(list_t);

#endif //_LIST_H_

