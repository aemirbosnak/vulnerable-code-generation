//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node;

node *push(node *head, int val) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->val = val;
    new_node->next = head;
    return new_node;
}

node *pop(node *head) {
    if (head == NULL) {
        return NULL;
    }
    node *new_head = head->next;
    free(head);
    return new_head;
}

void print_list(node *head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

void hanoi(int n, node **from, node **to, node **aux) {
    if (n == 1) {
        node *disk = pop(*from);
        *to = push(*to, disk->val);
        free(disk);
    } else {
        hanoi(n - 1, from, aux, to);
        node *disk = pop(*from);
        *to = push(*to, disk->val);
        free(disk);
        hanoi(n - 1, aux, to, from);
    }
}

int main() {
    int n = 3;
    node *from = NULL;
    node *to = NULL;
    node *aux = NULL;

    for (int i = n; i >= 1; i--) {
        from = push(from, i);
    }

    hanoi(n, &from, &to, &aux);

    print_list(to);

    return 0;
}