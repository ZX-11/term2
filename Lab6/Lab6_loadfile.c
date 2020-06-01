#include "Lab6_loadfile.h"
#define init() \
    enum ways way = strstr(FileAddr, ".txt") != NULL ? text:bin;\
    FILE *f = fopen(FileAddr, way == text?"r":"rb");\
    check(f != NULL, "ÎÄ¼þ¶ÁÈ¡Ê§°Ü");\
    switch (way) {\
    case text: fscanf(f, "%d", num); break;\
    case bin: fread(num, sizeof(int), 1, f);}

int **loadfile_Matrix(char *FileAddr, /*return*/int *num) {
    init();
    int **mat = make(int *, *num);
    for (int i = 0; i < *num; i++) {
        mat[i] = make(int, 3);
        switch (way) {
        case text: fscanf(f, "%d,%d,%d", &mat[i][0], &mat[i][1], &mat[i][2]); break;
        case bin: fread(mat[i], sizeof(int), 3, f);
        }
    }
    fclose(f);
    return mat;
}

Data *loadfile_StructArr(char *FileAddr, /*return*/int *num) {
    init();
    Data *arr = make(Data, *num);
    for (int i = 0; i < *num; i++) {
        switch (way) {
        case text: fscanf(f, "%d,%d,%d", &arr[i].i1, &arr[i].i2, &arr[i].i3); break;
        case bin: fread(&arr[i], sizeof(Data), 1, f);
        }
    }
    fclose(f);
    return arr;
}

Data **loadfile_PointerArr(char *FileAddr, /*return*/int *num) {
    init();
    Data **arr = make(Data *, *num);
    for (int i = 0; i < *num; i++) {
        arr[i] = new(Data);
        switch (way) {
        case text: fscanf(f, "%d,%d,%d", &arr[i]->i1, &arr[i]->i2, &arr[i]->i3); break;
        case bin: fread(arr[i], sizeof(Data), 1, f);
        }
    }
    fclose(f);
    return arr;
}

List *loadfile_List(char *FileAddr, /*return*/int *num) {
    init();
    List *ls = list_New();
    Data buf;
    for (int i = 0; i < *num; i++) {
        switch (way) {
        case text: fscanf(f, "%d,%d,%d", &buf.i1, &buf.i2, &buf.i3); break;
        case bin: fread(&buf, sizeof(Data), 1, f);
        }
        list_PushBackValue(ls, buf);
    }
    fclose(f);
    return ls;
}