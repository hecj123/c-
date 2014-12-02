#include<stdio.h>
int mian()
{
    char c1,c2;
    printf("Please enter a capital letter:");
    scanf("%s",&c1);
    c2=c1+32;
    printf("\n%s",c2);
    return 0;
}