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
            newconf.MinRecordNum, newmode == automatic ? "�Զ�ģʽ":"����ģʽ");
        gets_s(buf, 256);
        sscanf(buf, "%d", &choice);
        switch (choice) {
        case 1:
            printf("�����µ��ļ��洢Ŀ¼��");
            gets_s(newconf.FileSavePath, MAX_STR_LEN);
            if (newconf.FileSavePath[strlen(newconf.FileSavePath)-1] != '/' && newconf.FileSavePath[strlen(newconf.FileSavePath)-1] != '\\') {
                strcat(newconf.FileSavePath, "/");
            }
            break;
        case 2:
            printf("�����µ��ļ����ƣ�");
            gets_s(newconf.FileName, MAX_STR_LEN);
            break;
        case 3:
            printf("�����һ������Ԫ�����ֵ��");
            gets_s(buf, 256);
            sscanf(buf, "%d", &newconf.MaxValue12);
            break;
        case 4:
            printf("�����һ������Ԫ����Сֵ��");
            gets_s(buf, 256);
            sscanf(buf, "%d", &newconf.MinValue12);
            break;
        case 5:
            printf("���������Ԫ�����ֵ��");
            gets_s(buf, 256);
            sscanf(buf, "%d", &newconf.MaxValue3);
            break;
        case 6:
            printf("���������Ԫ����Сֵ��");
            gets_s(buf, 256);
            sscanf(buf, "%d", &newconf.MinValue3);
            break;
        case 7:
            printf("�����¼�������ֵ��");
            gets_s(buf, 256);
            sscanf(buf, "%d", &newconf.MaxRecordNum);
            break;
        case 8:
            printf("�����¼������Сֵ��");
            gets_s(buf, 256);
            sscanf(buf, "%d", &newconf.MinRecordNum);
            break;
        case 9:
            printf("��ѡ����ģʽ\n1.�Զ�ģʽ\n2.����ģʽ\n������ѡ����ţ�");
            re: gets_s(buf, 256);
            sscanf(buf, "%d", &newmode);
            if (newmode != automatic && newmode != interactive) {
                printf("����������������룺");
                goto re;
            }
            break;
        }
    }
    FILE *f = fopen("conf.ini", "w");
    check(f != NULL, "�����ļ�4��ʧ��");
    fprintf(f, "%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n", \
            newconf.FileSavePath, newconf.FileName, newconf.MaxValue12, newconf.MinValue12, \
            newconf.MaxValue3, newconf.MinValue3, newconf.MaxRecordNum, newconf.MinRecordNum);
    fclose(f);
    f = fopen("conf5.ini", "w");
    check(f != NULL, "�����ļ�5��ʧ��");
    fprintf(f, "%d", newmode);
    fclose(f);
    puts("�޸ĳɹ�");
}