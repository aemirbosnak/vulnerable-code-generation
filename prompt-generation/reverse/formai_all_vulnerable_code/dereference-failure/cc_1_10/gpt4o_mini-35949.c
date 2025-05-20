//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: mind-bending
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
        printf("Maximum children reached for node %s\n", parent->name);
    }
}

void freeNode(Node *node) {
    for (int i = 0; i < node->childCount; i++) {
        freeNode(node->children[i]);
    }
    free(node);
}

void printXML(Node *node, int depth) {
    if (node == NULL) return;
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    
    if (strlen(node->value) > 0) {
        printf("<%s>%s</%s>\n", node->name, node->value, node->name);
    } else {
        printf("<%s>\n", node->name);
        for (int i = 0; i < node->childCount; i++) {
            printXML(node->children[i], depth + 1);
        }
        for (int i = 0; i < depth; i++) {
            printf("  ");
        }
        printf("</%s>\n", node->name);
    }
}

Node* parseXML(const char *xml) {
    Node *root = NULL;
    Node *currentParent = NULL;
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
    int i = 0, j = 0;
    char parsingValue = 0;

    while (xml[i] != '\0') {
        if (xml[i] == '<') {
            // Closing tag
            if (xml[i + 1] == '/') {
                i += 2; // Skip "</"
                while (xml[i] != '>') {
                    i++;
                }
                i++; // Skip ">"
                currentParent = NULL; // Go back to parent (if implemented)
            } else {
                // Opening tag
                i++; // Skip "<"
                j = 0; // Reset name index
                while (xml[i] != '>' && xml[i] != ' ') {
                    name[j++] = xml[i++];
                }
                name[j] = '\0'; // Null-terminate the string
                
                // Create a new node
                if (!root) { 
                    root = createNode(name, "");
                    currentParent = root;
                } else {
                    Node *newNode = createNode(name, "");
                    addChild(currentParent, newNode);
                    currentParent = newNode;
                }
                
                // Check for attributes or value
                if (xml[i] == ' ') {
                    while (xml[i] != '>') i++; // Skip attributes
                } 
                
                i++; // Skip ">"
            }
        } else if (xml[i] != '\0') {
            // Text value
            j = 0;
            while (xml[i] != '<' && xml[i] != '\0') {
                value[j++] = xml[i++];
            }
            value[j] = '\0'; // Null terminate value
            
            if (currentParent) {
                strncpy(currentParent->value, value, MAX_VALUE_LENGTH);
                parsingValue = 1;
            }
        }
    }
    
    return root;
}

int main() {
    const char *xmlData = 
        "<book>\n"
        "  <title>The C Programming Language</title>\n"
        "  <author>Brian W. Kernighan</author>\n"
        "  <author>Dennis M. Ritchie</author>\n"
        "  <year>1978</year>\n"
        "  <price>39.95</price>\n"
        "</book>\n";
    
    Node *parsedXML = parseXML(xmlData);
    printXML(parsedXML, 0);
    freeNode(parsedXML);
    
    return 0;
}