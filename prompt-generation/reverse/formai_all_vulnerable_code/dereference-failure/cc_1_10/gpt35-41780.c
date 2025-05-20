//FormAI DATASET v1.0 Category: Data structures visualization ; Style: scientific
#include<stdio.h>

//Defining the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

//Function to push a new node to the start of the Linked list
void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

//Function to print the Linked list
void printList(struct Node* node) {
    while(node != NULL) {
        printf("%d->",node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    //Creating a Linked list with 4 nodes
    struct Node* head = NULL;
    push(&head,1);
    push(&head,2);
    push(&head,3);
    push(&head,4);
    
    //Printing the Linked list before performing any operations
    printf("Initial Linked List:\n");
    printList(head);
    
    //Removing the second node from the Linked list
    struct Node* temp = head->next;
    head->next = temp->next;
    free(temp);
    
    //Printing the Linked list after removing the second node
    printf("Linked List after removing the 2nd node:\n");
    printList(head);
    
    //Adding a new node at the end of the Linked list
    push(&head,5);
    
    //Printing the Linked list after adding a new node to the end
    printf("Linked List after adding a new node at the end:\n");
    printList(head);
    
    return 0;
}