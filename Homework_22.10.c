//двоичное представление числа

#include <stdio.h>
main()
{
 const int s = sizeof(int) * 8;
 int n=0;
 scanf ("%d", &n);
 for (int i = 0; i<s; i++)
 {
 printf ("%d", (n << s - 1) & 1);
 n = n << 1;
 }
 
}
