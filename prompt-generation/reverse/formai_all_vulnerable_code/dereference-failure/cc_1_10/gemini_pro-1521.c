//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: portable
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct list {
    node *head;
    node *tail;
} list;

void push_front(list *l, int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = l->head;
    l->head = new_node;
    if (l->tail == NULL) {
        l->tail = new_node;
    }
}

void push_back(list *l, int data) {
    node *new_node = malloc(sizeof(node));
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

int pop_front(list *l) {
    if (l->head == NULL) {
        return -1;
    }
    int data = l->head->data;
    node *new_head = l->head->next;
    free(l->head);
    l->head = new_head;
    if (l->head == NULL) {
        l->tail = NULL;
    }
    return data;
}

int pop_back(list *l) {
    if (l->tail == NULL) {
        return -1;
    }
    int data = l->tail->data;
    node *new_tail = l->tail->next;
    free(l->tail);
    l->tail = new_tail;
    if (l->tail == NULL) {
        l->head = NULL;
    }
    return data;
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
    l.head = NULL;
    l.tail = NULL;
    push_front(&l, 1);
    push_front(&l, 2);
    push_front(&l, 3);
    push_back(&l, 4);
    push_back(&l, 5);
    push_back(&l, 6);
    print_list(&l);
    printf("Popped front: %d\n", pop_front(&l));
    printf("Popped back: %d\n", pop_back(&l));
    print_list(&l);
    return 0;
}