#ifndef LAB6_LOADFILE
#define LAB6_LOADFILE
#include <string.h>
#include "extdlib.h"
#include "Lab6_list.h"
int **loadfile_Matrix(char *FileName, int *num);
Data *loadfile_StructArr(char *FileName, int *num);
Data **loadfile_PointerArr(char *FileName, int *num);
List *loadfile_List(char *FileName, int *num);
#endif