//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LEN 256
#define MAX_VALUE_LEN 256
#define MAX_CHILDREN 10

typedef struct XMLNode {
    char tag[MAX_TAG_LEN];
    char value[MAX_VALUE_LEN];
    struct XMLNode *children[MAX_CHILDREN];
    int childCount;
} XMLNode;

void initXMLNode(XMLNode *node, const char *tag) {
    strncpy(node->tag, tag, MAX_TAG_LEN);
    node->tag[MAX_TAG_LEN - 1] = '\0'; // Ensure null termination
    node->value[0] = '\0'; // Empty value by default
    node->childCount = 0;
}

void addChild(XMLNode *parent, XMLNode *child) {
    if (parent->childCount < MAX_CHILDREN) {
        parent->children[parent->childCount++] = child;
    } else {
        printf("Max children limit reached for tag: %s\n", parent->tag);
    }
}

void parseXML(const char *xmlData, XMLNode *node) {
    const char *startTag = "<";
    const char *endTag = ">";
    const char *closeTag = "/";

    char *ptr = strstr(xmlData, startTag);
    while (ptr != NULL) {
        ptr++;
        char tag[MAX_TAG_LEN];
        sscanf(ptr, "%s", tag);
        char *tagClose = strstr(ptr, endTag);
        if (tagClose == NULL) {
            printf("Error: Mismatched tags\n");
            return;
        }

        // Detect closing tag
        if (tag[0] == '/') {
            // Should not reach here
            return;
        }

        // Create a child node and add it to the current node
        XMLNode *childNode = (XMLNode *)malloc(sizeof(XMLNode));
        initXMLNode(childNode, tag);
        addChild(node, childNode);

        // Move pointer to the end of the current tag
        ptr = tagClose + 1;

        // Save the value until the next opening tag
        char value[MAX_VALUE_LEN] = "";
        char *valueEnd = strstr(ptr, startTag);
        if (valueEnd == NULL) {
            valueEnd = strstr(ptr, endTag);
            if (valueEnd == NULL) {
                printf("Error: Value without closing tag\n");
                return;
            }
        }
        strncpy(childNode->value, ptr, valueEnd - ptr);
        childNode->value[valueEnd - ptr] = '\0';

        // Proceed to the next tag
        ptr = valueEnd;
    }
}

void printXMLNode(XMLNode *node, int level) {
    if (!node) return;

    for (int i = 0; i < level; ++i) {
        printf("\t");
    }
    printf("<%s>%s</%s>\n", node->tag, node->value, node->tag);

    for (int i = 0; i < node->childCount; ++i) {
        printXMLNode(node->children[i], level + 1);
    }
}

void freeXMLNode(XMLNode *node) {
    if (!node) return;

    for (int i = 0; i < node->childCount; ++i) {
        freeXMLNode(node->children[i]);
    }
    free(node);
}

int main() {
    const char *xmlData = "<book><title>XML Parsing in C</title><author>Jane Doe</author></book>";
    XMLNode *rootNode = (XMLNode *)malloc(sizeof(XMLNode));
    initXMLNode(rootNode, "root");

    parseXML(xmlData, rootNode);
    printf("Parsed XML Structure:\n");
    printXMLNode(rootNode, 0);

    freeXMLNode(rootNode);
    return 0;
}