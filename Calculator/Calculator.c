#include <stdio.h>
#include <stdlib.h>
#include "Calculator.h"

void main ()
{
	char digt;
	LongNum **num1 = LongNum_empty();
	LongNum **num2 = LongNum_empty();
	LongNum **result = LongNum_empty();
	stack **head =	NULL;


	scanf ("%c",&digt);
	LongNum_enter(&(*num1),digt);
	if ((*num1)->sign == (int)'E')
	{
		printf("Unknown command\n");
		Stack_delete (&(*head));
		return 1;
	}
	Stack_push (&(*head), &(*num1));
	scanf ("%c",&digt);
	LongNum_enter(&(*num2),digt);
	if ((*num2)->sign == (int)'E')
	{
		printf("Unknown command\n");
		Stack_delete (&(*head));
		return 1;
	}
	Stack_push (&(*head), &(*num2));
	while (digt != '#')
	{
		scanf ("%c",&digt);
		if ((digt == '+') || (digt == '-') || (digt == '*') || (digt == '/') && ( Stack_size(&(*head)) != 0))
		{
			switch (digt)
			{
			case '+':
				 Stack_pop (&(*head), &(*num1));
				 Stack_pop (&(*head), &(*num2));
				 LongNum_sum (&(*num1), &(*num2), &(*result));
				 LongNum_revert(&(*result));
				 Stack_push (&(*head), &(*result));
				 LongNum_clear (&(*num1));
				 LongNum_clear (&(*num2));
				 LongNum_clear (&(*result));
				 break;
			case '-':
				 Stack_pop (&(*head), &(*num1));
				 Stack_pop (&(*head), &(*num2));
				 LongNum_sub (&(*num1), &(*num2), &(*result));
				 LongNum_revert(&(*result));
				 Stack_push (&(*head), &(*result));
				 LongNum_clear (&(*num1));
				 LongNum_clear (&(*num2));
				 LongNum_clear (&(*result));
				 break;
			 case '*':
				 Stack_pop (&(*head), &(*num1));
				 Stack_pop (&(*head), &(*num2));
				 LongNum_multi (&(*num1), &(*num2), &(*result));
				 LongNum_revert(&(*result));
				 Stack_push (&(*head), &(*result));
				 LongNum_clear (&(*num1));
				 LongNum_clear (&(*num2));
				 LongNum_clear (&(*result));
				 break;
			 case '/':
				 Stack_pop (&(*head), &(*num1));
				 Stack_pop (&(*head), &(*num2));
				 LongNum_division (&(*num1), &(*num2), &(*result));
				 LongNum_revert(&(*result));
				 Stack_push (&(*head), &(*result));
				 LongNum_clear (&(*num1));
				 LongNum_clear (&(*num2));
				 LongNum_clear (&(*result));
				 break;
			}
		}
		else if ((digt == '+') || (digt == '-') || (digt == '*') || (digt == '/') && ( Stack_size(&(*head)) == 0))
		{
			printf("Not enough argumrnts\n");
		}
		else if ((digt > '0') && (digt < '9'))
		{
			LongNum_enter(&(*num1),digt);
	        if ((*num1)->sign == (int)'E')
	        {
				printf("Unknown command\n");
		        Stack_delete (&(*head));
		        return 1;
	        }
	        Stack_push (&(*head), &(*num1));
		}
		else if (digt == '=')
		{
			if ((*head)->val->sign)
			{
				printf ("-");
				List_print ((*head)->val->digits);
			}
			else 
			{
				List_print ((*head)->val->digits);
			}
		}
		else 
		{
			printf("Unknown command\n");
			Stack_delete (&(*head));
			return 1;
		}
	}
	Stack_print(&(*head));
	return;
}
