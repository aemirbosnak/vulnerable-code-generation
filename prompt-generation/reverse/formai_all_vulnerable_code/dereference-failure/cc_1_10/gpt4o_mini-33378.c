//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENT 100
#define MAX_LINE_LENGTH 256

typedef struct {
    char tag_name[50];
    char content[MAX_LINE_LENGTH];
    struct Node* next;
} Node;

typedef struct {
    Node* head;
} XMLDocument;

XMLDocument* createXMLDocument() {
    XMLDocument* doc = (XMLDocument*)malloc(sizeof(XMLDocument));
    doc->head = NULL;
    return doc;
}

void freeNode(Node* node) {
    if (node) {
        freeNode(node->next);
        free(node);
    }
}

void freeXMLDocument(XMLDocument* doc) {
    if (doc) {
        freeNode(doc->head);
        free(doc);
    }
}

Node* createNode(const char* tag_name, const char* content) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->tag_name, tag_name);
    strcpy(newNode->content, content);
    newNode->next = NULL;
    return newNode;
}

void appendNode(XMLDocument* doc, const char* tag_name, const char* content) {
    Node* newNode = createNode(tag_name, content);
    if (doc->head == NULL) {
        doc->head = newNode;
    } else {
        Node* current = doc->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void printXMLDocument(XMLDocument* doc) {
    if (!doc || !doc->head) {
        printf("The XML Document is empty.\n");
        return;
    }
    
    Node* current = doc->head;
    while (current != NULL) {
        printf("<%s>%s</%s>\n", current->tag_name, current->content, current->tag_name);
        current = current->next;
    }
}

void parseXML(const char* xml_string, XMLDocument* doc) {
    char tag_name[50];
    char content[MAX_LINE_LENGTH];
    char line[MAX_LINE_LENGTH];
    
    FILE* stream = fmemopen((void*)xml_string, strlen(xml_string), "r");
    if (!stream) {
        fprintf(stderr, "Failed to create memory stream.\n");
        return;
    }

    while (fgets(line, sizeof(line), stream)) {
        if (sscanf(line, "<%49[^>]>%255[^<]</%49[^>]", tag_name, content, tag_name) == 3) {
            appendNode(doc, tag_name, content);
        }
    }
    
    fclose(stream);
}

void clearBuffer(char* buffer, int size) {
    for (int i = 0; i < size; i++) {
        buffer[i] = '\0';
    }
}

int main() {
    const char* xml_data = "<greeting>Hello, World!</greeting>\n<farewell>Goodbye, World!</farewell>\n";
    
    XMLDocument* doc = createXMLDocument();
    parseXML(xml_data, doc);
    
    printf("Parsed XML Document:\n");
    printXMLDocument(doc);
    
    freeXMLDocument(doc);
    
    return 0;
}