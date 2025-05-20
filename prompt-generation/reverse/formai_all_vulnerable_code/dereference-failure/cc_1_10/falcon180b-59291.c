//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Node structure for the XML tree
typedef struct node {
    char *name;
    char *value;
    struct node *child;
    struct node *next;
} Node;

// Function prototypes
Node *create_node(char *name, char *value);
Node *add_child(Node *parent, Node *child);
void print_node(Node *node, int depth);

int main(int argc, char **argv) {
    FILE *file;
    char buffer[1024];
    Node *root = NULL;
    Node *current = NULL;
    int depth = 0;

    // Open the XML file
    if (argc!= 2) {
        printf("Usage: %s <xml_file>\n", argv[0]);
        return 1;
    }
    file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Parse the XML file
    while (fgets(buffer, sizeof(buffer), file)!= NULL) {
        if (buffer[0] == '<') {
            // Start of a new tag
            if (current!= NULL) {
                current->next = create_node("", "");
                current = current->next;
            }
            char *name = strtok(buffer, " ");
            char *value = strtok(NULL, " ");
            if (name == NULL || value == NULL) {
                printf("Invalid tag.\n");
                return 1;
            }
            current = create_node(name, value);
        } else if (buffer[0] == '>') {
            // End of a tag
            if (current == NULL) {
                printf("Invalid tag.\n");
                return 1;
            }
            current->child = create_node("", "");
            current = current->child;
        } else {
            // Text content
            if (current == NULL) {
                printf("Invalid text.\n");
                return 1;
            }
            if (current->value!= NULL) {
                printf("Duplicate content.\n");
                return 1;
            }
            current->value = strdup(buffer);
        }
    }

    // Print the XML tree
    print_node(root, 0);

    return 0;
}

// Create a new node with the given name and value
Node *create_node(char *name, char *value) {
    Node *node = malloc(sizeof(Node));
    node->name = name!= NULL? strdup(name) : NULL;
    node->value = value!= NULL? strdup(value) : NULL;
    node->child = NULL;
    node->next = NULL;
    return node;
}

// Add a child node to the given parent node
Node *add_child(Node *parent, Node *child) {
    child->next = parent->child;
    parent->child = child;
    return child;
}

// Print the given node and its children recursively
void print_node(Node *node, int depth) {
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    if (node->name!= NULL) {
        printf("%s", node->name);
    } else {
        printf("(text)");
    }
    if (node->value!= NULL) {
        printf("=\"%s\"", node->value);
    }
    printf(">\n");
    depth++;
    Node *child = node->child;
    while (child!= NULL) {
        print_node(child, depth);
        child = child->next;
    }
    depth--;
    printf("</%s>\n", node->name);
}