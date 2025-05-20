//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    char *data;
    struct node *next;
} node_t;

void print_list(node_t *head) {
    while (head) {
        printf("%s\n", head->data);
        head = head->next;
    }
}

void free_list(node_t *head) {
    while (head) {
        node_t *next = head->next;
        free(head->data);
        free(head);
        head = next;
    }
}

node_t *push(node_t *head, char *data) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = head;
    return new_node;
}

node_t *reverse(node_t *head) {
    node_t *prev = NULL;
    node_t *current = head;
    while (current) {
        node_t *next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

int main() {
    srand(time(NULL));

    // Create a linked list of random strings.
    node_t *head = NULL;
    for (int i = 0; i < 10; i++) {
        char *str = malloc(10);
        for (int j = 0; j < 10; j++) {
            str[j] = rand() % 26 + 'a';
        }
        head = push(head, str);
    }

    // Print the original list.
    printf("Original list:\n");
    print_list(head);

    // Reverse the list.
    head = reverse(head);

    // Print the reversed list.
    printf("\nReversed list:\n");
    print_list(head);

    // Free the list.
    free_list(head);

    return 0;
}