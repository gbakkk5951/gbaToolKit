int main(){}
#include<cstdio>
#include<cstring>
struct _Main{
char sname[200];
_Main(){
	int i,j,k;
	printf("请选择模式\n1:处理源文件\n2:分析数据\n")
	
	
	
}	
void pre_deal(){
	int i,j,k;
	printf("源程序名:");
	scanf("%s",sname);
	printf("输出文件:");
	for(i=0;sname[i]&&sname[i]!='.';i++){
		putchar(sname[i]);
	}
	printf("%s","_test.cpp\n");
	strcpy(sname+i,"_test.cpp"); 
	printf("sname : %s\n",sname);
	
	
	
}	
	
	
	
}observer;
