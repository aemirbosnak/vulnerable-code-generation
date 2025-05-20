//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *name;
    double amount;
    struct node *next;
} node;

node *create_node(char *name, double amount) {
    node *new_node = malloc(sizeof(node));
    new_node->name = strdup(name);
    new_node->amount = amount;
    new_node->next = NULL;
    return new_node;
}

void add_node(node **head, node *new_node) {
    if (*head == NULL) {
        *head = new_node;
    } else {
        add_node(&(*head)->next, new_node);
    }
}

void print_list(node *head) {
    if (head == NULL) {
        return;
    } else {
        printf("%s: %.2f\n", head->name, head->amount);
        print_list(head->next);
    }
}

void free_list(node *head) {
    if (head == NULL) {
        return;
    } else {
        free_list(head->next);
        free(head->name);
        free(head);
    }
}

int main() {
    node *head = NULL;
    char *name;
    double amount;
    int choice;

    do {
        printf("1. Add an expense\n");
        printf("2. Print the list of expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the expense: ");
                scanf(" %s", name);
                printf("Enter the amount of the expense: ");
                scanf("%lf", &amount);
                add_node(&head, create_node(name, amount));
                break;
            case 2:
                print_list(head);
                break;
            case 3:
                free_list(head);
                exit(0);
        }
    } while (choice != 3);

    return 0;
}