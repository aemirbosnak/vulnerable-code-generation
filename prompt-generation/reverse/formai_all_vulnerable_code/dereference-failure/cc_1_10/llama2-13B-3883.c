//LLAMA2-13B DATASET v1.0 Category: Memory management ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAGIC_NUMBER 42

struct node {
    int data;
    struct node *next;
};

struct list {
    struct node *head;
};

void init_list(struct list *list) {
    list->head = NULL;
}

void push(struct list *list, int data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = list->head;
    list->head = new_node;
}

int pop(struct list *list) {
    int data = list->head->data;
    list->head = list->head->next;
    free(list->head);
    list->head = NULL;
    return data;
}

int main() {
    struct list list;

    srand(time(NULL));

    for (int i = 0; i < 100; i++) {
        int data = rand() % 10;
        push(&list, data);
    }

    for (int i = 0; i < 100; i++) {
        int data = pop(&list);
        printf("%d ", data);
    }

    return 0;
}