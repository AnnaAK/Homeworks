// struct of node in list
 typedef struct node
    {
        int val; // value of node
        struct node *next; // pointer to the next element
    } node;

// adding a new element to the top of the list
void List_additionElement (node **head, int el);

// delete the first occurrence of an element in the list
void List_deleteElement(node **head, int el);

// prints the entire list
void List_print (node **head);

//clear the list
void List_clear(node **head);

//return size of list
int List_size (node **head);
