//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 100
#define MAX_VALUE 100
#define MAX_CHILDREN 10

typedef struct Node {
    char tagName[MAX_TAG_NAME];
    char value[MAX_VALUE];
    struct Node *children[MAX_CHILDREN];
    int childCount;
} Node;

Node* createNode(const char *tagName, const char *value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->tagName, tagName);
    strcpy(newNode->value, value);
    newNode->childCount = 0;
    return newNode;
}

void addChild(Node *parent, Node *child) {
    if (parent->childCount < MAX_CHILDREN) {
        parent->children[parent->childCount++] = child;
    } else {
        printf("Maximum children limit reached for tag: %s\n", parent->tagName);
    }
}

void printXML(Node *node, int depth) {
    if (node == NULL) return;

    for (int i = 0; i < depth; ++i) {
        printf("  ");
    }
    
    printf("<%s>", node->tagName);
    if (strlen(node->value) > 0) {
        printf("%s", node->value);
    }
    printf("\n");

    for (int i = 0; i < node->childCount; ++i) {
        printXML(node->children[i], depth + 1);
    }

    for (int i = 0; i < depth; ++i) {
        printf("  ");
    }
    
    printf("</%s>\n", node->tagName);
}

Node* parseXML(const char *xml) {
    Node *root = NULL;
    char tagName[MAX_TAG_NAME];
    char value[MAX_VALUE];
    int i = 0, j = 0;
    
    while (xml[i] != '\0') {
        if (xml[i] == '<') {
            j = 0;
            while (xml[i] != '>' && xml[i] != '\0') {
                if (xml[i] == '/') { // End tag
                    break;
                }
                tagName[j++] = xml[i++];
            }
            tagName[j] = '\0';
            if (xml[i] == '>') {
                // Create node for the tag
                Node *node = createNode(tagName, "");
                if (root == NULL) {
                    root = node;
                }
                j = 0;
                // Now, let's check for the value
                i++;
                while (xml[i] != '<' && xml[i] != '\0') {
                    value[j++] = xml[i++];
                }
                value[j] = '\0'; // Terminate the string for value
                strcpy(node->value, value);
                // If there are more tags, recursively add children
                if (xml[i] == '<' && xml[i + 1] != '/') {
                    Node *childNode = parseXML(&xml[i]);
                    addChild(node, childNode);
                }   
            }
        }
        i++;
    }
    return root;
}

int main() {
    const char *xmlString = "<root>Hello<child1>World</child1><child2>!</child2></root>";
    Node *parsedXML = parseXML(xmlString);
    
    printf("Parsed XML structure:\n");
    printXML(parsedXML, 0);
    
    // Clean-up
    free(parsedXML);
    return 0;
}