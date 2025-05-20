//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    int data;
    char name[20];
    struct Node* next;
} Node;

Node* createNode(int data, const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, int data, const char* name) {
    Node* newNode = createNode(data, name);
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* head) {
    Node* current = head;
    printf("***** ENERGETIC LINKED LIST *****\n");
    printf("Index | Data  | Name   \n");
    printf("----------------------------------\n");
    while (current != NULL) {
        printf("%2d | %5d  | %s  \n", current - head, current->data, current->name);
        current = current->next;
    }
}

void insertAtEnd(Node** head, int data, const char* name) {
    Node* newNode = createNode(data, name);
    Node* current = *head;
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (current->next != NULL)
        current = current->next;

    current->next = newNode;
}

void deleteNode(Node** head, int data) {
    Node* temp = *head, *prev;

    if (temp != NULL && temp->data == data) {
        *head = temp->next;  // Changed head
        free(temp);          // Free old head
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

int main() {
    Node* head = NULL;

    insertAtBeginning(&head, 10, "John");
    insertAtBeginning(&head, 20, "Mike");
    insertAtBeginning(&head, 30, "Lucy");
    insertAtEnd(&head, 40, "Tom");
    insertAtEnd(&head, 50, "Sara");

    printList(head);

    deleteNode(&head, 20);
    printList(head);

    deleteNode(&head, 10);
    printList(head);

    deleteNode(&head, 50);
    printList(head);

    return 0;
}