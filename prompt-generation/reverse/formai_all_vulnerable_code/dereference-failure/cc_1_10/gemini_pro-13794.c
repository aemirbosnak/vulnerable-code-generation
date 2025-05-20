//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the HTML tree
typedef struct node {
    char *tag;
    char *content;
    struct node *next;
    struct node *children;
} node;

// Function to create a new node
node *create_node(char *tag, char *content) {
    node *new_node = malloc(sizeof(node));
    new_node->tag = strdup(tag);
    new_node->content = strdup(content);
    new_node->next = NULL;
    new_node->children = NULL;
    return new_node;
}

// Function to add a child node to a parent node
void add_child(node *parent, node *child) {
    if (parent->children == NULL) {
        parent->children = child;
    } else {
        node *current = parent->children;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = child;
    }
}

// Function to print the HTML tree
void print_html(node *root) {
    if (root == NULL) {
        return;
    }

    printf("<%s>", root->tag);
    if (root->content != NULL) {
        printf("%s", root->content);
    }

    if (root->children != NULL) {
        print_html(root->children);
    }

    printf("</%s>", root->tag);
}

// Function to beautify the HTML tree
void beautify_html(node *root) {
    if (root == NULL) {
        return;
    }

    // Add a newline before the opening tag
    printf("\n<%s>", root->tag);

    // If the node has content, add a newline after the opening tag
    if (root->content != NULL) {
        printf("\n%s", root->content);
    }

    // If the node has children, beautify them
    if (root->children != NULL) {
        beautify_html(root->children);
    }

    // Add a newline before the closing tag
    printf("\n</%s>", root->tag);
}

// Main function
int main() {
    // Create the root node of the HTML tree
    node *root = create_node("html", NULL);

    // Add some child nodes to the root node
    add_child(root, create_node("head", NULL));
    add_child(root, create_node("body", NULL));

    // Add some child nodes to the head node
    add_child(root->children, create_node("title", "My Website"));

    // Add some child nodes to the body node
    add_child(root->children->next, create_node("h1", "Welcome to my website"));
    add_child(root->children->next, create_node("p", "This is my website. It is still under construction, but I hope you enjoy it."));

    // Print the HTML tree
    print_html(root);

    // Beautify the HTML tree
    beautify_html(root);

    return 0;
}