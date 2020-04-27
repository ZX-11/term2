#ifndef LAB4_FUNC_H
#define LAB4_FUNC_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <io.h>
#include "Lab4_data.h"
#define RandIn(min, max) (rand()%((max)-(min))+(min))
#define make(type,len) (type*)malloc(sizeof(type)*(len))
bool GetNumFrom(char *str);
bool GetNameFrom(char *str);
bool IsValidFileName(char* FileName);
bool SplitPath(char* path);
DATA *GenerateData();
int GenerateFile(int way, DATA *data);
#endif //LAB4_FUNC_H
