//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 1000
#define MAX_VALUE_LENGTH 1000

typedef struct {
    char *key;
    char *value;
} element_t;

typedef struct {
    element_t *elements;
    int num_elements;
} document_t;

document_t *create_document() {
    document_t *doc = malloc(sizeof(document_t));
    doc->elements = malloc(MAX_ELEMENTS * sizeof(element_t));
    doc->num_elements = 0;
    return doc;
}

void destroy_document(document_t *doc) {
    for (int i = 0; i < doc->num_elements; i++) {
        free(doc->elements[i].key);
        free(doc->elements[i].value);
    }
    free(doc->elements);
    free(doc);
}

void add_element(document_t *doc, char *key, char *value) {
    if (doc->num_elements >= MAX_ELEMENTS) {
        printf("Error: Maximum number of elements reached.\n");
        return;
    }
    element_t *new_element = malloc(sizeof(element_t));
    new_element->key = strdup(key);
    new_element->value = strdup(value);
    doc->elements[doc->num_elements++] = *new_element;
}

int main() {
    FILE *fp = fopen("example.xml", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }
    char line[MAX_VALUE_LENGTH];
    document_t *doc = create_document();
    int in_element = 0;
    while (fgets(line, MAX_VALUE_LENGTH, fp)!= NULL) {
        char *ptr = line;
        while (*ptr!= '\0' && isspace(*ptr)) ptr++;
        if (in_element) {
            if (*ptr == '>') {
                in_element = 0;
            } else {
                char *value_start = strchr(ptr, '"');
                if (value_start == NULL) {
                    printf("Error: Invalid XML format.\n");
                    destroy_document(doc);
                    fclose(fp);
                    return 1;
                }
                value_start++;
                char *value_end = strchr(value_start, '"');
                if (value_end == NULL) {
                    printf("Error: Invalid XML format.\n");
                    destroy_document(doc);
                    fclose(fp);
                    return 1;
                }
                *value_end = '\0';
                add_element(doc, ptr, value_start);
            }
        } else {
            if (strncmp(ptr, "<element", 8) == 0) {
                in_element = 1;
            }
        }
    }
    fclose(fp);
    printf("Document parsed successfully!\n");
    for (int i = 0; i < doc->num_elements; i++) {
        printf("Key: %s, Value: %s\n", doc->elements[i].key, doc->elements[i].value);
    }
    destroy_document(doc);
    return 0;
}