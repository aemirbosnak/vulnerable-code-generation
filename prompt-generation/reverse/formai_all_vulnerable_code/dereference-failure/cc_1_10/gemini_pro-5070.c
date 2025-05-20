//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

/* A node in a linked list. */
struct node {
    int data;
    struct node *next;
};

/* A linked list. */
struct list {
    struct node *head;
    struct node *tail;
};

/* Create a new linked list. */
struct list *create_list() {
    struct list *list = malloc(sizeof(struct list));
    if (!list) {
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

/* Insert a new node into a linked list. */
void insert_node(struct list *list, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    if (!new_node) {
        return;
    }
    new_node->data = data;
    new_node->next = NULL;
    if (!list->head) {
        list->head = new_node;
    } else {
        list->tail->next = new_node;
    }
    list->tail = new_node;
}

/* Print a linked list. */
void print_list(struct list *list) {
    struct node *current = list->head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

/* Free a linked list. */
void free_list(struct list *list) {
    struct node *current = list->head;
    while (current) {
        struct node *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

int main() {
    struct list *list = create_list();
    insert_node(list, 1);
    insert_node(list, 2);
    insert_node(list, 3);
    print_list(list);
    free_list(list);
    return 0;
}