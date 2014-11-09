// Anna Kudryashova
// Может ли целое число быть представлено на машине с n-разрядным словом и дополнительным кодом.

#include <stdio.h>
int presentation ( int n, int w)
{
   const int s = sizeof (int) * 8 + 1 + ~w;
   int z = !(((n << s) >> s) ^ n);
   return z;
}
main (void)
{
   int n = 0, w = 0;
   scanf ("%d %d", &n, &w);
   printf ("%d\n", presentation (n,w));
   return 0;
  
}
