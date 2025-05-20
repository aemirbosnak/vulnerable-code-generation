//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold the HTML tags
typedef struct tag {
    char *name;
    char *attrs;
    struct tag *children;
    struct tag *next;
} tag;

// Function to create a new HTML tag
tag *new_tag(char *name, char *attrs) {
    tag *t = malloc(sizeof(tag));
    t->name = strdup(name);
    t->attrs = strdup(attrs);
    t->children = NULL;
    t->next = NULL;
    return t;
}

// Function to add a child tag to a parent tag
void add_child(tag *parent, tag *child) {
    if (parent->children == NULL) {
        parent->children = child;
    } else {
        tag *tmp = parent->children;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = child;
    }
}

// Function to print the HTML tags
void print_tags(tag *t) {
    if (t == NULL) {
        return;
    }
    printf("<%s %s>", t->name, t->attrs);
    if (t->children != NULL) {
        print_tags(t->children);
    }
    printf("</%s>", t->name);
}

// Main function
int main() {
    // Create the root tag
    tag *root = new_tag("html", "");

    // Add the head tag
    tag *head = new_tag("head", "");
    add_child(root, head);

    // Add the title tag
    tag *title = new_tag("title", "");
    add_child(head, title);

    // Add the body tag
    tag *body = new_tag("body", "");
    add_child(root, body);

    // Add the h1 tag
    tag *h1 = new_tag("h1", "");
    add_child(body, h1);

    // Add the p tag
    tag *p = new_tag("p", "");
    add_child(body, p);

    // Print the HTML tags
    print_tags(root);

    return 0;
}