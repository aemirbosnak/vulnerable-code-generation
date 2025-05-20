//FormAI DATASET v1.0 Category: Memory management ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

void freeList(Node *head) {
    Node *current = head;
    Node *next;

    while(current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    Node *head = malloc(sizeof(Node));
    if (head == NULL) {
        printf("Unable to allocate memory for head node\n");
        return 1;
    }
    head->value = 1;

    Node *tail = head;

    for (int i = 2; i <= 10; i++) {
        Node *newNode = malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Unable to allocate memory for new node\n");
            freeList(head);
            return 1;
        }
        newNode->value = i;
        tail->next = newNode;
        tail = newNode;
    }
    tail->next = NULL;

    printf("Linked list: ");
    Node *current = head;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");

    freeList(head);
    return 0;
}