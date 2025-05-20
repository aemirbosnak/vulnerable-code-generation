//GEMINI-pro DATASET v1.0 Category: Building a XML Parser ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *value;
} XMLNode;

typedef struct {
    XMLNode *nodes;
    int num_nodes;
} XMLDocument;

XMLDocument *parse_xml(char *xml) {
    XMLDocument *doc = malloc(sizeof(XMLDocument));
    doc->nodes = malloc(sizeof(XMLNode));
    doc->num_nodes = 0;

    char *start = xml;
    char *end = xml;

    while (*end != '\0') {
        if (*end == '<') {
            start = end;
            end = strchr(end, '>');
            if (end == NULL) {
                fprintf(stderr, "Error: Unterminated XML tag\n");
                return NULL;
            }

            *end = '\0';
            char *name = strdup(start + 1);
            char *value = strchr(start, '=');
            if (value != NULL) {
                *value = '\0';
                value = strdup(value + 1);
            }

            XMLNode *node = malloc(sizeof(XMLNode));
            node->name = name;
            node->value = value;

            doc->nodes = realloc(doc->nodes, (doc->num_nodes + 1) * sizeof(XMLNode));
            doc->nodes[doc->num_nodes++] = *node;

            end++;
        } else {
            end++;
        }
    }

    return doc;
}

void free_xml_document(XMLDocument *doc) {
    for (int i = 0; i < doc->num_nodes; i++) {
        free(doc->nodes[i].name);
        free(doc->nodes[i].value);
    }
    free(doc->nodes);
    free(doc);
}

void print_xml_document(XMLDocument *doc) {
    for (int i = 0; i < doc->num_nodes; i++) {
        printf("<%s", doc->nodes[i].name);
        if (doc->nodes[i].value != NULL) {
            printf("=%s", doc->nodes[i].value);
        }
        printf(">\n");
    }
}

int main() {
    char *xml = "<root><child1 value=\"value1\"/><child2/><child3 value=\"value3\"/></root>";
    XMLDocument *doc = parse_xml(xml);
    print_xml_document(doc);
    free_xml_document(doc);
    return 0;
}