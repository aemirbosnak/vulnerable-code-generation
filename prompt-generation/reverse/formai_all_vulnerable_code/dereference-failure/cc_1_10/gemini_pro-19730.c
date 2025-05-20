//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *name;
    char *email;
    struct node *next;
} node;

node *create_node(char *name, char *email) {
    node *new_node = malloc(sizeof(node));
    new_node->name = strdup(name);
    new_node->email = strdup(email);
    new_node->next = NULL;
    return new_node;
}

void add_to_list(node **head, node *new_node) {
    if (*head == NULL) {
        *head = new_node;
    } else {
        add_to_list(&(*head)->next, new_node);
    }
}

void print_list(node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
    } else {
        printf("%s (%s)\n", head->name, head->email);
        print_list(head->next);
    }
}

void delete_node(node **head, char *name) {
    if (*head == NULL) {
        printf("The list is empty.\n");
    } else if (strcmp((*head)->name, name) == 0) {
        node *temp = *head;
        *head = (*head)->next;
        free(temp->name);
        free(temp->email);
        free(temp);
    } else {
        delete_node(&(*head)->next, name);
    }
}

int main() {
    node *head = NULL;

    add_to_list(&head, create_node("John", "john@example.com"));
    add_to_list(&head, create_node("Jane", "jane@example.com"));
    add_to_list(&head, create_node("Bob", "bob@example.com"));

    print_list(head);

    delete_node(&head, "John");

    print_list(head);

    return 0;
}