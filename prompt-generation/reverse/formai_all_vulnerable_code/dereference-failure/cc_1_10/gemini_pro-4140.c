//GEMINI-pro DATASET v1.0 Category: Error handling ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct list {
    node *head;
    node *tail;
    int size;
} list;

void print_list(list *l) {
    node *current = l->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    list *l = malloc(sizeof(list));
    if (l == NULL) {
        fprintf(stderr, "Error: could not allocate memory for list.\n");
        exit(1);
    }
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;

    // add some nodes to the list
    for (int i = 0; i < 10; i++) {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL) {
            fprintf(stderr, "Error: could not allocate memory for node.\n");
            exit(1);
        }
        new_node->data = i;
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

    // print the list
    print_list(l);

    // free the list
    node *current = l->head;
    while (current != NULL) {
        node *next = current->next;
        free(current);
        current = next;
    }
    free(l);

    return 0;
}