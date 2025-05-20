//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char *tag;
    struct node *parent;
    struct node *children;
    struct node *next;
} node;

node *create_node(char *tag) {
    node *n = malloc(sizeof(node));
    n->tag = strdup(tag);
    n->parent = NULL;
    n->children = NULL;
    n->next = NULL;
    return n;
}

void add_child(node *parent, node *child) {
    if (parent->children == NULL) {
        parent->children = child;
    } else {
        node *last = parent->children;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = child;
    }
    child->parent = parent;
}

void print_node(node *n) {
    printf("<%s>", n->tag);
    if (n->children != NULL) {
        print_node(n->children);
    }
    printf("</%s>", n->tag);
}

void print_tree(node *n) {
    print_node(n);
    if (n->next != NULL) {
        print_tree(n->next);
    }
}

int main() {
    node *html = create_node("html");
    node *head = create_node("head");
    node *title = create_node("title");
    node *body = create_node("body");
    node *p = create_node("p");
    node *strong = create_node("strong");

    add_child(html, head);
    add_child(html, body);
    add_child(head, title);
    add_child(body, p);
    add_child(p, strong);

    strcpy(title->tag, "My Title");
    strcpy(p->tag, "This is a paragraph.");
    strcpy(strong->tag, "This is bold text.");

    print_tree(html);

    return 0;
}