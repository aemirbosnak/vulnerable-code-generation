//GEMINI-pro DATASET v1.0 Category: Educational ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// A linked list node
typedef struct node {
    int data;
    struct node *next;
} node;

// A linked list
typedef struct list {
    node *head;
    node *tail;
    int size;
} list;

// Create a new list
list *new_list() {
    list *l = malloc(sizeof(list));
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
    return l;
}

// Insert an element at the head of the list
void insert_head(list *l, int data) {
    node *n = malloc(sizeof(node));
    n->data = data;
    n->next = l->head;
    l->head = n;
    if (l->tail == NULL) {
        l->tail = n;
    }
    l->size++;
}

// Insert an element at the tail of the list
void insert_tail(list *l, int data) {
    node *n = malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    if (l->tail == NULL) {
        l->head = n;
        l->tail = n;
    } else {
        l->tail->next = n;
        l->tail = n;
    }
    l->size++;
}

// Remove an element from the head of the list
int remove_head(list *l) {
    if (l->head == NULL) {
        return -1;
    }
    int data = l->head->data;
    node *n = l->head;
    l->head = l->head->next;
    if (l->head == NULL) {
        l->tail = NULL;
    }
    free(n);
    l->size--;
    return data;
}

// Remove an element from the tail of the list
int remove_tail(list *l) {
    if (l->tail == NULL) {
        return -1;
    }
    int data = l->tail->data;
    node *n = l->tail;
    if (l->tail == l->head) {
        l->head = NULL;
        l->tail = NULL;
    } else {
        node *p = l->head;
        while (p->next != l->tail) {
            p = p->next;
        }
        p->next = NULL;
        l->tail = p;
    }
    free(n);
    l->size--;
    return data;
}

// Get the size of the list
int size(list *l) {
    return l->size;
}

// Print the list
void print(list *l) {
    node *n = l->head;
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

// Free the list
void free_list(list *l) {
    while (l->head != NULL) {
        node *n = l->head;
        l->head = l->head->next;
        free(n);
    }
    free(l);
}

int main() {
    list *l = new_list();
    insert_head(l, 1);
    insert_tail(l, 2);
    insert_head(l, 3);
    insert_tail(l, 4);
    insert_head(l, 5);
    print(l); // 5 3 1 2 4
    printf("Size: %d\n", size(l)); // 5
    remove_head(l); // 3 1 2 4
    remove_tail(l); // 3 1 2
    print(l);
    free_list(l);
    return 0;
}