#include<stdio.h>
#include<stdlib.h>   //stdlib 头文件即standard library标准库头文件
int main()
{
   FILE * fp;
   char ch,filename[10];
   printf("Please enter the file name:");
   
   scanf("%s",filename);
   if((fp=fopen(filename,"w"))==NULL)    //打开输出文件并使fp指向此文件
   {
      printf("Unable to open this file\n"); //如果打开出错，就输出“打不开”的信息
      exit(0);     //终止程序
   }
   
   ch=getchar();     //用来接收最后输入的回车符
   printf("Please enter a string  in the disk（Ends with a #）：");
   ch=getchar();   //接收从键盘输入的第一个字符
   while(ch!='#')  //当输入#时结束循环
   {
      fputc(ch,fp);
      putchar(ch);
      ch=getchar();
   }
   
   fclose(fp);
   putchar(10);
   return 0;
}