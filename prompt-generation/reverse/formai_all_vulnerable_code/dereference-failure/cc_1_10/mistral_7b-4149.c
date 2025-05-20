//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#define LINKLIST_SIZE 10

typedef struct Node {
    int data;
    char name[20];
    struct Node *next;
} Node;

Node *head = NULL;

void createNode(int data, char *name) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    strcpy(newNode->name, name);
    newNode->next = head;
    head = newNode;
}

void displayList() {
    Node *temp = head;
    printf("\n---- Linked List ----\n");
    while (temp != NULL) {
        printf("Data: %d, Name: %s -> ", temp->data, temp->name);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertAtBeginning(int data, char *name) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    strcpy(newNode->name, name);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data, char *name) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    Node *temp = head;
    newNode->data = data;
    strcpy(newNode->name, name);
    if (head == NULL) {
        head = newNode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteNode(int key) {
    Node *temp = head, *prev;
    if (temp != NULL && temp->data == key) {
        head = temp->next;
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

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <Operation> <Data> <Name>\n", argv[0]);
        return 1;
    }

    char operation = argv[1][0];

    switch (operation) {
        case 'C':
            createNode(atoi(argv[2]), argv[3]);
            break;
        case 'D':
            displayList();
            break;
        case 'I':
            insertAtBeginning(atoi(argv[2]), argv[3]);
            displayList();
            break;
        case 'E':
            insertAtEnd(atoi(argv[2]), argv[3]);
            displayList();
            break;
        case 'R':
            deleteNode(atoi(argv[2]));
            displayList();
            break;
        default:
            printf("Invalid Operation: %c\n", operation);
            return 1;
    }

    return 0;
}