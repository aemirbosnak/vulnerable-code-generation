//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ELEMENTS 100

typedef struct Element {
    char name[50];
    char value[256];
} Element;

typedef struct XMLNode {
    Element elements[MAX_ELEMENTS];
    int elementCount;
    struct XMLNode* next;
} XMLNode;

// Function to initialize a new XML Node
XMLNode* createNode() {
    XMLNode* node = (XMLNode*)malloc(sizeof(XMLNode));
    node->elementCount = 0;
    node->next = NULL;
    return node;
}

// Function to parse a single line of XML
void parseLine(XMLNode* currentNode, const char* line) {
    char name[50] = {0};
    char value[256] = {0};

    if (sscanf(line, "<%[^>]>%[^<]</%[^>]", name, value, name) == 3) {
        // Found an element
        if (currentNode->elementCount < MAX_ELEMENTS) {
            strcpy(currentNode->elements[currentNode->elementCount].name, name);
            strcpy(currentNode->elements[currentNode->elementCount].value, value);
            currentNode->elementCount++;
        }
    }
}

// Function to print the XMLNode’s elements
void printXMLNode(XMLNode* node) {
    for (int i = 0; i < node->elementCount; i++) {
        printf("Element Name: %s, Value: %s\n", node->elements[i].name, node->elements[i].value);
    }
}

// The grand affair begins here
void parseXML(const char* filepath) {
    FILE* file = fopen(filepath, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filepath);
        return;
    }

    char line[MAX_LINE_LENGTH];
    XMLNode* head = createNode();
    XMLNode* currentNode = head;

    while (fgets(line, sizeof(line), file)) {
        parseLine(currentNode, line);
    }

    fclose(file);
    
    // Embrace the findings
    printf("The Contents of the Parsed XML:\n");
    printXMLNode(head);
    
    // Free allocated memory
    free(head);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml-file-path>\n", argv[0]);
        return 1;
    }

    printf("Elementary my dear Watson, we shall parse the XML file...\n");
    parseXML(argv[1]);

    printf("The investigation concludes, and the case of the XML document is solved.\n");
    return 0;
}