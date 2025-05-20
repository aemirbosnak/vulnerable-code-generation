//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node* create_node(int data) {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_node(node **head, int data) {
    node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void delete_node(node **head, int data) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->data == data) {
        *head = (*head)->next;
        return;
    }

    node *current = *head;
    node *prev = NULL;
    while (current != NULL) {
        if (current->data == data) {
            prev->next = current->next;
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    srand(time(NULL));

    // Create a linked list of surreal numbers
    node *head = NULL;
    for (int i = 0; i < 10; i++) {
        insert_node(&head, rand() % 100);
    }

    // Print the linked list
    print_list(head);

    // Delete a surreal number from the linked list
    delete_node(&head, 5);

    // Print the linked list
    print_list(head);

    return 0;
}