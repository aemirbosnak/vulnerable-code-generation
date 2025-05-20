//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* tag;
    char* text;
    struct Node** children;
    int child_count;
} Node;

Node* create_node(const char* tag) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->tag = strdup(tag);
    node->text = NULL;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void free_node(Node* node) {
    if (node) {
        free(node->tag);
        if (node->text) {
            free(node->text);
        }
        for (int i = 0; i < node->child_count; i++) {
            free_node(node->children[i]);
        }
        free(node->children);
        free(node);
    }
}

void append_child(Node* parent, Node* child) {
    parent->child_count++;
    parent->children = realloc(parent->children, sizeof(Node*) * parent->child_count);
    parent->children[parent->child_count - 1] = child;
}

void parse_xml(const char* xml, Node* root) {
    char tag[256];
    char text[256];
    const char* pos = xml;
    while (*pos) {
        if (*pos == '<') {
            if (*(pos + 1) == '/') { // closing tag
                pos = strchr(pos, '>');
                pos++;
                continue;
            } else { // opening tag
                pos++;
                sscanf(pos, "%[^>]", tag);
                Node* new_node = create_node(tag);
                append_child(root, new_node);
                pos = strchr(pos, '>');
                pos++;
                while (*pos && *pos != '<') {
                    sscanf(pos, "%[^<]", text);
                    new_node->text = strdup(text);
                    pos = strchr(pos, '<');
                }
            }
        } else {
            pos++;
        }
    }
}

void print_xml(Node* node, int indent) {
    for (int i = 0; i < indent; i++) {
        printf("  ");
    }
    printf("<%s>", node->tag);
    if (node->text) {
        printf("%s", node->text);
    }
    printf("\n");
    for (int i = 0; i < node->child_count; i++) {
        print_xml(node->children[i], indent + 1);
    }
    for (int i = 0; i < indent; i++) {
        printf("  ");
    }
    printf("</%s>\n", node->tag);
}

int main() {
    const char* xml_data = "<book><title>Programming in C</title><author>John Doe</author></book>";
    
    Node* root = create_node("root");
    
    parse_xml(xml_data, root);
    
    printf("Parsed XML Structure:\n");
    print_xml(root->children[0], 0); // Print the first child tagged "book"
    
    free_node(root);
    return 0;
}