//FormAI DATASET v1.0 Category: Linked list operations ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

void add(Node** head, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

void display(Node* head) {
    printf("List: ");
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void remove_node(Node** head, int value) {
    Node* current = *head;
    Node* previous = NULL;
    while (current != NULL) {
        if (current->data == value) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Value %d not found.\n", value);
}

void reverse(Node** head) {
    Node* previous = NULL;
    Node* current = *head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    *head = previous;
}

int main() {
    Node* head = NULL;
    add(&head, 8);
    add(&head, 5);
    add(&head, 3);
    add(&head, 1);
    display(head);
    remove_node(&head, 5);
    display(head);
    reverse(&head);
    display(head);
    return 0;
}