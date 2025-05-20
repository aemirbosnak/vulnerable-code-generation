//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TOKEN_SIZE 100
#define MAX_LINE_SIZE 1024

typedef struct Node {
    char tag[MAX_TOKEN_SIZE];
    char value[MAX_LINE_SIZE];
    struct Node* next;
    struct Node* children;
} Node;

Node* createNode(const char* tag) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strncpy(newNode->tag, tag, MAX_TOKEN_SIZE);
    newNode->tag[MAX_TOKEN_SIZE - 1] = '\0';
    newNode->value[0] = '\0';
    newNode->next = NULL;
    newNode->children = NULL;
    return newNode;
}

void freeNode(Node* node) {
    if (node != NULL) {
        freeNode(node->next);
        freeNode(node->children);
        free(node);
    }
}

Node* parseXML(FILE* file) {
    char line[MAX_LINE_SIZE];
    Node* root = createNode("root");
    Node* currentNode = root;
    char tagBuffer[MAX_TOKEN_SIZE];
    char valueBuffer[MAX_LINE_SIZE];
    int inTag = 0, inValue = 0;

    while (fgets(line, sizeof(line), file) != NULL) {
        char* ptr = line;
        while (*ptr) {
            if (*ptr == '<') {
                inTag = 1;
                sscanf(ptr, "<%[^>]", tagBuffer);
                currentNode->children = createNode(tagBuffer);
                currentNode = currentNode->children;
                ptr += strlen(tagBuffer) + 2; // Move past the tag
            } else if (*ptr == '>') {
                inTag = 0;
                ptr++; // Move past the '>'
            } else if (*ptr == '/') {
                // Assuming the format is like </tag>
                sscanf(ptr, "</%[^>]", tagBuffer);
                currentNode = currentNode->next;
                ptr += strlen(tagBuffer) + 3; // Move past the closing tag
            } else if (*ptr == '\n' || *ptr == '\r') {
                ptr++; // Skip line endings
            } else {
                inValue = 1;
                // Copy the value until we hit a special character
                char* start = ptr;
                while (*ptr && *ptr != '<' && *ptr != '/') {
                    ptr++;
                }
                strncpy(valueBuffer, start, ptr - start);
                valueBuffer[ptr - start] = '\0';
                strncpy(currentNode->value, valueBuffer, MAX_LINE_SIZE);
                currentNode->value[MAX_LINE_SIZE - 1] = '\0';
            }
        }
    }
    return root;
}

void printXML(Node* node, int indent) {
    if (node == NULL) {
        return;
    }

    for (int i = 0; i < indent; i++) {
        printf("  ");
    }
    printf("<%s>", node->tag);
    if (strlen(node->value) > 0) {
        printf("%s", node->value);
    }
    printf("\n");

    printXML(node->children, indent + 1);
    printXML(node->next, indent);
    for (int i = 0; i < indent; i++) {
        printf("  ");
    }
    printf("</%s>\n", node->tag);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <xmlfile>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    Node* root = parseXML(file);
    fclose(file);

    printXML(root, 0);

    freeNode(root);
    return EXIT_SUCCESS;
}