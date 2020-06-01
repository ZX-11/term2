#ifndef LIST
#define LIST

#include "extdlib.h"
#include "Lab6_data.h"

#define Type Data

typedef struct Element {
    struct Element *next;
    Type value;
} Element;

typedef struct List {
    struct Element root;
    struct Element *end; 
    int len;
} List;

List *list_New(void);
void list_Del(List *l);
Element *list_Front(List *l);
Element *list_PushBackElement(List *l, Element *e);
Element *list_PushBackValue(List *l, Type v);
Element *list_PopFront(List *l);
#endif