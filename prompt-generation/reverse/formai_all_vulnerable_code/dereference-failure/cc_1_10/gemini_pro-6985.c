//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

void push(node_t **head, int data)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
}

int pop(node_t **head)
{
    if (*head == NULL) {
        return -1;
    }

    int data = (*head)->data;
    node_t *temp = *head;
    *head = (*head)->next;
    free(temp);

    return data;
}

void print_list(node_t *head)
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void tower_of_hanoi(int n, node_t **source, node_t **destination, node_t **auxiliary)
{
    if (n == 1) {
        push(destination, pop(source));
        return;
    }

    tower_of_hanoi(n - 1, source, auxiliary, destination);
    push(destination, pop(source));
    tower_of_hanoi(n - 1, auxiliary, destination, source);
}

int main()
{
    int n;
    node_t *source = NULL;
    node_t *destination = NULL;
    node_t *auxiliary = NULL;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    for (int i = n; i >= 1; i--) {
        push(&source, i);
    }

    printf("Initial state of the tower:\n");
    print_list(source);
    print_list(destination);
    print_list(auxiliary);

    tower_of_hanoi(n, &source, &destination, &auxiliary);

    printf("\nFinal state of the tower:\n");
    print_list(source);
    print_list(destination);
    print_list(auxiliary);

    return 0;
}