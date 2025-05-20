//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node* head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    head = newNode;
}

void playGame(Node* head) {
    int size = 0;
    Node* current = head;

    while (current) {
        size++;
        current = current->next;
    }

    int target = rand() % size;
    current = head;

    for (int i = 0; i < target; i++) {
        current = current->next;
    }

    printf("The data of the memory cell is: %d\n", current->data);
}

int main() {
    Node* head = NULL;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);

    playGame(head);

    return 0;
}