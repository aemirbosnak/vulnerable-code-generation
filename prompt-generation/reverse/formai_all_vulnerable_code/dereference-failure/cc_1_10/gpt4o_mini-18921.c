//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct XMLNode {
    char *name;
    char *value;
    struct XMLNode **children;
    int childCount;
} XMLNode;

XMLNode* createNode(const char *name, const char *value) {
    XMLNode *node = (XMLNode*)malloc(sizeof(XMLNode));
    node->name = strdup(name);
    node->value = value ? strdup(value) : NULL;
    node->children = NULL;
    node->childCount = 0;
    return node;
}

void addChild(XMLNode *parent, XMLNode *child) {
    parent->children = (XMLNode**)realloc(parent->children, sizeof(XMLNode*) * (parent->childCount + 1));
    parent->children[parent->childCount++] = child;
}

void freeNode(XMLNode *node) {
    if (!node) return;
    free(node->name);
    if (node->value) free(node->value);
    for (int i = 0; i < node->childCount; i++) {
        freeNode(node->children[i]);
    }
    free(node->children);
    free(node);
}

void printXML(XMLNode *node, int depth) {
    if (!node) return;
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>", node->name);
    if (node->value) {
        printf("%s", node->value);
    }
    printf("\n");
    for (int i = 0; i < node->childCount; i++) {
        printXML(node->children[i], depth + 1);
    }
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("</%s>\n", node->name);
}

char* readFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *content = (char*)malloc(length + 1);
    fread(content, 1, length, file);
    content[length] = '\0';
    fclose(file);
    return content;
}

int parseXML(const char *xml, XMLNode **root) {
    // For simplicity, we will add a very basic parser
    const char *curr = xml;
    XMLNode *currentNode = NULL;

    while (*curr) {
        if (*curr == '<') {
            // Check for closing tag
            if (*(curr + 1) == '/') {
                while (*curr != '>') curr++; // Skip to '>'
                curr++;
                continue;
            }

            // Start of a new tag
            const char *tagStart = curr + 1;
            while (*curr != '>' && *curr != ' ') curr++;
            int tagLength = curr - tagStart;

            char *tagName = (char*)malloc(tagLength + 1);
            strncpy(tagName, tagStart, tagLength);
            tagName[tagLength] = '\0';

            currentNode = createNode(tagName, NULL);
            free(tagName);
            if (*root == NULL) {
                *root = currentNode;
            } else {
                addChild(currentNode, *root);
                *root = currentNode;
            }

            while (*curr != '>') curr++; // Skip to closing '>'
        } else if (*curr == '>' && currentNode) {
            const char *valueStart = curr + 1;
            while (*valueStart && *valueStart != '<') valueStart++;
            int valueLength = valueStart - (currentNode->name + strlen(currentNode->name) + 2);
            if (valueLength > 0) {
                char *value = (char*)malloc(valueLength + 1);
                strncpy(value, curr + 1, valueLength);
                value[valueLength] = '\0';
                currentNode->value = value;
            }
        }
        curr++;
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <xml_file>\n", argv[0]);
        return 1;
    }

    XMLNode *root = NULL;
    char *xmlContent = readFile(argv[1]);
    if (!xmlContent) {
        return 1;
    }

    parseXML(xmlContent, &root);
    printXML(root, 0);
    freeNode(root);
    free(xmlContent);
    return 0;
}