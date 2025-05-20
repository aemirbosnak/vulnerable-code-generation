//GEMINI-pro DATASET v1.0 Category: Linked list operations ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} node;

typedef struct list {
    node *head;
    node *tail;
} list;

void print_list(list *l) {
    node *curr = l->head;
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    list romeo, juliet;

    // Initialize Romeo's list
    romeo.head = NULL;
    romeo.tail = NULL;

    // Initialize Juliet's list
    juliet.head = NULL;
    juliet.tail = NULL;

    // Add elements to Romeo's list
    node *n1 = malloc(sizeof(node));
    n1->data = 1;
    n1->next = NULL;
    n1->prev = NULL;
    if (romeo.head == NULL) {
        romeo.head = n1;
    } else {
        romeo.tail->next = n1;
        n1->prev = romeo.tail;
    }
    romeo.tail = n1;

    // Add elements to Juliet's list
    node *n2 = malloc(sizeof(node));
    n2->data = 2;
    n2->next = NULL;
    n2->prev = NULL;
    if (juliet.head == NULL) {
        juliet.head = n2;
    } else {
        juliet.tail->next = n2;
        n2->prev = juliet.tail;
    }
    juliet.tail = n2;

    // Print Romeo's list
    printf("Romeo's list:\n");
    print_list(&romeo);

    // Print Juliet's list
    printf("Juliet's list:\n");
    print_list(&juliet);

    // Merge Romeo and Juliet's lists
    romeo.tail->next = juliet.head;
    juliet.head->prev = romeo.tail;
    romeo.tail = juliet.tail;

    // Print the merged list
    printf("Merged list:\n");
    print_list(&romeo);

    // Free the list nodes
    node *curr, *prev;
    curr = romeo.head;
    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
        free(prev);
    }

    curr = juliet.head;
    while (curr != NULL) {
        prev = curr;
        curr = curr->next;
        free(prev);
    }

    return 0;
}