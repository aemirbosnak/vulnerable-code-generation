//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void print_list(Node* head) {
    Node* current = head;
    int row = 0;
    int col = 0;

    while (current != NULL) {
        printf("\033[%d;%dH", row, col);
        if (current->data < 0) {
            printf("%c", '[');
            printf("%d", current->data);
            printf("%c", ']');
            printf("%c", ' ');
            printf("%c", 'R');
        } else {
            printf("%d", current->data);
        }

        col += 3;
        current = current->next;

        if (current != NULL) {
            printf("-> ");
            usleep(100000);
        }
    }

    printf("\033[%d;%dH|______|\n", row, col);
}

void append(Node** head_ref, int new_data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = NULL;

    Node* last = *head_ref;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

int main() {
    Node* head = NULL;

    append(&head, 5);
    append(&head, 2);
    append(&head, 7);
    append(&head, 1);
    append(&head, -3);

    print_list(head);

    return 0;
}