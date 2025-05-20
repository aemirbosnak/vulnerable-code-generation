//FormAI DATASET v1.0 Category: Data structures visualization ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 10

typedef struct node {
    int value;
    struct node *next;
} Node;

void init_list(Node **head) {
    *head = NULL;
}

void print_list(Node *head) {
    Node *ptr = head;
    while (ptr != NULL) {
        printf("%d ", ptr->value);
        ptr = ptr->next;
    }
    printf("\n");
}

void insert_front(Node **head, int value) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = *head;
    *head = new_node;
}

void shuffle(int *array, size_t n) {
    if (n > 1) {
        size_t i;
        for (i = 0; i < n - 1; i++) {
            size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
            int t = array[j];
            array[j] = array[i];
            array[i] = t;
        }
    }
}

int main() {
    Node *head;
    init_list(&head);

    int i;
    int values[LENGTH];
    srand(time(NULL));
    for (i = 0; i < LENGTH; i++) {
        values[i] = i + 1;
    }

    shuffle(values, LENGTH);
    for (i = 0; i < LENGTH; i++) {
        insert_front(&head, values[i]);
    }

    print_list(head);

    return 0;
}