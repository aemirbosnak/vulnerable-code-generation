//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: Alan Turing
/**
 * XML Parser in C
 *
 * This program is a simple XML parser written in C. It can parse XML documents and extract the text content of the elements.
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent an XML element
typedef struct xml_element {
    char *name;
    char *value;
    struct xml_element *next;
} xml_element;

// Function to create a new XML element
xml_element *new_xml_element(char *name, char *value) {
    xml_element *element = malloc(sizeof(xml_element));
    element->name = strdup(name);
    element->value = strdup(value);
    element->next = NULL;
    return element;
}

// Function to parse an XML document
xml_element *parse_xml(char *xml) {
    xml_element *head = NULL;
    xml_element *current = NULL;
    char *start = xml;
    char *end = NULL;

    // Loop through the XML document until the end is reached
    while (*start != '\0') {
        // Find the start of the next element
        start = strchr(start, '<');
        if (start == NULL) {
            break;
        }

        // Find the end of the next element
        end = strchr(start, '>');
        if (end == NULL) {
            break;
        }

        // Create a new XML element
        xml_element *element = new_xml_element(start + 1, end - 1);

        // Add the new element to the list of elements
        if (head == NULL) {
            head = element;
        } else {
            current->next = element;
        }
        current = element;

        // Move to the next character after the end of the element
        start = end + 1;
    }

    return head;
}

// Function to print the XML elements
void print_xml_elements(xml_element *head) {
    xml_element *current = head;

    // Loop through the list of elements
    while (current != NULL) {
        // Print the element's name and value
        printf("Element: %s, Value: %s\n", current->name, current->value);

        // Move to the next element
        current = current->next;
    }
}

// Main function
int main() {
    // XML document to be parsed
    char *xml = "<root><child>Hello</child><child>World</child></root>";

    // Parse the XML document
    xml_element *head = parse_xml(xml);

    // Print the XML elements
    print_xml_elements(head);

    return 0;
}