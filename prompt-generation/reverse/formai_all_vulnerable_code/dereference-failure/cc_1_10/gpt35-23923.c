//FormAI DATASET v1.0 Category: Linked list operations ; Style: visionary
#include<stdio.h>
#include<stdlib.h>

// Define a structure for the linked list
struct Node{
    int data;
    struct Node* next;
};

// Add a new element to the end of the linked list
void addElement(struct Node** head, int data){
    // Create a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data; // Add data to the new node
    newNode->next = NULL; // Set the next pointer to NULL
    
    // If the list is empty
    if(*head == NULL){
        *head = newNode;
        return;
    }
    
    // Traverse to the end of the list
    struct Node* temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    // Add the new node to the end of the list
    temp->next = newNode;
}

// Delete the first occurrence of an element from the linked list
void deleteElement(struct Node** head, int data){
    // If the list is empty
    if(*head == NULL){
        printf("The list is empty.\n");
        return;
    }
    
    // If the first node contains the data
    if((*head)->data == data){
        *head = (*head)->next;
        return;
    }
    
    // Traverse the list and delete the node
    struct Node* temp = *head;
    while(temp->next != NULL){
        if(temp->next->data == data){
            temp->next = temp->next->next;
            return;
        }
        temp = temp->next;
    }
    
    printf("Element not found.\n");
}

// Display the linked list
void displayList(struct Node* head){
    // If the list is empty
    if(head == NULL){
        printf("The list is empty.\n");
        return;
    }
    
    printf("The linked list is:\n");
    
    // Traverse the list and print the data of each node
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL; // Initialize the list
    
    // Add some elements to the list
    addElement(&head, 5);
    addElement(&head, 10);
    addElement(&head, 15);
    addElement(&head, 20);
    
    // Display the initial list
    displayList(head);
    
    // Delete an element from the list
    deleteElement(&head, 10);
    
    // Display the updated list
    displayList(head);
    
    return 0;
}