//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

typedef struct fibonacci_t {
    int value;
    struct fibonacci_t *next;
} fibonacci;

void fibonacci_sequence(int n, fibonacci **head) {
    if (n <= 0) {
        *head = NULL;
        return;
    }

    if (*head == NULL) {
        *head = (fibonacci *)malloc(sizeof(fibonacci));
        (*head)->value = 0;
        (*head)->next = NULL;
    } else {
        fibonacci *previous = *head;
        fibonacci *current;

        while (previous->next && previous->next->value < n) {
            previous = previous->next;
        }

        if (previous->next) {
            current = (fibonacci *)malloc(sizeof(fibonacci));
            current->value = previous->value + previous->next->value;
            previous->next = current;
            current->next = NULL;
        } else {
            fibonacci *new_node = (fibonacci *)malloc(sizeof(fibonacci));
            new_node->value = previous->value + previous->next->value;
            previous->next = new_node;
            new_node->next = NULL;
        }
    }

    fibonacci_sequence(n - 1, head);
}

void print_fibonacci_sequence(fibonacci *head) {
    fibonacci *current = head;

    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }

    printf("\n");
}

int main() {
    int n;
    fibonacci *head = NULL;

    printf("Enter a number: ");
    scanf("%d", &n);

    fibonacci_sequence(n, &head);
    print_fibonacci_sequence(head);

    fibonacci *current = head;
    fibonacci *previous = NULL;

    while (current != NULL) {
        previous = current;
        current = current->next;
        free(previous);
    }

    return 0;
}