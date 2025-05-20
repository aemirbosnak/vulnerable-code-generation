//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_LENGTH 50
#define MAX_CONTENT_LENGTH 200

typedef struct XmlNode {
    char tag[MAX_TAG_LENGTH];
    char content[MAX_CONTENT_LENGTH];
    struct XmlNode *next;
} XmlNode;

// Function to create a new XML node
XmlNode* createNode(const char* tag, const char* content) {
    XmlNode *newNode = (XmlNode*)malloc(sizeof(XmlNode));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->tag, tag, MAX_TAG_LENGTH);
    strncpy(newNode->content, content, MAX_CONTENT_LENGTH);
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the linked list of XML nodes
void addNode(XmlNode **head, const char* tag, const char* content) {
    XmlNode *newNode = createNode(tag, content);
    newNode->next = *head;
    *head = newNode;
}

// Function to free the linked list nodes
void freeNodes(XmlNode *head) {
    XmlNode *temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// Function to parse XML from a file
void parseXml(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Cannot open file: %s\n", filename);
        return;
    }

    char line[256];
    XmlNode *head = NULL;

    while (fgets(line, sizeof(line), file)) {
        char tag[MAX_TAG_LENGTH];
        char content[MAX_CONTENT_LENGTH];
        
        // Initialize buffers
        tag[0] = '\0';
        content[0] = '\0';

        // Basic parsing logic: Extracting tags and content
        char *startTag = strstr(line, "<");
        char *endTag = strstr(line, ">");
        
        if (startTag && endTag && startTag < endTag) {
            strncpy(tag, startTag + 1, endTag - startTag - 1);
            tag[endTag - startTag - 1] = '\0';
        }

        char *contentStart = endTag + 1;
        char *contentEnd = strstr(contentStart, "<");

        if (contentStart < contentEnd && contentEnd) {
            strncpy(content, contentStart, contentEnd - contentStart);
            content[contentEnd - contentStart] = '\0';
            addNode(&head, tag, content);
        }
    }

    fclose(file);

    // Print parsed XML contents
    XmlNode *current = head;
    while (current) {
        printf("Tag: %s, Content: %s\n", current->tag, current->content);
        current = current->next;
    }

    // Clean up
    freeNodes(head);
}

int main() {
    const char *filename = "example.xml";
    parseXml(filename);
    return 0;
}