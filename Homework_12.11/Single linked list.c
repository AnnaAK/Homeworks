// Kudryashova Anna
/* list
a - add element
r - delete element
p - show all list
q - exit
*/

#include <stdio.h>

 typedef struct node
    {
        int val;
        struct node *next;
    } node;

node *head = NULL;
node *temp = NULL;
  

void addition ( struct node_t *el, struct node_t **start)
{
  node *temp = (node*)malloc(sizeof (node));
  if (temp != NULL) 
  {
    p = *start;
    if (!*start)  *start = el;
    else 
    {
      el->next = p; 
      *start = el;
    }
  }
}

void delete(
     struct node_t *p, /* предыдущий элемент */
     struct node_t *el, /* удаляемый элемент */
     struct node_t **start, /* начало списка */
     struct node_t **end) /* конец списка */
{
  if(p) p->next = el->next;
  else *start = el->next;

  if(el==*end && p) *end = p;
}


 void main()
 {
    int element;
    char comand;
    char MasEnter[10];
    gets(enter);
    if (enter < 10)
    
    
  
    switch (comand)
    {
      case 'a': 
      scanf ("%d", &element);
      f.val = element;
      addition();
      break;
       
      case 'r':
      scanf ("%d", &element);
      delete();
      break;
      case 'p':
      case 'q':
      exit (0);
      return 0;
    }
   
   
   
   
   
   
   
   
   
   
 }
