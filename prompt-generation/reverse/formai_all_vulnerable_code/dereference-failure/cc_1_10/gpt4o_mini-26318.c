//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* tag;
    char* content;
    struct Node* next;
    struct Node* children;
} Node;

Node* create_node(const char* tag, const char* content) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->tag = strdup(tag);
    new_node->content = strdup(content);
    new_node->next = NULL;
    new_node->children = NULL;
    return new_node;
}

void append_child(Node* parent, Node* child) {
    if (!parent->children) {
        parent->children = child;
    } else {
        Node* current = parent->children;
        while (current->next) {
            current = current->next;
        }
        current->next = child;
    }
}

void free_node(Node* node) {
    if (node) {
        free(node->tag);
        free(node->content);
        free_node(node->children);
        free_node(node->next);
        free(node);
    }
}

void print_xml(Node* node, int depth) {
    if (!node) return;
    
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>", node->tag);
    if (node->content && strlen(node->content) > 0) {
        printf("%s", node->content);
    }

    if (node->children) {
        printf("\n");
        print_xml(node->children, depth + 1);
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
    }
    printf("</%s>\n", node->tag);

    print_xml(node->next, depth);
}

Node* parse_xml(const char* xml) {
    Node* root = NULL;
    Node* current = NULL;
    const char* ptr = xml;
    
    while (*ptr) {
        if (*ptr == '<') {
            if (*(ptr + 1) == '/') {
                // End tag
                while (*ptr != '>') ptr++;
                ptr++; // Move past '>'
                if (current) {
                    current = current->next;
                }
            } else {
                // Start tag
                const char* start = ptr + 1;
                while (*ptr != '>' && *ptr != ' ') ptr++;
                size_t tag_length = ptr - start;
                char tag[32];
                strncpy(tag, start, tag_length);
                tag[tag_length] = '\0';
                
                ptr++; // Move past '>'
                const char* content_start = ptr;

                // Find content until next tag or end
                while (*ptr && *ptr != '<') ptr++;
                size_t content_length = ptr - content_start;
                char content[256];
                strncpy(content, content_start, content_length);
                content[content_length] = '\0';

                Node* new_node = create_node(tag, content);
                if (!root) {
                    root = new_node;
                    current = new_node;
                } else {
                    append_child(current, new_node);
                }
                current = new_node; // Set current to new node
            }
        }
        ptr++;
    }
    return root;
}

int main() {
    const char* xml = "<root>Hello World<child1>Content1</child1><child2>Content2</child2></root>";

    Node* xml_tree = parse_xml(xml);
    if (xml_tree) {
        print_xml(xml_tree, 0);
        free_node(xml_tree);
    } else {
        printf("Failed to parse XML.\n");
    }

    return 0;
}