//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 256
#define MAX_VALUE_LENGTH 512

typedef struct Node {
    char tag[MAX_TAG_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct Node* children;
    struct Node* sibling;
} Node;

Node* createNode(const char* tag, const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->tag, tag, MAX_TAG_LENGTH);
    strncpy(newNode->value, value, MAX_VALUE_LENGTH);
    newNode->children = NULL;
    newNode->sibling = NULL;
    return newNode;
}

void appendChild(Node* parent, Node* child) {
    if (parent->children == NULL) {
        parent->children = child;
    } else {
        Node* current = parent->children;
        while (current->sibling != NULL) {
            current = current->sibling;
        }
        current->sibling = child;
    }
}

void freeTree(Node* root) {
    if (root) {
        freeTree(root->children);
        freeTree(root->sibling);
        free(root);
    }
}

Node* parseXML(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    Node* root = NULL;
    Node* current = NULL;

    while (fgets(line, sizeof(line), file)) {
        char tag[MAX_TAG_LENGTH];
        char value[MAX_VALUE_LENGTH];
        if (sscanf(line, " <%[^>]> ", tag) == 1) {
            // New tag
            Node* node = createNode(tag, "");
            if (root == NULL) {
                root = node; // Set root
            } else if (current != NULL) {
                appendChild(current, node); // Append to current
            }
            current = node; // Update current
        } else if (sscanf(line, " </%[^>]> ", tag) == 1) {
            // Closing tag
            if (current != NULL && strcmp(current->tag, tag) == 0) {
                current = current->sibling; // Move back to the previous node
            }
        } else if (sscanf(line, " <%[^>]>\n %[^<]", tag, value) == 2) {
            // Tag with a value
            Node* node = createNode(tag, value);
            if (root == NULL) {
                root = node; 
            } else if (current != NULL) {
                appendChild(current, node); 
            }
        }
    }

    fclose(file);
    return root;
}

void printTree(Node* root, int depth) {
    if (root == NULL) return;

    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>", root->tag);

    if (strlen(root->value) > 0) {
        printf(" %s", root->value);
    }
    
    printf("\n");
    printTree(root->children, depth + 1);
    for (Node* sibling = root->sibling; sibling != NULL; sibling = sibling->sibling) {
        printTree(sibling, depth);
    }

    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("</%s>\n", root->tag);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return 1;
    }

    Node* root = parseXML(argv[1]);
    if (root) {
        printTree(root, 0);
        freeTree(root);
    }

    return 0;
}