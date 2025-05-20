//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *tag;
    char *attr;
    char *value;
} element;

typedef struct {
    element *elements;
    int element_count;
} xml;

typedef struct {
    char *name;
    char *value;
} attribute;

void create_element(xml *doc, char *tag, char *attr, char *value) {
    if (doc->element_count == 0) {
        doc->elements = malloc(sizeof(element));
    } else {
        doc->elements = realloc(doc->elements, sizeof(element) * (doc->element_count + 1));
    }
    element elem;
    elem.tag = strdup(tag);
    elem.attr = strdup(attr);
    elem.value = strdup(value);
    doc->elements[doc->element_count] = elem;
    doc->element_count++;
}

void print_element(element elem, int indent) {
    int i;
    for (i = 0; i < indent; i++) {
        putchar(' ');
        putchar(' ');
    }
    printf("<%s", elem.tag);
    if (elem.attr != NULL) {
        printf(" %s", elem.attr);
    }
    printf("> ");
    if (elem.value != NULL) {
        printf("%s ", elem.value);
    }
    printf("</%s>\n", elem.tag);
}

void print_document(xml doc) {
    int i;
    for (i = 0; i < doc.element_count; i++) {
        print_element(doc.elements[i], 0);
    }
}

int main() {
    xml doc;
    doc.elements = NULL;
    doc.element_count = 0;

    create_element(&doc, "knight", "name=\"Lancelot\"", NULL);
    create_element(&doc, "armor", "color=\"silver\"", "Shiny");
    create_element(&doc, "weapon", "type=\"sword\"", "Sharp and pointy");
    create_element(&doc, "/armor", NULL, NULL);
    create_element(&doc, "/knight", NULL, NULL);

    print_document(doc);

    return 0;
}