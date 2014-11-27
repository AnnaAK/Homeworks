// Kudryashova Anna
/* list
a - add element
r - delete element
p - show all list
q - exit
*/

#include <stdio.h>
#include <stdlib.h>
#include "Linked list.h"

 typedef struct IntNode
{
     int val;
     struct IntNode *next;
} node;

node* additionElement (node* oldHead, int el)
{
  node *NewEl = (node*)malloc(sizeof (node));
  if (NewEl != NULL)
  {
     NewEl->val = el;
     NewEl->next = oldHead;
     return NewEl;
  }
  else printf("Not enough memory\n");
}

node* deleteElement(node* headDel, int el)
{
  node  *prevDel, *nextDel, *NewHead;
  while (nextDel != NULL)
  {
     if (headDel->val == el)
  {
     NewHead = headDel->next;
     free(headDel);
     return NewHead;
  }
  else if (headDel->val != el)
  {
     prevDel = headDel;
     nextDel = headDel->next;
     if (nextDel->val == el)
     {
        prevDel->next =  nextDel -> next;
        free(nextDel);
     }
     return headDel;
   }
  else printf("Such element don't exist\n");
 }
}

void printList (node* headPrint)
{
  node *nextPrint;
  nextPrint = headPrint;
  while ( nextPrint != NULL )
  {
    if ( nextPrint->next != NULL)
    printf ("%d, ", nextPrint->val);
    else printf ("%d", nextPrint->val);
    nextPrint = nextPrint->next;
  }
  printf("\n");
}

void main()
 {
    int element;
    char comand = NULL;
    node *head = NULL;

    printf (" \t a - add new element\n \t r - delete element\n \t p - show all list\n \t q - exit\n ");
    while (comand != 'q')
    {
       scanf("%c", &comand);
       switch (comand)
       {
         case 'a':
           scanf("%d", &element);
           head = additionElement (head, element);
           break;
         case 'r':
           scanf("%d", &element);
           head = deleteElement (head, element);
           break;
         case 'p':
          printList(head);
          comand = getchar();
          break;

     }
    }
     return 0;
 }
