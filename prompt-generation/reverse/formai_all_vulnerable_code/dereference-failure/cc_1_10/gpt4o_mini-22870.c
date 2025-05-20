//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 50
#define MAX_TAG_CONTENT 100
#define MAX_XML_SIZE 1024

typedef struct XMLNode {
    char tagName[MAX_TAG_NAME];
    char content[MAX_TAG_CONTENT];
    struct XMLNode* next;
} XMLNode;

XMLNode* createNode(const char* tagName, const char* content) {
    XMLNode* newNode = (XMLNode*)malloc(sizeof(XMLNode));
    strcpy(newNode->tagName, tagName);
    strcpy(newNode->content, content);
    newNode->next = NULL;
    return newNode;
}

void appendNode(XMLNode** head, const char* tagName, const char* content) {
    if (*head == NULL) {
        *head = createNode(tagName, content);
    } else {
        XMLNode* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = createNode(tagName, content);
    }
}

void freeNodes(XMLNode* head) {
    XMLNode* current = head;
    XMLNode* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

void printXMLNodes(XMLNode* head) {
    XMLNode* current = head;
    printf("\nThe Clue Presentation:\n");
    while (current != NULL) {
        printf("Tag: <%s>, Content: %s\n", current->tagName, current->content);
        current = current->next;
    }
}

void parseXML(const char* xmlString, XMLNode** head) {
    const char* start;
    const char* end;
    char tagName[MAX_TAG_NAME];
    char content[MAX_TAG_CONTENT];
    
    start = xmlString;
    while ((start = strchr(start, '<')) != NULL) {
        end = strchr(start, '>');
        if (end == NULL) break;

        // Find the tag name
        int tagNameLength = end - start - 1;
        strncpy(tagName, start + 1, tagNameLength);
        tagName[tagNameLength] = '\0';

        // Find the content
        start = end + 1;
        end = strchr(start, '<');
        if (end == NULL) break;

        int contentLength = end - start;
        strncpy(content, start, contentLength);
        content[contentLength] = '\0';

        // Append the node to the list
        appendNode(head, tagName, content);

        // Move the start pointer
        start = end;
    }
}

int main() {
    puts("Elementary, my dear Watson!");

    const char* xmlInput = "<note> <to>Tidwell</to> <from>Sherlock</from> <heading>Reminder</heading> <body>Do not forget to parse XML!</body> </note>";
    XMLNode* head = NULL;

    printf("Input XML:\n%s\n", xmlInput);
    parseXML(xmlInput, &head);

    printXMLNodes(head);
    
    freeNodes(head);
    puts("The case is closed!");

    return 0;
}