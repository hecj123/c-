#include<stdio.h>
int main()
{
    int fac(int n);
    int n,y;
    printf("please input an integer number:");
    scanf("%d",&n);
    y=fac(n);
    printf("%d!=%d\n",n,y);
    return 0;
}

int fac(int n)
{
    int f;
    if(n<0)
      printf("date error");   //n不能小于0
    else if(n==0||n==1)
    f=1;
    else f=fac(n-1)*n;
    return(f);
}