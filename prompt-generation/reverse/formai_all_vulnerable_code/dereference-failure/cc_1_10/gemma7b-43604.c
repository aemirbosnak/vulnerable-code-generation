//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    head = (Node*)malloc(sizeof(Node));
    head->data = 10;
    head->next = NULL;

    Node* second = (Node*)malloc(sizeof(Node));
    second->data = 20;
    second->next = NULL;

    head->next = second;

    Node* third = (Node*)malloc(sizeof(Node));
    third->data = 30;
    third->next = NULL;

    second->next = third;

    Node* fourth = (Node*)malloc(sizeof(Node));
    fourth->data = 40;
    fourth->next = NULL;

    third->next = fourth;

    Node* fifth = (Node*)malloc(sizeof(Node));
    fifth->data = 50;
    fifth->next = NULL;

    fourth->next = fifth;

    // Let's see if we can traverse the list
    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    // Free the memory allocated for each node
    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);

    return 0;
}