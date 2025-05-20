//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_XML_LINES 1024
#define MAX_TAG_NAME 256
#define MAX_VALUE_LENGTH 1024

typedef struct XmlNode {
    char tag[MAX_TAG_NAME];
    char value[MAX_VALUE_LENGTH];
    struct XmlNode* next;
    struct XmlNode* child;
} XmlNode;

XmlNode* createNode(const char* tag, const char* value) {
    XmlNode* newNode = (XmlNode*)malloc(sizeof(XmlNode));
    strncpy(newNode->tag, tag, MAX_TAG_NAME);
    strncpy(newNode->value, value, MAX_VALUE_LENGTH);
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}

void freeXmlNode(XmlNode* node) {
    if (node) {
        freeXmlNode(node->child);
        freeXmlNode(node->next);
        free(node);
    }
}

void addChild(XmlNode* parent, XmlNode* child) {
    if (parent->child == NULL) {
        parent->child = child;
    } else {
        XmlNode* sibling = parent->child;
        while (sibling->next != NULL) {
            sibling = sibling->next;
        }
        sibling->next = child;
    }
}

void printXmlNode(XmlNode* node, int depth) {
    if (!node) return;

    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>%s</%s>\n", node->tag, node->value, node->tag);
    printXmlNode(node->child, depth + 1);
    printXmlNode(node->next, depth);
}

XmlNode* parseXml(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return NULL;
    }

    XmlNode* root = NULL;
    XmlNode* current = NULL;
    char line[MAX_VALUE_LENGTH];
    char tag[MAX_TAG_NAME];
    char value[MAX_VALUE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        char* lptr = line;
        // Skip leading spaces
        while (*lptr == ' ') lptr++;

        if (lptr[0] == '<' && lptr[1] != '/') {
            current = createNode("", "");
            sscanf(lptr, "<%[^>]>%[^<]", tag, value);
            strncpy(current->tag, tag, MAX_TAG_NAME);
            strncpy(current->value, value, MAX_VALUE_LENGTH);
            addChild(root, current);
            root = current; // Update root to the latest node
        } else if (lptr[0] == '<' && lptr[1] == '/') {
            // End of current node
            root = root->next; // Pop the top node
        }
    }

    fclose(file);
    return root;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    XmlNode* xml = parseXml(argv[1]);
    if (xml) {
        printf("Parsed XML:\n");
        printXmlNode(xml, 0);
        freeXmlNode(xml);
    }

    return EXIT_SUCCESS;
}