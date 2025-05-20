//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

// Define a struct to hold each XML element in the file
typedef struct {
    char *name;
    char *content;
} XmlElement;

// Define a struct to hold the parsed XML file
typedef struct {
    XmlElement **elements;
    int num_elements;
} XmlDocument;

// Function to read the XML file and parse its contents into an XmlDocument
XmlDocument parse_xml_file(char *filename) {
    FILE *xml_file = fopen(filename, "r");
    if (xml_file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    XmlDocument doc;
    doc.num_elements = 0;
    doc.elements = malloc(sizeof(XmlElement *));
    if (doc.elements == NULL) {
        printf("Error: Could not allocate memory for XmlDocument elements\n");
        exit(1);
    }

    char current_char;
    char current_tag[100];
    char current_content[200];
    int tag_index = 0;
    int content_index = 0;
    int element_index = -1;
    bool in_tag = false;
    bool in_content = false;
    bool in_element = false;

    while ((current_char = fgetc(xml_file)) != EOF) {
        if (current_char == '<') {
            in_tag = true;
            in_content = false;
            if (in_element) {
                doc.elements[element_index]->content = strdup(current_content);
                in_element = false;
                content_index = 0;
            }
            tag_index = 0;
            continue;
        } else if (current_char == '>') {
            in_tag = false;
            if (in_element) {
                in_content = true;
            } else {
                in_element = true;
                element_index++;
                doc.num_elements++;
                doc.elements = realloc(doc.elements, (doc.num_elements + 1) * sizeof(XmlElement *));
                doc.elements[element_index] = malloc(sizeof(XmlElement));
                doc.elements[element_index]->name = strdup(current_tag);
                in_content = true;
            }
            continue;
        }

        if (in_tag) {
            current_tag[tag_index] = current_char;
            tag_index++;
        }

        if (in_content) {
            current_content[content_index] = current_char;
            content_index++;
        }
    }

    fclose(xml_file);

    if (in_element) {
        doc.elements[element_index]->content = strdup(current_content);
    }

    return doc;
}

int main() {
    XmlDocument doc = parse_xml_file("example.xml");

    for (int i = 0; i < doc.num_elements; i++) {
        printf("Element #%d\n", i+1);
        printf("Name: %s\n", doc.elements[i]->name);
        printf("Content: %s\n", doc.elements[i]->content);
        printf("\n");
    }

    return 0;
}