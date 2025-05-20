//GPT-4o-mini DATASET v1.0 Category: Building a XML Parser ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENT 100
#define MAX_VALUE 256

typedef struct {
    char name[MAX_ELEMENT];
    char value[MAX_VALUE];
} XmlElement;

typedef struct {
    XmlElement *elements;
    int size;
    int capacity;
} XmlDocument;

// Function prototypes
XmlDocument* createXmlDocument();
void freeXmlDocument(XmlDocument *doc);
void parseXmlFile(XmlDocument *doc, const char *filename);
void addElement(XmlDocument *doc, const char *name, const char *value);
void printXmlDocument(XmlDocument *doc);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <xml_filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    XmlDocument *doc = createXmlDocument();
    parseXmlFile(doc, argv[1]);
    printXmlDocument(doc);
    freeXmlDocument(doc);
    return EXIT_SUCCESS;
}

XmlDocument* createXmlDocument() {
    XmlDocument *doc = (XmlDocument *)malloc(sizeof(XmlDocument));
    if (!doc) {
        perror("Failed to allocate memory for XmlDocument");
        exit(EXIT_FAILURE);
    }
    doc->elements = (XmlElement *)malloc(sizeof(XmlElement) * MAX_ELEMENT);
    doc->size = 0;
    doc->capacity = MAX_ELEMENT;
    return doc;
}

void freeXmlDocument(XmlDocument *doc) {
    free(doc->elements);
    free(doc);
}

void addElement(XmlDocument *doc, const char *name, const char *value) {
    if (doc->size >= doc->capacity) {
        fprintf(stderr, "Exceeded maximum number of elements in XML document.\n");
        return;
    }
    strncpy(doc->elements[doc->size].name, name, MAX_ELEMENT);
    strncpy(doc->elements[doc->size].value, value, MAX_VALUE);
    doc->size++;
}

void parseXmlFile(XmlDocument *doc, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    char line[512];
    while (fgets(line, sizeof(line), file)) {
        char *start = strstr(line, "<");
        char *end = strstr(line, ">");
        
        if (start && end && start < end) {
            char elementName[MAX_ELEMENT] = {0};
            char elementValue[MAX_VALUE] = {0};
            size_t nameLength = end - start - 1; // Length of the element name

            strncpy(elementName, start + 1, nameLength);
            elementName[nameLength] = '\0';

            // Now extract the value between opening and closing tags
            start = end + 1;
            end = strstr(start, "<");
            if (end) {
                size_t valueLength = end - start; // Length of the value
                strncpy(elementValue, start, valueLength);
                elementValue[valueLength] = '\0';
                addElement(doc, elementName, elementValue);
            }
        }
    }
    
    fclose(file);
}

void printXmlDocument(XmlDocument *doc) {
    printf("Parsed XML Document:\n");
    for (int i = 0; i < doc->size; i++) {
        printf("Element: %s, Value: %s\n", doc->elements[i].name, doc->elements[i].value);
    }
}