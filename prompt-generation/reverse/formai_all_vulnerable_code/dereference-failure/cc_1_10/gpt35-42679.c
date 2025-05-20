//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct xml_node_t {
    char *tagname;
    char *data;
    struct xml_node_t *children;
    struct xml_node_t *next;
} xml_node;

void parse_xml_node(char *xml_string, xml_node **node);

void parse_xml_children(char *xml_string, xml_node **node) {
    while (*xml_string != '\0') {
        if (*xml_string == '<') {
            xml_string++;

            if (*xml_string == '?') {
                while (*xml_string != '>' && *xml_string != '\0') {
                    xml_string++;
                }
            } else if (*xml_string == '/') {
                break;
            } else {
                xml_node *child = malloc(sizeof(xml_node));
                child->children = NULL;
                child->tagname = strtok(xml_string, " >");

                while (*xml_string != '>') {
                    xml_string++;
                }

                xml_string++;

                if (*xml_string == '<' && *(xml_string + 1) == '/') {
                    child->data = NULL;
                    child->next = NULL;
                } else {
                    char *start = xml_string;
                    while (*xml_string != '<' && *xml_string != '\0') {
                        xml_string++;
                    }

                    char *data = calloc(xml_string - start + 1, sizeof(char));
                    strncpy(data, start, xml_string - start);
                    child->data = data;
                    child->next = NULL;
                    parse_xml_node(xml_string, &child->next);
                }

                *node = child;
                node = &(*node)->next;
            }
        } else {
            xml_string++;
        }
    }
}

void parse_xml_node(char *xml_string, xml_node **node) {
    while (*xml_string != '\0') {
        if (*xml_string == '<') {
            xml_string++;

            if (*xml_string == '/') {
                xml_string++;
                break;
            } else {
                parse_xml_children(xml_string, node);
            }
        } else {
            xml_string++;
        }
    }
}

int main() {
    char xml_string[] = "<root>Hello World! <foo>Bar</foo></root>";
    xml_node *root = malloc(sizeof(xml_node));
    root->tagname = strtok(xml_string, "<>");
    root->data = NULL;
    root->children = NULL;
    root->next = NULL;

    parse_xml_node(xml_string, &root->children);

    printf("Tagname: %s\n", root->tagname);
    printf("Data: %s\n", root->data);

    xml_node *child = root->children;
    while (child != NULL) {
        printf("Tagname: %s\n", child->tagname);
        printf("Data: %s\n", child->data);

        child = child->next;
    }

    return 0;
}