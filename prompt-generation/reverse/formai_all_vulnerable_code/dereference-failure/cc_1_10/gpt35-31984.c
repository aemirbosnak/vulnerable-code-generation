//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: artistic
/*
* File: xml_parser.c
* Desc: A simple C program to parse an XML file.
* Notes: This program assumes that the XML file has a root element and no attributes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *value;
} Element;

void parse_xml(char *xml_file_path) {
    FILE *xml_file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    char *open_tag = NULL;
    char *close_tag = NULL;
    int inside_element = 0;
    int element_count = 0;
    Element *elements = NULL;
    int i;

    // Open the XML file for reading
    xml_file = fopen(xml_file_path, "r");
    if (xml_file == NULL) {
        printf("Error: Could not open XML file %s\n", xml_file_path);
        return;
    }

    // Read the XML file line by line
    while ((read = getline(&line, &len, xml_file)) != -1) {
        // Trim newline character at the end of the line
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = '\0';
        }

        // Check if we're inside an XML element
        if (inside_element) {
            // Check if this is the closing tag for the element
            close_tag = malloc(strlen(open_tag) + 3); // Allocate memory for the closing tag
            sprintf(close_tag, "</%s>", open_tag + 1); // Create the closing tag, skipping the '<' character at the beginning
            if (strstr(line, close_tag) != NULL) { // Check if this is the closing tag for the current element
                // Add the parsed element to the array of elements
                elements = realloc(elements, (element_count + 1) * sizeof(Element));
                elements[element_count].name = malloc(strlen(open_tag));
                strcpy(elements[element_count].name, open_tag + 1);
                elements[element_count].value = malloc(strlen(line) - strlen(open_tag) - 3);
                strncpy(elements[element_count].value, line + strlen(open_tag) + 2, strlen(line) - strlen(open_tag) - 3);
                elements[element_count].value[strlen(elements[element_count].value)] = '\0';
                element_count++;

                inside_element = 0; // We're no longer inside an element
                free(open_tag);
                free(close_tag);
            } else {
                // We're still inside the same element, so concatenate the line to the element's value
                elements[element_count - 1].value = realloc(elements[element_count - 1].value, strlen(elements[element_count - 1].value) + strlen(line) + 1);
                strcat(elements[element_count - 1].value, line);
            }
        } else {
            // Check if this is the opening tag for an XML element
            if (line[0] == '<' && line[1] != '/') {
                inside_element = 1;
                open_tag = malloc(strlen(line));
                strcpy(open_tag, line);
            }
        }
    }

    // Print the parsed elements
    printf("Parsed %d elements:\n", element_count);
    for (i = 0; i < element_count; i++) {
        printf("  %s: %s\n", elements[i].name, elements[i].value);
        free(elements[i].name);
        free(elements[i].value);
    }
    free(elements);

    fclose(xml_file);
    if (line)
        free(line);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <XML file path>\n", argv[0]);
        return 1;
    }

    parse_xml(argv[1]);
    return 0;
}