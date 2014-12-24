#include <stdlib.h>
#include "Stack.h"


void Stack_push (stack **head, LongNum **digits)
{
	stack *temp = (stack*)malloc(sizeof(stack));
	node *data = (*digits)->digits;

	if (temp != NULL)
	{
	temp->val = LongNum_empty ();
	while(data != NULL)
	{
		List_additionElement(&temp->val->digits, data->val);
		data = data->next;
	}
	LongNum_revert(&temp->val);
	temp->val->sign = (*digits)->sign;
	temp->next = *head;
	*head = temp;
	return;
    }
	else 
	{
		printf("Not enough memory\n");
	}
}
void Stack_pop (stack **head, LongNum **digits)
{
	stack *temp = *head;
	if (*head != NULL)
	{
		*digits = temp->val;
		*head = (*head)->next;
		free(temp);
		return;
	}
	else
	{
		printf("Stack is empty");
	}
}

int Stack_size (stack **head)
{
	stack *temp = *head;
	int curr = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		curr = curr + 1;
	}
	return curr;
}
void Stack_clear (stack **head)
{
	stack *temp = *head;
	while (temp != NULL)
	{
		*head = (*head)->next;
		LongNum_clear(&temp->val);
		free(temp);
		temp = *head;
	}
	return;
}
void Stack_delete (stack **head)
{
	Stack_clear(head);
	free (*head);
	return;
}

void Stack_print (stack **head)
{
  stack *nextPrint;
  *nextPrint = **head;
  while ( nextPrint != NULL )
  {
    if ( nextPrint->next != NULL)
		printf ("%d, ", nextPrint->val->digits->val);
	else printf ("%d", nextPrint->val->digits->val);
    nextPrint = nextPrint->next;
  }
  printf("\n");
}
