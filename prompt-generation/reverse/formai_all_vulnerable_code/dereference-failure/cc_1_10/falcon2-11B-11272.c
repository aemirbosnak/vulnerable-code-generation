//Falcon2-11B DATASET v1.0 Category: Data structures visualization ; Style: authentic
#include <stdio.h>

// Structure for a node in linked list
struct node 
{ 
    int data; 
    struct node *next; 
}; 

// Function to insert a new node at the beginning of linked list 
void push(struct node** head_ref, int new_data) 
{ 
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
    new_node->data = new_data; 
    new_node->next = *head_ref; 
    *head_ref = new_node; 
} 

// Function to print linked list 
void display(struct node* head) 
{ 
    struct node* temp = head; 
    while(temp!=NULL) 
    { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    } 
    printf("\n"); 
} 

// Structure for double linked list
struct dll_node 
{ 
    int data; 
    struct dll_node *prev; 
    struct dll_node *next; 
}; 

// Function to insert a new node at the beginning of doubly linked list 
void push_front(struct dll_node** head_ref, int new_data) 
{ 
    struct dll_node* new_node = (struct dll_node*)malloc(sizeof(struct dll_node)); 
    new_node->data = new_data; 
    new_node->prev = NULL; 
    new_node->next = *head_ref; 
    *head_ref = new_node; 
} 

// Function to print doubly linked list 
void display_dll(struct dll_node* head) 
{ 
    struct dll_node* temp = head; 
    while(temp!=NULL) 
    { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    } 
    printf("\n"); 
} 

// Driver program to test above functions 
int main() 
{ 
    struct node* head = NULL; 
    push(&head, 10); 
    push(&head, 20); 
    push(&head, 30); 
    display(head); 
    return 0; 
}