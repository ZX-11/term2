#ifndef LAB6_CONF
#define LAB6_CONF
#include "Lab6_data.h"
#include "extdlib.h"
#include <string.h>
#define resetmenu "\
1. 文件存储目录：　　　　　%s\n\
2. 文件名称：　　　　　　　%s\n\
3. 第一、二个元素最大值：　%d\n\
4. 第一、二个元素最小值：　%d\n\
5. 第三个元素最大值：　　　%d\n\
6. 第三个元素最小值：　　　%d\n\
7. 记录条数最大值：　　　　%d\n\
8. 记录条数最小值：　　　　%d\n\
9. 工作模式：　　　　　　　%s\n\
0. 确认并写入更改\n\
请选择修改的项目："

void conf_Reset(void);
#endif