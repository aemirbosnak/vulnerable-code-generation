//GEMINI-pro DATASET v1.0 Category: Pattern printing ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct list {
    node *head;
    node *tail;
    int size;
} list;

void insert_at_beginning(list *l, int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = l->head;
    l->head = new_node;
    l->size++;
}

void insert_at_end(list *l, int data) {
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
    l->size++;
}

void insert_at_index(list *l, int data, int index) {
    if (index == 0) {
        insert_at_beginning(l, data);
        return;
    }
    if (index == l->size) {
        insert_at_end(l, data);
        return;
    }
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    node *current = l->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    l->size++;
}

void delete_at_beginning(list *l) {
    if (l->size == 0) {
        return;
    }
    node *current = l->head;
    l->head = current->next;
    free(current);
    l->size--;
}

void delete_at_end(list *l) {
    if (l->size == 0) {
        return;
    }
    node *current = l->head;
    while (current->next != l->tail) {
        current = current->next;
    }
    free(l->tail);
    current->next = NULL;
    l->tail = current;
    l->size--;
}

void delete_at_index(list *l, int index) {
    if (index == 0) {
        delete_at_beginning(l);
        return;
    }
    if (index == l->size - 1) {
        delete_at_end(l);
        return;
    }
    node *current = l->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    node *temp = current->next;
    current->next = temp->next;
    free(temp);
    l->size--;
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
    l.size = 0;
    insert_at_end(&l, 1);
    insert_at_end(&l, 2);
    insert_at_end(&l, 3);
    insert_at_end(&l, 4);
    insert_at_end(&l, 5);
    print_list(&l);
    delete_at_beginning(&l);
    delete_at_end(&l);
    delete_at_index(&l, 2);
    print_list(&l);
    return 0;
}