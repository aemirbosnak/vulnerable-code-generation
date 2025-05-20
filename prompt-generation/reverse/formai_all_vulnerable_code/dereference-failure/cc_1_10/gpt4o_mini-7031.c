//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 100
#define MAX_VALUE_SIZE 256
#define MAX_CHILDREN 10

typedef struct Node {
    char tag[MAX_TAG_NAME];
    char value[MAX_VALUE_SIZE];
    struct Node *children[MAX_CHILDREN];
    int childCount;
} Node;

Node* createNode(const char* tag, const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->tag, tag, MAX_TAG_NAME);
    strncpy(newNode->value, value, MAX_VALUE_SIZE);
    newNode->childCount = 0;
    return newNode;
}

void addChild(Node* parent, Node* child) {
    if (parent->childCount < MAX_CHILDREN) {
        parent->children[parent->childCount++] = child;
    } else {
        printf("Maximum child limit reached for tag: %s\n", parent->tag);
    }
}

void parseXML(FILE* file, Node* currentNode) {
    char line[512];
    while (fgets(line, sizeof(line), file)) {
        char tag[MAX_TAG_NAME];
        char value[MAX_VALUE_SIZE];

        // Try to find and parse opening tag
        if (sscanf(line, "<%99[^>]>%255[^\n]", tag, value) == 2) {
            Node* newNode = createNode(tag, value);
            addChild(currentNode, newNode);
            parseXML(file, newNode); // Recursively parse children
        }

        // Try to find and parse closing tag
        else if (sscanf(line, "</%99[^>]>") == 1) {
            return; // Return to the parent node
        }
    }
}

void printNode(Node* node, int level) {
    if (!node) return;

    for (int i = 0; i < level; i++) {
        printf("    "); // Indent based on level
    }
    printf("Tag: %s, Value: %s\n", node->tag, node->value);

    for (int i = 0; i < node->childCount; i++) {
        printNode(node->children[i], level + 1); // Print each child
    }
}

void freeNode(Node* node) {
    if (!node) return;

    for (int i = 0; i < node->childCount; i++) {
        freeNode(node->children[i]); // Recursively free children
    }
    free(node); // Free the current node
}

int main() {
    // Opening XML file for parsing
    FILE* file = fopen("example.xml", "r");
    if (!file) {
        fprintf(stderr, "Error opening file!\n");
        return 1;
    }

    // Create the root node for the XML parse tree
    Node* root = createNode("root", ""); // Dummy root node
    parseXML(file, root); // Start parsing the XML

    // Close the file when done
    fclose(file);

    // Print the parsed XML structure
    printf("Parsed XML Structure:\n");
    printNode(root, 0);

    // Free allocated memory
    freeNode(root);

    return 0;
}