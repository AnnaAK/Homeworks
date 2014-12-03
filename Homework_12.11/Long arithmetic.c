#include <stdio.h>
#include <stdlib.h>

typedef struct LongNum {
  char sign; 
  node *digits;
} LongNum;

LongNum* LongNum_empty () {
*temp = (LongNum*)malloc(sizeof (LongNum));
if (temp != NULL)
{
   temp->sign = 0;
   temp->digits = NULL;
   return temp;
}
else printf("Not enough memory\n");
}

LongNum* LongNum_enter() {
   char digit;
   LongNum *num1 = LongNum_empty();
   scanf("%c", &digit);
   if (digit == '-') num1->sign = -1;
   else if (digit == 'q')
        break;
   else if (digit < '0' || digit > '9')
        printf("Error\n");
   else if (digit > '0' && digit < '9') 
     {
        num1->sign = 0;
        return num1;
     }
   else additionElement(&num1->digits, (int)digit - {int}'0');
   while (digit != 'q')
   {
       scanf("%c", &digit);
       if (digit < '0' || digit > '9')
       { 
         if (digit == ' ') break;
         else 
         {
             num->sign = 0;
             return num1;
         }
       }
       additionElement(&num1->digits, (int)digit - (int)'0');
   }
   return num1;
}


 void LongNum_sum (LongNum **num1, LongNum **num2, LongNum **result)
 {
  node *temp1 = (*num1)->digits;
  node *temp2 = (*num2)->digits;
  int curr = 0;
  while (temp1 != NULL || temp2 != NULL)
  {
      if (temp1 != NULL)
      {
        curr = curr + temp1->val;
        temp1 = temp1->next;
      }
      if (temp2 != NULL)
      {
        curr = curr + temp2->val;
        temp2 = temp2->next;
      }
      additionElement(&(*result)->digits, curr % 10);
      curr = curr / 10;
  }
  if (curr)
    additionElement(&(*result)->digits, curr);
  return;
}

void LongNum_abs (LongNum **num1, LongNum **num2, LongNum **result)
{
    
}

void LongNum_sub (LongNum **num1, LongNum **num2, LongNum **result)
{
  node *temp1 = (*num1)->digits;
  node *temp2 = (*num2)->digits;
}
        
     
     
