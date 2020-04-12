#ifndef LAB3_FUNC
#define LAB3_FUNC
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <io.h>
#define RandIn(min, max) (rand()%((max)-(min))+(min))
void GetNum(void);
void GetName(void);
bool GetNumFrom(char *str);
bool GetNameFrom(char *str);
bool IsValidFileName(char* FileName);
bool SplitPath(char* path);
int generate(void);
#endif //LAB3_FUNC
