//GEMINI-pro DATASET v1.0 Category: Searching algorithm ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int value;
    struct Node *next;
} Node;

Node *create_list(int n) {
    Node *head = NULL;
    Node *current = NULL;

    for (int i = 0; i < n; i++) {
        Node *new_node = malloc(sizeof(Node));
        new_node->value = rand() % 100;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
            current = new_node;
        } else {
            current->next = new_node;
            current = current->next;
        }
    }

    return head;
}

void print_list(Node *head) {
    Node *current = head;

    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

int search_list(Node *head, int target) {
    Node *current = head;

    while (current != NULL) {
        if (current->value == target) {
            return 1;
        }

        current = current->next;
    }

    return 0;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a linked list of 100 random numbers
    Node *head = create_list(100);

    // Print the linked list
    print_list(head);

    // Search for a random number in the linked list
    int target = rand() % 100;

    // If the number is found, print a message
    if (search_list(head, target)) {
        printf("The number %d was found in the list.\n", target);
    } else {
        printf("The number %d was not found in the list.\n", target);
    }

    return 0;
}