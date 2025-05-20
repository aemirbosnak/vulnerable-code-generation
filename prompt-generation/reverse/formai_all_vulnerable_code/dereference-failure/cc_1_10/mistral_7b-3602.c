//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100
#define DATA_SIZE 50

typedef struct Node {
    char data[DATA_SIZE];
    struct Node *next;
} Node;

Node *head = NULL;
Node *current = NULL;

void createList() {
    int i;
    for (i = 0; i < MAX_LIST_SIZE; i++) {
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->next = NULL;
        strcpy(newNode->data, "");
        if (head == NULL) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }
}

void insertData(int position, char *data) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    Node *traverse = head;

    if (position < 0 || position > MAX_LIST_SIZE) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    if (position == 0) {
        newNode->next = head;
        strcpy(newNode->data, data);
        head = newNode;
    } else {
        for (int i = 0; i < position - 1; i++) {
            traverse = traverse->next;
        }
        newNode->next = traverse->next;
        strcpy(newNode->data, data);
        traverse->next = newNode;
    }
}

void deleteData(int position) {
    Node *traverse = head;
    Node *previous = NULL;

    if (position < 0 || position > MAX_LIST_SIZE) {
        printf("Invalid position\n");
        return;
    }

    if (position == 0) {
        head = head->next;
    } else {
        for (int i = 0; i < position - 1; i++) {
            previous = traverse;
            traverse = traverse->next;
        }
        previous->next = traverse->next;
    }

    free(traverse);
}

void displayList() {
    Node *traverse = head;

    printf("List:\n");
    while (traverse != NULL) {
        printf("%s -> ", traverse->data);
        traverse = traverse->next;
    }
    printf("NULL\n");
}

int main() {
    createList();
    insertData(0, "Apple");
    insertData(1, "Banana");
    insertData(2, "Orange");
    insertData(3, "Mango");
    displayList();
    deleteData(1);
    displayList();
    deleteData(0);
    displayList();

    return 0;
}