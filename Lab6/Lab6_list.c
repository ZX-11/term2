#include "Lab6_list.h"

List *list_New() {
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

Element *insert(List *l, Element *e, Element *at) {
    Element *n = at->next;
    at->next = e;
    e->next = n;
    l->len++;
    if (at == l->end) l->end = e;
    return e;
}

Element *insertvalue(List *l, Type v, Element *at) {
    Element *e = new(Element);
    e->value = v;
    return insert(l, e, at);
}

Element *list_PushBackElement(List *l, Element *e) {
    return insert(l, e, l->end);
}

Element *list_PushBackValue(List *l, Type v) {
    return insertvalue(l, v, l->end);
}

Element *list_PopFront(List *l) {
    if (l->len > 0) {
        Element *e = l->root.next;
        l->root.next = e->next;
        e->next = NULL;
        l->len--;
        if (l->len == 0) l->end = &l->root;
        return e;
    }
    return NULL;
}