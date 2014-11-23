/* Kudryashova Anna  
вывести знак, экспоенту и мантиссу с union */
#include <stdio.h>
struct floatstruct
{
  int sign;
  int exponenta;
  int mantissa;
} f;

 void presentation (floatstruct)
{
  #define max 255
  if (f.sign) f.sign = -1;
  else f.sign = 1;
  if (f.exponenta == 0 && f.mantissa == 0)
    printf ("0\n");
  else if (f.exponenta == max && f.mantissa == 0)
  {
    if (f.sign > 0) printf ("+ infinity");
    else printf ("- infinity");
  }
  else if (f.exponenta == max && f.mantissa != 0)
    printf ("NaN");
  else
    printf("%d * 2^%d * %f\n", f.sign, f.exponenta - 127, 1+((float)f.mantissa)/(1 << 23));
}
void value (int b)
{
  int sign = (b >> 31) & 1;
  int exponenta = (b >> 23) & ((1 << 8) - 1);
  int mantissa = b & ((1 << 23) - 1);
  f.sign = sign;
  f.mantissa = mantissa;
  f.exponenta = exponenta;
  presentation(f);
}
int main (void)
  {
	union
	{
		float floatval;
		int intval;
	} floatN;

	scanf("%f", &floatN.intval);
	value(floatN.intval);
	return 0;

}
