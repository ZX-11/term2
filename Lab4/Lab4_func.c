#include "Lab4_data.h"
#include "Lab4_func.h"
extern CONF conf;

//函数功能：从字符串中获取数量并存储于conf.num
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
//判断str中是否包含accept中的任何字符
bool ContainsAny(char *str, char *accept) {
    for (char *p = str; *p ; p++) {
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
//生成数据
DATA *GenerateData(void) {
    DATA *data = make(DATA, conf.num);
    if (data == NULL) {
        fprintf(stderr, "错误：内存不足\n");
        exit(1);
    }
    for (int i = 0; i < conf.num; i++) {
        data[i].i1 = RandIn(conf.MinValue12, conf.MaxValue12);
        do {
            data[i].i2 = RandIn(conf.MinValue12, conf.MaxValue12);
        } while (data[i].i1 == data[i].i2);
        data[i].i3 = RandIn(conf.MinValue3, conf.MaxValue3);
    }
    return data;
}
//生成数据文件
int GenerateFile(int way, DATA *data) {
    //判断目录是否存在，不存在则创建目录
    if (access(conf.FileSavePath, 0) != 0 && mkdir(conf.FileSavePath) != 0) {
        fprintf(stderr, "错误：文件目录创建失败\n");
        exit(1);
    }
    //拼接文件名
    char FileAddr[1024];
    strcpy(FileAddr, conf.FileSavePath);
    strcat(FileAddr, conf.FileName);
    //处理拓展名
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
    //开始计时
    clock_t start = clock();
    //创建文件
    FILE *f = fopen(FileAddr, way == text ? "w" : "wb");
    if (f == NULL) {
        fprintf(stderr, "错误：文件创建失败\n");
        exit(1);
    }
    //分情况写入文件
    switch (way) {
    case text:
        fprintf(f, "%d\n", conf.num);
        for (int i = 0; i < conf.num; i++) {
            fprintf(f, "%d,%d,%d\n", data[i].i1, data[i].i2, data[i].i3);
        }
        break;
    case bin:
        fwrite(&conf.num, sizeof(conf.num), 1, f);
        fwrite(data, sizeof(data[0]), conf.num, f);
        break;
    }
    fclose(f);
    //输出运行时间
    printf("%s文件生成成功, 用时%ldms\n", way == text ? "文本" : "二进制", clock() - start);
    return 0;
}