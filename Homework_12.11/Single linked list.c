// Kudryashova Anna
/* list
a - add element
r - delete element
p - show all list
q - exit
*/

#include <stdio.h>
#include <stdlib.h>

 typedef   struct node_t
    {
        int val;
        int *next;
    } node;

node* additionElement (int el, node* oldHead)
{
  node* NewEl = (node*)malloc(sizeof (node));
  if (NewEl != NULL)
  {
   NewEl -> val = el;
   NewEl -> next = oldHead;
   return NewEl;
  }
}

node* deleteElement(int el, node* headDel)
{
  node  *prevDel, *nextDel, *NewHead;
  while (nextDel != NULL)
  if (headDel -> val == el)
  {
    NewHead = headDel -> next;
    free (headDel);
    return NewHead;
  }
  else
  {
    prevDel = headDel;
    nextDel = headDel -> next;
    if (nextDel -> val == el)
     prevDel -> next =  nextDel -> next;
     free (nextDel);
     return headDel;
   }
}

void printList (node* headPrint)
{
node *nextPrint;
nextPrint = headPrint;
while ( nextPrint != NULL )
{
printf ("%d ", nextPrint -> val);
nextPrint = nextPrint -> next;
}
}

void main()
 {
    int element;
    char comand = NULL;
    node *head = NULL;
    printf (" \t a - add new element\n \t r - delete element\n \t p - show all list\n \t q - exit\n ");
    while (comand != 'q')
    {
       comand = getchar();
       switch (comand)
       {
         case 'a':
           element = 0;
           comand = getchar();
           while (comand != ' ')
           {
             element = (int) comand - 48;
             comand = getchar();
           }
           head = additionElement (element, head);
           break;
         case 'r':
          element = 0;
          comand = getchar();
          while (comand != ' ')
           {
             element = (int) comand - 48;
             comand = getchar();
           }
           head = deleteElement (element, head);
           break;
         case 'p':
          printList(head);
          comand = getchar;
          break;
     }
    }
     return 0;
 }
