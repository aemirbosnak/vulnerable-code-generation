//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *email;
    struct node *next;
} node;

node *create_node(char *email) {
    node *new_node = malloc(sizeof(node));
    new_node->email = strdup(email);
    new_node->next = NULL;
    return new_node;
}

void insert_node(node **head, node *new_node) {
    if (*head == NULL) {
        *head = new_node;
    } else {
        insert_node(&(*head)->next, new_node);
    }
}

void print_node(node *head) {
    if (head == NULL) {
        return;
    } else {
        printf("%s\n", head->email);
        print_node(head->next);
    }
}

node *find_node(node *head, char *email) {
    if (head == NULL) {
        return NULL;
    } else if (strcmp(head->email, email) == 0) {
        return head;
    } else {
        return find_node(head->next, email);
    }
}

void delete_node(node **head, node *to_delete) {
    if (*head == NULL) {
        return;
    } else if (*head == to_delete) {
        *head = (*head)->next;
        free(to_delete);
    } else {
        delete_node(&(*head)->next, to_delete);
    }
}

int main() {
    node *head = NULL;
    insert_node(&head, create_node("alice@example.com"));
    insert_node(&head, create_node("bob@example.com"));
    insert_node(&head, create_node("charlie@example.com"));
    print_node(head);
    node *found_node = find_node(head, "bob@example.com");
    if (found_node != NULL) {
        printf("Found node: %s\n", found_node->email);
    } else {
        printf("Node not found.\n");
    }
    delete_node(&head, found_node);
    print_node(head);
    return 0;
}