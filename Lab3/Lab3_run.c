#include "Lab3_func.h"
#include "Lab3_data.h"

CONF conf = {"OutputData/", "default.txt", 16, 128, 0, 128, 0, 128, 0};

int Run(int argc, char *argv[]) {
    if (argc > 3) {
        fprintf(stderr,"错误：输入参数过多\n");
        exit(1);
    }
    srand(time(NULL));
    bool getNum = false, getName = false;
    //遍历命令行参数，逐个匹配
    for (int i = 1; i < argc; i++) {
        if (!getNum && GetNumFrom(argv[i])) {
            getNum = true;
        } else if (!getName && GetNameFrom(argv[i])) {
            getName = true;
        } else {
            fprintf(stderr, "错误：%s\n", (!getNum)&&(i == 3) ? "找不到记录条数参数":"命令行参数不合法");
            exit(1);
        }
    }
    //从用户输入中获取未被匹配的项
    if (!getNum) GetNum();
    if (!getName) GetName();
    //生成随机数文件
    return generate();
}