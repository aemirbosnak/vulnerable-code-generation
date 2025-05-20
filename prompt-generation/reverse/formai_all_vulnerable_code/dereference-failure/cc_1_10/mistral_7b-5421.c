//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 50

typedef struct Node {
    int data;
    char name[20];
    struct Node* next;
} Node;

Node* createNode(int data, char* name) {
    Node* newNode = (Node*) malloc(sizeof(Node));

    newNode->data = data;
    strcpy(newNode->name, name);
    newNode->next = NULL;

    return newNode;
}

void insertAtHead(Node** head, int data, char* name) {
    Node* newNode = createNode(data, name);

    newNode->next = *head;
    *head = newNode;
}

void insertAtTail(Node** head, int data, char* name) {
    Node* newNode = createNode(data, name);
    Node* temp = *head;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayList(Node* head) {
    Node* temp = head;

    printf("List: ");
    while (temp != NULL) {
        printf("(%d, %s) -> ", temp->data, temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteNode(Node** head, int key) {
    Node* temp = *head, *prev;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

int main() {
    Node* head = NULL;

    insertAtHead(&head, 1, "Apple");
    insertAtHead(&head, 2, "Banana");
    insertAtTail(&head, 3, "Cherry");
    insertAtTail(&head, 4, "Durian");
    insertAtTail(&head, 5, "Elderberry");

    displayList(head);

    deleteNode(&head, 2);
    deleteNode(&head, 5);

    displayList(head);

    return 0;
}