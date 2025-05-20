//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: detailed
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
} list;

void create_list(list *l) {
    l->head = NULL;
    l->tail = NULL;
}

void insert_at_head(list *l, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = l->head;
    l->head = new_node;
    if (l->tail == NULL) {
        l->tail = new_node;
    }
}

void insert_at_tail(list *l, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (l->tail == NULL) {
        l->head = new_node;
        l->tail = new_node;
    } else {
        l->tail->next = new_node;
        l->tail = new_node;
    }
}

void delete_at_head(list *l) {
    if (l->head == NULL) {
        return;
    } else {
        node *temp = l->head;
        l->head = l->head->next;
        free(temp);
        if (l->head == NULL) {
            l->tail = NULL;
        }
    }
}

void delete_at_tail(list *l) {
    if (l->tail == NULL) {
        return;
    } else if (l->head == l->tail) {
        free(l->head);
        l->head = NULL;
        l->tail = NULL;
    } else {
        node *temp = l->head;
        while (temp->next != l->tail) {
            temp = temp->next;
        }
        free(l->tail);
        l->tail = temp;
        l->tail->next = NULL;
    }
}

void print_list(list *l) {
    node *temp = l->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    list l;
    create_list(&l);

    insert_at_head(&l, 1);
    insert_at_head(&l, 2);
    insert_at_tail(&l, 3);
    insert_at_tail(&l, 4);

    print_list(&l);  // Output: 2 1 3 4

    delete_at_head(&l);
    delete_at_tail(&l);

    print_list(&l);  // Output: 1 3

    return 0;
}