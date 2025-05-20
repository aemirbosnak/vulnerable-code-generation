//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024
#define MAX_TAG_NAME 100
#define MAX_XML_SIZE 10240

typedef struct XmlNode {
    char tagName[MAX_TAG_NAME];
    char content[MAX_BUFFER];
    struct XmlNode* next;
    struct XmlNode* child;
} XmlNode;

// Function to create a new XML node
XmlNode* createNode(const char* tagName, const char* content) {
    XmlNode* newNode = (XmlNode*)malloc(sizeof(XmlNode));
    strncpy(newNode->tagName, tagName, MAX_TAG_NAME);
    strncpy(newNode->content, content, MAX_BUFFER);
    newNode->next = NULL;
    newNode->child = NULL;
    return newNode;
}

// Function to parse the XML content
XmlNode* parseXML(const char* xml) {
    XmlNode* head = NULL;
    XmlNode* tail = NULL;
    XmlNode* currentNode = NULL;

    const char* cursor = xml;
    char tagName[MAX_TAG_NAME];
    char content[MAX_BUFFER];
    
    while (*cursor) {
        if (*cursor == '<') {
            cursor++;
            if (*cursor == '/') { // Closing tag
                while (*cursor != '>') cursor++;
                cursor++;
                continue;
            }

            int tagIndex = 0;
            while (*cursor != '>' && tagIndex < MAX_TAG_NAME - 1) {
                tagName[tagIndex++] = *cursor++;
            }
            tagName[tagIndex] = '\0';
            cursor++; // Skip '>'

            // Grab the content until we hit a new tag
            int contentIndex = 0;
            while (*cursor && *cursor != '<' && contentIndex < MAX_BUFFER - 1) {
                content[contentIndex++] = *cursor++;
            }
            content[contentIndex] = '\0';

            // Create a new node and append it to the list
            XmlNode* newNode = createNode(tagName, content);
            if (head == NULL) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
            continue;
        }
        cursor++;
    }
    return head;
}

// Function to print the XML nodes
void printXml(XmlNode* node) {
    while (node) {
        printf("Tag: <%s>, Content: '%s'\n", node->tagName, node->content);
        if (node->child) {
            printXml(node->child);
        }
        node = node->next;
    }
}

// Function to free the XML nodes
void freeXml(XmlNode* node) {
    while (node) {
        XmlNode* nextNode = node->next;
        free(node);
        node = nextNode;
    }
}

int main() {
    const char* xmlData = "<note><to>Tove</to><from>Jani</from><heading>Reminder</heading><body>Don't forget me this weekend!</body></note>";

    XmlNode* parsedXml = parseXML(xmlData);
    printf("Parsed XML Data:\n");
    printXml(parsedXml);

    freeXml(parsedXml);
    return 0;
}