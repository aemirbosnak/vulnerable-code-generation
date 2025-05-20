//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000

// A struct to hold the XML element information
typedef struct {
    char *tag_name;                        // The element's tag name
    int num_attributes;                    // The number of attributes the element has
    char *attribute_names[MAX_ELEMENTS];   // An array to hold the names of the element's attributes
    char *attribute_values[MAX_ELEMENTS];  // An array to hold the values of the element's attributes
    char *text;                            // The element's text content, if any
} XMLElement;

// A function to parse an XML file and return an array of XMLElements
XMLElement *parseXMLFile(const char *filename) {
    FILE *fp = fopen(filename, "r");        // Open the file for reading
    if (fp == NULL) {
        printf("Error: Unable to open file '%s'.\n", filename);
        exit(-1);
    }

    XMLElement *elements = malloc(MAX_ELEMENTS * sizeof(XMLElement));   // Allocate the array of XMLElements
    int num_elements = 0;                                                // Count the number of elements

    char line[256];                    // A buffer to hold each line of input
    char prev_tag_name[256] = "";     // The name of the most recently seen tag
    int tag_level = 0;                 // The current level of nesting, based on the number of indents
    char *token, *attribute;           // Pointers to the current token and attribute being parsed

    while (fgets(line, sizeof(line), fp)) {    // Read a line from the file
        if (line[0] != '\t') {                  // If this line does not start with a tab, it is a new element
            num_elements++;
            XMLElement *element = &elements[num_elements - 1];
            element->tag_name = strdup(line);   // Copy the tag name to the element's struct
            element->num_attributes = 0;
            element->text = NULL;
            tag_level = 1;
            strcpy(prev_tag_name, element->tag_name);
        }
        else {  // Otherwise, this line is part of the previous element
            line[strlen(line) - 1] = '\0';    // Remove the newline character from the end of the line
            token = strtok(line, " ");        // Get the first token, which should be the attribute name
            attribute = token;
            token = strtok(NULL, " ");        // Get the second token, which should be the attribute value
            char *value = token;

            if (strcmp(attribute, "text") == 0) {         // If this is the 'text' attribute, store the text content
                XMLElement *element = &elements[num_elements - 1];
                element->text = strdup(value);
            }
            else {  // Otherwise, add the attribute to the current element's struct
                XMLElement *element = &elements[num_elements - 1];
                element->attribute_names[element->num_attributes] = strdup(attribute);
                element->attribute_values[element->num_attributes] = strdup(value);
                element->num_attributes++;
            }
        }
    }

    fclose(fp);    // Close the file

    return elements;    // Return the array of XMLElements
}

int main() {
    char *filename = "example.xml";                 // The name of the file to parse
    XMLElement *elements = parseXMLFile(filename);  // Parse the file and get an array of elements

    printf("Parsed %d elements from file '%s':\n", MAX_ELEMENTS, filename);
    for (int i = 0; i < MAX_ELEMENTS; i++) {
        XMLElement *element = &elements[i];
        if (element->tag_name != NULL) {
            printf("<%s", element->tag_name);
            for (int j = 0; j < element->num_attributes; j++) {
                printf(" %s=\"%s\"", element->attribute_names[j], element->attribute_values[j]);
            }
            if (element->text != NULL) {
                printf(">%s</%s>\n", element->text, element->tag_name);
            }
            else {
                printf(" />\n");
            }
        }
    }

    return 0;
}