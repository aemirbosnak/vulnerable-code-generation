//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct xml_element {
    char* name;
    char* value;
    int num_attributes;
    char** attribute_names;
    char** attribute_values;
    struct xml_element** children;
    int num_children;
} xml_element;

void free_element(xml_element* element) {
    int i;
    for (i = 0; i < element->num_children; i++) {
        free_element(element->children[i]);
    }
    for (i = 0; i < element->num_attributes; i++) {
        free(element->attribute_names[i]);
        free(element->attribute_values[i]);
    }
    free(element->name);
    free(element->value);
    free(element->attribute_names);
    free(element->attribute_values);
    free(element->children);
    free(element);
}

xml_element* parse_xml_element(char* input) {
    xml_element* element = malloc(sizeof(xml_element));
    element->num_attributes = 0;
    element->num_children = 0;
    element->attribute_names = NULL;
    element->attribute_values = NULL;
    element->children = NULL;

    char* start_tag = strstr(input, "<");
    char* end_tag = strstr(start_tag, ">");

    if (start_tag != input) {
        element->name = NULL;
        element->value = strndup(input, start_tag - input);
    } else {
        char* space = strchr(start_tag, ' ');
        if (space) {
            element->name = strndup(start_tag + 1, space - start_tag - 1);
            char* attribute_start = space + 1;
            while (1) {
                char* equals = strchr(attribute_start, '=');
                if (!equals) {
                    element->num_attributes++;
                    element->attribute_names = realloc(element->attribute_names, element->num_attributes * sizeof(char*));
                    element->attribute_values = realloc(element->attribute_values, element->num_attributes * sizeof(char*));
                    element->attribute_names[element->num_attributes - 1] = NULL;
                    element->attribute_values[element->num_attributes - 1] = NULL;
                    break;
                }
                element->num_attributes++;
                element->attribute_names = realloc(element->attribute_names, element->num_attributes * sizeof(char*));
                element->attribute_values = realloc(element->attribute_values, element->num_attributes * sizeof(char*));
                element->attribute_names[element->num_attributes - 1] = strndup(attribute_start, equals - attribute_start);
                char* attribute_value_start = equals + 1;
                if (*attribute_value_start == '\"') {
                    attribute_value_start++;
                }
                char* attribute_value_end = strchr(attribute_value_start, '\"');
                element->attribute_values[element->num_attributes - 1] = strndup(attribute_value_start, attribute_value_end - attribute_value_start);
                attribute_start = attribute_value_end + 1;
            }
        } else {
            element->name = strndup(start_tag + 1, end_tag - start_tag - 1);
        }
        element->value = NULL;
    }

    char* search_start = end_tag;
    while (1) {
        char* child_start = strstr(search_start, "<");
        if (!child_start) {
            break;
        }
        char* child_end = strstr(child_start, ">");
        if (*(child_end - 1) == '/') {
            if (!element->children) {
                element->children = malloc(sizeof(xml_element*));
            } else {
                element->children = realloc(element->children, (element->num_children + 1) * sizeof(xml_element*));
            }
            element->children[element->num_children] = malloc(sizeof(xml_element));
            element->children[element->num_children]->num_children = 0;
            element->children[element->num_children]->num_attributes = 0;
            element->children[element->num_children]->name = strndup(child_start + 1, child_end - child_start - 2);
            element->children[element->num_children]->value = NULL;
            element->children[element->num_children]->attribute_names = NULL;
            element->children[element->num_children]->attribute_values = NULL;
            element->num_children++;
            search_start = child_end;
        } else {
            char* matching_tag = strstr(child_end, element->name);
            if (matching_tag == child_end + 1) {
                if (*element->name != '/') {
                    if (!element->children) {
                        element->children = malloc(sizeof(xml_element*));
                    } else {
                        element->children = realloc(element->children, (element->num_children + 1) * sizeof(xml_element*));
                    }
                    element->children[element->num_children] = parse_xml_element(child_end + 1);
                    element->num_children++;
                }
                search_start = matching_tag + strlen(element->name);
            } else {
                if (!element->value) {
                    element->value = strndup(end_tag + 1, child_start - end_tag - 1);
                }
                search_start = child_start;
            }
        }
    }

    return element;
}

int main() {
    char* input_string = "<html lang=\"en\"><head><title>My Web Page</title></head><body><h1>Welcome to my web page!</h1><p>Here is some information about me:</p><ul><li><b>Name:</b> John Doe</li><li><b>Age:</b> 30</li><li><b>Occupation:</b> Software Engineer</li></ul></body></html>";
    xml_element* root_element = parse_xml_element(input_string);
    printf("%s", root_element->children[0]->children[0]->value);
    free_element(root_element);
    return 0;
}