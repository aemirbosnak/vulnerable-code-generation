//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 100
#define MAX_TAG_VALUE 256

typedef struct XMLNode {
    char tag[MAX_TAG_NAME];
    char value[MAX_TAG_VALUE];
    struct XMLNode* next;
    struct XMLNode* child;
} XMLNode;

XMLNode* createNode(const char* tag, const char* value) {
    XMLNode* newNode = (XMLNode*)malloc(sizeof(XMLNode));
    strncpy(newNode->tag, tag, MAX_TAG_NAME);
    strncpy(newNode->value, value, MAX_TAG_VALUE);
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}

void freeNode(XMLNode* node) {
    if (node) {
        freeNode(node->child);
        freeNode(node->next);
        free(node);
    }
}

void printXMLNode(XMLNode* node, int depth) {
    if (!node) return;
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>", node->tag);
    if (strlen(node->value) > 0) {
        printf("%s", node->value);
    }
    printf("\n");
    printXMLNode(node->child, depth + 1);
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("</%s>\n", node->tag);
    printXMLNode(node->next, depth);
}

XMLNode* parseXML(const char* xmlContent) {
    XMLNode* head = NULL;
    XMLNode* currentNode = NULL;
    char tag[MAX_TAG_NAME];
    char value[MAX_TAG_VALUE];
    int inTag = 0, inValue = 0;

    for (const char* ptr = xmlContent; *ptr != '\0'; ptr++) {
        if (*ptr == '<') {
            inTag = 1;
            inValue = 0;
            if (currentNode) {
                currentNode->next = createNode("", "");
                currentNode = currentNode->next;
            } else {
                head = createNode("", "");
                currentNode = head;
            }
            ptr++;
            int i = 0;
            while (*ptr != '>' && i < MAX_TAG_NAME - 1) {
                tag[i++] = *ptr++;
            }
            tag[i] = '\0';
            strncpy(currentNode->tag, tag, MAX_TAG_NAME);
            currentNode->next = NULL;
            currentNode->child = NULL;
            if (*ptr == '>') inTag = 0;
            continue;
        } else if (*ptr == '>') {
            inTag = 0;
            continue;
        }

        if (inTag == 0 && *ptr != '/') {
            inValue = 1;
            int valueIndex = 0;
            while (*ptr != '<' && valueIndex < MAX_TAG_VALUE - 1) {
                value[valueIndex++] = *ptr++;
            }
            value[valueIndex] = '\0';
            strncpy(currentNode->value, value, MAX_TAG_VALUE);
            currentNode->child = NULL; // Reset child for the next value.
            if (*ptr == '<' && *(ptr + 1) == '/') {
                // End tag detected
                break;
            }
        }
    }
    return head;
}

int main() {
    const char* xmlContent = "<book><title>Programming in C</title><author>John Doe</author></book>";
    XMLNode* xmlTree = parseXML(xmlContent);

    printf("Parsed XML Structure:\n");
    printXMLNode(xmlTree, 0);

    freeNode(xmlTree);
    return 0;
}