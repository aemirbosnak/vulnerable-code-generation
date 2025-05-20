//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *value;
} attribute;

typedef struct {
    char *tag;
    attribute *attributes;
    int num_attributes;
    char *content;
} element;

typedef struct {
    element *elements;
    int num_elements;
} document;

document *parse_html(char *html) {
    document *doc = malloc(sizeof(document));
    doc->elements = NULL;
    doc->num_elements = 0;

    char *start = html;
    char *end;

    while ((end = strchr(start, '<'))) {
        if (end - start > 0) {
            element *element = malloc(sizeof(element));
            element->tag = malloc(end - start + 1);
            strncpy(element->tag, start, end - start);
            element->tag[end - start] = '\0';
            element->attributes = NULL;
            element->num_attributes = 0;
            element->content = NULL;

            doc->elements = realloc(doc->elements, (doc->num_elements + 1) * sizeof(element));
            doc->elements[doc->num_elements++] = *element;
        }

        start = end + 1;
        end = strchr(start, '>');
        if (end) {
            if (start[0] == '/') {
                doc->elements[doc->num_elements - 1].tag[strlen(doc->elements[doc->num_elements - 1].tag) - 1] = '\0';
            } else {
                char *content = malloc(end - start + 1);
                strncpy(content, start, end - start);
                content[end - start] = '\0';

                doc->elements[doc->num_elements - 1].content = content;

                char *attr_start = start;
                char *attr_end;

                while ((attr_end = strchr(attr_start, '='))) {
                    char *name = malloc(attr_end - attr_start + 1);
                    strncpy(name, attr_start, attr_end - attr_start);
                    name[attr_end - attr_start] = '\0';

                    attr_start = attr_end + 1;
                    attr_end = strchr(attr_start, '"');

                    char *value = malloc(attr_end - attr_start + 1);
                    strncpy(value, attr_start, attr_end - attr_start);
                    value[attr_end - attr_start] = '\0';

                    attribute *attribute = malloc(sizeof(attribute));
                    attribute->name = name;
                    attribute->value = value;

                    doc->elements[doc->num_elements - 1].attributes = realloc(doc->elements[doc->num_elements - 1].attributes, (doc->elements[doc->num_elements - 1].num_attributes + 1) * sizeof(attribute));
                    doc->elements[doc->num_elements - 1].attributes[doc->elements[doc->num_elements - 1].num_attributes++] = *attribute;

                    attr_start = attr_end + 1;
                }
            }

            start = end + 1;
        }
    }

    return doc;
}

char *beautify_html(document *doc) {
    char *html = malloc(1024);
    int html_length = 0;

    for (int i = 0; i < doc->num_elements; i++) {
        element *element = &doc->elements[i];

        html_length += snprintf(html + html_length, 1024 - html_length, "<%s", element->tag);
        for (int j = 0; j < element->num_attributes; j++) {
            attribute *attribute = &element->attributes[j];
            html_length += snprintf(html + html_length, 1024 - html_length, " %s=\"%s\"", attribute->name, attribute->value);
        }
        html_length += snprintf(html + html_length, 1024 - html_length, ">");

        if (element->content) {
            html_length += snprintf(html + html_length, 1024 - html_length, "%s", element->content);
        }

        html_length += snprintf(html + html_length, 1024 - html_length, "</%s>", element->tag);
    }

    return html;
}

int main() {
    char *html = "<html><head><title>Beautify HTML</title></head><body><h1>Hello World</h1></body></html>";

    document *doc = parse_html(html);
    char *beautified_html = beautify_html(doc);

    printf("%s\n", beautified_html);

    return 0;
}