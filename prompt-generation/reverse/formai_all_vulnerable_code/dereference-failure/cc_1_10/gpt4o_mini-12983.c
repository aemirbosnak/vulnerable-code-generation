//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024
#define MAX_TAG_NAME 100
#define MAX_VALUE 100

typedef struct XMLNode {
    char tagName[MAX_TAG_NAME];
    char value[MAX_VALUE];
    struct XMLNode *next;
} XMLNode;

// Function prototypes
XMLNode* createNode(const char* tagName, const char* value);
void freeXMLNode(XMLNode* node);
void printXML(XMLNode* root);
void parseXMLFile(const char* filename, XMLNode** root);
void trimWhitespace(char* str);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    XMLNode* root = NULL;
    parseXMLFile(argv[1], &root);
    printXML(root);

    // Free the allocated memory
    XMLNode* current = root;
    while (current) {
        XMLNode* next = current->next;
        freeXMLNode(current);
        current = next;
    }

    return EXIT_SUCCESS;
}

XMLNode* createNode(const char* tagName, const char* value) {
    XMLNode* newNode = (XMLNode*)malloc(sizeof(XMLNode));
    if (!newNode) {
        fprintf(stderr, "Memory allocation error.\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->tagName, tagName, MAX_TAG_NAME);
    strncpy(newNode->value, value, MAX_VALUE);
    newNode->next = NULL;
    return newNode;
}

void freeXMLNode(XMLNode* node) {
    free(node);
}

void printXML(XMLNode* root) {
    XMLNode* current = root;
    while (current) {
        printf("Tag: <%s>, Value: '%s'\n", current->tagName, current->value);
        current = current->next;
    }
}

void parseXMLFile(const char* filename, XMLNode** root) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_BUFFER];
    XMLNode* lastNode = NULL;

    while (fgets(buffer, sizeof(buffer), file)) {
        char tagName[MAX_TAG_NAME];
        char value[MAX_VALUE];

        // Check for opening tag
        if (sscanf(buffer, " <%[^>]> ", tagName) == 1) {
            // Read the next line for value
            if (fgets(buffer, sizeof(buffer), file)) {
                trimWhitespace(buffer);
                if (sscanf(buffer, "%s", value) == 1) {
                    XMLNode* newNode = createNode(tagName, value);
                    if (*root == NULL) {
                        *root = newNode; // Set as root node
                    } else {
                        lastNode->next = newNode; // Append to the list
                    }
                    lastNode = newNode; // Update last node
                }
            }
        }
    }

    fclose(file);
}

void trimWhitespace(char* str) {
    char* end = str + strlen(str) - 1;
    
    while (end > str && (*end == ' ' || *end == '\n')) {
        *end = '\0';
        end--;
    }
}