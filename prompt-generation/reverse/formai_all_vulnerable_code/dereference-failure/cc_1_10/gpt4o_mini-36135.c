//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LEN 64
#define MAX_VALUE_LEN 256
#define MAX_XML_LEN 2048

typedef struct Node {
    char tag[MAX_TAG_LEN];
    char value[MAX_VALUE_LEN];
    struct Node* next;
    struct Node* child;
} Node;

Node* createNode(const char* tag, const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->tag, tag);
    strcpy(newNode->value, value);
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}

void addChild(Node* parent, Node* child) {
    if (!parent->child) {
        parent->child = child;
    } else {
        Node* temp = parent->child;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = child;
    }
}

void printTree(Node* node, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("Tag: %s, Value: %s\n", node->tag, node->value);
    if (node->child) {
        printTree(node->child, depth + 1);
    }
    if (node->next) {
        printTree(node->next, depth);
    }
}

void freeTree(Node* node) {
    if (node) {
        freeTree(node->child);
        freeTree(node->next);
        free(node);
    }
}

Node* parseXML(const char* xml) {
    Node* root = NULL;
    Node* current = NULL;
    char tag[MAX_TAG_LEN];
    char value[MAX_VALUE_LEN];
    const char* ptr = xml;
    
    while (*ptr) {
        if (*ptr == '<') {
            ptr++;
            if (*ptr == '/') {
                while (*ptr != '>') ptr++; // Skip closing tag
                ptr++;
                current = current ? current->next : NULL; // Go up one level
            } else {
                // Read tag name
                int tagLen = 0;
                while (*ptr != '>' && *ptr != ' ') {
                    tag[tagLen++] = *ptr++;
                }
                tag[tagLen] = '\0';

                // Create a new node
                Node* newNode = createNode(tag, "");

                // Add the node to the tree
                if (!root) {
                    root = newNode;
                } else {
                    addChild(current, newNode);
                }
                
                current = newNode; // Move current to the new node
                
                if (*ptr == '>') {
                    ptr++; // Move past '>'
                }
                // Skip value extraction if tag is self-closing or empty
                if (*ptr != '<') {
                    int valueLen = 0;
                    while (*ptr != '<') {
                        value[valueLen++] = *ptr++;
                    }
                    value[valueLen] = '\0';
                    strcpy(current->value, value); // Assign value
                }
            }
        } else {
            ptr++;
        }
    }
    
    return root;
}

int main() {
    char xml[MAX_XML_LEN] = "<greeting><text>Hello, world!</text><info><author>John Doe</author></info></greeting>";
    
    printf("Parsing XML: \n%s\n\n", xml);
    Node* root = parseXML(xml);
    
    printf("Parsed XML Tree:\n");
    printTree(root, 0);

    freeTree(root); // Clean up the memory
    return 0;
}