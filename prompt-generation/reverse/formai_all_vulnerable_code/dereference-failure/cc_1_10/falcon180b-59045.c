//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 200

typedef struct {
    char *name;
    char *value;
} element_t;

typedef struct {
    int num_elements;
    element_t elements[MAX_ELEMENTS];
} xml_t;

int parse_xml(xml_t *xml, char *xml_string) {
    char *start = xml_string;
    char *end = start;
    int num_elements = 0;

    while (num_elements < MAX_ELEMENTS && *end!= '\0') {
        if (*end == '<') {
            end++;
            while (*end!= '>' && *end!= '\0') {
                end++;
            }
            if (*end == '>') {
                end++;
                xml->elements[num_elements].name = malloc(MAX_NAME_LENGTH);
                strncpy(xml->elements[num_elements].name, start, MAX_NAME_LENGTH);
                xml->elements[num_elements].name[MAX_NAME_LENGTH - 1] = '\0';
                start = end;
                num_elements++;
            }
        } else if (*end == '=') {
            end++;
            while (*end!= '\"' && *end!= '\0') {
                end++;
            }
            if (*end == '\"') {
                end++;
                xml->elements[num_elements].value = malloc(MAX_VALUE_LENGTH);
                strncpy(xml->elements[num_elements].value, start, MAX_VALUE_LENGTH);
                xml->elements[num_elements].value[MAX_VALUE_LENGTH - 1] = '\0';
                start = end + 1;
                num_elements++;
            }
        } else {
            end++;
        }
    }

    if (*end!= '\0') {
        return 0;
    }

    xml->num_elements = num_elements;
    return 1;
}

void print_xml(xml_t *xml) {
    int i;

    for (i = 0; i < xml->num_elements; i++) {
        printf("Name: %s\nValue: %s\n", xml->elements[i].name, xml->elements[i].value);
    }
}

int main() {
    char xml_string[] = "<name>John</name><age>30</age>";
    xml_t xml;

    if (parse_xml(&xml, xml_string)) {
        print_xml(&xml);
    }

    return 0;
}