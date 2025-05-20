//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char *name;
    char *value;
} attribute;

typedef struct {
    char *name;
    attribute *attributes;
    int num_attributes;
    char *text;
    struct element_node *children;
    struct element_node *next_sibling;
    struct element_node *parent;
} element_node;

void parse_node(char *node, element_node *curr_node) {

    char *token = strtok(node, " ");

    if (token[0] == '<' && token[1] != '/') {
        // New element
        curr_node->name = strdup(&token[1]);
        curr_node->num_attributes = 0;
        curr_node->text = NULL;
        curr_node->children = NULL;
        curr_node->next_sibling = NULL;

        // Handle attributes
        while (token != NULL && token[strlen(token)-1] != '>') {
            token = strtok(NULL, " ");
            if (token != NULL && token[0] != '/') {
                curr_node->num_attributes++;
                curr_node->attributes = realloc(curr_node->attributes, curr_node->num_attributes * sizeof(attribute));
                curr_node->attributes[curr_node->num_attributes-1].name = strdup(token);
                token = strtok(NULL, "\"");
                token = strtok(NULL, "\"");
                curr_node->attributes[curr_node->num_attributes-1].value = strdup(token);
            }
        }

        // Recursively parse child elements
        char *start_node = strtok(NULL, "");
        while (start_node != NULL) {
            element_node *new_node = malloc(sizeof(element_node));
            new_node->parent = curr_node;
            parse_node(start_node, new_node);
            if (curr_node->children == NULL) {
                curr_node->children = new_node;
            } else {
                element_node *sibling = curr_node->children;
                while (sibling->next_sibling != NULL) {
                    sibling = sibling->next_sibling;
                }
                sibling->next_sibling = new_node;
            }
            start_node = strtok(NULL, "");
        }

    } else if (token[0] == '<' && token[1] == '/') {
        // Closing tag
        if (curr_node->parent != NULL) {
            curr_node = curr_node->parent;
        }

    } else {
        // Text node
        curr_node->text = strdup(token);
    }

}

void print_element(element_node *node) {
    printf("<%s", node->name);
    for (int i=0; i<node->num_attributes; i++) {
        printf(" %s=\"%s\"", node->attributes[i].name, node->attributes[i].value);
    }
    printf(">");

    if (node->text != NULL) {
        printf("%s", node->text);
    }

    if (node->children != NULL) {
        element_node *child = node->children;
        while (child != NULL) {
            print_element(child);
            child = child->next_sibling;
        }
    }

    printf("</%s>", node->name);
}

int main() {

    char *xml = "<root><person name=\"John\" age=\"30\"><address><street>123 Main St.</street><city>Anytown</city></address></person></root>";

    element_node *root = malloc(sizeof(element_node));
    root->parent = NULL;
    parse_node(xml, root);
    print_element(root);
    printf("\n");

    return 0;
}