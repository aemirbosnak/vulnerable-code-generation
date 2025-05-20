//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    char* name;
    struct Node* next;
} Node;

Node* createNode(int data, char* name) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->name = strdup(name);
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* current = head;
    printf("--- Curious Linked List --- \n");
    printf("Data Name Next\n");
    while (current != NULL) {
        printf("%d %s %p\n", current->data, current->name, current->next);
        current = current->next;
    }
}

void insertAtBeginning(Node** head, int data, char* name) {
    Node* newNode = createNode(data, name);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node** head, int data, char* name) {
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

int main(void) {
    Node* curiousList = NULL;

    insertAtBeginning(&curiousList, 42, "forty-two");
    insertAtBeginning(&curiousList, 13, "thirteen");
    insertAtBeginning(&curiousList, 66, "sixty-six");

    insertAtEnd(&curiousList, 7, "seven");
    insertAtEnd(&curiousList, 11, "eleven");
    insertAtEnd(&curiousList, 17, "seventeen");

    printList(curiousList);

    free(curiousList);
    return 0;
}