// Kudryashova Anna
// вывести знак числа через битовые операции

#include <stdio.h>
int sign (int n)
{
    const int m = sizeof (int) * 8 - 1 ;
   int z = 0;
   z = (n >> m) + !(n >> m) + ~(!n + ~0);
   return z;
}
int main ()
{
  int n;
  scanf ("%d", &n);
  printf("%d", sign(n));
  return 0;
}
