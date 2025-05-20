//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char tag[50];
    char value[100];
    struct Node* children[10]; // Maximum 10 children
    int child_count;
} Node;

// Function prototypes
Node* createNode(const char* tag, const char* value);
void freeNode(Node* node);
void printXML(Node* node, int level);
void parseXML(const char* filename, Node* node);
void parseStartTag(char* line, Node* parent);
void parseEndTag(char* line, Node* currentNode);
void parseValue(char* line, Node* currentNode);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Node* root = createNode("root", ""); // Root node
    parseXML(argv[1], root);
    printXML(root, 0);
    freeNode(root);
    
    return EXIT_SUCCESS;
}

Node* createNode(const char* tag, const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->tag, tag);
    strcpy(newNode->value, value);
    newNode->child_count = 0;
    return newNode;
}

void freeNode(Node* node) {
    for (int i = 0; i < node->child_count; i++) {
        freeNode(node->children[i]);
    }
    free(node);
}

void printXML(Node* node, int level) {
    if (node == NULL) return;

    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("<%s>\n", node->tag);
    if (strlen(node->value) > 0) {
        for (int i = 0; i < level + 1; i++) {
            printf("  ");
        }
        printf("%s\n", node->value);
    }
    for (int i = 0; i < node->child_count; i++) {
        printXML(node->children[i], level + 1);
    }
    for (int i = 0; i < level; i++) {
        printf("  ");
    }
    printf("</%s>\n", node->tag);
}

void parseXML(const char* filename, Node* node) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[150];
    Node* currentNode = node;

    while (fgets(line, sizeof(line), file)) {
        char* trimmed_line = strtok(line, "\n");
        // Handle comments or empty lines
        if (trimmed_line[0] == '<' && trimmed_line[1] == '?') {
            continue; // skip declaration
        } else if (strncmp(trimmed_line, "<!--", 4) == 0) {
            continue; // skip comments
        } else if (strncmp(trimmed_line, "<", 1) == 0) {
            if (strchr(trimmed_line, '/')) {
                parseEndTag(trimmed_line, currentNode);
                if (currentNode->child_count > 0) {
                    currentNode = currentNode->children[currentNode->child_count - 1]; // Move to last child
                }
            } else {
                parseStartTag(trimmed_line, currentNode);
                currentNode = currentNode->children[currentNode->child_count - 1]; // Switch to new child
            }
        } else {
            parseValue(trimmed_line, currentNode);
        }
    }

    fclose(file);
}

void parseStartTag(char* line, Node* parent) {
    char tag[50];
    sscanf(line, "<%s", tag);
    tag[strcspn(tag, " >")] = 0; // Remove extra characters

    Node* newNode = createNode(tag, "");
    parent->children[parent->child_count++] = newNode;
}

void parseEndTag(char* line, Node* currentNode) {
    char tag[50];
    sscanf(line, "</%s", tag);
    tag[strcspn(tag, " >")] = 0; // Remove extra characters
}

void parseValue(char* line, Node* currentNode) {
    strcat(currentNode->value, line);
    currentNode->value[strcspn(currentNode->value, "\n")] = 0; // Remove newline
}