//Gemma-7B DATASET v1.0 Category: Traffic Flow Simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    struct Node* next;
    int data;
} Node;

void InsertAtTail(Node** head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        ((*head)->next = newNode);
        *head = newNode;
    }
}

void PrintList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Insert some nodes
    InsertAtTail(&head, 10);
    InsertAtTail(&head, 20);
    InsertAtTail(&head, 30);
    InsertAtTail(&head, 40);

    // Print the list
    PrintList(head);

    // Randomly change some node data
    srand(time(NULL));
    head->data = rand() % 100;

    // Print the list after modification
    PrintList(head);

    return 0;
}