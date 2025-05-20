//FormAI DATASET v1.0 Category: Linked list operations ; Style: random
#include<stdio.h> 
#include<stdlib.h> 

struct Node 
{ 
    int data; 
    struct Node *next; 
}; 

void insert_at_beginning(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 

    new_node->data = new_data; 

    new_node->next = (*head_ref); 

    (*head_ref) = new_node; 
} 

void insert_after(struct Node* prev_node, int new_data) 
{ 
    if (prev_node == NULL) 
    { 
        printf("The given previous node cannot be NULL"); 
        return; 
    } 

    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node)); 

    new_node->data = new_data; 

    new_node->next = prev_node->next; 

    prev_node->next = new_node; 
} 

void delete_node(struct Node **head_ref, int key) 
{ 
    struct Node* temp = *head_ref, *prev; 

    if(temp != NULL && temp->data == key) 
    { 
        *head_ref = temp->next;   
        free(temp);               
        return; 
    } 

    while (temp != NULL && temp->data != key) 
    { 
        prev = temp; 
        temp = temp->next; 
    } 

    if (temp == NULL) return; 

    prev->next = temp->next; 

    free(temp);  
} 

void print_list(struct Node *node) 
{ 
    while (node != NULL) 
    { 
        printf(" %d ", node->data); 
        node = node->next; 
    } 
} 

int main() 
{ 
    struct Node* head = NULL; 

    insert_at_beginning(&head, 5); 

    insert_at_beginning(&head, 34); 

    insert_after(head->next, 47); 

    delete_node(&head, 5); 

    printf("\n Created Linked list is: "); 
    print_list(head); 

    return 0; 
}