//FormAI DATASET v1.0 Category: Linked list operations ; Style: thoughtful
#include <stdio.h> 
#include <stdlib.h> 

// Creating a node structure
struct node { 
    int data; 
    struct node* next; 
}; 

// Function to add elements to the linked list
void push(struct node** head_ref, int new_data) { 
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); 
    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 

// Function to count the total number of nodes in the linked list
int countNodes(struct node* head) { 
    int count = 0; 
    struct node* current = head; 
    while (current != NULL) { 
        count++; 
        current = current->next; 
    } 
    return count; 
} 

// Function to find the nth node from the end of the linked list
void nthNodeFromEnd(struct node* head, int n) { 
    int len = countNodes(head); 
    if (len < n) {
        printf("Error: Index out of range.\n"); 
        return; 
    }
    struct node* temp = head; 
    for (int i = 1; i < len - n + 1; i++) 
        temp = temp->next; 
    printf("The nth node from the end of the linked list is: %d\n", temp->data); 
} 

// Function to delete a node from the linked list
void deleteNode(struct node** head_ref, int key) { 
    struct node* temp = *head_ref, *prev; 
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

// Function to print the linked list
void printList(struct node* node) { 
    while (node != NULL) { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
} 

// Main function
int main() { 
    struct node* head = NULL; 
    push(&head, 1); 
    push(&head, 2); 
    push(&head, 3); 
    push(&head, 4); 
    push(&head, 5); 
    printf("Linked list before deletion: "); 
    printList(head); 
    printf("\n"); 
    deleteNode(&head, 3); 
    printf("Linked list after deletion: "); 
    printList(head); 
    printf("\n"); 
    printf("Total number of nodes in the linked list are: %d\n", countNodes(head));
    nthNodeFromEnd(head, 2);
    return 0; 
}