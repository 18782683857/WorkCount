#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//����ַ��� 
int split(char str[])
{    //ʹ��strtok()ʵ�ַָ�
	int n = 0;
	//char str[] = "hello,world hello";
	char* str1 = strtok(str, " ,");
	
	while (str1 != NULL)
	{
         str1 = strtok(NULL, " ,");
		 n++;
	}
	return n;
}
//ͳ���ַ��� 
int getCountChar(char *name){
	FILE *fp;
	int count = 0;
	char ch[1024];
	fp = fopen(name, "r");
	while(fgets(ch,1024,fp) != NULL)//���ж�ȡfp��ָ���ļ��е�����
	{
		count +=split(ch);

	}
	fclose(fp);
	return count;
}
//ͳ�Ƶ����� 
int getCount(char *name){
	FILE *fp;
	int count_char = 0;
	char ch;
	fp = fopen(name, "r");
	while((ch=fgetc(fp)) != EOF){
		count_char++;
	}
	fclose(fp);
	return count_char;
}



int main(int argc, char *argv[]){

	int count,char_count;
	//�жϿ��Ʋ����Ƿ���� 
	if(strcmp(argv[1],"-c") == 0){
		count = getCount(argv[2]);
		printf("�ַ�����%d",count);
	}
	else if(strcmp(argv[1],"-w") == 0){
		count = getCountChar(argv[2]);
		printf("��������%d",count);
	}
	return 0;
}
