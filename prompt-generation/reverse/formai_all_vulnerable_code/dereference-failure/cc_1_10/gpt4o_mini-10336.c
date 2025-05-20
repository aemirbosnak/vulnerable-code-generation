//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LENGTH 100
#define MAX_VALUE_LENGTH 256
#define MAX_CHILDREN 10

typedef struct Node {
    char tag[MAX_TAG_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct Node* children[MAX_CHILDREN];
    int child_count;
} Node;

Node* createNode(const char* tag) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        perror("Failed to allocate memory for node");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->tag, tag, MAX_TAG_LENGTH);
    newNode->value[0] = '\0'; // Initialize value as an empty string.
    newNode->child_count = 0;
    return newNode;
}

void freeNode(Node* node) {
    for (int i = 0; i < node->child_count; i++) {
        freeNode(node->children[i]);
    }
    free(node);
}

void parseXML(FILE* file, Node* parent) {
    char line[512];
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "</") != NULL) {
            // End of current element
            return;
        } else if (strstr(line, "<") != NULL) {
            // Start of a new element
            Node* child = createNode(strtok(line + 1, ">")); // Get tag name
            if (strchr(child->tag, ' ')) {
                *strchr(child->tag, ' ') = '\0'; // Remove attributes if present.
            }
            parent->children[parent->child_count++] = child;

            // Check if value is present in the same line
            char* value = strchr(line, '>');
            if (value != NULL) {
                value++; // Move to the character after '>'
                if (*value != '\n' && *value != '<') {
                    // Extract value until next <
                    char* endValue = strchr(value, '<');
                    if (endValue != NULL) {
                        strncpy(child->value, value, endValue - value);
                        child->value[endValue - value] = '\0'; // Null terminate
                    }
                }
            }

            // Recursive parse for children
            parseXML(file, child);
        }
    }
}

void printNode(Node* node, int indent) {
    for (int i = 0; i < indent; i++)
        printf("  ");
    printf("<%s>", node->tag);
    if (strlen(node->value) > 0) {
        printf(" %s", node->value);
    }
    printf("\n");

    for (int i = 0; i < node->child_count; i++) {
        printNode(node->children[i], indent + 1);
    }

    for (int i = 0; i < indent; i++)
        printf("  ");
    printf("</%s>\n", node->tag);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE* xmlFile = fopen(argv[1], "r");
    if (xmlFile == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    Node* root = createNode("root");
    parseXML(xmlFile, root);
    fclose(xmlFile);

    // Print the parsed XML
    printf("Parsed XML structure:\n");
    printNode(root, 0);

    freeNode(root);
    return EXIT_SUCCESS;
}