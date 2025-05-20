//LLAMA2-13B DATASET v1.0 Category: Database querying ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 1024
#define MAGIC_NUMBER 42

struct node {
    int data;
    struct node *next;
};

struct list {
    struct node *head;
    struct node *tail;
};

void init_list(struct list *list) {
    list->head = NULL;
    list->tail = NULL;
}

void insert_node(struct list *list, int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

int find_node(struct list *list, int data) {
    struct node *current = list->head;

    while (current != NULL) {
        if (current->data == data) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

void print_list(struct list *list) {
    struct node *current = list->head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    struct list list;

    init_list(&list);

    insert_node(&list, 1);
    insert_node(&list, 2);
    insert_node(&list, 3);
    insert_node(&list, 4);
    insert_node(&list, 5);

    struct node *node = find_node(&list, 3);

    if (node != NULL) {
        printf("Found node with value 3\n");
    } else {
        printf("Node with value 3 not found\n");
    }

    print_list(&list);

    return 0;
}