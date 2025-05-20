//FormAI DATASET v1.0 Category: Linked list operations ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void print_list(struct node *head) {
    struct node *current = head;
    while(current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_node(struct node **head, int data) {
    struct node *new_node = create_node(data);
    if(*head == NULL) {
        *head = new_node;
    } else {
        struct node *current = *head;
        while(current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void delete_node(struct node **head, int data) {
    struct node *current = *head;
    struct node *prev = NULL;
    while(current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    if(current == NULL) {
        printf("Element not found in list\n");
        return;
    }
    if(prev == NULL) {
        *head = current->next;
    } else {
        prev->next = current->next;
    }
    free(current);
}

int main() {
    struct node *head = NULL;
    insert_node(&head, 5);
    insert_node(&head, 10);
    insert_node(&head, 15);
    printf("Linked List after insertion: ");
    print_list(head);
    delete_node(&head, 10);
    printf("Linked List after deletion: ");
    print_list(head);
    return 0;
}