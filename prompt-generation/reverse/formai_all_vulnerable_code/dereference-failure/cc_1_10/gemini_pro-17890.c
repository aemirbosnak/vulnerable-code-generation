//GEMINI-pro DATASET v1.0 Category: Fibonacci Sequence Visualizer ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct list {
    node *head;
    node *tail;
    int size;
} list;

void push(list *l, int data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (l->size == 0) {
        l->head = new_node;
        l->tail = new_node;
    } else {
        l->tail->next = new_node;
        l->tail = new_node;
    }

    l->size++;
}

void print_list(list *l) {
    node *current = l->head;

    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");
}

void free_list(list *l) {
    node *current = l->head;

    while (current != NULL) {
        node *next = current->next;
        free(current);
        current = next;
    }

    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
}

int main() {
    srand(time(NULL));

    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    list *l = malloc(sizeof(list));
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;

    int a = 0;
    int b = 1;
    int c;

    for (int i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
        push(l, c);
    }

    printf("The Fibonacci sequence is: ");
    print_list(l);

    free_list(l);
    free(l);

    return 0;
}