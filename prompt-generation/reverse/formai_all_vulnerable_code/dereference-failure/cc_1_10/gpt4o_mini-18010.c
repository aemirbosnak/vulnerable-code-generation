//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct Node {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct Node *children[MAX_NODES];
    int childCount;
} Node;

Node* createNode(const char *name, const char *value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strncpy(newNode->name, name, MAX_NAME_LENGTH);
    strncpy(newNode->value, value, MAX_VALUE_LENGTH);
    newNode->childCount = 0;
    return newNode;
}

void addChild(Node *parent, Node *child) {
    if (parent->childCount < MAX_NODES) {
        parent->children[parent->childCount++] = child;
    } else {
        fprintf(stderr, "Too many children for %s\n", parent->name);
    }
}

void freeNode(Node *node) {
    for (int i = 0; i < node->childCount; i++) {
        freeNode(node->children[i]);
    }
    free(node);
}

void parseXML(const char *xml, Node *parent) {
    char tagName[MAX_NAME_LENGTH];
    char tagValue[MAX_VALUE_LENGTH];
    char *currPosition = (char *)xml;
    while (*currPosition) {
        if (*currPosition == '<') {
            currPosition++;
            if (*currPosition == '/') {
                // End of current tag.
                break;
            }
            char *endTag = strchr(currPosition, '>');
            if (!endTag) {
                perror("Malformed XML: No closing tag found.");
                exit(EXIT_FAILURE);
            }
            strncpy(tagName, currPosition, endTag - currPosition);
            tagName[endTag - currPosition] = '\0';
            currPosition = endTag + 1;

            // Extract the value of the inner content until the next starting tag or closing tag
            char *contentStart = strstr(currPosition, "<");
            if (contentStart) {
                strncpy(tagValue, currPosition, contentStart - currPosition);
                tagValue[contentStart - currPosition] = '\0';
                currPosition = contentStart; // Move to the next tag
            } else {
                strncpy(tagValue, currPosition, strlen(currPosition));
                tagValue[strlen(currPosition)] = '\0';
                currPosition += strlen(currPosition);
            }

            Node *childNode = createNode(tagName, tagValue);
            addChild(parent, childNode);
        }
    }
}

void displayTree(Node *node, int depth) {
    for (int i = 0; i < depth; ++i) {
        printf("--");
    }
    printf(" %s: %s\n", node->name, node->value);
    for (int i = 0; i < node->childCount; ++i) {
        displayTree(node->children[i], depth + 1);
    }
}

int main() {
    char xmlInput[] = "<book><title>The Adventures of Sherlock Holmes</title><author>Arthur Conan Doyle</author><year>1892</year></book>";
    Node *root = createNode("root", "");

    parseXML(xmlInput, root);
    
    printf("Parsed XML Structure:\n");
    displayTree(root, 0);

    freeNode(root); // Clean up
    return 0;
}