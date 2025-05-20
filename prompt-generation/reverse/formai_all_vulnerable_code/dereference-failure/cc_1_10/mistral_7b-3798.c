//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIST_SIZE 100
#define ELEMENT_SIZE 100

typedef struct Node {
    int data;
    char name[ELEMENT_SIZE];
    struct Node* next;
} Node;

Node* createNode(int data, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(Node** head, int data, char* name) {
    Node* newNode = createNode(data, name);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("Data: %d, Name: %s, Next: %p\n", temp->data, temp->name, temp->next);
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;

    append(&head, 5, "Five");
    append(&head, 10, "Ten");
    append(&head, 15, "Fifteen");
    append(&head, 20, "Twenty");

    printList(head);

    return 0;
}