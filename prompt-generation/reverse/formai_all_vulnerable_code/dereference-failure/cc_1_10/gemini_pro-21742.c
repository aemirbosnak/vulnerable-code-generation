//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct list {
    node *head;
    node *tail;
    int size;
} list;

void init_list(list *l) {
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
}

void add_to_list(list *l, int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (l->head == NULL) {
        l->head = new_node;
        l->tail = new_node;
    } else {
        l->tail->next = new_node;
        l->tail = new_node;
    }

    l->size++;
}

void remove_from_list(list *l, int data) {
    node *current = l->head;
    node *previous = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (previous == NULL) {
                l->head = current->next;
            } else {
                previous->next = current->next;
            }

            if (current == l->tail) {
                l->tail = previous;
            }

            free(current);
            l->size--;
            return;
        }

        previous = current;
        current = current->next;
    }
}

void print_list(list *l) {
    node *current = l->head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    list l;
    init_list(&l);

    add_to_list(&l, 1);
    add_to_list(&l, 2);
    add_to_list(&l, 3);
    add_to_list(&l, 4);
    add_to_list(&l, 5);

    print_list(&l);

    remove_from_list(&l, 3);

    print_list(&l);

    return 0;
}