//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_SIZE 256
#define MAX_CONTENT_SIZE 1024
#define MAX_LINE_SIZE 1024

typedef struct XMLNode {
    char tag[MAX_TAG_SIZE];
    char content[MAX_CONTENT_SIZE];
    struct XMLNode* next;
    struct XMLNode* child;
} XMLNode;

XMLNode* createNode(char* tag, char* content) {
    XMLNode* node = (XMLNode*)malloc(sizeof(XMLNode));
    strncpy(node->tag, tag, MAX_TAG_SIZE);
    strncpy(node->content, content, MAX_CONTENT_SIZE);
    node->next = NULL;
    node->child = NULL;
    return node;
}

void freeXMLNode(XMLNode* node) {
    if (node) {
        freeXMLNode(node->child);
        freeXMLNode(node->next);
        free(node);
    }
}

void printXML(XMLNode* node, int level) {
    if (!node) return;
    
    for (int i = 0; i < level; i++) printf("  ");
    printf("<%s>", node->tag);
    if (strlen(node->content) > 0) {
        printf("%s", node->content);
    }
    printf("\n");
    
    printXML(node->child, level + 1);
    
    for (int i = 0; i < level; i++) printf("  ");
    printf("</%s>\n", node->tag);
    printXML(node->next, level);
}

void parseLine(XMLNode** currentNode, char* line) {
    char tag[MAX_TAG_SIZE], content[MAX_CONTENT_SIZE];
    int i = 0, j = 0;

    if (line[i] == '<') {
        char* closing = strchr(line, '>');
        if (closing) {
            strncpy(tag, line + 1, closing - line - 1);
            tag[closing - line - 1] = '\0';
            *currentNode = createNode(tag, "");

            // Handle content
            char* contentStart = closing + 1;
            if (*contentStart != '<') {
                char* contentEnd = strchr(contentStart, '<');
                if (contentEnd) {
                    strncpy(content, contentStart, contentEnd - contentStart);
                    content[contentEnd - contentStart] = '\0';
                    strncpy((*currentNode)->content, content, MAX_CONTENT_SIZE);
                }
            }
        }
    }
}

void parseXML(const char* filename, XMLNode** root) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return;
    }

    char line[MAX_LINE_SIZE];
    XMLNode* currentNode = NULL;
    *root = NULL;

    while (fgets(line, sizeof(line), file)) {
        XMLNode* newNode = NULL;
        parseLine(&newNode, line);
        if (newNode) {
            if (*root == NULL) {
                *root = newNode;
            } else {
                currentNode->next = newNode;
            }
            currentNode = newNode;
        }
    }
    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <xml_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    XMLNode* root = NULL;
    parseXML(argv[1], &root);
    
    printf("Parsed XML:\n");
    printXML(root, 0);

    freeXMLNode(root);
    return EXIT_SUCCESS;
}