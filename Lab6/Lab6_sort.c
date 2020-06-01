#include "Lab6_sort.h"

int CompareArray(const void *_a, const void *_b) {
    int **a = (int **)_a;
    int **b = (int **)_b;
    return (*a)[2] - (*b)[2];
}

int CompareData(const void *_a, const void *_b) {
    Data *a = (Data *)_a;
    Data *b = (Data *)_b;
    return (*a).i3 - (*b).i3;
}

int ComparePointer(const void *_a, const void *_b) {
    Data **a = (Data **)_a;
    Data **b = (Data **)_b;
    return (**a).i3 - (**b).i3;
}

int CompareElement(const void *_a, const void *_b) {
    Element **a = (Element **)_a;
    Element **b = (Element **)_b;
    return (**a).value.i3 - (**b).value.i3;
}

void sort_Matrix(int **mat, int num) {
    qsort(mat, num, sizeof(mat[0]), CompareArray);
}

void sort_StructArr(Data *arr, int num) {
    qsort(arr, num, sizeof(arr[0]), CompareData);
}

void sort_PointerArr(Data **arr, int num) {
    qsort(arr, num, sizeof(arr[0]), ComparePointer);
}

void sort_List(List *l) {
    int len = l->len;
    Element **temp = make(Element *, len);
    for (int i = 0; i < len; i++) {
        temp[i] = list_PopFront(l);
    }
    qsort(temp, len, sizeof(temp[0]), CompareElement);
    for (int i = 0; i < len; i++) {
        list_PushBackElement(l, temp[i]);
    }
}