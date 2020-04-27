#include "Lab4_func.h"
CONF conf;
void init() {
    FILE *f = fopen("conf.ini", "r");
    if (f == NULL) {
        fprintf(stderr, "错误：配置信息读取失败\n");
        exit(1);
    }
    fscanf(f, "%s%s%d%d%d%d%d%d", conf.FileSavePath, conf.FileName,\
           &conf.MaxValue12, &conf.MinValue12, &conf.MaxValue3,    \
           &conf.MinValue3, &conf.MaxRecordNum, &conf.MinRecordNum);
    srand(time(NULL));
    conf.num = RandIn(conf.MinRecordNum, conf.MaxRecordNum);
    fclose(f);
}
int Run(int argc, char *argv[]) {
    init();
    enum ways way = both;
    switch (argc) {
    case 4:
        if (strcmp(argv[3], "t") == 0) {
            way = text;
        } else if (strcmp(argv[3], "d") == 0) {
            way = bin;
        } else {
            goto invalid;
        }
    case 3:
        if (strcmp(argv[2], "-") != 0 && !GetNameFrom(argv[2])) goto invalid;
    case 2:
        if (strcmp(argv[1], "-") != 0 && !GetNumFrom(argv[1])) goto invalid;
    case 1:
        break;
    invalid:
        fprintf(stderr, "错误：命令行参数不合法\n");
        exit(1);
    default:
        fprintf(stderr, "错误：命令行参数过多\n");
        exit(1);
    }
    DATA *data = GenerateData();
    if (way == both) {
        GenerateFile(text, data);
        GenerateFile(bin, data);
    } else {
        GenerateFile(way, data);
    }
    free(data);
    return 0;
}