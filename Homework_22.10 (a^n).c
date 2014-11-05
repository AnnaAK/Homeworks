//возведение в степень через битовые операции

#include <stdio.h>

  int stepen (int a,int n)
  {
    int count = 1;
    while (n)
    if (n%2 != 0)
    {
      count *= a;
      --n;
    }
    else
    {
    a *= a;
    n >>= 1;
    }
    return count;
  }
int main ()
{
int a = 0, n = 0;
scanf ("%d", &a);
scanf ("%d", &n);
printf ("%d\n", stepen (a,n));
return 0;
}
