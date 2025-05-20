//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_NAME 64
#define MAX_TAG_VALUE 256

typedef struct XmlNode {
    char tag[MAX_TAG_NAME];
    char value[MAX_TAG_VALUE];
    struct XmlNode *next;
    struct XmlNode *child;
} XmlNode;

// Function to create a new XML node
XmlNode* createNode(const char* tag, const char* value) {
    XmlNode *node = (XmlNode *)malloc(sizeof(XmlNode));
    if (!node) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strncpy(node->tag, tag, MAX_TAG_NAME);
    strncpy(node->value, value, MAX_TAG_VALUE);
    node->next = NULL;
    node->child = NULL;

    return node;
}

// Function to parse a line containing XML data
int parseLine(char *line, XmlNode **currentNode) {
    char tag[MAX_TAG_NAME];
    char value[MAX_TAG_VALUE];

    // Look for the start of a tag
    if (sscanf(line, "<%63[^>]>", tag) == 1) {
        // It's a start tag
        XmlNode *newNode = createNode(tag, "");
        newNode->next = (*currentNode);
        (*currentNode) = newNode;

        // Extracting value if there's text after the tag
        char* text = strstr(line, ">") + 1;
        char* endTag = strstr(text, "</");
        if (endTag) {
            int length = endTag - text;
            strncpy(newNode->value, text, length);
            newNode->value[length] = '\0';
        }

        // Move to process next line
        return 1;
    } else if (sscanf(line, "</%63[^>]", tag) == 1) {
        // It's an end tag
        XmlNode *parent = (*currentNode);
        (*currentNode) = (*currentNode)->next; // Move up to the previous node
        return 2;
    }
  
    return 0; // Not a tag
}

// Function to print the parsed XML nodes
void printXml(XmlNode *node, int level) {
    if (!node) return;

    for (int i = 0; i < level; i++) {
        printf("  "); // Indentation for pretty printing
    }

    printf("<%s>%s</%s>\n", node->tag, node->value[0] ? node->value : "", node->tag);
    printXml(node->child, level + 1);
    printXml(node->next, level);
}

// Function to free allocated memory for XML nodes
void freeXml(XmlNode *node) {
    if (!node) return;
    
    freeXml(node->child);
    freeXml(node->next);
    free(node);
}

// Main function to drive the XML parser
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    XmlNode *currentNode = NULL;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file)) {
        parseLine(line, &currentNode);
    }

    fclose(file);

    // Printing the parsed XML in a structured format
    printf("Parsed XML:\n");
    printXml(currentNode, 0);

    // Cleanup allocated memory
    freeXml(currentNode);

    return EXIT_SUCCESS;
}