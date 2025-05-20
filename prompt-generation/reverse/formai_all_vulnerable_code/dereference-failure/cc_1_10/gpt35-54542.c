//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold information about the XML tag
typedef struct {
    char* tag_name;
    int num_attributes;
    char** attribute_names;
    char** attribute_values;
    char* body;
} XmlTag;

// Function to parse a single XML tag
XmlTag* parse_tag(char* tag_string) {
    XmlTag* tag = malloc(sizeof(XmlTag));
    tag->num_attributes = 0;
    tag->attribute_names = NULL;
    tag->attribute_values = NULL;
    tag->body = NULL;

    // Find the tag name
    char* start = strchr(tag_string, '<') + 1;
    char* end = strchr(start, '>');
    int tag_name_len = end - start;
    tag->tag_name = malloc((tag_name_len + 1) * sizeof(char));
    strncpy(tag->tag_name, start, tag_name_len);
    tag->tag_name[tag_name_len] = '\0';

    // Find tag body, if it exists
    start = end + 1;
    end = strchr(start, '<');
    if (end) {
        int body_len = end - start;
        tag->body = malloc((body_len + 1) * sizeof(char));
        strncpy(tag->body, start, body_len);
        tag->body[body_len] = '\0';
    }

    // Find attribute names and values
    char* attr_start = strchr(tag_string, ' ');
    while (attr_start && attr_start < end) {
        tag->num_attributes++;
        tag->attribute_names = realloc(tag->attribute_names, tag->num_attributes * sizeof(char*));
        tag->attribute_values = realloc(tag->attribute_values, tag->num_attributes * sizeof(char*));

        // Find attribute name
        start = attr_start + 1;
        end = strchr(start, '=');
        int attr_name_len = end - start;
        tag->attribute_names[tag->num_attributes - 1] = malloc((attr_name_len + 1) * sizeof(char));
        strncpy(tag->attribute_names[tag->num_attributes - 1], start, attr_name_len);
        tag->attribute_names[tag->num_attributes - 1][attr_name_len] = '\0';

        // Find attribute value
        start = end + 2;
        end = strchr(start, '\"');
        int attr_value_len = end - start;
        tag->attribute_values[tag->num_attributes - 1] = malloc((attr_value_len + 1) * sizeof(char));
        strncpy(tag->attribute_values[tag->num_attributes - 1], start, attr_value_len);
        tag->attribute_values[tag->num_attributes - 1][attr_value_len] = '\0';

        // Move to next attribute
        attr_start = strchr(end + 1, ' ');
    }

    return tag;
}

int main() {
    // Test the XML parser with a sample input
    char* xml_input = "<person name=\"John Doe\" age=\"30\">Hello, world!</person>";
    XmlTag* person_tag = parse_tag(xml_input);
    printf("Tag name: %s\n", person_tag->tag_name);
    printf("Body: %s\n", person_tag->body);
    printf("Attribute 1 - Name: %s, Value: %s\n", person_tag->attribute_names[0], person_tag->attribute_values[0]);
    printf("Attribute 2 - Name: %s, Value: %s\n", person_tag->attribute_names[1], person_tag->attribute_values[1]);

    // Clean up
    free(person_tag->tag_name);
    free(person_tag->body);
    for (int i = 0; i < person_tag->num_attributes; i++) {
        free(person_tag->attribute_names[i]);
        free(person_tag->attribute_values[i]);
    }
    free(person_tag->attribute_names);
    free(person_tag->attribute_values);
    free(person_tag);
    return 0;
}