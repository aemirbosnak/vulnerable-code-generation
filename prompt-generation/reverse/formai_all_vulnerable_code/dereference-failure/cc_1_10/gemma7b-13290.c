//Gemma-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVES 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void Hanoi(Node* source, Node* destination, Node* auxiliary, int moves) {
    if (moves > MAX_MOVES) {
        return;
    }

    if (source->next == NULL) {
        destination->data = source->data;
        source->data = -1;
        moves++;
        return;
    }

    Hanoi(source, auxiliary, destination, moves + 1);
    Hanoi(auxiliary, destination, source, moves + 1);
    destination->data = source->data;
    source->data = -1;
    moves++;
}

int main() {
    Node* head = malloc(sizeof(Node));
    head->data = 3;
    head->next = malloc(sizeof(Node));
    head->next->data = 5;
    head->next->next = malloc(sizeof(Node));
    head->next->next->data = 8;

    Node* destination = malloc(sizeof(Node));
    destination->data = -1;

    Hanoi(head, destination, NULL, 0);

    printf("Moves: %d\n", destination->data);

    free(head);
    free(destination);

    return 0;
}