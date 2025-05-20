//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *element_name;
    char *element_data;
} XML_ELEMENT;

typedef struct {
    XML_ELEMENT *elements;
    int num_elements;
} XML_DOCUMENT;

void parse_xml(char *xml, XML_DOCUMENT *doc) {
    // Start parsing the XML string
    printf("Parsing XML...\n");

    char *token = strtok(xml, "<>"); // Get the first tag

    while (token != NULL) {
        // Check if this is an opening tag
        if (token[0] == '/') {
            token = strtok(NULL, "<>"); // Go to the next tag
            continue;
        }

        // Allocate memory for the new element
        XML_ELEMENT *new_element = malloc(sizeof(XML_ELEMENT));

        // Get the element name
        new_element->element_name = strdup(token);

        // Get the element data
        token = strtok(NULL, "<>");
        if (strlen(token) != 0 && token[0] != '/') {
            new_element->element_data = strdup(token);
        } else {
            new_element->element_data = NULL;
        }

        // Add the new element to the document
        doc->elements = realloc(doc->elements, (doc->num_elements + 1) * sizeof(XML_ELEMENT));
        doc->elements[doc->num_elements] = *new_element;
        doc->num_elements++;

        // Go to the next tag
        token = strtok(NULL, "<>");
    }

    printf("XML parsing complete.\n");
}

int main() {
    char xml[] = "<book><title>The Great Gatsby</title><author>F. Scott Fitzgerald</author><year>1925</year></book>";

    XML_DOCUMENT doc;
    doc.elements = NULL;
    doc.num_elements = 0;

    parse_xml(xml, &doc);

    printf("XML document contains %d elements.\n", doc.num_elements);
    for (int i = 0; i < doc.num_elements; i++) {
        printf("Element %d: %s - %s\n", i+1, doc.elements[i].element_name, doc.elements[i].element_data);
    }

    return 0;
}