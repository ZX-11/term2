#ifndef LAB4_DATA_H
#define LAB4_DATA_H
#define MAX_STR_LEN 1024
enum ways {text, bin, both};
typedef struct {
    char FileSavePath[MAX_STR_LEN] ; //用于存放数据记录文件的存储目录
    char FileName[MAX_STR_LEN] ; //用于存储数据记录文件的文件名信息
    int num; //用于存放生成的记录条数
    int MaxValue12; //用于存放实验2中生成的数据记录三元组中第1、2个元素取值的上限
    int MinValue12; //用于存放实验2中生成的数据记录三元组中第1、2个元素取值的下限
    int MaxValue3 ; //用于存放实验2中生成的数据记录三元组中第3个元素取值的上限
    int MinValue3; //用于存放实验2中生成的数据记录三元组中第3个元素取值的下限
    int MaxRecordNum; //用于存放数据记录文件需要随机生成记录条数时条数值的上限
    int MinRecordNum; //用于存放数据记录文件需要随机生成记录条数时条数值的下限
} CONF;
typedef struct {
    int i1;
    int i2;
    int i3;
} DATA;
#endif //LAB4_DATA_H
