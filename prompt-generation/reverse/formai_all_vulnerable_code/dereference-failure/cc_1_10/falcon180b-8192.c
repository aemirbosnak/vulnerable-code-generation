//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_ELEMENTS 1000
#define MAX_ATTRIBUTES 100
#define MAX_VALUE_LENGTH 1000
#define MAX_ELEMENT_NAME_LENGTH 100

typedef struct {
    char *name;
    char *value;
    struct element_attribute *next;
} element_attribute;

typedef struct {
    char *name;
    int num_attributes;
    element_attribute *attributes;
    struct element *next;
} element;

typedef struct {
    element *head;
    int num_elements;
} xml_document;

xml_document *xml_parse(char *xml_string) {
    xml_document *document = malloc(sizeof(xml_document));
    document->head = NULL;
    document->num_elements = 0;
    char *current_element = strtok(xml_string, "<");
    while (current_element!= NULL) {
        element *new_element = malloc(sizeof(element));
        new_element->name = strdup(current_element);
        new_element->num_attributes = 0;
        new_element->attributes = NULL;
        new_element->next = NULL;
        if (document->head == NULL) {
            document->head = new_element;
        } else {
            element *last_element = document->head;
            while (last_element->next!= NULL) {
                last_element = last_element->next;
            }
            last_element->next = new_element;
        }
        document->num_elements++;
        current_element = strtok(NULL, "<");
    }
    return document;
}

void xml_free(xml_document *document) {
    element *current_element = document->head;
    while (current_element!= NULL) {
        element_attribute *current_attribute = current_element->attributes;
        while (current_attribute!= NULL) {
            free(current_attribute->name);
            free(current_attribute->value);
            free(current_attribute);
            current_attribute = current_attribute->next;
        }
        free(current_element->name);
        free(current_element);
        current_element = current_element->next;
    }
    free(document);
}

void xml_print(xml_document *document) {
    element *current_element = document->head;
    while (current_element!= NULL) {
        printf("<%s", current_element->name);
        element_attribute *current_attribute = current_element->attributes;
        while (current_attribute!= NULL) {
            printf(" %s=\"%s\"", current_attribute->name, current_attribute->value);
            current_attribute = current_attribute->next;
        }
        printf(">");
        current_element = current_element->next;
    }
}

int main() {
    char xml_string[] =
        "<bookstore>"
        "<book>"
        "<title>Harry Potter</title>"
        "<author>J.K. Rowling</author>"
        "<price>29.99</price>"
        "</book>"
        "<book>"
        "<title>The Hobbit</title>"
        "<author>J.R.R. Tolkien</author>"
        "<price>19.99</price>"
        "</book>"
        "</bookstore>";
    xml_document *document = xml_parse(xml_string);
    xml_print(document);
    xml_free(document);
    return 0;
}