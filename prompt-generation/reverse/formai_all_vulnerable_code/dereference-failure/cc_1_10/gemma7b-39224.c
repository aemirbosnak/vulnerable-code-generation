//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

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
        ((*head)->next = newNode);
        *head = newNode;
    }
}

void greedy_algorithm(Node* head) {
    int i = 0;
    int total_sum = 0;
    Node* current_node = head;

    while (current_node) {
        total_sum += current_node->data;
        i++;
        current_node = current_node->next;
    }

    printf("Total sum of nodes: %d\n", total_sum);
    printf("Number of nodes: %d\n", i);
}

int main() {
    Node* head = NULL;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);

    greedy_algorithm(head);

    return 0;
}