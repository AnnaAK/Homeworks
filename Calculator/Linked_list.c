#include <stdio.h>
#include <stdlib.h>
#include "Linked_list.h"





void List_additionElement (node **head, int el)
{
  node *NewEl = (node*)malloc(sizeof (node));
  if (NewEl != NULL)
  {
     NewEl->val = el;
     NewEl->next = *head;
	 *head = NewEl;
     return;
  }
  else printf("Not enough memory\n");
}



void List_deleteElement(node **head, int el)
{
  node *prevDel = NULL;
  node *temp = *head;
  while (temp != NULL)
  {
     if (temp->val == el)
  {
     *head = (*head)->next;
     free(head);
     return;
  }
  else if (temp->val != el)
  {
     prevDel = *head;
     temp = (*head)->next;
     if (temp->val == el)
     {
        prevDel->next =  temp->next;
        free(temp);
     }
     return;
   }
  else printf("Such element doesn't exist\n");
 }
}

void List_print (node **head)
{
  node *temp = *head;
 
  while ( temp != NULL )
  {
    if ( temp->next != NULL)
    printf ("%d, ", temp->val);
    else printf ("%d", temp->val);
    temp = temp ->next;
  }
  printf("\n");
}
void List_clear(node **head)
{
	node *temp = *head;
	while (temp != NULL)
	{
		*head = (*head)->next;
		free(temp);
        temp = *head;
	}
	free(*head);
	return;
}

int List_size (node **head)
{
	node *temp = *head;
	int count = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		count = count + 1;
	}
	return count;

}
