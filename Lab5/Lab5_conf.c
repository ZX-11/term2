#include "Lab5_conf.h"
extern CONF conf;
extern int mode;

void conf_Reset(void) {
    CONF newconf = conf;
    int choice = -1, newmode = mode;
    char buf[256];
    while (choice != 0) {
        system("cls");
        printf(resetmenu, newconf.FileSavePath, newconf.FileName, newconf.MaxValue12, \
            newconf.MinValue12, newconf.MaxValue3, newconf.MinValue3, newconf.MaxRecordNum, \
            newconf.MinRecordNum, newmode == automatic ? "自动模式":"交互模式");
        gets_s(buf, 256);
        sscanf(buf, "%d", &choice);
        switch (choice) {
        case 1:
            printf("输入新的文件存储目录：");
            gets_s(newconf.FileSavePath, MAX_STR_LEN);
            if (newconf.FileSavePath[strlen(newconf.FileSavePath)-1] != '/' && newconf.FileSavePath[strlen(newconf.FileSavePath)-1] != '\\') {
                strcat(newconf.FileSavePath, "/");
            }
            break;
        case 2:
            printf("输入新的文件名称：");
            gets_s(newconf.FileName, MAX_STR_LEN);
            break;
        case 3:
            printf("输入第一、二个元素最大值：");
            gets_s(buf, 256);
            sscanf(buf, "%d", &newconf.MaxValue12);
            break;
        case 4:
            printf("输入第一、二个元素最小值：");
            gets_s(buf, 256);
            sscanf(buf, "%d", &newconf.MinValue12);
            break;
        case 5:
            printf("输入第三个元素最大值：");
            gets_s(buf, 256);
            sscanf(buf, "%d", &newconf.MaxValue3);
            break;
        case 6:
            printf("输入第三个元素最小值：");
            gets_s(buf, 256);
            sscanf(buf, "%d", &newconf.MinValue3);
            break;
        case 7:
            printf("输入记录条数最大值：");
            gets_s(buf, 256);
            sscanf(buf, "%d", &newconf.MaxRecordNum);
            break;
        case 8:
            printf("输入记录条数最小值：");
            gets_s(buf, 256);
            sscanf(buf, "%d", &newconf.MinRecordNum);
            break;
        case 9:
            printf("请选择工作模式\n1.自动模式\n2.交互模式\n请输入选项序号：");
            re: gets_s(buf, 256);
            sscanf(buf, "%d", &newmode);
            if (newmode != automatic && newmode != interactive) {
                printf("输入错误，请重新输入：");
                goto re;
            }
            break;
        }
    }
    FILE *f = fopen("conf.ini", "w");
    check(f != NULL, "配置文件4打开失败");
    fprintf(f, "%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n", \
            newconf.FileSavePath, newconf.FileName, newconf.MaxValue12, newconf.MinValue12, \
            newconf.MaxValue3, newconf.MinValue3, newconf.MaxRecordNum, newconf.MinRecordNum);
    fclose(f);
    f = fopen("conf5.ini", "w");
    check(f != NULL, "配置文件5打开失败");
    fprintf(f, "%d", newmode);
    fclose(f);
    puts("修改成功");
}