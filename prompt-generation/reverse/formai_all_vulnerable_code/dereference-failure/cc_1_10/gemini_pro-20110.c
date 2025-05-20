//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LENGTH 100

typedef struct _XMLNode XMLNode;

struct _XMLNode {
    char *tag;
    char *value;
    XMLNode *parent;
    XMLNode *next;
    XMLNode *child;
};

XMLNode *create_node(char *tag, char *value) {
    XMLNode *node = malloc(sizeof(XMLNode));
    node->tag = malloc(strlen(tag) + 1);
    strcpy(node->tag, tag);
    node->value = malloc(strlen(value) + 1);
    strcpy(node->value, value);
    node->parent = NULL;
    node->next = NULL;
    node->child = NULL;
    return node;
}

void free_node(XMLNode *node) {
    free(node->tag);
    free(node->value);
    free(node);
}

XMLNode *parse_xml(char *xml) {
    XMLNode *root = create_node("root", "");
    XMLNode *current_node = root;
    int i = 0;
    while (xml[i] != '\0') {
        if (xml[i] == '<') {
            i++;
            char tag[MAX_TAG_LENGTH];
            int j = 0;
            while (xml[i] != '>' && xml[i] != '\0') {
                tag[j] = xml[i];
                i++;
                j++;
            }
            tag[j] = '\0';
            XMLNode *new_node = create_node(tag, "");
            new_node->parent = current_node;
            current_node->next = new_node;
            current_node = new_node;
        } else if (xml[i] == '>') {
            i++;
            char value[MAX_TAG_LENGTH];
            int j = 0;
            while (xml[i] != '<' && xml[i] != '\0') {
                value[j] = xml[i];
                i++;
                j++;
            }
            value[j] = '\0';
            current_node->value = malloc(strlen(value) + 1);
            strcpy(current_node->value, value);
        } else {
            i++;
        }
    }
    return root;
}

void print_xml(XMLNode *node) {
    printf("<%s>", node->tag);
    if (node->value != NULL) {
        printf("%s", node->value);
    }
    if (node->child != NULL) {
        print_xml(node->child);
    }
    if (node->next != NULL) {
        print_xml(node->next);
    }
    printf("</%s>", node->tag);
}

int main() {
    char *xml = "<root><child1>value1</child1><child2><child2_1>value2_1</child2_1><child2_2>value2_2</child2_2></child2></root>";
    XMLNode *root = parse_xml(xml);
    print_xml(root);
    return 0;
}