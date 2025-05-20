//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 100

typedef struct {
    char *name;
    char *value;
    int attribute;
} element;

element elements[MAX_ELEMENTS];
int num_elements = 0;

void startElement(char *name, char *value, int attribute) {
    if (num_elements >= MAX_ELEMENTS) {
        printf("Error: Too many elements\n");
        exit(1);
    }
    elements[num_elements].name = strdup(name);
    elements[num_elements].value = strdup(value);
    elements[num_elements].attribute = attribute;
    num_elements++;
}

void endElement(char *name) {
    int i;
    for (i = 0; i < num_elements; i++) {
        if (strcmp(elements[i].name, name) == 0) {
            free(elements[i].name);
            free(elements[i].value);
            num_elements--;
            return;
        }
    }
    printf("Error: End element without start element\n");
    exit(1);
}

void characters(char *data) {
    int i;
    for (i = 0; i < num_elements; i++) {
        if (elements[i].attribute) {
            printf("Attribute %s=%s\n", elements[i].name, elements[i].value);
        } else {
            printf("Element %s: %s\n", elements[i].name, data);
        }
    }
}

int main() {
    FILE *fp;
    char buffer[1024];
    int len;

    fp = fopen("example.xml", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file\n");
        exit(1);
    }

    while ((len = fread(buffer, 1, sizeof(buffer), fp)) > 0) {
        buffer[len] = '\0';
        startElement("text", buffer, 0);
        characters(buffer);
    }

    fclose(fp);

    return 0;
}