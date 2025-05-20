//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

typedef enum { NONE, ELEMENT, ATTRIBUTE, CONTENT } tag_type;

struct element {
    char* name;
    char* value;
    struct element* parent;
    struct element* children;
    struct element* next;
};

void print_tree(struct element* node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf(" ");
    }
    printf("<%s>", node->name);
    if (node->value && strlen(node->value) > 0) {
        printf("%s", node->value);
    }
    printf("\n");
    struct element* child = node->children;
    while (child) {
        print_tree(child, depth + 1);
        child = child->next;
    }
    for (int i = 0; i < depth; i++) {
        printf(" ");
    }
    printf("</%s>\n", node->name);
}

void parse_tag(char* buffer, struct element* parent) {
    char* token = strtok(buffer, " \n\r\t>");
    struct element* node = malloc(sizeof(struct element));
    node->name = strdup(token);
    node->value = NULL;
    node->parent = parent;
    node->children = NULL;
    node->next = NULL;
    tag_type type = ELEMENT;
    while ((token = strtok(NULL, " \n\r\t>"))) {
        if (type == ATTRIBUTE) {
            type = ELEMENT;
            char* value = strtok(token, "\"");
            node->next = malloc(sizeof(struct element));
            node->next->name = strdup("");
            node->next->value = strdup(value);
            node->next->parent = node;
            node->next->children = NULL;
            node->next->next = NULL;
            node = node->next;
            continue;
        }
        if (*token == '/') {
            return;
        }
        if (*token == '\"') {
            type = ATTRIBUTE;
            continue;
        }
        if (type == ELEMENT) {
            node->next = malloc(sizeof(struct element));
            node->next->name = strdup(token);
            node->next->value = NULL;
            node->next->parent = node->parent;
            node->next->children = NULL;
            node->next->next = NULL;
            node = node->next;
            type = CONTENT;
        } else if (type == CONTENT) {
            node->value = strdup(token);
            type = ELEMENT;
        }
    }
}

void parse_xml(FILE* file) {
    struct element* root = malloc(sizeof(struct element));
    root->name = strdup("");
    root->value = NULL;
    root->parent = NULL;
    root->children = NULL;
    root->next = NULL;
    struct element* parent = root;
    char buffer[BUFFER_SIZE];
    while (fgets(buffer, BUFFER_SIZE, file)) {
        char* token;
        while ((token = strstr(buffer, "<"))) {
            if (token == buffer) {
                token = strchr(token, '>');
                if (token) {
                    parent->value = strdup(buffer + 1);
                    parent->value[token - buffer - 1] = '\0';
                } else {
                    parent->value = strdup(buffer + 1);
                    parse_xml(file);
                    free(parent->value);
                    parent->value = NULL;
                }
            } else {
                *token = '\0';
                parse_tag(buffer, parent);
                struct element* child = parent->children;
                while (child && child->next) {
                    child = child->next;
                }
                if (child) {
                    parent = child;
                }
            }
            buffer[strlen(buffer) - strlen(token)] = '\0';
            memmove(buffer, token + 1, BUFFER_SIZE - (token - buffer) - 1);
        }
        if (parent->value && strlen(parent->value) > 0) {
            printf("%s", parent->value);
        }
    }
    print_tree(root, 0);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s file.xml\n", argv[0]);
        return 1;
    }
    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: couldn't open file\n");
        return 1;
    }
    parse_xml(file);
    fclose(file);
    return 0;
}