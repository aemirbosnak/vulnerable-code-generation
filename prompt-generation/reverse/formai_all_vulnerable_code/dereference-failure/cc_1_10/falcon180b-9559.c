//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_ELEMENT_NAME_LENGTH 50
#define MAX_ELEMENT_VALUE_LENGTH 100

typedef struct {
    char name[MAX_ELEMENT_NAME_LENGTH];
    char value[MAX_ELEMENT_VALUE_LENGTH];
} xml_element;

typedef struct {
    int num_elements;
    xml_element elements[MAX_ELEMENTS];
} xml_document;

xml_document* create_xml_document() {
    xml_document* doc = (xml_document*)malloc(sizeof(xml_document));
    doc->num_elements = 0;
    return doc;
}

void add_element(xml_document* doc, char* name, char* value) {
    if (doc->num_elements >= MAX_ELEMENTS) {
        printf("Error: Maximum number of elements reached.\n");
        return;
    }
    strncpy(doc->elements[doc->num_elements].name, name, MAX_ELEMENT_NAME_LENGTH);
    strncpy(doc->elements[doc->num_elements].value, value, MAX_ELEMENT_VALUE_LENGTH);
    doc->num_elements++;
}

void print_xml_document(xml_document* doc) {
    printf("<document>\n");
    for (int i = 0; i < doc->num_elements; i++) {
        printf("\t<%s>%s</%s>\n", doc->elements[i].name, doc->elements[i].value, doc->elements[i].name);
    }
    printf("</document>\n");
}

int main() {
    xml_document* doc = create_xml_document();
    add_element(doc, "name", "John");
    add_element(doc, "age", "30");
    add_element(doc, "city", "New York");
    print_xml_document(doc);
    free(doc);
    return 0;
}