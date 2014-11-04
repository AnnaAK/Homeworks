//  вывести знак. экспоненту и мантиссу
// структура с битовыми полями

#include <stdio.h>
struct floatstruct
{
  int sign;
  int exponenta;
  int mantissa;
} f;
 void presentation (floatstruct)
 #define max 255
{
  if (f.sign)
  f.sign = -1;
  else
  f.sign = 1;
  if (f.exponenta == 0 && f.mantissa == 0)
    printf ("0\n");
  else
  if (f.exponenta == max && f.mantissa == 0)
  if (f.sign>0)
    printf ("sign = +");
  else
    printf ("sign = -");
  else if (f.exponenta == max && f.mantissa !=0)
    printf ("NaN");
  else 
    printf("%d * 2^%d * %f\n", f.sign, f.exponenta - 127, 1+((float)f.mantissa)/(1 << 23));
}

main(void)
{
  {
	union
	{
		float floatval;
		struct
		{
			unsigned m : 23;
			unsigned e : 8;
			unsigned s : 1;
		} bitfield;
	} floatN;

	scanf("%f", &floatN.floatval);
	f.sign = floatN.bitfield.s;
	f.exponenta = floatN.bitfield.e;
	f.mantissa = floatN.bitfield.m;
	print(f);
}
return 0;
}
