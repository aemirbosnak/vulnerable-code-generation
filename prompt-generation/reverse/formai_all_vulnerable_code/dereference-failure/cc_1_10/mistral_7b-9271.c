//MISTRAL-7B DATASET v1.0 Category: Memory management ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head = NULL;
int size = 0;

void printList() {
    Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void append(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    size++;
}

int main() {
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        append(i);
    }
    printList();

    Node* current = head;
    while (current != NULL) {
        int temp = current->data;
        Node* next = current->next;

        free(current);
        current = next;
    }

    head = NULL;
    size = 0;

    printList();

    return 0;
}