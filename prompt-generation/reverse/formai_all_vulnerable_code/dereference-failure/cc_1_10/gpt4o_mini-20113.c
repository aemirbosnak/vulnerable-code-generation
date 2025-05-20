//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256
#define MAX_TAG_LENGTH 64
#define MAX_VALUE_LENGTH 256

typedef struct Tag {
    char name[MAX_TAG_LENGTH];
    char value[MAX_VALUE_LENGTH];
} Tag;

typedef struct Node {
    Tag tag;
    struct Node *next;
    struct Node *children;
} Node;

Node* createNode(const char* name, const char* value) {
    Node *newNode = malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Out of memory!\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->tag.name, name, MAX_TAG_LENGTH);
    strncpy(newNode->tag.value, value, MAX_VALUE_LENGTH);
    newNode->next = NULL;
    newNode->children = NULL;
    return newNode;
}

void addChild(Node* parent, Node* child) {
    if (parent->children == NULL) {
        parent->children = child;
    } else {
        Node* current = parent->children;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = child;
    }
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->children);
    freeTree(root->next);
    free(root);
}

void printTree(Node* root, int depth) {
    if (!root) return;
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("<%s>%s</%s>\n", root->tag.name, root->tag.value[0] ? root->tag.value : "", root->tag.name);
    printTree(root->children, depth + 1);
    printTree(root->next, depth);
}

Node* parseXML(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Cannot open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    Node *root = NULL;
    Node *currentNode = NULL;

    while (fgets(line, sizeof(line), file)) {
        // Strip newline from the end of the line
        line[strcspn(line, "\n")] = '\0';

        if (line[0] == '<') {  // Start of a tag
            char tagName[MAX_TAG_LENGTH], tagValue[MAX_VALUE_LENGTH];
            if (sscanf(line, "<%[^>]>%[^<</%*s", tagName, tagValue) == 2) {
                Node *newNode = createNode(tagName, tagValue);
                if (root == NULL) {
                    root = newNode;  // Set root only once
                } else if (currentNode) {
                    addChild(currentNode, newNode);
                }
                currentNode = newNode;  // Move down in the tree
            } else if (sscanf(line, "</%[^>]>") == 1) {
                // End of a tag, move up in the tree
                if (currentNode) {
                    currentNode = currentNode->next;  // Move back to parent
                }
            }
        }
    }

    fclose(file);
    return root;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Node *xmlTree = parseXML(argv[1]);
    printf("Survivor's Crib: XML Document Gleaned from the Ruins:\n");
    printTree(xmlTree, 0);
    freeTree(xmlTree);
    return 0;
}