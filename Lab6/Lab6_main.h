#ifndef LAB6_MAIN
#define LAB6_MAIN
#include <stdio.h>
#include <stdbool.h>
#include "extdlib.h"
#include "Lab6_data.h"
#include "Lab6_loadfile.h"
#include "Lab6_view.h"
#include "Lab6_call.h"
#include "Lab6_conf.h"
#include "Lab6_sort.h"
#define menu "�������ʵ��5����\n\
1. ����ʵ��4�������ɼ�¼�ļ����ı���ʽ��\n\
2. ����ʵ��4�������ɼ�¼�ļ��������Ʒ�ʽ��\n\
3. ��ȡָ�����ݼ�¼�ļ������򣨶�ά����洢��ʽ��\n\
4. ��ȡָ�����ݼ�¼�ļ������򣨽ṹ������洢��ʽ��\n\
5. ��ȡָ�����ݼ�¼�ļ�������ָ������洢��ʽ��\n\
6. ��ȡָ�����ݼ�¼�ļ������������洢��ʽ��\n\
7. ����ʵ��4�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ��������ı���ʽ�������ά���鷽ʽ�洢��\n\
8. ����ʵ��4�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ��������ı���ʽ������ṹ�����鷽ʽ�洢��\n\
9. ����ʵ��4�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ��������ı���ʽ�����ָ�����鷽ʽ�洢��\n\
10.����ʵ��4�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ��������ı���ʽ�����������ʽ�洢��\n\
11.����ʵ��4�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ������򣨶����Ʒ�ʽ�������ά���鷽ʽ�洢��\n\
12.����ʵ��4�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ������򣨶����Ʒ�ʽ������ṹ�����鷽ʽ�洢��\n\
13.����ʵ��4�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ������򣨶����Ʒ�ʽ�����ָ�����鷽ʽ�洢��\n\
14.����ʵ��4�������ݼ�¼�ļ���ͬʱ��ȡ���ݼ�¼�ļ������򣨶����Ʒ�ʽ�����������ʽ�洢��\n\
15.�����������ò���ֵ\n\
0. �˳�\n\
��������Ҫִ�еĳ�����ţ�"
int Run(void);

#endif