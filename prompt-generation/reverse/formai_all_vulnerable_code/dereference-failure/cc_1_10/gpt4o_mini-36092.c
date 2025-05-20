//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 256

typedef struct Node {
    char tag[MAX_TAG_LENGTH];
    char *content;
    struct Node **children;
    size_t child_count;
} Node;

Node *create_node(const char *tag) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        perror("Failed to allocate memory for Node");
        exit(EXIT_FAILURE);
    }
    strncpy(node->tag, tag, MAX_TAG_LENGTH);
    node->content = NULL;
    node->children = NULL;
    node->child_count = 0;
    return node;
}

void free_node(Node *node) {
    if (node) {
        free(node->content);
        for (size_t i = 0; i < node->child_count; i++) {
            free_node(node->children[i]);
        }
        free(node->children);
        free(node);
    }
}

void append_child(Node *parent, Node *child) {
    parent->child_count++;
    parent->children = realloc(parent->children, parent->child_count * sizeof(Node *));
    if (parent->children == NULL) {
        perror("Failed to reallocate memory for children");
        exit(EXIT_FAILURE);
    }
    parent->children[parent->child_count - 1] = child;
}

void parse_line(Node *current_node, char *line) {
    char *tag_start = strchr(line, '<');
    char *tag_end = strchr(line, '>');
    
    if (tag_start && tag_end) {
        // Extracting the tag
        size_t tag_length = tag_end - tag_start - 1;
        char tag[MAX_TAG_LENGTH];
        strncpy(tag, tag_start + 1, tag_length);
        tag[tag_length] = '\0';

        // Check for closing tag
        if (tag[0] == '/') {
            // Closing tag
            return;
        } else {
            // Opening tag
            Node *new_node = create_node(tag);
            append_child(current_node, new_node);
            current_node = new_node;

            // Get content
            char *content_start = tag_end + 1;
            char *content_end = strchr(content_start, '<');
            if (content_end) {
                size_t content_length = content_end - content_start;
                current_node->content = (char *)malloc(content_length + 1);
                strncpy(current_node->content, content_start, content_length);
                current_node->content[content_length] = '\0';

                // Recursive parsing
                parse_line(current_node, content_end);
            }
        }
    }
}

Node *parse_xml(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    Node *root = create_node("root");

    while (fgets(line, sizeof(line), file)) {
        parse_line(root, line);
    }

    fclose(file);
    return root;
}

void print_xml(Node *node, int indent) {
    if (node) {
        for (int i = 0; i < indent; i++) {
            printf(" ");
        }
        
        printf("<%s>", node->tag);
        if (node->content) {
            printf("%s", node->content);
        }
        printf("\n");

        for (size_t i = 0; i < node->child_count; i++) {
            print_xml(node->children[i], indent + 2);
        }

        for (int i = 0; i < indent; i++) {
            printf(" ");
        }
        printf("</%s>\n", node->tag);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Node *root = parse_xml(argv[1]);
    print_xml(root, 0);
    free_node(root);
    return EXIT_SUCCESS;
}