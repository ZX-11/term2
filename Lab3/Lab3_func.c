#include "Lab3_data.h"
#include "Lab3_func.h"

extern CONF conf;
//从字符串中获取数量并存储于conf.num
bool GetNumFrom(char *str) {
    if (strcmp(str, "r") == 0) {
        conf.num = RandIn(conf.MinRecordNum, conf.MaxRecordNum);
        return true;
    }
    char *p;
    int t = strtol(str, &p, 10);
    if (t > 0 && *p == '\0') {
        conf.num = t;
        return true;
    }
    return false;
}
//提示用户输入数量并获取
void GetNum(void) {
    char buf[128];
    while (true) {
        printf("请输入记录条数：");
        gets(buf);
        if (GetNumFrom(buf)) return;
        puts("错误：记录条数输入错误，请重新输入");
    }
}
//从字符串中获取文件名称并存储于conf.FileName或分离地址并分别存储于conf.FileSavePath和conf.FileName
bool GetNameFrom(char *str) {
    if (IsValidFileName(str)) {
        strcpy(conf.FileName, str);
        return true;
    }
    if (SplitPath(str)) {
        return true;
    }
    return false;
}
//提示用户输入存储地址并获取
void GetName(void) {
    char buf[1024];
    while (true) {
        printf("请输入文件存储名或完整路径：");
        gets(buf);
        if (GetNameFrom(buf)) return;
        puts("错误：文件名或文件目录有误，请重新输入");
    }
}
//判断str中是否包含accept中的任何字符
bool ContainsAny(char *str, char *accept) {
    for (char *p = str; *p; p++) {
        for (char *q = accept; *q; q++) {
            if (*p == *q) return true;
        }
    }
    return false;
}
//判断文件名是否合法
bool IsValidFileName(char *FileName) {
    return (!ContainsAny(FileName, "/:*?\\<>|") && (strstr(FileName, ".txt") != NULL || strstr(FileName, ".dat") != NULL));
}
//分离地址中的路径和文件名，分别存储于conf.FileSavePath和conf.FileName
bool SplitPath(char *path) {
    //使用splitpath将地址分为盘符、路径、文件名、拓展名四部分
    char drive[1024], dir[1024], FileName[256], ext[8];
    _splitpath(path, drive, dir, FileName, ext);
    //将拓展名连接到文件名
    strcat(FileName, ext);
    //判断路径和文件名的合法性
    if (!ContainsAny(dir, ":*?<>|") && IsValidFileName(FileName)) {
        strcpy(conf.FileName, FileName);
        strcpy(conf.FileSavePath, strcat(drive, dir));
        return true;
    }
    return false;
}
//生成随机数文件
int generate(void) {
    //判断目录是否存在，不存在则创建目录
    if (access(conf.FileSavePath, 0) != 0 && mkdir(conf.FileSavePath) != 0) {
        fprintf(stderr, "错误：文件目录创建失败\n");
        exit(1);
    }
    //拼装文件路径
    strcat(conf.FileSavePath, conf.FileName);
    //创建文件
    FILE *f = fopen(conf.FileSavePath, "w");
    if (f == NULL) {
        fprintf(stderr, "错误：文件创建失败\n");
        exit(1);
    }
    //生成随机值并写入文件
    fprintf(f, "%d\n", conf.num);
    for (int i = 0; i < conf.num; i++) {
        int e1 = RandIn(conf.MinValue12, conf.MaxValue12), e2;
        do {
            e2 = RandIn(conf.MinValue12, conf.MaxValue12);
        } while (e1 == e2);
        int e3 = RandIn(conf.MinValue3, conf.MaxValue3);
        fprintf(f, "%d,%d,%d\n", e1, e2, e3);
    }
    fclose(f);
    puts("文件生成成功");
    return 0;
}