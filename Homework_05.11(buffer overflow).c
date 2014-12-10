// переполнение буфера
// Kudryashova Anna

#include <stdio.h>
#include <string.h>
int f2(char overflow[])
 {
    char data[4];
    printf ("\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n"); // stack до ввода данных
    strcpy (data,overflow);
	printf("\n");
    printf ("\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n"); // stack после ввода данных
    return;
 }
int f1()
 {
    printf(" COMPLITE\n");
    exit (1);

 }
int main()
{
   char overflow[] = "overflowover\x59\x11\x87\x00";
   printf ("f2:\t%p\nf1:\t%p\nmain:\t%p\n", &f2, &f1, &main);
   printf("\n");
   f2(overflow);
   return 0;
}
