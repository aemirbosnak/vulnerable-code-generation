//Falcon-180B DATASET v1.0 Category: Building a XML Parser ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ELEMENTS 100
#define MAX_NAME_LEN 50
#define MAX_VALUE_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char value[MAX_VALUE_LEN];
} element_t;

int num_elements = 0;
element_t elements[MAX_ELEMENTS];

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
        printf("Name: %s, Value: %s\n", elements[i].name, elements[i].value);
    }
}

int main() {
    char buffer[1024];
    FILE* xml_file = fopen("example.xml", "r");

    if (xml_file == NULL) {
        printf("Error: Could not open XML file.\n");
        return 1;
    }

    while (fgets(buffer, sizeof(buffer), xml_file)!= NULL) {
        char* name = NULL;
        char* value = NULL;

        int len = strlen(buffer);
        char* pos = strchr(buffer, '=');

        if (pos == NULL) {
            printf("Error: Invalid XML format.\n");
            fclose(xml_file);
            return 1;
        }

        *pos = '\0';
        name = strdup(buffer);
        value = strdup(pos + 1);

        add_element(name, value);
    }

    fclose(xml_file);
    print_elements();

    return 0;
}