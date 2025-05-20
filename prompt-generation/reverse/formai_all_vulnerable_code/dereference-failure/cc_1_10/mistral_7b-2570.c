//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 10

typedef struct Node {
    int data;
    char symbol;
    struct Node* next;
} Node;

void print_list(Node* head) {
    Node* current = head;

    puts("List:");
    while (current != NULL) {
        printf(" %c ", current->symbol);
        current = current->next;
    }
    puts("|");
}

void initialize_list(Node** head) {
    Node* current = *head;
    Node** previous = head;

    for (int i = 0; i < SIZE; ++i) {
        current = malloc(sizeof(Node));
        current->data = i;
        current->symbol = '*' + i;
        current->next = NULL;

        if (*head == NULL) {
            *head = current;
        } else {
            while (*previous != NULL) {
                previous = &((*previous)->next);
            }
            *previous = current;
        }
        previous = &current->next;
    }
}

int main() {
    Node* list_head = NULL;

    puts("Before initialization:");
    print_list(list_head);

    initialize_list(&list_head);

    puts("\nAfter initialization:");
    print_list(list_head);

    free(list_head);

    return 0;
}