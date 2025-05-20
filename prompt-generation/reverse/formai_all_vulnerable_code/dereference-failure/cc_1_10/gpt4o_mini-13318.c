//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 256

typedef struct XMLNode {
    char tag[MAX_TAG_LENGTH];
    char value[MAX_LINE_LENGTH];
    struct XMLNode* next;
    struct XMLNode* child;
} XMLNode;

void initializeNode(XMLNode* node, const char* tag, const char* value) {
    strcpy(node->tag, tag);
    strcpy(node->value, value);
    node->next = NULL;
    node->child = NULL;
}

void freeXMLTree(XMLNode* root) {
    if (root) {
        freeXMLTree(root->child);
        freeXMLTree(root->next);
        free(root);
    }
}

XMLNode* createXMLNode() {
    XMLNode* node = (XMLNode*)malloc(sizeof(XMLNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    return node;
}

void parseXML(char* line, XMLNode** current) {
    char* tagStart = strchr(line, '<');
    char* tagEnd = strchr(line, '>');
    if (!tagStart || !tagEnd || tagEnd < tagStart) {
        return;
    }

    size_t tagLength = tagEnd - tagStart - 1;
    char tag[MAX_TAG_LENGTH] = {0};
    strncpy(tag, tagStart + 1, tagLength);
    
    // Handle closing tag
    if (tag[0] == '/') {
        return;
    }

    XMLNode* newNode = createXMLNode();
    initializeNode(newNode, tag, "");

    if (*current) {
        newNode->next = (*current)->child;
        (*current)->child = newNode;
    }

    *current = newNode;
}

void readXMLFile(const char* filename, XMLNode** root) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Failed to open file: %s\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    XMLNode* current = NULL;
    *root = createXMLNode();

    while (fgets(line, sizeof(line), file)) {
        parseXML(line, &current);
    }

    fclose(file);
}

void printXML(XMLNode* node, int depth) {
    if (!node) return;

    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>", node->tag);
    if (strlen(node->value) > 0) {
        printf("%s", node->value);
    }
    if (node->child) {
        printf("\n");
        printXML(node->child, depth + 1);
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
    }
    printf("</%s>\n", node->tag);
    printXML(node->next, depth);
}

void usage(const char* programName) {
    printf("Usage: %s <filename>\n", programName);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    XMLNode* root = NULL;
    readXMLFile(argv[1], &root);
    printXML(root, 0);
    freeXMLTree(root);

    return EXIT_SUCCESS;
}