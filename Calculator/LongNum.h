#include "Linked_list.h"

typedef struct LongNum {
  int sign; 
  node *digits;
} LongNum;


// create a empty LongNumber
LongNum* LongNum_empty ();


// reads the number entered
void LongNum_enter(LongNum **num,char num1);

// reverted enterned number
void LongNum_revert(LongNum **num);

// delete all digits from LongNumber
void LongNum_clear (LongNum **num);

// free memory
void LongNum_delete (LongNum **num);

// adds two numbers
void LongNum_sum (LongNum **num1, LongNum **num2, LongNum **result);

// finds the difference between two numbers
void LongNum_sub (LongNum **num1, LongNum **num2, LongNum **result);

// finds the product of two numbers
void LongNum_multi(LongNum **num1, LongNum **num2, LongNum **result);

// return 1 if num1 > num2 and return 0 if num2 > num1
int Bigger (node **num1, node **num2);

// for division
node* List_sub (node **num1, node **num2, node **result);
