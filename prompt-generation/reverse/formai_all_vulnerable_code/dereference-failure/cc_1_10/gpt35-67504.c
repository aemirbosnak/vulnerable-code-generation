//FormAI DATASET v1.0 Category: Data structures visualization ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void add_node(struct node **head, int data) {
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_list(struct node *head) {
    printf("--------------\n");
    printf("|     HEAD     |\n");
    printf("--------------\n");
    struct node *temp = head;
    while (temp != NULL) {
        printf("|     %-4d     |\n", temp->data);
        printf("--------------\n");
        temp = temp->next;
    }
    printf("|     NULL     |\n");
    printf("--------------\n");
}

int main() {
    struct node *head = NULL;

    add_node(&head, 1);
    add_node(&head, 2);
    add_node(&head, 3);
    add_node(&head, 4);
    add_node(&head, 5);

    print_list(head);

    return 0;
}