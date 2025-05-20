//FormAI DATASET v1.0 Category: Data structures visualization ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

typedef struct node {  // define a node struct to represent elements in the linked list
    int data;
    struct node* next;
} node;

typedef struct list {  // define a list struct to represent the linked list
    node* head;
    int num_items;
} list;

// function to insert element at the beginning of the linked list
void insert(list* lst, int value) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = value;
    new_node->next = lst->head;
    lst->head = new_node;
    lst->num_items++;
}

// function to delete first occurrence of element in the linked list
void delete(list* lst, int value) {
    node* current = lst->head;
    node* previous = NULL;

    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Element not found\n");
        return;
    }

    if (previous == NULL) {
        lst->head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    lst->num_items--;
}

// function to display the linked list
void display(list* lst) {
    node* current = lst->head;
    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    list lst = { .head = NULL, .num_items = 0 };

    printf("Initial list: ");
    display(&lst);

    insert(&lst, 5);
    insert(&lst, 10);
    insert(&lst, 15);
    insert(&lst, 20);

    printf("List after insertions: ");
    display(&lst);

    delete(&lst, 10);

    printf("List after deletion of 10: ");
    display(&lst);

    return 0;
}