//MISTRAL-7B DATASET v1.0 Category: Data structures visualization ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void print_list(Node* head) {
    Node* current = head;
    int i = 0;

    printf("Linked List Visualization:\n");
    while (current != NULL) {
        printf("[%d] -> ", current->data);
        current = current->next;
        i++;
        if (i >= SIZE) {
            printf("...\n");
            break;
        }
    }
    printf("\n");
}

void push(Node** head_ref, int new_data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    Node* head = NULL;

    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 5);
    push(&head, 4);

    printf("Linked List:\n");
    print_list(head);

    free(head);

    return 0;
}