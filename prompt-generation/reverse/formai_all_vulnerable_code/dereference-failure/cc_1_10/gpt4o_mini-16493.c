//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024
#define MAX_TAG_NAME 64
#define MAX_VALUE 256

typedef struct XMLNode {
    char tag[MAX_TAG_NAME];
    char value[MAX_VALUE];
    struct XMLNode *children;
    struct XMLNode *next;
} XMLNode;

XMLNode* createNode(const char *tag, const char *value) {
    XMLNode* newNode = (XMLNode*)malloc(sizeof(XMLNode));
    if (newNode == NULL) {
        perror("Failed to allocate memory for XMLNode");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->tag, tag, MAX_TAG_NAME);
    strncpy(newNode->value, value, MAX_VALUE);
    newNode->children = NULL;
    newNode->next = NULL;
    return newNode;
}

void appendChild(XMLNode *parent, XMLNode *child) {
    if (parent->children == NULL) {
        parent->children = child;
    } else {
        XMLNode *current = parent->children;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = child;
    }
}

void freeXMLNode(XMLNode *node) {
    if (node != NULL) {
        freeXMLNode(node->children);
        freeXMLNode(node->next);
        free(node);
    }
}

void printXMLNode(XMLNode *node, int depth) {
    if (node == NULL) return;

    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    if (node->value[0] != '\0') {
        printf("<%s>%s</%s>\n", node->tag, node->value, node->tag);
    } else {
        printf("<%s>\n", node->tag);
    }
    printXMLNode(node->children, depth + 1);
    if (node->value[0] == '\0') {
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("</%s>\n", node->tag);
    }
}

char* getTagContent(char *line, char *tag) {
    char *contentStart = strstr(line, ">");
    char *contentEnd = strstr(line, "</");
    if (!contentStart || !contentEnd) return NULL;

    size_t tagLength = contentStart - line - strlen(tag) - 1;
    char *content = (char *)malloc(tagLength + 1);
    strncpy(content, contentStart + 1, tagLength);
    content[tagLength] = '\0';
    return content;
}

XMLNode* parseLine(char *line) {
    char tag[MAX_TAG_NAME] = {'\0'};
    sscanf(line, "<%s", tag);
    if (line[strlen(line) - 2] == '/') { // Self-closing tag
        return createNode(tag, "");
    }

    char *content = getTagContent(line, tag);
    XMLNode *node = createNode(tag, content ? content : "");
    free(content);
    return node;
}

XMLNode* parseXML(FILE *file) {
    XMLNode *root = createNode("root", "");
    XMLNode *current = root;

    char line[MAX_BUFFER];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "<") && strstr(line, ">")) {
            XMLNode *node = parseLine(line);
            appendChild(current, node);
            if (node->value[0] == '\0') {
                current = node; // Move deeper into the XML tree
            }
        } else if (strstr(line, "</")) {
            current = current->next; // Move back up to the parent node
        }
    }
    return root;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename.xml>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Could not open file");
        return EXIT_FAILURE;
    }

    XMLNode *xmlTree = parseXML(file);
    fclose(file);

    printXMLNode(xmlTree, 0);
    freeXMLNode(xmlTree);

    return EXIT_SUCCESS;
}