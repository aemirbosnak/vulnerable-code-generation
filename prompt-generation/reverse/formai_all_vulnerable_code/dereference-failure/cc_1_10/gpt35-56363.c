//FormAI DATASET v1.0 Category: Memory management ; Style: visionary
#include <stdio.h> 
#include <stdlib.h> 
  
// Define a struct to represent a node in a linked list 
struct Node { 
    int data; 
    struct Node* next; 
}; 
  
// Function to allocate memory for a new node and assign the given value and next pointer 
struct Node* createNode(int data) { 
    struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
    node->data = data; 
    node->next = NULL; 
    return node; 
} 
  
// Function to insert a new node at the beginning of the linked list 
void insertNode(struct Node** head_ref, int data) { 
    struct Node* node = createNode(data); 
    node->next = *head_ref; 
    *head_ref = node; 
} 
  
// Function to traverse the linked list and print each element 
void traverseList(struct Node* head) { 
    struct Node* ptr = head; 
    while (ptr != NULL) { 
        printf("%d ", ptr->data); 
        ptr = ptr->next; 
    } 
    printf("\n"); 
} 
  
// Main function to test the linked list implementation 
int main() 
{ 
    struct Node* head = NULL; 
  
    insertNode(&head, 5); 
    insertNode(&head, 7); 
    insertNode(&head, 9); 
    insertNode(&head, 11); 
  
    printf("Original List: "); 
    traverseList(head); 
  
    // Releasing the memory allocated for the linked list 
    struct Node* curr = head; 
    while (curr != NULL) { 
        struct Node* temp = curr; 
        curr = curr->next; 
        free(temp); 
    } 
    head = NULL; 
  
    printf("Memory Released Successfully!\n"); 
    return 0; 
}