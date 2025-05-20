//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LEN 1024
#define MAX_ELEMENTS 1024

typedef struct {
    char *name;
    char *value;
} attribute_t;

typedef struct {
    char *name;
    int num_attributes;
    attribute_t *attributes;
} element_t;

typedef struct {
    element_t *elements;
    int num_elements;
} document_t;

char *read_token(FILE *fp);
element_t *create_element(char *name);
document_t *create_document();
void add_attribute(element_t *element, char *name, char *value);
void add_element(document_t *document, element_t *element);

int main() {
    FILE *fp = fopen("example.xml", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    document_t *document = create_document();

    char *token = read_token(fp);
    while (token!= NULL) {
        if (strcmp(token, "<element") == 0) {
            element_t *element = create_element(read_token(fp));
            while (strcmp(token, "</element")!= 0) {
                add_attribute(element, token, read_token(fp));
                token = read_token(fp);
            }
            add_element(document, element);
        }
        token = read_token(fp);
    }

    fclose(fp);

    return 0;
}

char *read_token(FILE *fp) {
    char token[MAX_TOKEN_LEN];
    char c;
    int i = 0;

    while ((c = fgetc(fp))!= EOF && i < MAX_TOKEN_LEN - 1) {
        if (isspace(c)) {
            token[i] = '\0';
            break;
        }
        token[i++] = c;
    }

    if (i == 0) {
        return NULL;
    }

    return strdup(token);
}

element_t *create_element(char *name) {
    element_t *element = malloc(sizeof(element_t));
    element->name = strdup(name);
    element->num_attributes = 0;
    element->attributes = NULL;

    return element;
}

document_t *create_document() {
    document_t *document = malloc(sizeof(document_t));
    document->elements = NULL;
    document->num_elements = 0;

    return document;
}

void add_attribute(element_t *element, char *name, char *value) {
    attribute_t *attribute = malloc(sizeof(attribute_t));
    attribute->name = strdup(name);
    attribute->value = strdup(value);

    element->attributes = realloc(element->attributes, sizeof(attribute_t) * (element->num_attributes + 1));
    element->attributes[element->num_attributes++] = *attribute;
}

void add_element(document_t *document, element_t *element) {
    document->elements = realloc(document->elements, sizeof(element_t) * (document->num_elements + 1));
    document->elements[document->num_elements++] = *element;
}