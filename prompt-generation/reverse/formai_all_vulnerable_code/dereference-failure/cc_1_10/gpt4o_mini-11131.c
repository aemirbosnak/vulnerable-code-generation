//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TAG_NAME 100
#define MAX_TAG_CONTENT 256

typedef struct XMLNode {
    char tagName[MAX_TAG_NAME];
    char content[MAX_TAG_CONTENT];
    struct XMLNode *next;
} XMLNode;

XMLNode* createNode(const char* tagName, const char* content) {
    XMLNode* newNode = (XMLNode*)malloc(sizeof(XMLNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    strncpy(newNode->tagName, tagName, MAX_TAG_NAME);
    strncpy(newNode->content, content, MAX_TAG_CONTENT);
    newNode->next = NULL;
    return newNode;
}

void addNode(XMLNode** head, const char* tagName, const char* content) {
    XMLNode* newNode = createNode(tagName, content);
    newNode->next = *head;
    *head = newNode;
}

void printXMLNodes(const XMLNode* head) {
    const XMLNode* current = head;
    while (current != NULL) {
        printf("<%s>%s</%s>\n", current->tagName, current->content, current->tagName);
        current = current->next;
    }
}

void freeXMLNodes(XMLNode* head) {
    XMLNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

void parseXML(FILE* file, XMLNode** head) {
    char line[512];
    while (fgets(line, sizeof(line), file)) {
        char tagName[MAX_TAG_NAME];
        char content[MAX_TAG_CONTENT];
        
        if (sscanf(line, "<%99[^>]>%255[^<]</%99[^>]", tagName, content, tagName) == 3) {
            addNode(head, tagName, content);
        }
    }
}

void readXMLFile(const char* fileName, XMLNode** head) {
    FILE* file = fopen(fileName, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s for reading.\n", fileName);
        exit(EXIT_FAILURE);
    }
    
    parseXML(file, head);
    fclose(file);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    XMLNode* head = NULL;
    readXMLFile(argv[1], &head);
    printf("Parsed XML:\n");
    printXMLNodes(head);
    freeXMLNodes(head);

    return EXIT_SUCCESS;
}