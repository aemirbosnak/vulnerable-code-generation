//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int year;
    struct node *next;
} node_t;

node_t *create_node(int year) {
    node_t *node = malloc(sizeof(node_t));
    node->year = year;
    node->next = NULL;
    return node;
}

void add_node(node_t **head, int year) {
    node_t *new_node = create_node(year);
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node_t *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d\n", current->year);
        current = current->next;
    }
}

void free_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        node_t *next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a linked list of years
    node_t *head = NULL;
    for (int i = 0; i < 10; i++) {
        int year = rand() % 2000 + 1;
        add_node(&head, year);
    }

    // Print the list of years
    printf("Original list of years:\n");
    print_list(head);

    // Travel through the list of years
    int current_year = 2023;
    while (head != NULL) {
        // Move to the next year
        current_year = head->year;
        head = head->next;

        // Visit the year
        printf("Visiting the year %d\n", current_year);

        // Do something in the year
        int action = rand() % 3;
        switch (action) {
            case 0:
                printf("  Learned something new.\n");
                break;
            case 1:
                printf("  Met someone interesting.\n");
                break;
            case 2:
                printf("  Had a great time.\n");
                break;
        }
    }

    // Free the list of years
    free_list(head);

    return 0;
}