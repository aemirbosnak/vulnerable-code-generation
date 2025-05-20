//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_VALUE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} element_t;

typedef struct {
    int num_elements;
    element_t elements[MAX_ELEMENTS];
} xml_data_t;

xml_data_t* parse_xml(char* xml_data) {
    xml_data_t* result = malloc(sizeof(xml_data_t));
    result->num_elements = 0;

    char* current_element = strtok(xml_data, "<");
    while (current_element!= NULL) {
        if (result->num_elements >= MAX_ELEMENTS) {
            printf("Error: Maximum number of elements reached.\n");
            exit(1);
        }

        element_t* new_element = &result->elements[result->num_elements];
        strncpy(new_element->name, current_element, MAX_NAME_LENGTH);
        new_element->name[MAX_NAME_LENGTH - 1] = '\0';

        char* value_start = strchr(current_element, '>') + 1;
        strncpy(new_element->value, value_start, MAX_VALUE_LENGTH);
        new_element->value[MAX_VALUE_LENGTH - 1] = '\0';

        current_element = strtok(NULL, "<");
        result->num_elements++;
    }

    return result;
}

void print_xml_data(xml_data_t* data) {
    printf("Number of elements: %d\n", data->num_elements);
    for (int i = 0; i < data->num_elements; i++) {
        printf("Name: %s, Value: %s\n", data->elements[i].name, data->elements[i].value);
    }
}

int main() {
    char* xml_data = "<name>John</name><age>30</age><city>New York</city>";
    xml_data_t* result = parse_xml(xml_data);
    print_xml_data(result);

    free(result);
    return 0;
}