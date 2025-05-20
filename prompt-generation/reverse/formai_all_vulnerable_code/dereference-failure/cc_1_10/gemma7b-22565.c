//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: artistic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct node {
    int x, y;
    struct node* next;
} node;

void initialize(node** head) {
    *head = NULL;
}

void insert(node** head, int x, int y) {
    node* newNode = malloc(sizeof(node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
        *head = newNode;
    }
}

void percolate(node** head) {
    srand(time(NULL));
    for (node* current = *head; current; current = current->next) {
        int r = rand() % 2;
        if (r == 0) {
            insert(head, current->x + 1, current->y);
        } else {
            insert(head, current->x - 1, current->y);
        }
    }
}

int main() {
    node* head = NULL;
    initialize(&head);

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            insert(head, x, y);
        }
    }

    percolate(&head);

    return 0;
}