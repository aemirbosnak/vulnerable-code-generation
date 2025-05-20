//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char *tag;
    char *value;
    struct Node *parent;
    struct Node *firstChild;
    struct Node *nextSibling;
} Node;

Node *parseXML(char *xml) {
    Node *root = NULL;
    Node *current = NULL;
    char *start = xml;

    while (*start != '\0') {
        if (*start == '<') {
            start++;
            if (*start == '/') {
                start++;
                while (*start != '>') {
                    start++;
                }
                current = current->parent;
            } else {
                char *tag = start;
                while (*start != '>' && *start != ' ') {
                    start++;
                }
                *start = '\0';
                Node *node = malloc(sizeof(Node));
                node->tag = strdup(tag);
                node->value = NULL;
                node->parent = current;
                node->firstChild = NULL;
                node->nextSibling = NULL;
                if (current == NULL) {
                    root = node;
                } else {
                    if (current->firstChild == NULL) {
                        current->firstChild = node;
                    } else {
                        Node *last = current->firstChild;
                        while (last->nextSibling != NULL) {
                            last = last->nextSibling;
                        }
                        last->nextSibling = node;
                    }
                }
                current = node;
                start++;
            }
        } else if (*start == '>') {
            start++;
            if (current != NULL) {
                char *value = start;
                while (*start != '<' && *start != '\0') {
                    start++;
                }
                *start = '\0';
                current->value = strdup(value);
            }
        } else {
            start++;
        }
    }

    return root;
}

void printXML(Node *node) {
    if (node == NULL) {
        return;
    }

    printf("<%s", node->tag);
    if (node->value != NULL) {
        printf(">%s", node->value);
    } else {
        printf(">");
    }

    Node *child = node->firstChild;
    while (child != NULL) {
        printXML(child);
        child = child->nextSibling;
    }

    if (node->value == NULL) {
        printf("</%s>", node->tag);
    }
}

int main() {
    char *xml = "<root><child1>Hello</child1><child2>World</child2></root>";
    Node *root = parseXML(xml);
    printXML(root);
    return 0;
}