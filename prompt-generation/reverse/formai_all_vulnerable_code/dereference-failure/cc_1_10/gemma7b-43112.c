//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

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

void greedy_algorithm(Node** head) {
    Node* current = *head;
    Node* previous = NULL;
    int total_cost = 0;

    while (current) {
        int current_cost = current->data;
        if (previous) {
            int previous_cost = previous->data;
            if (current_cost < previous_cost) {
                total_cost += current_cost - previous_cost;
            }
        }
        previous = current;
        current = current->next;
    }

    printf("Total cost: %d\n", total_cost);
}

int main() {
    Node* head = NULL;
    insert(&head, 6);
    insert(&head, 3);
    insert(&head, 8);
    insert(&head, 10);
    insert(&head, 2);

    greedy_algorithm(&head);

    return 0;
}