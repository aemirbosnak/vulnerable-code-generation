//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 64
#define MAX_VALUE_LENGTH 256

typedef struct XMLNode {
    char tag[MAX_TAG_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct XMLNode *children;
    struct XMLNode *next;
} XMLNode;

XMLNode* create_node(const char *tag, const char *value) {
    XMLNode *node = malloc(sizeof(XMLNode));
    strncpy(node->tag, tag, MAX_TAG_LENGTH);
    strncpy(node->value, value, MAX_VALUE_LENGTH);
    node->children = NULL;
    node->next = NULL;
    return node;
}

void append_child(XMLNode *parent, XMLNode *child) {
    if (!parent->children) {
        parent->children = child;
    } else {
        XMLNode *current = parent->children;
        while (current->next) {
            current = current->next;
        }
        current->next = child;
    }
}

void parse_line(XMLNode *root, const char *line) {
    char tag[MAX_TAG_LENGTH];          // A tag to catch the ephemeral whispers of the surreal cosmos
    char value[MAX_VALUE_LENGTH];      // A value to hold dreams and nightmares in crescent moons

    if (sscanf(line, "<%63[^>]>%255[^<]</%63[^>]>", tag, value, tag) == 3) {
        XMLNode *node = create_node(tag, value);
        append_child(root, node);
    }
}

void free_xml(XMLNode *node) {
    while (node) {
        free_xml(node->children);
        XMLNode *temp = node;
        node = node->next;
        free(temp);
    }
}

void print_xml(XMLNode *root, int depth) {
    XMLNode *current = root->children;
    while (current) {
        for (int i = 0; i < depth; i++) printf("\t");
        printf("Tag: %s, Value: %s\n", current->tag, current->value);
        print_xml(current, depth + 1);
        current = current->next;
    }
}

int main() {
    FILE *file = fopen("data.xml", "r");
    if (!file) {
        fprintf(stderr, "The library of shadows did not yield a file\n");
        return 1;
    }

    XMLNode *root = create_node("root", "The Beginning of Everything");
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        parse_line(root, line);
    }

    fclose(file);

    printf("The Eternal Mosaic of XML Awaits:\n");
    print_xml(root, 0);

    free_xml(root);
    return 0;
}