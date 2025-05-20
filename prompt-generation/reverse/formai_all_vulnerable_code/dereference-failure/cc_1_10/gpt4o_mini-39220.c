//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TAG_LENGTH 256

typedef struct {
    char tag[MAX_TAG_LENGTH];
    char content[MAX_LINE_LENGTH];
} XmlNode;

typedef struct {
    XmlNode *nodes;
    int size;
    int capacity;
} XmlDocument;

void initXmlDocument(XmlDocument *doc) {
    doc->size = 0;
    doc->capacity = 10;
    doc->nodes = (XmlNode *)malloc(doc->capacity * sizeof(XmlNode));
}

void freeXmlDocument(XmlDocument *doc) {
    free(doc->nodes);
}

void resizeXmlDocument(XmlDocument *doc) {
    doc->capacity *= 2;
    doc->nodes = (XmlNode *)realloc(doc->nodes, doc->capacity * sizeof(XmlNode));
}

void addNode(XmlDocument *doc, const char *tag, const char *content) {
    if (doc->size >= doc->capacity) {
        resizeXmlDocument(doc);
    }
    
    strncpy(doc->nodes[doc->size].tag, tag, MAX_TAG_LENGTH - 1);
    doc->nodes[doc->size].tag[MAX_TAG_LENGTH - 1] = '\0'; // null-terminate
    strncpy(doc->nodes[doc->size].content, content, MAX_LINE_LENGTH - 1);
    doc->nodes[doc->size].content[MAX_LINE_LENGTH - 1] = '\0'; // null-terminate
    
    doc->size++;
}

void parseXmlLine(XmlDocument *doc, const char *line) {
    char tag[MAX_TAG_LENGTH];
    char content[MAX_LINE_LENGTH];
    
    // Extracting the tag
    if (sscanf(line, "<%[^>]>%[^<]</%[^>]", tag, content, tag) == 3) {
        addNode(doc, tag, content);
    }
}

void printXmlDocument(XmlDocument *doc) {
    for (int i = 0; i < doc->size; i++) {
        printf("Tag: %s\n", doc->nodes[i].tag);
        printf("Content: %s\n\n", doc->nodes[i].content);
    }
}

void readXmlFile(const char *filename, XmlDocument *doc) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }
    
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        parseXmlLine(doc, line);
    }
    
    fclose(file);
}

int main() {
    printf("Exciting XML Parser Program!\n");
    
    XmlDocument doc;
    initXmlDocument(&doc);
    
    const char *filename = "example.xml"; // The XML file to be parsed
    readXmlFile(filename, &doc);
    
    printf("Parsed XML Document:\n");
    printXmlDocument(&doc);
    
    freeXmlDocument(&doc);
    printf("Finished parsing! Bye!\n");
    
    return 0;
}