//Gemma-7B DATASET v1.0 Category: Data structures visualization ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct node {
    int data;
    struct node* next;
};

struct linked_list {
    struct node* head;
    struct node* tail;
};

void insert_at_tail(struct linked_list* ll, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (ll->head == NULL) {
        ll->head = new_node;
        ll->tail = new_node;
    } else {
        ll->tail->next = new_node;
        ll->tail = new_node;
    }
}

void traverse_list(struct linked_list* ll) {
    struct node* current = ll->head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct linked_list* ll = (struct linked_list*)malloc(sizeof(struct linked_list));
    ll->head = NULL;
    ll->tail = NULL;

    insert_at_tail(ll, 10);
    insert_at_tail(ll, 20);
    insert_at_tail(ll, 30);
    insert_at_tail(ll, 40);

    traverse_list(ll);

    free(ll);
    return 0;
}