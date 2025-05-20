//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node** head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void shuffle(Node* head) {
    srand(time(NULL));
    for (int i = 0; i < MAX_SIZE; i++) {
        int r = rand() % MAX_SIZE;
        int temp = head->data;
        head->data = head->next->data;
        head->next->data = temp;
        head = head->next;
    }
}

int main() {
    Node* head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    shuffle(head);

    printf("Shuffled list:");
    Node* current = head;
    while (current) {
        printf(" %d", current->data);
        current = current->next;
    }

    return 0;
}