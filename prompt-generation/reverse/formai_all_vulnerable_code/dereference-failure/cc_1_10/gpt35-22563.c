//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct xml_element {
    char *name;
    char *content;
    struct xml_element *child;
    struct xml_element *sibling;
} xml_element;

xml_element *parse(xml_element *parent, char *xml) {
    char *start_tag = strstr(xml, "<");
    char *end_tag = strstr(start_tag, ">");

    if (!start_tag || !end_tag) {
        return NULL;
    }

    xml_element *element = (xml_element *)malloc(sizeof(xml_element));
    element->name = (char *)malloc(end_tag - start_tag - 1);
    strncpy(element->name, start_tag + 1, end_tag - start_tag - 1);
    element->name[end_tag - start_tag - 1] = '\0';

    char *content_start = end_tag + 1;
    char *tag_end = strstr(content_start, "<");

    if (!tag_end) {
        size_t content_length = strlen(content_start) - 1;
        element->content = (char *)malloc(content_length);
        strncpy(element->content, content_start, content_length);
        element->content[content_length] = '\0';
        return element;
    }

    size_t content_length = tag_end - content_start;
    element->content = (char *)malloc(content_length);
    strncpy(element->content, content_start, content_length);
    element->content[content_length] = '\0';

    xml_element *child = NULL;
    xml_element *sibling = NULL;
    parse(parent, tag_end);

    if (!parent->child) {
        parent->child = element;
    } else {
        child = parent->child;

        while (child) {
            sibling = child;
            child = child->sibling;
        }

        sibling->sibling = element;
    }

    return element;
}

void print_element(xml_element *element, int indent) {
    for (int i = 0; i < indent; i++) {
        printf("\t");
    }

    printf("<%s>", element->name);

    if (element->content) {
        printf("%s", element->content);
    }

    printf("\n");

    if (element->child) {
        print_element(element->child, indent + 1);
    }

    if (element->sibling) {
        print_element(element->sibling, indent);
    } else {
        for (int i = 0; i < indent - 1; i++) {
            printf("\t");
        }

        printf("</%s>\n", element->name);
    }
}

int main() {
    xml_element *root = (xml_element *)malloc(sizeof(xml_element));
    root->name = "root";
    parse(root, "<root><element>Content</element><element><nested>Content</nested></element></root>");
    print_element(root, 0);
    return 0;
}