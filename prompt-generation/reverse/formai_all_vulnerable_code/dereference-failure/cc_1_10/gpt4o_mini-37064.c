//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME_LENGTH 50
#define MAX_CONTENT_LENGTH 256

typedef struct XmlNode {
    char tag[MAX_TAG_NAME_LENGTH];
    char content[MAX_CONTENT_LENGTH];
    struct XmlNode *next;
} XmlNode;

XmlNode *head = NULL;

// Function to create a new XML node
XmlNode* createNode(const char *tag, const char *content) {
    XmlNode *newNode = (XmlNode*) malloc(sizeof(XmlNode));
    strncpy(newNode->tag, tag, MAX_TAG_NAME_LENGTH);
    strncpy(newNode->content, content, MAX_CONTENT_LENGTH);
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the linked list
void addNode(XmlNode *node) {
    if (head == NULL) {
        head = node;
    } else {
        XmlNode *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

// Function to print the XML nodes
void printXmlNodes() {
    XmlNode *current = head;
    while (current != NULL) {
        printf("Tag: %s, Content: %s\n", current->tag, current->content);
        current = current->next;
    }
}

// Function to parse the XML file
void parseXmlFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return;
    }

    char line[512];
    char tag[MAX_TAG_NAME_LENGTH];
    char content[MAX_CONTENT_LENGTH];
    
    while (fgets(line, sizeof(line), file)) {
        char *tagStart = strchr(line, '<');
        char *tagEnd = strchr(line, '>');
        
        if (tagStart && tagEnd && tagEnd > tagStart) {
            size_t tagLength = tagEnd - tagStart - 1;
            memcpy(tag, tagStart + 1, tagLength);
            tag[tagLength] = '\0';
            
            // Now find the content, which should be after the tagEnd
            char *contentStart = tagEnd + 1; // Skip '>'
            char *contentEnd = strchr(contentStart, '<'); // Find next '<'
            if (contentEnd) {
                size_t contentLength = contentEnd - contentStart;
                memcpy(content, contentStart, contentLength);
                content[contentLength] = '\0';
                
                // Create and add the node to the list
                XmlNode *node = createNode(tag, content);
                addNode(node);
            }
        }
    }

    fclose(file);
}

// Cleanup function to free the memory
void cleanup() {
    XmlNode *current = head;
    while (current != NULL) {
        XmlNode *temp = current;
        current = current->next;
        free(temp);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    parseXmlFile(argv[1]);
    printf("Parsed XML Nodes:\n");
    printXmlNodes();
    cleanup();

    return EXIT_SUCCESS;
}