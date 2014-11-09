// Kudryashova Anna
// сколько раз подстрока s2 входит в строку s1 

#include <stdio.h>
#include <string.h>

int main()
{
	char t[1000], s1[2000], s2[1000];
	int a = strlen(s1), b = strlen(s2), i = 0, j = 0, k = 0, z = 0;
	scanf("%s", &s1);
	scanf("%s", &s2);
	for (i = 0; i <= a - b; ++i)
	{
	  k = 1;
	  for (j = 0; j < b; ++j)
	   {
	      if (s1[i + j] != s2[j])
		{
		  k = 0;
		  break;
		}
	   }
		if (k)
            z = z + 1;
	}
	printf("%d", z);
	return 0;
}
