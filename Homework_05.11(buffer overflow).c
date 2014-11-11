// переполнение буфера
// Kudryashova Anna

#include <stdio.h>
#include <stdlib.h>
int f2()
 {
    char *str = "COMPLITE";
    char data[2];
    strcpy(data, str);


 }
int f1()
 {
    printf(" COMPLITE\n");
    exit (0);

 }
int main(void)
{
   printf ("%d %d %d\n", &f2, &f1, &main);
   f2();
   return 0;
}
#include <stdio.h>
#include <stdlib.h>
int f2()
 {
    char *str = "COMPLITE";
    char data[2];
    scanf("%s", data);


 }
int f1()
 {
    printf(" COMPLITE\n");
    exit (1);

 }
int main()
{
   printf ("%d %d %d\n", &f2, &f1, &main);
   f2();
   return 0;
}
