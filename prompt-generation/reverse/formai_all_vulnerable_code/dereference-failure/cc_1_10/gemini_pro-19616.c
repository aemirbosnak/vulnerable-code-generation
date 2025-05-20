//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *data;
    struct node *next;
} node;

node *create_node(char *data) {
    node *new_node = malloc(sizeof(node));
    new_node->data = strdup(data);
    new_node->next = NULL;
    return new_node;
}

void print_node(node *n) {
    printf("%s", n->data);
}

void print_list(node *head) {
    node *current = head;
    while (current != NULL) {
        print_node(current);
        current = current->next;
    }
}

void free_list(node *head) {
    node *current = head;
    while (current != NULL) {
        node *next = current->next;
        free(current->data);
        free(current);
        current = next;
    }
}

int main() {
    node *head = create_node("<!DOCTYPE html>");
    node *body = create_node("<body>");
    node *h1 = create_node("<h1>Hello, world!</h1>");
    node *p = create_node("<p>This is a paragraph.</p>");
    node *ul = create_node("<ul>");
    node *li1 = create_node("<li>Item 1</li>");
    node *li2 = create_node("<li>Item 2</li>");
    node *li3 = create_node("<li>Item 3</li>");

    head->next = body;
    body->next = h1;
    h1->next = p;
    p->next = ul;
    ul->next = li1;
    li1->next = li2;
    li2->next = li3;

    print_list(head);

    free_list(head);

    return 0;
}