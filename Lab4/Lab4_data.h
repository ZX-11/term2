#ifndef LAB4_DATA_H
#define LAB4_DATA_H
#define MAX_STR_LEN 1024
enum ways {text, bin, both};
typedef struct {
    char FileSavePath[MAX_STR_LEN] ; //���ڴ�����ݼ�¼�ļ��Ĵ洢Ŀ¼
    char FileName[MAX_STR_LEN] ; //���ڴ洢���ݼ�¼�ļ����ļ�����Ϣ
    int num; //���ڴ�����ɵļ�¼����
    int MaxValue12; //���ڴ��ʵ��2�����ɵ����ݼ�¼��Ԫ���е�1��2��Ԫ��ȡֵ������
    int MinValue12; //���ڴ��ʵ��2�����ɵ����ݼ�¼��Ԫ���е�1��2��Ԫ��ȡֵ������
    int MaxValue3 ; //���ڴ��ʵ��2�����ɵ����ݼ�¼��Ԫ���е�3��Ԫ��ȡֵ������
    int MinValue3; //���ڴ��ʵ��2�����ɵ����ݼ�¼��Ԫ���е�3��Ԫ��ȡֵ������
    int MaxRecordNum; //���ڴ�����ݼ�¼�ļ���Ҫ������ɼ�¼����ʱ����ֵ������
    int MinRecordNum; //���ڴ�����ݼ�¼�ļ���Ҫ������ɼ�¼����ʱ����ֵ������
} CONF;
typedef struct {
    int i1;
    int i2;
    int i3;
} DATA;
#endif //LAB4_DATA_H
