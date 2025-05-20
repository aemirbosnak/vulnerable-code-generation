//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the XML element
typedef struct xml_element {
    char* tag_name;
    char* content;
    int num_attributes;
    char** attribute_names;
    char** attribute_values;
    struct xml_element** children;
    int num_children;
} xml_element;

// Define the function for parsing an XML element
xml_element* parse_element(const char* xml_string, int* index) {
    // Initialize the element
    xml_element* element = (xml_element*) malloc(sizeof(xml_element));
    element->tag_name = NULL;
    element->content = NULL;
    element->num_attributes = 0;
    element->attribute_names = NULL;
    element->attribute_values = NULL;
    element->children = NULL;
    element->num_children = 0;

    // Parse the tag name
    int tag_start = *index;
    while (xml_string[*index] != '<' && xml_string[*index] != ' ' && xml_string[*index] != '>') {
        (*index)++;
    }
    int tag_end = *index;
    int tag_len = tag_end - tag_start;
    char* tag_name = (char*) malloc((tag_len + 1) * sizeof(char));
    strncpy(tag_name, xml_string + tag_start, tag_len);
    tag_name[tag_len] = '\0';
    element->tag_name = tag_name;

    // Parse the attributes
    while (xml_string[*index] != '>') {
        if (xml_string[*index] == ' ') {
            (*index)++;
            int attr_start = *index;
            while (xml_string[*index] != '=') {
                (*index)++;
            }
            int attr_end = *index;
            int attr_len = attr_end - attr_start;
            char* attr_name = (char*) malloc((attr_len + 1) * sizeof(char));
            strncpy(attr_name, xml_string + attr_start, attr_len);
            attr_name[attr_len] = '\0';
            element->num_attributes++;
            element->attribute_names = (char**) realloc(element->attribute_names, element->num_attributes * sizeof(char*));
            element->attribute_names[element->num_attributes - 1] = attr_name;
            (*index)++;
            int val_start = *index;
            while (xml_string[*index] != '"' && xml_string[*index] != '\'') {
                (*index)++;
            }
            char quote = xml_string[*index];
            (*index)++;
            int val_end = *index;
            while (xml_string[*index] != quote) {
                (*index)++;
            }
            int val_len = *index - val_start - 1;
            char* attr_value = (char*) malloc((val_len + 1) * sizeof(char));
            strncpy(attr_value, xml_string + val_start, val_len);
            attr_value[val_len] = '\0';
            element->attribute_values = (char**) realloc(element->attribute_values, element->num_attributes * sizeof(char*));
            element->attribute_values[element->num_attributes - 1] = attr_value;
            (*index)++;
        } else {
            (*index)++;
        }
    }

    // Parse the content and child elements
    if (xml_string[*index - 1] == '/') {
        // Self-closing tag
        return element;
    } else {
        (*index)++;
        int content_start = *index;
        while (xml_string[*index] != '<') {
            (*index)++;
        }
        int content_end = *index;
        int content_len = content_end - content_start;
        char* content = (char*) malloc((content_len + 1) * sizeof(char));
        strncpy(content, xml_string + content_start, content_len);
        content[content_len] = '\0';
        element->content = content;
        while (xml_string[*index] != '/') {
            element->num_children++;
            element->children = (xml_element**) realloc(element->children, element->num_children * sizeof(xml_element*));
            element->children[element->num_children - 1] = parse_element(xml_string, index);
        }
        int end_start = *index;
        while (xml_string[*index] != '>') {
            (*index)++;
        }
        int end_end = *index;
        int end_len = end_end - end_start;
        char* end_tag = (char*) malloc((end_len + 1) * sizeof(char));
        strncpy(end_tag, xml_string + end_start, end_len);
        end_tag[end_len] = '\0';
        if (strcmp(end_tag, element->tag_name) != 0) {
            printf("Error: tags do not match.\n");
            exit(1);
        }
        return element;
    }
}

// Define the function for printing an XML element
void print_element(xml_element* element, int indent_level) {
    // Print the tag name
    for (int i = 0; i < indent_level; i++) {
        printf("    ");
    }
    printf("<%s", element->tag_name);

    // Print the attributes
    for (int i = 0; i < element->num_attributes; i++) {
        printf(" %s=\"%s\"", element->attribute_names[i], element->attribute_values[i]);
    }

    if (element->num_children == 0) {
        // Print the self-closing tag if there are no child elements
        printf("/>\n");
    } else {
        // Print the opening tag
        printf(">\n");

        // Print the content
        if (element->content != NULL) {
            for (int i = 0; i < indent_level + 1; i++) {
                printf("    ");
            }
            printf("%s\n", element->content);
        }

        // Print the child elements
        for (int i = 0; i < element->num_children; i++) {
            print_element(element->children[i], indent_level + 1);
        }

        // Print the closing tag
        for (int i = 0; i < indent_level; i++) {
            printf("    ");
        }
        printf("</%s>\n", element->tag_name);
    }
}

int main() {
    // Define an example XML string
    const char* xml_string =
        "<html lang=\"en\">\n"
        "    <head>\n"
        "        <title>Example XML Parser</title>\n"
        "    </head>\n"
        "    <body>\n"
        "        <h1>Welcome to my example XML parser!</h1>\n"
        "        <p>This is just a simple example, but a real XML parser could be used for much more complex applications.</p>\n"
        "        <ul>\n"
        "            <li>Item 1</li>\n"
        "            <li>Item 2</li>\n"
        "            <li>Item 3</li>\n"
        "        </ul>\n"
        "    </body>\n"
        "</html>";

    // Parse the XML string and print the result
    int index = 0;
    xml_element* element = parse_element(xml_string, &index);
    print_element(element, 0);

    // Free the memory used by the XML element
    free(element->tag_name);
    if (element->content != NULL) {
        free(element->content);
    }
    for (int i = 0; i < element->num_attributes; i++) {
        free(element->attribute_names[i]);
        free(element->attribute_values[i]);
    }
    free(element->attribute_names);
    free(element->attribute_values);
    for (int i = 0; i < element->num_children; i++) {
        free(element->children[i]->tag_name);
        if (element->children[i]->content != NULL) {
            free(element->children[i]->content);
        }
        for (int j = 0; j < element->children[i]->num_attributes; j++) {
            free(element->children[i]->attribute_names[j]);
            free(element->children[i]->attribute_values[j]);
        }
        free(element->children[i]->attribute_names);
        free(element->children[i]->attribute_values);
        free(element->children[i]->children);
        free(element->children[i]);
    }
    free(element->children);
    free(element);

    return 0;
}