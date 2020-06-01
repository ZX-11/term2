#include "Lab6_call.h"
extern CONF conf;
extern int mode;

char *call_Generate(int way) {
    char num[256], cmd[2048], *FileAddr = make(char, 2048);
    switch (mode) {
    case automatic:
        strcpy(FileAddr, conf.FileSavePath);
        strcat(FileAddr, conf.FileName);
        sprintf(cmd, "Lab4 - - %s", way == text ? "t" : "d");
        check(system(cmd) == 0, "文件生成失败");
        break;
    case interactive:
        printf("请输入生成数量：");
        gets_s(num, 256);
        printf("请输入文件保存位置：");
        gets_s(FileAddr, 2048);
        sprintf(cmd, "Lab4 %s %s %s", num, FileAddr, way == text ? "t" : "d");
        check(system(cmd) == 0, "文件生成失败");
    }
    switch (way) {
    case text:
        if (strstr(FileAddr, ".txt") == NULL) {
            strcpy(strstr(FileAddr, "."), ".txt");
        }
        break;
    case bin:
        if (strstr(FileAddr, ".dat") == NULL) {
            strcpy(strstr(FileAddr, "."), ".dat");
        }
    }
    return FileAddr;
}