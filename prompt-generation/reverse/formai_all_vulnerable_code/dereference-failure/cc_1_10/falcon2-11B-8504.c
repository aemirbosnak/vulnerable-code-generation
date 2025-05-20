//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert_node(Node** head_ref, int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void delete_node(Node** head_ref, int data) {
    Node* current = *head_ref;
    Node* prev = NULL;

    while (current!= NULL && current->data!= data) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    if (prev == NULL) {
        *head_ref = current->next;
        free(current);
        return;
    }

    prev->next = current->next;
    free(current);
}

void print_linked_list(Node* head) {
    Node* current = head;

    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    insert_node(&head, 4);
    insert_node(&head, 5);

    print_linked_list(head);

    printf("\nDeleting node with data 3...\n");
    delete_node(&head, 3);

    print_linked_list(head);

    return 0;
}