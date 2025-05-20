//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *value;
} html_attribute;

typedef struct {
    char *name;
    html_attribute *attributes;
    int num_attributes;
} html_element;

typedef struct {
    html_element *elements;
    int num_elements;
} html_document;

html_document *html_parse(char *html) {
    html_document *document = malloc(sizeof(html_document));
    document->elements = NULL;
    document->num_elements = 0;

    char *element_start = html;
    char *element_end = strchr(element_start, '>');
    while (element_start && element_end) {
        char *element_name = malloc(element_end - element_start + 1);
        strncpy(element_name, element_start + 1, element_end - element_start - 1);
        element_name[element_end - element_start - 1] = '\0';

        html_element *element = malloc(sizeof(html_element));
        element->name = element_name;
        element->attributes = NULL;
        element->num_attributes = 0;

        char *attribute_start = strchr(element_start, ' ');
        while (attribute_start) {
            char *attribute_name = malloc(strchr(attribute_start, '=') - attribute_start);
            strncpy(attribute_name, attribute_start + 1, strchr(attribute_start, '=') - attribute_start - 1);
            attribute_name[strchr(attribute_start, '=') - attribute_start - 1] = '\0';

            char *attribute_value = malloc(strchr(attribute_start, '"') - strchr(attribute_start, '=') - 2);
            strncpy(attribute_value, strchr(attribute_start, '=') + 2, strchr(attribute_start, '"') - strchr(attribute_start, '=') - 2);
            attribute_value[strchr(attribute_start, '"') - strchr(attribute_start, '=') - 2] = '\0';

            html_attribute *attribute = malloc(sizeof(html_attribute));
            attribute->name = attribute_name;
            attribute->value = attribute_value;

            element->attributes = realloc(element->attributes, sizeof(html_attribute) * (element->num_attributes + 1));
            element->attributes[element->num_attributes] = *attribute;
            element->num_attributes++;

            attribute_start = strchr(attribute_start, ' ');
        }

        document->elements = realloc(document->elements, sizeof(html_element) * (document->num_elements + 1));
        document->elements[document->num_elements] = *element;
        document->num_elements++;

        element_start = element_end + 1;
        element_end = strchr(element_start, '<');
    }

    return document;
}

void html_beautify(html_document *document) {
    for (int i = 0; i < document->num_elements; i++) {
        html_element *element = &document->elements[i];

        printf("<%s", element->name);
        for (int j = 0; j < element->num_attributes; j++) {
            html_attribute *attribute = &element->attributes[j];

            printf(" %s=\"%s\"", attribute->name, attribute->value);
        }
        printf(">");

        if (element->num_attributes > 0) {
            printf("\n");
        }
    }
}

int main() {
    char *html = "<html><head><title>My Website</title></head><body><h1>My Website</h1><p>This is my website.</p></body></html>";

    html_document *document = html_parse(html);
    html_beautify(document);

    return 0;
}