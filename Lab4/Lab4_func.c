#include "Lab4_data.h"
#include "Lab4_func.h"
extern CONF conf;

//�������ܣ����ַ����л�ȡ�������洢��conf.num
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
//���ַ����л�ȡ�ļ����Ʋ��洢��conf.FileName������ַ���ֱ�洢��conf.FileSavePath��conf.FileName
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
//�ж�str���Ƿ����accept�е��κ��ַ�
bool ContainsAny(char *str, char *accept) {
    for (char *p = str; *p ; p++) {
        for (char *q = accept; *q; q++) {
            if (*p == *q) return true;
        }
    }
    return false;
}
//�ж��ļ����Ƿ�Ϸ�
bool IsValidFileName(char *FileName) {
    return (!ContainsAny(FileName, "/:*?\\<>|") && (strstr(FileName, ".txt") != NULL || strstr(FileName, ".dat") != NULL));
}
//�����ַ�е�·�����ļ������ֱ�洢��conf.FileSavePath��conf.FileName
bool SplitPath(char *path) {
    //ʹ��splitpath����ַ��Ϊ�̷���·�����ļ�������չ���Ĳ���
    char drive[1024], dir[1024], FileName[256], ext[8];
    _splitpath(path, drive, dir, FileName, ext);
    //����չ�����ӵ��ļ���
    strcat(FileName, ext);
    //�ж�·�����ļ����ĺϷ���
    if (!ContainsAny(dir, ":*?<>|") && IsValidFileName(FileName)) {
        strcpy(conf.FileName, FileName);
        strcpy(conf.FileSavePath, strcat(drive, dir));
        return true;
    }
    return false;
}
//��������
DATA *GenerateData(void) {
    DATA *data = make(DATA, conf.num);
    if (data == NULL) {
        fprintf(stderr, "�����ڴ治��\n");
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
//���������ļ�
int GenerateFile(int way, DATA *data) {
    //�ж�Ŀ¼�Ƿ���ڣ��������򴴽�Ŀ¼
    if (access(conf.FileSavePath, 0) != 0 && mkdir(conf.FileSavePath) != 0) {
        fprintf(stderr, "�����ļ�Ŀ¼����ʧ��\n");
        exit(1);
    }
    //ƴ���ļ���
    char FileAddr[1024];
    strcpy(FileAddr, conf.FileSavePath);
    strcat(FileAddr, conf.FileName);
    //������չ��
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
    //��ʼ��ʱ
    clock_t start = clock();
    //�����ļ�
    FILE *f = fopen(FileAddr, way == text ? "w" : "wb");
    if (f == NULL) {
        fprintf(stderr, "�����ļ�����ʧ��\n");
        exit(1);
    }
    //�����д���ļ�
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
    //�������ʱ��
    printf("%s�ļ����ɳɹ�, ��ʱ%ldms\n", way == text ? "�ı�" : "������", clock() - start);
    return 0;
}