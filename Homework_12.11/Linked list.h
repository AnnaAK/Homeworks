/* Kudryashova Anna
functions for linked list
*/


#ifndef LINKED_LIST
#define LINKED_LIST

// struct of node in list
 typedef struct node
    {
        int val; // value of node
        struct node *next; // pointer to the next element
    } node;

// adding a new element to the top of the list
void additionElement (int el, node* oldHead);

// delete the first occurrence of an element in the list
void deleteElement(int el, node* headDel);

// prints the entire list
void printList (node* headPrint);

#endif
