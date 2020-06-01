#include "Lab6_view.h"

void view_Matrix(int **mat, int num) {
    for (int i = 0; i < num; i++) {
        printf("%d,%d,%d\n", mat[i][0], mat[i][1], mat[i][2]);
    }
}

void view_StructArr(Data *arr, int num) {
    for (int i = 0; i < num; i++) {
        printf("%d,%d,%d\n", arr[i].i1, arr[i].i2, arr[i].i3);
    }
}

void view_PointerArr(Data **arr, int num) {
    for (int i = 0; i < num; i++) {
        printf("%d,%d,%d\n", arr[i]->i1, arr[i]->i2, arr[i]->i3);
    }
}

void view_List(List *ls) {
    for (Element *e = list_Front(ls); e != NULL; e = e->next) {
        printf("%d,%d,%d\n", e->value.i1, e->value.i2, e->value.i3);
    }
}