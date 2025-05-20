//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

typedef struct XMLNode {
    char *tagName;
    char *content;
    struct XMLNode *next;
    struct XMLNode *child;
} XMLNode;

// Function to create a new XML node
XMLNode* createNode(const char *tagName, const char *content) {
    XMLNode *newNode = (XMLNode *)malloc(sizeof(XMLNode));
    newNode->tagName = strdup(tagName);
    newNode->content = strdup(content);
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}

// Function to free XML node memory
void freeNode(XMLNode *node) {
    if (node) {
        free(node->tagName);
        free(node->content);
        free(node);
    }
}

// Function to parse a simple XML string
XMLNode* parseXML(const char *xml) {
    XMLNode *head = NULL;
    XMLNode *current = NULL;
    char buffer[MAX_BUFFER];
    int bufferIndex = 0;

    for (const char *ptr = xml; *ptr; ptr++) {
        if (*ptr == '<') {
            // If existing node is in progress, save it
            if (bufferIndex > 0) {
                buffer[bufferIndex] = '\0';
                if (current) {
                    current->content = strdup(buffer);
                }
                bufferIndex = 0;
            }

            // Read the tag name
            const char *tagStart = ptr + 1;
            const char *tagEnd = strchr(tagStart, '>');
            if (tagEnd == NULL) {
                break; // Malformed XML
            }

            size_t tagLength = tagEnd - tagStart;
            strncpy(buffer, tagStart, tagLength);
            buffer[tagLength] = '\0';

            if (*tagStart != '/') { // Opening tag
                XMLNode *newNode = createNode(buffer, "");
                if (!head) {
                    head = newNode; // Set head if first node
                } else {
                    current->next = newNode; // Link to previous node
                }
                current = newNode; // Move to current node
            } else { // Closing tag
                current = NULL; // End current node
            }
            ptr = tagEnd; // Move pointer past '>'
        } else if (current && bufferIndex < MAX_BUFFER - 1) {
            buffer[bufferIndex++] = *ptr; // Store content
        }
    }

    // Clean up the last node content
    if (bufferIndex > 0 && current) {
        buffer[bufferIndex] = '\0';
        current->content = strdup(buffer);
    }

    return head;
}

// Function to print the XML nodes
void printXML(XMLNode *node, int indent) {
    while (node) {
        for (int i = 0; i < indent; i++) {
            printf("  "); // Print indentation
        }
        printf("<%s>%s</%s>\n", node->tagName, node->content, node->tagName);
        printXML(node->child, indent + 1); // Recursive for child
        node = node->next; // Move to next sibling
    }
}

// Function to release the entire XML tree
void freeXML(XMLNode *node) {
    while (node) {
        XMLNode *next = node->next; // Store next node
        freeNode(node); // Free current node
        node = next; // Move to next
    }
}

// Main function to demonstrate XML parsing
int main() {
    const char *xmlData = "<root><element1>Content 1</element1><element2>Content 2</element2></root>";
    
    printf("Parsing XML:\n%s\n", xmlData);
    
    XMLNode *xmlTree = parseXML(xmlData);
    
    printf("\nParsed XML Structure:\n");
    printXML(xmlTree, 0); // Print the parsed XML in a structured way
    
    freeXML(xmlTree); // Free allocated nodes
    
    return 0;
}