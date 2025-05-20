//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 256

typedef struct Node {
    char tag[MAX_TAG_LENGTH];
    char value[MAX_LINE_LENGTH];
    struct Node* next;
    struct Node* children;
} Node;

Node* createNode(const char* tag, const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->tag, tag);
    strcpy(newNode->value, value);
    newNode->next = NULL;
    newNode->children = NULL;
    return newNode;
}

void appendChild(Node* parent, Node* child) {
    child->next = parent->children;
    parent->children = child;
}

void freeNode(Node* node) {
    if (node) {
        freeNode(node->children);
        freeNode(node->next);
        free(node);
    }
}

void printXML(Node* node, int depth) {
    if (node) {
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("<%s>\n", node->tag);
        if (strlen(node->value) > 0) {
            for (int i = 0; i < depth + 1; i++) {
                printf("  ");
            }
            printf("%s\n", node->value);
        }
        printXML(node->children, depth + 1);
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("</%s>\n", node->tag);
        printXML(node->next, depth);
    }
}

Node* parseXML(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Unable to open file: %s\n", filename);
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    Node* root = NULL;
    Node* currentNode = NULL;

    while (fgets(line, sizeof(line), file)) {
        char tag[MAX_TAG_LENGTH];
        char value[MAX_LINE_LENGTH];
        int i = 0;

        // Remove newline character
        line[strcspn(line, "\n")] = 0;

        // Check for opening tag
        if (sscanf(line, "<%[^>]>", tag) == 1) {
            if (!root) {
                root = createNode(tag, "");
                currentNode = root;
            } else {
                Node* child = createNode(tag, "");
                appendChild(currentNode, child);
                currentNode = child;
            }
        }
        
        // Check for closing tag
        else if (sscanf(line, "</%[^>]>", tag) == 1) {
            if (currentNode) {
                currentNode = currentNode->next; // Go back to the parent node
            }
        }

        // Check for value (not just a line with tags)
        else {
            strcpy(value, line);  
            if (currentNode) {
                strcpy(currentNode->value, value);
            }
        }
    }

    fclose(file);
    return root;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    Node* xmlTree = parseXML(argv[1]);
    if (xmlTree) {
        printf("Parsed XML Structure:\n");
        printXML(xmlTree, 0);
        freeNode(xmlTree);
    }

    return 0;
}