//FormAI DATASET v1.0 Category: Data structures visualization ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>

// Structure for linked list node
struct Node{
    int data;
    struct Node* next;
};

// Function to insert at the beginning of the linked list
void insertAtBeginning(struct Node** head, int data){
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // Set data for the new node
    newNode->data = data;
    // Set the next pointer of new node to the current head
    newNode->next = *head;
    // Set head to the new node
    *head = newNode;
}

// Function to insert at the end of the linked list
void insertAtEnd(struct Node** head, int data){
    // Allocate memory for the new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // Set data for the new node
    newNode->data = data;
    // Set the next pointer of new node to NULL
    newNode->next = NULL;
    // If the linked list is empty
    if(*head == NULL){
        // Set head to the new node
        *head = newNode;
        return;
    }
    // Traverse the linked list to the last node
    struct Node* current = *head;
    while(current->next != NULL){
        current = current->next;
    }
    // Set the next pointer of last node to the new node
    current->next = newNode;
}

// Function to delete a node from the linked list
void deleteNode(struct Node** head, int data){
    // If the linked list is empty
    if(*head == NULL){
        return;
    }
    // If data is at the beginning
    if((*head)->data == data){
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    // Traverse the linked list to find the node to be deleted
    struct Node* current = *head;
    while(current->next != NULL && current->next->data != data){
        current = current->next;
    }
    // If data is not found in the linked list
    if(current->next == NULL){
        return;
    }
    // Delete the node by changing pointers
    struct Node* temp = current->next;
    current->next = current->next->next;
    free(temp);
}

// Function to print the linked list
void printLinkedList(struct Node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    insertAtBeginning(&head, 5);
    insertAtEnd(&head, 6);
    insertAtBeginning(&head, 4);
    insertAtEnd(&head, 7);
    printf("Original Linked List: ");
    printLinkedList(head);
    deleteNode(&head, 6);
    printf("Linked List after deleting 6: ");
    printLinkedList(head);
    deleteNode(&head, 4);
    printf("Linked List after deleting 4: ");
    printLinkedList(head);
    deleteNode(&head, 7);
    printf("Linked List after deleting 7: ");
    printLinkedList(head);
    deleteNode(&head, 5);
    printf("Linked List after deleting 5: ");
    printLinkedList(head);
    return 0;
}