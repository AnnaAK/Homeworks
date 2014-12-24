#include "LongNum.h"

typedef struct stack
{
	LongNum *val;
	struct stack *next;
}stack;

// addition element on stack
void Stack_push (stack **head, LongNum **digits);

//return first element in stack and delete him
void Stack_pop (stack **head, LongNum **digits);

//return size of stack
int Stack_size (stack **head);

// delete all element from stack
void Stack_clear (stack **head);

// free memory
void Stack_delete (stack **head);

//print stack
void Stack_print (stack **head);
