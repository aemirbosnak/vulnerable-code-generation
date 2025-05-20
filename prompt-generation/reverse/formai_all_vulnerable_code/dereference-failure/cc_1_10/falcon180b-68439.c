//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define MAX_ELEMENTS 1000
#define MAX_NAME_LEN 100
#define MAX_VALUE_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} element_t;

typedef struct {
    int num_elements;
    element_t elements[MAX_ELEMENTS];
} xml_t;

xml_t* parse_xml(const char* xml_data) {
    xml_t* xml = (xml_t*)malloc(sizeof(xml_t));
    if (!xml) {
        printf("Error: Memory allocation failed.\n");
        return NULL;
    }

    xml->num_elements = 0;

    char* buffer = (char*)malloc(BUFFER_SIZE);
    if (!buffer) {
        printf("Error: Memory allocation failed.\n");
        free(xml);
        return NULL;
    }

    char* token = strtok(xml_data, "<");
    while (token!= NULL) {
        if (xml->num_elements >= MAX_ELEMENTS) {
            printf("Error: Maximum number of elements reached.\n");
            free(buffer);
            free(xml);
            return NULL;
        }

        element_t* element = &xml->elements[xml->num_elements];

        strcpy(element->name, token);
        token = strtok(NULL, " ");
        while (token!= NULL && token[0]!= '>') {
            if (strlen(element->value) >= MAX_VALUE_LEN) {
                printf("Error: Value too long.\n");
                free(buffer);
                free(xml);
                return NULL;
            }

            strcat(element->value, token);
            strcat(element->value, " ");

            token = strtok(NULL, " ");
        }

        if (token == NULL || token[0]!= '>') {
            printf("Error: Invalid XML format.\n");
            free(buffer);
            free(xml);
            return NULL;
        }

        xml->num_elements++;

        token = strtok(NULL, "<");
    }

    free(buffer);
    return xml;
}

void print_xml(const xml_t* xml) {
    for (int i = 0; i < xml->num_elements; i++) {
        printf("%s: %s\n", xml->elements[i].name, xml->elements[i].value);
    }
}

int main() {
    const char* xml_data = "<name>John</name><age>30</age><city>New York</city>";
    xml_t* xml = parse_xml(xml_data);
    if (xml) {
        print_xml(xml);
        free(xml);
    }

    return 0;
}