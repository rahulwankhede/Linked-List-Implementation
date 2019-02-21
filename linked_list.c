#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

/*takes a pointer to the head node of the list and prints it*/
void printlist(struct Node *head){
    struct Node *temp = head;
    while(temp != NULL){
        printf("%d, ", temp->data);
        temp = temp->next;
    }
}


/*takes a pointer to a pointer to the head node of the list and appends a node with data newdata at the head*/
void push(struct Node **headref, int newdata){
    struct Node *newnode = (struct Node*) malloc(sizeof(struct Node));
    newnode->data = newdata;
    newnode->next = *headref;
    *headref = newnode;
}



static void reverselist(struct Node **headref){
    struct Node *current = *headref;
    struct Node *prev = NULL;
    struct Node *temp = NULL;
    while(current->next){
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    current->next = prev;
    *headref = current;
}

int main()
{
    struct Node *head = NULL;
    push(&head, 2);
    push(&head, 4);
    push(&head, 6);
    push(&head, 8);
    
    
    printlist(head);
    
    reverselist(&head);
    
    //printf("%d", sizeof(struct Node));
    printlist(head);
    return 0;
}