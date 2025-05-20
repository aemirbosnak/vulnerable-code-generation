//FormAI DATASET v1.0 Category: Linked list operations ; Style: mind-bending
#include <stdio.h> 
#include <stdlib.h> 

//Defining node structure 
struct Node { 
    int data; 
    struct Node* next; 
}; 

//Function to insert a node at the beginning of the linked list.
void insert_at_beginning(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 

//Function to insert a node at the end of the linked list.
void insert_at_end(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); 
    struct Node* last = *head_ref; 
    new_node->data = new_data; 
    new_node->next = NULL; 
    if (*head_ref == NULL) { 
        *head_ref = new_node; 
        return; 
    } 
    while (last->next != NULL) 
        last = last->next; 
    last->next = new_node; 
    return; 
} 

//Function to delete a node from the linked list.
void delete_node(struct Node** head_ref, int key) 
{ 
    struct Node *temp = *head_ref, *prev; 
    if (temp != NULL && temp->data == key) { 
        *head_ref = temp->next; 
        free(temp); 
        return; 
    } 
    while (temp != NULL && temp->data != key) { 
        prev = temp; 
        temp = temp->next; 
    } 
    if (temp == NULL) 
        return; 
    prev->next = temp->next; 
    free(temp); 
} 

//Function to display the linked list.
void display(struct Node* node) 
{ 
    while (node != NULL) { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
} 

//Main function
int main() 
{ 
    //Creating initial linked list with two nodes.
    struct Node* head = NULL; 
    struct Node* second = NULL; 
    struct Node* third = NULL; 
    head = (struct Node*)malloc(sizeof(struct Node)); 
    second = (struct Node*)malloc(sizeof(struct Node)); 
    third = (struct Node*)malloc(sizeof(struct Node)); 
    head->data = 1; 
    head->next = second; 
    second->data = 2;   
    second->next = third; 
    third->data = 3; 
    third->next = NULL; 

    //Inserting a node at the beginning of the linked list.
    printf("\nBefore Insertion at Beginning:\n"); 
    display(head); 
    insert_at_beginning(&head, 0); 
    printf("\n\nAfter Insertion at Beginning:\n"); 
    display(head); 

    //Inserting a node at the end of the linked list.
    printf("\n\nBefore Insertion at End:\n"); 
    display(head); 
    insert_at_end(&head, 4); 
    printf("\n\nAfter Insertion at End:\n"); 
    display(head); 

    //Deleting a node from the linked list.
    printf("\n\nBefore Deletion:\n"); 
    display(head); 
    delete_node(&head, 2); 
    printf("\n\nAfter Deletion:\n"); 
    display(head); 
    return 0; 
}