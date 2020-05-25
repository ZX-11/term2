#include "Lab5_main.h"
#include "Lab5_loadfile.h"
CONF conf;
int mode;

void init(void) {
    FILE *f = fopen("conf5.ini", "r");
    check(f != NULL, "配置文件读取失败");
    fscanf(f, "%d", &mode);
    fclose(f);
    check(mode == automatic || mode == interactive, "配置文件有误");
    f = fopen("conf.ini", "r");
    check(f != NULL, "配置文件读取失败");
    fgetln(f, conf.FileSavePath);
    fgetln(f, conf.FileName);
    fscanf(f, "%d%d%d%d%d%d", &conf.MaxValue12, &conf.MinValue12, &conf.MaxValue3,\
           &conf.MinValue3, &conf.MaxRecordNum, &conf.MinRecordNum);
    fclose(f);
    check(access("Lab4.exe", 0) == 0, "依赖文件不存在");
}

int Run(void) {
    init();
    char buf[2048];
    for (;;) {
        int choice = -1, num = 0;
        system("cls");
        printf(menu);
        gets_s(buf, 2048);
        sscanf(buf, "%d", &choice);
        char *FileAddr = buf;
        switch (choice) {
        case 0: exit(0);
        case 1: call_Generate(text); break;
        case 2: call_Generate(bin); break;
        case 3: {
            printf("请输入文件位置：");
            gets_s(FileAddr, 2048);
            int **mat = loadfile_Matrix(FileAddr, &num);
            view_Matrix(mat, num);
            mat_Del(mat, num);
        } break;
        case 4: {
            printf("请输入文件位置：");
            gets_s(FileAddr, 2048);
            Data *arr = loadfile_StructArr(FileAddr, &num);
            view_StructArr(arr, num);
            free(arr);
        } break;
        case 5: {
            printf("请输入文件位置：");
            gets_s(FileAddr, 2048);
            Data **arr = loadfile_PointerArr(FileAddr, &num);
            view_PointerArr(arr, num);
            mat_Del(arr, num);
        } break;
        case 6: {
            printf("请输入文件位置：");
            gets_s(FileAddr, 2048);
            List *ls = loadfile_List(FileAddr, &num);
            view_List(ls);
            list_Del(ls);
        } break;
        case 7: {
            FileAddr = call_Generate(text);
            int **mat = loadfile_Matrix(FileAddr, &num);
            view_Matrix(mat, num);
            mat_Del(mat, num);
        } break;
        case 8: {
            FileAddr = call_Generate(text);
            Data *arr = loadfile_StructArr(FileAddr, &num);
            view_StructArr(arr, num);
            free(arr);
        } break;
        case 9: {
            FileAddr = call_Generate(text);
            Data **arr = loadfile_PointerArr(FileAddr, &num);
            view_PointerArr(arr, num);
            mat_Del(arr, num);
        } break;
        case 10: {
            FileAddr = call_Generate(text);
            List *ls = loadfile_List(FileAddr, &num);
            view_List(ls);
            list_Del(ls);
        } break;
        case 11: {
            FileAddr = call_Generate(bin);
            int **mat = loadfile_Matrix(FileAddr, &num);
            view_Matrix(mat, num);
            mat_Del(mat, num);
        } break;
        case 12: {
            FileAddr = call_Generate(bin);
            Data *arr = loadfile_StructArr(FileAddr, &num);
            view_StructArr(arr, num);
            free(arr);
        } break;
        case 13: {
            FileAddr = call_Generate(bin);
            Data **arr = loadfile_PointerArr(FileAddr, &num);
            view_PointerArr(arr, num);
            mat_Del(arr, num);
        } break;
        case 14: {
            FileAddr = call_Generate(bin);
            List *ls = loadfile_List(FileAddr, &num);
            view_List(ls);
            list_Del(ls);
        } break;
        case 15:
            conf_Reset();
            init();
            break;
        default:
            puts("序号输入有误！");
        }
        if (choice >= 7 && choice <= 14) free(FileAddr);
        system("pause");
    }
    return 0;
}