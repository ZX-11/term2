#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define make(type,len)  (type*)malloc(sizeof(type)*(len))
#define uint8           unsigned char

int main(int argc, char *argv[]) {
    //����Ĭ�ϲ���
    srand(time(NULL));
    int num = rand() % 63 + 1;
    char FileName[256] = "default.txt";
    //�������в����л�ȡ����
    bool GetNum = false, GetName = false;
    for (int i = 1; i < argc; i++) {
        char *end;
        int t = strtol(argv[i], &end, 10);
        if (!GetNum && *end == '\0' && t > 0) { 
            num = t;
            GetNum = true;
        } else if (!GetName) {
            strncpy(FileName, argv[i], 251);
            if (strchr(FileName, '.') == NULL) {
                strcat(FileName, ".txt"); 
            }
            GetName = true;
        } else {
            fprintf(stderr,"��������\n");
            exit(1);
        }
    }
    //����num * 3��ά����buf
    uint8 **buf = make(uint8 *, num);
    if (NULL == buf) {
        fprintf(stderr,"�ڴ治��\n");
        exit(1);
    }
    for (int i = 0; i < num; i++) {
        buf[i] = make(uint8, 3);
        if (NULL == buf[i]) {
            fprintf(stderr,"�ڴ治��\n");
            exit(1);
        }
    }
    //Ϊ��ά����buf�����ֵ
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < 3; j++) {
            buf[i][j] = rand() % 256;
        }
    }
    //�����ļ�
    FILE *f = fopen(FileName, "w");
    if (NULL == f) {
        fprintf(stderr,"�ļ�����ʧ��\n");
        exit(1);
    }
    //��buf������ļ�
    fprintf(f, "%d\n", num);
    for (int i = 0; i < num; i++) {
        fprintf(f, "%d,%d,%d\n", buf[i][0], buf[i][1], buf[i][2]);
    }
    //�ƺ���
    fclose(f);
    for (int i = 0; i < num; i++) free(buf[i]);
    free(buf);
    return 0;
}