//#include <stdio.h>
#ifndef _WANGJIE_H_//如果没有定义
#define _WANGJIE_H_//那就现在就定义//出现_SUM_H_错误也大概率不会出现错误
//int sum(int ,int);
//开始(void);
int sum(int a, int b)//求两个int类型数的和
{
	int c;
	c=a+b;
	return c;
}
void kaishi(void)
{
	//printf("当前文件的行数大概为:%d\n",__LINE__);发现在这里似乎没有说明用
		printf("当前的文件所处信息:%s\n",__FILE__);
		printf("当前程序运行的日期:%s\n",__DATE__);
		printf("当前的时间:%s\n",__TIME__);
		printf("本代码所写人:王杰 学号:320040300239 年级:20计科2班\n");
}
//以下为字节大小测试
void kaishi1()
{
	printf("一个字节long的大小为:%d\t",sizeof(long));
	printf("一个字节int的大小为:%d\n",sizeof(int));
	printf("一个字节double的大小为:%d\t",sizeof(double));
	printf("一个字节float的大小为:%d\n",sizeof(float));
	printf("一个字节char的大小为:%d\t",sizeof(char));
	printf("一个字节short的大小为:%d\n",sizeof(short));
}
#endif//结束开始的那个如果