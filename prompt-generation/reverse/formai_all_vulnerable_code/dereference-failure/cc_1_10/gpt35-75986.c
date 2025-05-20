//FormAI DATASET v1.0 Category: Data structures visualization ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// define a struct for node in the Doubly Linked List
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// define function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// define function to insert a node at the beginning of list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    if(*head == NULL) {
        *head = newNode;
    } else {
        (*head)->prev = newNode;
        newNode->next = *head;
        *head = newNode;
    }
}

// define function to insert a node at the end of list
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if(*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

// define function to delete a node from the list
void deleteNode(Node** head, int data) {
    Node* current = *head;
    while(current != NULL) {
        if(current->data == data) {
            if(current == *head) {
                *head = current->next;
                (*head)->prev = NULL;
            } else if(current->next == NULL) {
                current->prev->next = NULL;
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }
}

// define function to print the list
void printList(Node* head) {
    Node* current = head;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// main function
int main() {
    Node* head = NULL;
    printf("Original List: ");
    insertAtEnd(&head, 1);
    insertAtEnd(&head, 2);
    insertAtEnd(&head, 3);
    printList(head);
    printf("Inserting 4 at the beginning\n");
    insertAtBeginning(&head, 4);
    printList(head);
    printf("Inserting 5 at the end\n");
    insertAtEnd(&head, 5);
    printList(head);
    printf("Deleting 3 from the list\n");
    deleteNode(&head, 3);
    printList(head);
    return 0;
}