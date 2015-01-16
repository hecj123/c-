#include<stdio.h>
int main()
{
   char a[]="I am a programmer",b[20],*p1,*p2;
   p1=a,p2=b;
   for(;*p!='\0';p1++,p++)
   *p2=*p1;
   *p2='\0';

   printf("string a is:%s\n",a);
   printf("string b is:%s\n",b);
   for(i=0;b[i]!='\0';i++)
   printf("%c",b[i]);
   
   printf("\n");
   return 0;
}