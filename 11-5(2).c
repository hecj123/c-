#include<stdio.h>
int main()
{
   void copy_string(char from[],char to[])
   char a[]="I an a teacher";
   char b[]="You are a programmer";
   char *from=a,*to=b;
   printf("string a=%s\n string b=%s\n",a,b);
   printf("copy string a to string b:\n");
   copy_string(from,to);
   printf("\n string a=%s\n string b=%s\n",a,b);
   return 0;
  
}

void copy_string(char from[],char to[])
{
   int i=0;
   while(from[i]!='\0')
   {
      to[i]=from[i];
      i++;
   }
   to[i]='\0';
}