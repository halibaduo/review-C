//#include <stdio.h>
#ifndef _WANGJIE_H_//���û�ж���
#define _WANGJIE_H_//�Ǿ����ھͶ���//����_SUM_H_����Ҳ����ʲ�����ִ���
//int sum(int ,int);
//��ʼ(void);
int sum(int a, int b)//������int�������ĺ�
{
	int c;
	c=a+b;
	return c;
}
void kaishi(void)
{
	//printf("��ǰ�ļ����������Ϊ:%d\n",__LINE__);�����������ƺ�û��˵����
		printf("��ǰ���ļ�������Ϣ:%s\n",__FILE__);
		printf("��ǰ�������е�����:%s\n",__DATE__);
		printf("��ǰ��ʱ��:%s\n",__TIME__);
		printf("��������д��:���� ѧ��:320040300239 �꼶:20�ƿ�2��\n");
}
//����Ϊ�ֽڴ�С����
void kaishi1()
{
	printf("һ���ֽ�long�Ĵ�СΪ:%d\t",sizeof(long));
	printf("һ���ֽ�int�Ĵ�СΪ:%d\n",sizeof(int));
	printf("һ���ֽ�double�Ĵ�СΪ:%d\t",sizeof(double));
	printf("һ���ֽ�float�Ĵ�СΪ:%d\n",sizeof(float));
	printf("һ���ֽ�char�Ĵ�СΪ:%d\t",sizeof(char));
	printf("һ���ֽ�short�Ĵ�СΪ:%d\n",sizeof(short));
}
#endif//������ʼ���Ǹ����