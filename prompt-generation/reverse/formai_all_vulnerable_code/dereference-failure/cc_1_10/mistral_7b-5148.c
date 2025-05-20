//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    char name[20];
    struct Node* next;
} Node;

Node* head = NULL;
Node* current = NULL;

void createNode(int data, char* name) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        current = newNode;
    } else {
        current->next = newNode;
        current = newNode;
    }
}

void deleteNode(int data) {
    Node* temp = head;
    Node* previous = NULL;

    if (head != NULL && head->data == data) {
        head = head->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data) {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node not found.\n");
        return;
    }

    previous->next = temp->next;
    free(temp);
}

void modifyNode(int data, char* newName) {
    Node* temp = head;

    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node not found.\n");
        return;
    }

    strcpy(temp->name, newName);
}

void displayList() {
    Node* temp = head;

    printf("\nCurrent linked list:\n");
    while (temp != NULL) {
        printf("%d %s -> ", temp->data, temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    createNode(1, "One");
    createNode(2, "Two");
    createNode(3, "Three");

    displayList();

    modifyNode(2, "TwoNew");
    deleteNode(1);

    displayList();

    deleteNode(3);

    displayList();

    free(head);

    return 0;
}