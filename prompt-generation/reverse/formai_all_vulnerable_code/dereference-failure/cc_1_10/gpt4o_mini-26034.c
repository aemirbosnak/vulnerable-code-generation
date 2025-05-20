//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char tag[50];
    char value[100];
    struct Node *child;
    struct Node *sibling;
} Node;

Node* createNode(const char* tag, const char* value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->tag, tag);
    strcpy(newNode->value, value);
    newNode->child = NULL;
    newNode->sibling = NULL;
    return newNode;
}

void addChild(Node *parent, Node *child) {
    if (parent->child == NULL) {
        parent->child = child;
    } else {
        Node *sibling = parent->child;
        while (sibling->sibling != NULL) {
            sibling = sibling->sibling;
        }
        sibling->sibling = child;
    }
}

void freeTree(Node *root) {
    if (root) {
        freeTree(root->child);
        freeTree(root->sibling);
        free(root);
    }
}

void printTree(Node* root, int depth) {
    if (!root) return;
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>%s</%s>\n", root->tag, root->value, root->tag);
    printTree(root->child, depth + 1);
    printTree(root->sibling, depth);
}

Node* parseXML(const char* xml) {
    Node *root = NULL;
    Node *current = NULL;
    char tag[50], value[100];
    const char *pos = xml, *end;
    
    while (*pos) {
        if (*pos == '<') {
            end = strchr(pos, '>');
            if (end == NULL) {
                break; // Unmatched '<'
            }
            int tagLength = end - pos - 1;
            strncpy(tag, pos + 1, tagLength);
            tag[tagLength] = '\0';
            
            if (*(end + 1) != '<') {  // this is a value
                pos = end + 1;
                end = strchr(pos, '<');
                if (end == NULL) {
                    break; // Unmatched '<'
                }
                int valueLength = end - pos;
                strncpy(value, pos, valueLength);
                value[valueLength] = '\0';
                pos = end;
                
                Node *newNode = createNode(tag, value);
                if (!root) {
                    root = newNode;
                } else {
                    addChild(current, newNode);
                }
                current = newNode;
            } else { // Found end tag
                current = current->sibling; // Go back to the parent
            }
            pos = end + 1; // Move past '>'
        } else {
            pos++; // Move forward if not at '<'
        }
    }
    
    return root;
}

int main() {
    const char *xmlData = "<book><title>XML Basics</title><author>John Doe</author></book>";
    
    Node *tree = parseXML(xmlData);
    
    printf("Parsed XML Tree:\n");
    printTree(tree, 0);
    
    freeTree(tree);
    return 0;
}