#ifndef LIST
#define LIST

#include "extdlib.h"
#include "Lab5_data.h"

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
Element *list_PushBack(List *l, Type v);

#endif