#include "Lab3_data.h"
#include "Lab3_func.h"

extern CONF conf;
//���ַ����л�ȡ�������洢��conf.num
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
//��ʾ�û�������������ȡ
void GetNum(void) {
    char buf[128];
    while (true) {
        printf("�������¼������");
        gets(buf);
        if (GetNumFrom(buf)) return;
        puts("���󣺼�¼���������������������");
    }
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
//��ʾ�û�����洢��ַ����ȡ
void GetName(void) {
    char buf[1024];
    while (true) {
        printf("�������ļ��洢��������·����");
        gets(buf);
        if (GetNameFrom(buf)) return;
        puts("�����ļ������ļ�Ŀ¼��������������");
    }
}
//�ж�str���Ƿ����accept�е��κ��ַ�
bool ContainsAny(char *str, char *accept) {
    for (char *p = str; *p; p++) {
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
//����������ļ�
int generate(void) {
    //�ж�Ŀ¼�Ƿ���ڣ��������򴴽�Ŀ¼
    if (access(conf.FileSavePath, 0) != 0 && mkdir(conf.FileSavePath) != 0) {
        fprintf(stderr, "�����ļ�Ŀ¼����ʧ��\n");
        exit(1);
    }
    //ƴװ�ļ�·��
    strcat(conf.FileSavePath, conf.FileName);
    //�����ļ�
    FILE *f = fopen(conf.FileSavePath, "w");
    if (f == NULL) {
        fprintf(stderr, "�����ļ�����ʧ��\n");
        exit(1);
    }
    //�������ֵ��д���ļ�
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
    puts("�ļ����ɳɹ�");
    return 0;
}