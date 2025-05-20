//Gemma-7B DATASET v1.0 Category: Data recovery tool ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void recoverData(Node* head) {
    if (head == NULL) {
        return;
    }

    Node* current = head;
    Node* previous = NULL;

    // Traverse the linked list to find the middle node
    while (current->next) {
        previous = current;
        current = current->next;
    }

    // Swap the middle node and the last node
    Node* middle = previous->next;
    previous->next = middle->next;
    middle->next = previous;

    // Print the recovered data
    current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main() {
    // Create a linked list
    Node* head = malloc(sizeof(Node));
    head->data = 10;
    head->next = malloc(sizeof(Node));
    head->next->data = 20;
    head->next->next = malloc(sizeof(Node));
    head->next->next->data = 30;

    // Recover the data
    recoverData(head);

    // Print the recovered data
    printf("\n");
    return 0;
}