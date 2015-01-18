#include<stdio.h>
#include<stdlib.h>   //stdlib 头文件即standard library标准库头文件
int main()
{
   FILE * fp;
   char ch,filename[10];
   printf("请输入所用的文件名:");
   
   sacanf("%s",filename);
   if((fp=fopen(filename,"w"))==NULL)
   {
      printf("无法打开此文件\n");
      exit(0);
   }
   
   char=getchar();
   printf("请输入一个准备存储到磁盘的字符串（以#结束）：");
   ch=getchar();
   while(ch!='#')
   {
      fputc(ch,fp);
      putchar(ch);
      ch=getchar();
   }
   
   fclose(fp);
   putchar(10);
   return 0;
}