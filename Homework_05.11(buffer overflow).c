// переполнение буфера

#include <stdio.h>
#include <stdlib.h>
int f2()
{
    printf("%s\n",f2);
    exit (0);
}
int f1()
{
    printf("1\n");

}
void main()
{
char data [10];
scanf("%s",data);
int r=f1();
printf ("%d\n",r);
}
