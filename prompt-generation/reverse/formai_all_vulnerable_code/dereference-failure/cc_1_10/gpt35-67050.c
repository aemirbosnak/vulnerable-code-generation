//FormAI DATASET v1.0 Category: Linked list operations ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Define the structure of each node in the linked list
typedef struct Node{
    int value;
    struct Node *next;
}Node;

// Declare the functions for linked list operations
void insertFirst(Node **head, int value);
void insertLast(Node **head, int value);
void insertAtIndex(Node **head, int value, int index);
void deleteFirst(Node **head);
void deleteLast(Node **head);
void deleteAtIndex(Node **head, int index);
int getSize(Node **head);
void printList(Node **head);

int main(){

    // Initialize the linked list
    Node *head = NULL;

    // Insert values into the linked list
    insertFirst(&head, 10);
    insertLast(&head, 20);
    insertAtIndex(&head, 30, 1);

    // Print the linked list
    printf("The linked list is: ");
    printList(&head);

    // Delete values from the linked list
    deleteFirst(&head);
    deleteLast(&head);
    deleteAtIndex(&head, 0);

    // Print the updated linked list
    printf("The updated linked list is: ");
    printList(&head);

    // Get the size of the linked list
    int size = getSize(&head);
    printf("The size of the linked list is: %d\n", size);

    return 0;
}

// Insert a node at the beginning of the linked list
void insertFirst(Node **head, int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}

// Insert a node at the end of the linked list
void insertLast(Node **head, int value){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL){
        *head = newNode;
        return;
    }

    Node *current = *head;
    while(current->next != NULL){
        current = current->next;
    }

    current->next = newNode;
}

// Insert a node at a specified index in the linked list
void insertAtIndex(Node **head, int value, int index){
    if (index == 0){
        insertFirst(head, value);
        return;
    }

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;

    Node *prev = *head;
    int i = 0;
    while (i < index-1 && prev != NULL){
        prev = prev->next;
        i++;
    }
    if (prev == NULL){
        return;
    }

    newNode->next = prev->next;
    prev->next = newNode;
}

// Delete the first node from the linked list
void deleteFirst(Node **head){
    if (*head == NULL){
        return;
    }

    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Delete the last node from the linked list
void deleteLast(Node **head){
    if (*head == NULL){
        return;
    }
    if ((*head)->next == NULL){
        deleteFirst(head);
        return;
    }

    Node *prev = *head;
    Node *current = (*head)->next;
    while(current->next != NULL){
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
    free(current);
}

// Delete a node at the specified index in the linked list
void deleteAtIndex(Node **head, int index){
    if (*head == NULL){
        return;
    }
    if (index == 0){
        deleteFirst(head);
        return;
    }

    Node *prev = *head;
    int i = 0;
    while (i < index-1 && prev != NULL){
        prev = prev->next;
        i++;
    }
    if (prev == NULL || prev->next == NULL){
        return;
    }

    Node *temp = prev->next;
    prev->next = temp->next;
    free(temp);
}

// Get the size of the linked list
int getSize(Node **head){
    int size = 0;
    Node *current = *head;

    while(current != NULL){
        size++;
        current = current->next;
    }

    return size;
}

// Print the linked list
void printList(Node **head){
    if (*head == NULL){
        printf("The list is empty!\n");
        return;
    }

    Node *current = *head;
    while(current != NULL){
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}