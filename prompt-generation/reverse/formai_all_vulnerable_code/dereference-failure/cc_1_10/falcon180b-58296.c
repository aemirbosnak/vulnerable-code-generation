//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 1000
#define MAX_NAME_LENGTH 100
#define MAX_VALUE_LENGTH 1000

typedef struct {
    char name[MAX_NAME_LENGTH];
    char value[MAX_VALUE_LENGTH];
} element_t;

element_t elements[MAX_ELEMENTS];
int num_elements = 0;

void add_element(char* name, char* value) {
    if (num_elements >= MAX_ELEMENTS) {
        printf("Error: Maximum number of elements reached.\n");
        return;
    }

    strcpy(elements[num_elements].name, name);
    strcpy(elements[num_elements].value, value);

    num_elements++;
}

void print_elements() {
    printf("Elements:\n");
    for (int i = 0; i < num_elements; i++) {
        printf("%s: %s\n", elements[i].name, elements[i].value);
    }
}

int main() {
    // Example XML data
    char* xml_data = "<root>\n"
                      "  <element name=\"name\" value=\"John\"/>\n"
                      "  <element name=\"age\" value=\"30\"/>\n"
                      "</root>";

    // Parse XML data
    char* current_element = strtok(xml_data, "\n");
    while (current_element!= NULL) {
        if (strncmp(current_element, "<element ", 9) == 0) {
            char* name_start = strstr(current_element, " name=\"") + 8;
            char* name_end = strstr(name_start, "\"/>");
            char* value_start = strstr(current_element, " value=\"") + 9;
            char* value_end = strstr(value_start, "\"/>");

            char name[MAX_NAME_LENGTH];
            char value[MAX_VALUE_LENGTH];

            strncpy(name, name_start, name_end - name_start);
            name[name_end - name_start] = '\0';

            strncpy(value, value_start, value_end - value_start);
            value[value_end - value_start] = '\0';

            add_element(name, value);
        }

        current_element = strtok(NULL, "\n");
    }

    // Print parsed data
    print_elements();

    return 0;
}