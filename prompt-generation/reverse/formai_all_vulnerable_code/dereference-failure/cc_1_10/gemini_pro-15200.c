//GEMINI-pro DATASET v1.0 Category: Greedy Algorithms ; Style: funny
#include <stdio.h>
#include <stdlib.h>

typedef struct _node {
    int data;
    struct _node *next;
} node;

node *create_node(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void insert_node(node **head, int data) {
    node *new_node = create_node(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    node *head = NULL;
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        int data;
        printf("Enter the element: ");
        scanf("%d", &data);
        insert_node(&head, data);
    }
    printf("The original list is: ");
    print_list(head);
    node *current = head;
    node *previous = NULL;
    while (current != NULL) {
        if (current->data % 2 == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            current = previous->next;
        } else {
            previous = current;
            current = current->next;
        }
    }
    printf("The list after removing even numbers is: ");
    print_list(head);
    return 0;
}