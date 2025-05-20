//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

typedef struct fibonacci_node_t {
    int value;
    struct fibonacci_node_t *next;
} fibonacci_node_t;

fibonacci_node_t *fibonacci_initialize() {
    fibonacci_node_t *head = malloc(sizeof(fibonacci_node_t));
    head->value = 0;
    head->next = malloc(sizeof(fibonacci_node_t));
    head->next->value = 1;
    head->next->next = NULL;
    return head;
}

int fibonacci_get(fibonacci_node_t *head, int n) {
    if (n == 0) {
        return head->value;
    } else if (n == 1) {
        return head->next->value;
    } else {
        fibonacci_node_t *current = head;
        for (int i = 2; i <= n; i++) {
            int next_value = current->value + current->next->value;
            fibonacci_node_t *new_node = malloc(sizeof(fibonacci_node_t));
            new_node->value = next_value;
            new_node->next = NULL;
            current->next->next = new_node;
            current = current->next;
        }
        return current->next->value;
    }
}

void fibonacci_print(fibonacci_node_t *head, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci_get(head, i));
    }
    printf("\n");
}

void fibonacci_free(fibonacci_node_t *head) {
    fibonacci_node_t *current = head;
    while (current != NULL) {
        fibonacci_node_t *next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    fibonacci_node_t *head = fibonacci_initialize();
    printf("The first 10 Fibonacci numbers are:\n");
    fibonacci_print(head, 10);
    fibonacci_free(head);
    return 0;
}