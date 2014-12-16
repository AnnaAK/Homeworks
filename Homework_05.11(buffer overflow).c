// переполнение буфера
// Kudryashova Anna

#include <stdio.h>
#include <string.h>
int f2()
 {
    char data[4];
	scanf("%s",data, "\x30\x10\x40\x00");
	printf("\n");
    
 
 }
int f1()
 {
    printf(" COMPLITE\n");
 }
int main()
{
   printf ("f2:\t%p\nf1:\t%p\nmain:\t%p\n", &f2, &f1, &main);
   printf("\n");
   f2();
   return 0;
}
