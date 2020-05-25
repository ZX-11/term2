#include "Lab5_list.h"

List *list_New(void) {
    List *l = new(List);
    l->root.next = NULL;
    l->end = &l->root;
    l->len = 0;
    return l;
}

void list_Del(List *l) {
    Element *p = &l->root, *q;
    for (int i = 0; i < l->len; i++) {
        q = p;
        p = p->next;
        free(q);
    }
}

Element *list_Front(List *l) {
    return (l->len == 0) ? NULL : l->root.next;
}

Element *insertvalue(List *l, Type v, Element *at) {
    Element *e = new(Element);
    e->value = v;
    Element *n = at->next;
    at->next = e;
    e->next = n;
    l->len++;
    if (at == l->end) l->end = e;
    return e;
}

Element *list_PushBack(List *l, Type v) {
    return insertvalue(l, v, l->end);
}