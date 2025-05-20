//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

struct list {
    struct node *head;
    struct node *tail;
    int size;
};

void push(struct list *list, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

void print_list(struct list *list) {
    struct node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void free_list(struct list *list) {
    struct node *current = list->head;
    while (current != NULL) {
        struct node *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

int main() {
    struct list *list = malloc(sizeof(struct list));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    push(list, 1);
    push(list, 2);
    push(list, 3);
    push(list, 4);
    push(list, 5);

    print_list(list);

    free_list(list);

    return 0;
}