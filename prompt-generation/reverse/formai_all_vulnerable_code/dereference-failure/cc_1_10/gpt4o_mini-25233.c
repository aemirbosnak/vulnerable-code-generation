//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ELEMENT_NAME 256
#define MAX_CONTENT_LENGTH 1024

typedef struct XMLNode {
    char elementName[MAX_ELEMENT_NAME];
    char content[MAX_CONTENT_LENGTH];
    struct XMLNode *next;
} XMLNode;

XMLNode* createNode(const char* elementName, const char* content) {
    XMLNode* newNode = (XMLNode*)malloc(sizeof(XMLNode));
    if (newNode == NULL) {
        perror("Unable to allocate memory for new XML node");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->elementName, elementName, MAX_ELEMENT_NAME - 1);
    newNode->elementName[MAX_ELEMENT_NAME - 1] = '\0';
    strncpy(newNode->content, content, MAX_CONTENT_LENGTH - 1);
    newNode->content[MAX_CONTENT_LENGTH - 1] = '\0';
    newNode->next = NULL;
    return newNode;
}

void appendNode(XMLNode** head, const char* elementName, const char* content) {
    XMLNode* newNode = createNode(elementName, content);
    if (*head == NULL) {
        *head = newNode;
    } else {
        XMLNode* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void freeNodeList(XMLNode* head) {
    XMLNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void parseXMLLine(const char* line, XMLNode** head) {
    char elementName[MAX_ELEMENT_NAME];
    char content[MAX_CONTENT_LENGTH];

    // Extract element name and content using simple string manipulation
    if (sscanf(line, "<%[^>]>%[^<]</%[^>]>",
               elementName, content, elementName) == 3) {
        appendNode(head, elementName, content);
    }
}

void readXMLFile(const char* filename, XMLNode** head) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open XML file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        parseXMLLine(line, head);
    }

    fclose(file);
}

void printParsedXML(XMLNode* head) {
    XMLNode* current = head;
    while (current != NULL) {
        printf("Element: %s\n", current->elementName);
        printf("Content: %s\n\n", current->content);
        current = current->next;
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    XMLNode* parsedXML = NULL;

    readXMLFile(argv[1], &parsedXML);
    printParsedXML(parsedXML);
    freeNodeList(parsedXML);

    return EXIT_SUCCESS;
}