//FormAI DATASET v1.0 Category: Linked list operations ; Style: unmistakable
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* create_node(int data) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_node(Node** head_ref, int data) {
    Node* new_node = create_node(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void delete_node(Node** head_ref, int data) {
    Node* current = *head_ref, *prev = NULL;
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Node not found\n");
        return;
    }
    if (prev == NULL) {
        *head_ref = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
}

void print_list(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    insert_node(&head, 1);
    insert_node(&head, 2);
    insert_node(&head, 3);
    insert_node(&head, 4);
    printf("List after inserting 1, 2, 3, 4: ");
    print_list(head);
    delete_node(&head, 3);
    printf("List after deleting node with data 3: ");
    print_list(head);
    return 0;
}