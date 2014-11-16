// переполнение буфера
// Kudryashova Anna

#include <stdio.h>
int f2()
 {
    char data[2];
    printf ("\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n\t%p\n"); // stack до ввода данных
    scanf ("%s", data);
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
   printf ("f2:\t%p\nf1:\t%p\nmain:\t%p\n", &f2, &f1, &main);
   printf("\n");
   f2();
   return 0;
}
