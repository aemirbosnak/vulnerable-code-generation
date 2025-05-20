//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#define MAX_ELEMENT_COUNT 100
#define MAX_ELEMENT_NAME_LENGTH 100
#define MAX_ELEMENT_VALUE_LENGTH 1000

typedef struct {
    char name[MAX_ELEMENT_NAME_LENGTH];
    char value[MAX_ELEMENT_VALUE_LENGTH];
} Element;

typedef struct {
    Element elements[MAX_ELEMENT_COUNT];
    int element_count;
} XMLDocument;

XMLDocument* create_xml_document() {
    XMLDocument* document = malloc(sizeof(XMLDocument));
    document->element_count = 0;
    return document;
}

void free_xml_document(XMLDocument* document) {
    free(document);
}

void add_element_to_document(XMLDocument* document, const char* name, const char* value) {
    if (document->element_count < MAX_ELEMENT_COUNT) {
        strcpy(document->elements[document->element_count].name, name);
        strcpy(document->elements[document->element_count].value, value);
        document->element_count++;
    } else {
        printf("Error: Maximum element count reached.\n");
    }
}

void print_xml_document(XMLDocument* document) {
    printf("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
    for (int i = 0; i < document->element_count; i++) {
        printf("<%s>%s</%s>\n", document->elements[i].name, document->elements[i].value, document->elements[i].name);
    }
}

int main() {
    XMLDocument* document = create_xml_document();

    add_element_to_document(document, "root", "This is the root element.");
    add_element_to_document(document, "child1", "This is the first child element.");
    add_element_to_document(document, "child2", "This is the second child element.");

    print_xml_document(document);

    free_xml_document(document);

    return 0;
}