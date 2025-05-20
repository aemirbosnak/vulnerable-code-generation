//FormAI DATASET v1.0 Category: Linked list operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// Declaration of the Node structure
typedef struct Node { 
    int data; 
    struct Node* next; 
} Node; 

// Function to insert a new item at the end of the list
void insert(Node** head, int data) { 
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    newNode->data = data; 
    newNode->next = NULL; 
  
    if (*head == NULL) { 
        *head = newNode; 
        return; 
    } 
  
    Node* lastNode = *head; 
    while (lastNode->next != NULL) 
        lastNode = lastNode->next; 
  
    lastNode->next = newNode; 
    return; 
} 

// Function to remove an item from the list
void delete(Node** head, int data) { 
    Node* temp = *head, *prev; 
  
    if (temp != NULL && temp->data == data) { 
        *head = temp->next;   
        free(temp);               
        return; 
    } 
  
    while (temp != NULL && temp->data != data) { 
        prev= temp; 
        temp = temp->next; 
    } 
  
    if (temp == NULL) 
        return; 
  
    prev->next = temp->next; 
    free(temp); 
} 

// Function to print the entire list
void printList(Node* head) { 
    Node* temp = head; 
    while (temp != NULL) { 
        printf("%d ", temp->data); 
        temp = temp->next; 
    } 
} 

int main() { 
    Node* head = NULL; 

    // Insert three numbers to start the list
    insert(&head, 666);
    insert(&head, 777);
    insert(&head, 888);

    // Print the entire list
    printf("Initial linked list: "); 
    printList(head); 
    printf("\n"); 

    // Add two more numbers
    insert(&head, 999);
    insert(&head, 123);

    // Print the updated list
    printf("Updated linked list: "); 
    printList(head); 
    printf("\n"); 

    // Remove a number from the list
    delete(&head, 123);

    // Print the updated list again
    printf("Updated linked list after deletion: "); 
    printList(head); 
    printf("\n"); 

    return 0; 
}