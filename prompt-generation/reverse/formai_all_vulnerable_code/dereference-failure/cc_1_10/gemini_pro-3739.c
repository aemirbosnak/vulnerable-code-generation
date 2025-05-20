//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A struct to represent a node in the parse tree.
typedef struct node {
    char *tag;
    struct node *parent;
    struct node *children;
    struct node *next;
} node;

// A struct to represent the parse tree.
typedef struct tree {
    node *root;
} tree;

// A function to create a new node.
node *new_node(char *tag) {
    node *n = malloc(sizeof(node));
    n->tag = tag;
    n->parent = NULL;
    n->children = NULL;
    n->next = NULL;
    return n;
}

// A function to add a child to a node.
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
}

// A function to parse an HTML document.
tree *parse_html(char *html) {
    tree *t = malloc(sizeof(tree));
    t->root = new_node("html");

    node *current = t->root;

    char *start = html;
    char *end = html;

    while (*end != '\0') {
        // Skip whitespace
        while (*end == ' ' || *end == '\t' || *end == '\n') {
            end++;
        }

        // If we're at the end of the document, we're done.
        if (*end == '\0') {
            break;
        }

        // If we're at the start of a tag, create a new node.
        if (*end == '<') {
            start = end + 1;
            end = start;

            while (*end != '>' && *end != '\0') {
                end++;
            }

            if (*end == '\0') {
                break;
            }

            char *tag = malloc(end - start + 1);
            strncpy(tag, start, end - start);
            tag[end - start] = '\0';

            node *n = new_node(tag);
            add_child(current, n);
            current = n;

            end++;
        }

        // If we're at the end of a tag, move up the tree.
        else if (*end == '>') {
            current = current->parent;
            end++;
        }

        // Otherwise, we're in the middle of a text node.
        else {
            start = end;
            end++;

            while (*end != '<' && *end != '\0') {
                end++;
            }

            char *text = malloc(end - start + 1);
            strncpy(text, start, end - start);
            text[end - start] = '\0';

            node *n = new_node(text);
            add_child(current, n);
        }
    }

    return t;
}

// A function to print the parse tree.
void print_tree(tree *t) {
    node *current = t->root;

    while (current != NULL) {
        printf("%s", current->tag);

        if (current->children != NULL) {
            printf("(");
            print_tree(current->children);
            printf(")");
        }

        current = current->next;
    }
}

// A function to free the parse tree.
void free_tree(tree *t) {
    node *current = t->root;

    while (current != NULL) {
        node *next = current->next;
        free(current->tag);
        free(current);
        current = next;
    }

    free(t);
}

int main() {
    // Parse the HTML document.
    tree *t = parse_html("<html><head><title>Hello World</title></head><body><h1>Hello World</h1></body></html>");

    // Print the parse tree.
    print_tree(t);

    // Free the parse tree.
    free_tree(t);

    return 0;
}