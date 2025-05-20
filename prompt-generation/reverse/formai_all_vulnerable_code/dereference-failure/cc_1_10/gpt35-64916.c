//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* tag;
    char* text;
    struct Node* children;
    struct Node* next;
} Node;

void add_child(Node** parent, Node* child) {
    if (*parent) {
        Node* last_child = (*parent)->children;
        if (!last_child) {
            (*parent)->children = child;
        }
        else {
            while (last_child->next) {
                last_child = last_child->next;
            }
            last_child->next = child;
        }
    }
    else {
        *parent = child;
    }
}

Node* parse_element(char* xml, int* index) {
    Node* node = malloc(sizeof(Node));
    node->children = NULL;
    node->next = NULL;

    // Parse opening tag
    int start_index = *index;
    while (xml[*index] != '>') {
        (*index)++;
    }
    int tag_len = (*index) - start_index;
    node->tag = malloc(sizeof(char) * (tag_len + 1));
    strncpy(node->tag, xml + start_index, tag_len);
    node->tag[tag_len] = '\0';
    (*index)++; // Consume '>' character

    // Parse children and text
    while (xml[*index] != '<') {
        if (xml[*index] == '\0') {
            fprintf(stderr, "Error: unexpected end of string\n");
            exit(1);
        }
        (*index)++;
    }

    int text_len = (*index) - (*index - 1);
    node->text = malloc(sizeof(char) * (text_len + 1));
    strncpy(node->text, xml + (*index - 1), text_len);
    node->text[text_len] = '\0';

    while (xml[*index] == '<') {
        if (xml[(*index) + 1] == '/') {
            (*index) += 2; // Consume '</' characters
            start_index = *index;
            while (xml[*index] != '>') {
                (*index)++;
            }
            tag_len = (*index) - start_index;
            char tag[tag_len + 1];
            strncpy(tag, xml + start_index, tag_len);
            tag[tag_len] = '\0';
            if (strcmp(tag, node->tag) != 0) {
                fprintf(stderr, "Error: tag mismatch\n");
                exit(1);
            }
            (*index)++; // Consume '>' character
            return node;
        }
        else {
            (*index)++; // Consume '<' character
            Node* child_node = parse_element(xml, index);
            add_child(&node->children, child_node);
        }
    }

    return node;
}

void print_node(Node* node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>%s\n", node->tag, node->text);
    Node* child = node->children;
    while (child) {
        print_node(child, depth + 1);
        child = child->next;
    }
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("</%s>\n", node->tag);
}

int main() {
    char xml[] = "<html><head><title>My Page</title></head><body><p>Welcome to my page!</p></body></html>";
    int index = 0;
    Node* root = parse_element(xml, &index);
    print_node(root, 0);
    return 0;
}