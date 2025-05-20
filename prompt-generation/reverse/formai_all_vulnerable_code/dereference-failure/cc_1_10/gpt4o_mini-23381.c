//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* element;
    struct Node* children;
    struct Node* sibling;
} Node;

Node* createNode(const char* element) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->element = strdup(element);
    newNode->children = NULL;
    newNode->sibling = NULL;
    return newNode;
}

void addChild(Node* parent, Node* child) {
    if (parent->children == NULL) {
        parent->children = child;
    } else {
        Node* temp = parent->children;
        while (temp->sibling) {
            temp = temp->sibling;
        }
        temp->sibling = child;
    }
}

void freeNode(Node* node) {
    if (node == NULL) return;
    free(node->element);
    freeNode(node->children);
    freeNode(node->sibling);
    free(node);
}

Node* parseXML(const char* xml) {
    Node* root = NULL;
    Node* current = NULL;
    const char* pos = xml;
    char tag[128];
    int isClosingTag = 0;
    
    while (*pos) {
        if (*pos == '<') {
            isClosingTag = (*(pos + 1) == '/');
            pos++;
            if (isClosingTag) pos++; // Skip '/'
            sscanf(pos, "%127[^>]", tag);
            pos += strlen(tag) + 1; // Move past the tag
            
            if (isClosingTag) {
                // Handle closing tag
                if (current && strcmp(current->element, tag) == 0) {
                    Node* temp = current;
                    current = NULL; // Move up to the parent
                    temp->sibling = root; // Attach completed child to root
                    root = temp;
                }
            } else {
                // Handle opening tag
                Node* newNode = createNode(tag);
                if (current) {
                    addChild(current, newNode);
                } else {
                    root = newNode; // It's the root element
                }
                current = newNode; // Move to the new node
            }
        }
        pos++;
    }
    return root;
}

void printXMLTree(Node* node, int depth) {
    if (node == NULL) return;
    for (int i = 0; i < depth; i++) {
        printf("\t");
    }
    printf("%s\n", node->element);
    printXMLTree(node->children, depth + 1);
    printXMLTree(node->sibling, depth);
}

int main() {
    const char* xmlData = "<root><child1><subchild1/></child1><child2/></root>";
    Node* xmlTree = parseXML(xmlData);
    
    printf("Parsed XML Structure:\n");
    printXMLTree(xmlTree, 0);
    
    freeNode(xmlTree);
    return 0;
}