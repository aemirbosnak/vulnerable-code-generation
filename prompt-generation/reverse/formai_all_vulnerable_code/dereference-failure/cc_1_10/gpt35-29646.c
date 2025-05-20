//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold the parsed data
typedef struct {
    char* tag;
    char* content;
} xml_element;

// Function to parse a single tag
xml_element* parse_tag(char* tag_str) {
    // Allocate memory for the struct
    xml_element* element = malloc(sizeof(xml_element));

    // Parse the tag and content
    char* end_tag_str = strstr(tag_str, "</");
    if (end_tag_str == NULL) {
        fprintf(stderr, "Invalid tag: %s\n", tag_str);
        free(element);
        return NULL;
    }
    int content_len = end_tag_str - tag_str - strlen(element->tag) - 2;
    if (content_len <= 0) {
        // No content for this element
        element->content = NULL;
    } else {
        element->content = malloc(content_len + 1);
        strncpy(element->content, tag_str + strlen(element->tag) + 2, content_len);
        element->content[content_len] = '\0';
    }

    // Return the parsed element
    return element;
}

// Function to parse the entire XML document
xml_element** parse_xml(char* xml_str, int* num_elements) {
    // Allocate an array to hold the parsed elements
    int max_elements = 10;
    xml_element** elements = malloc(sizeof(xml_element*) * max_elements);
    *num_elements = 0;

    // Loop through the tags in the XML string
    char* tag_str = strtok(xml_str, "<");
    while (tag_str != NULL) {
        // Ignore comments and other non-element tags
        if (tag_str[0] == '?' || tag_str[0] == '!') {
            tag_str = strtok(NULL, "<");
            continue;
        }

        // Parse the tag and add it to the array
        xml_element* element = parse_tag(tag_str);
        if (element != NULL) {
            if (*num_elements == max_elements) {
                // Double the size of the array if we have reached capacity
                max_elements *= 2;
                elements = realloc(elements, sizeof(xml_element*) * max_elements);
            }
            elements[*num_elements] = element;
            (*num_elements)++;
        }

        // Move on to the next tag in the XML string
        tag_str = strtok(NULL, "<");
    }

    // Return the array of parsed elements
    return elements;
}

int main() {
    // Example XML document
    char* xml_str = "<?xml version=\"1.0\"?><book><title>The Catcher in the Rye</title><author>J.D. Salinger</author><published>1951</published></book>";

    // Parse the XML document
    int num_elements;
    xml_element** elements = parse_xml(xml_str, &num_elements);

    // Print the parsed elements
    for (int i = 0; i < num_elements; i++) {
        xml_element* element = elements[i];
        printf("[%s] %s\n", element->tag, element->content);
    }

    // Free the parsed elements
    for (int i = 0; i < num_elements; i++) {
        xml_element* element = elements[i];
        free(element->tag);
        if (element->content != NULL) {
            free(element->content);
        }
        free(element);
    }
    free(elements);

    return 0;
}