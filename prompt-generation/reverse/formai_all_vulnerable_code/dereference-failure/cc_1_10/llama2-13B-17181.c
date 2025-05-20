//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define N 100
#define M 10

struct node {
    int data;
    struct node *next;
};

struct list {
    struct node *head;
};

void init_list(struct list *list) {
    int i;
    for (i = 0; i < N; i++) {
        struct node *new_node = malloc(sizeof(struct node));
        new_node->data = i % M;
        new_node->next = list->head;
        list->head = new_node;
    }
}

void print_list(struct list *list) {
    struct node *current = list->head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void insert_node(struct list *list, int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
}

int main() {
    struct list list;
    init_list(&list);
    print_list(&list);

    for (int i = 0; i < N; i++) {
        insert_node(&list, i % M);
    }

    print_list(&list);

    return 0;
}