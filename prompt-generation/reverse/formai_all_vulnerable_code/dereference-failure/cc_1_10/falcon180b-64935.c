//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 1000
#define MAX_NAME_LENGTH 100
#define MAX_VALUE_LENGTH 200

typedef struct {
    char *name;
    char *value;
    int is_attribute;
} xml_element;

xml_element elements[MAX_ELEMENTS];
int num_elements = 0;

void start_element(char *name, char *value, int is_attribute) {
    if (num_elements >= MAX_ELEMENTS) {
        printf("Error: Maximum number of elements reached.\n");
        exit(1);
    }
    xml_element new_element;
    new_element.name = strdup(name);
    new_element.value = strdup(value);
    new_element.is_attribute = is_attribute;
    elements[num_elements++] = new_element;
}

void end_element(char *name) {
}

void characters(char *text) {
}

void start_document() {
}

void end_document() {
}

int main() {
    xml_element root_element;
    root_element.name = strdup("root");
    root_element.value = NULL;
    root_element.is_attribute = 0;
    elements[num_elements++] = root_element;

    start_element("name", "John", 0);
    start_element("age", "30", 0);
    start_element("city", "New York", 0);
    start_element("country", "USA", 0);
    start_element("gender", "male", 0);
    end_element("gender");
    end_element("country");
    end_element("city");
    end_element("age");
    end_element("name");

    end_document();

    for (int i = 0; i < num_elements; i++) {
        if (elements[i].is_attribute) {
            printf("Attribute: %s=%s\n", elements[i].name, elements[i].value);
        } else {
            printf("Element: %s\n", elements[i].name);
            if (elements[i].value!= NULL) {
                printf("  Value: %s\n", elements[i].value);
            }
        }
    }

    return 0;
}