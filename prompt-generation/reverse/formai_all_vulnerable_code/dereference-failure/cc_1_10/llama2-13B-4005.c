//LLAMA2-13B DATASET v1.0 Category: Linked list operations ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

struct node {
    int data;
    struct node *next;
};

struct list {
    struct node *head;
};

void add_node(struct list *list, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
}

int get_node(struct list *list, int data) {
    struct node *current = list->head;
    while (current != NULL && current->data != data) {
        current = current->next;
    }
    return current;
}

void remove_node(struct list *list, int data) {
    struct node *current = list->head;
    struct node *prev = NULL;

    while (current != NULL) {
        if (current->data == data) {
            if (prev == NULL) {
                list->head = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

int main() {
    struct list *list = (struct list *)malloc(sizeof(struct list));
    add_node(list, 1);
    add_node(list, 2);
    add_node(list, 3);
    add_node(list, 4);

    struct node *node = get_node(list, 2);
    if (node != NULL) {
        printf("Found node with data %d\n", node->data);
    } else {
        printf("Node not found\n");
    }

    remove_node(list, 3);

    node = get_node(list, 2);
    if (node != NULL) {
        printf("Found node with data %d\n", node->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}