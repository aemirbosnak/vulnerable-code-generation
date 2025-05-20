//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 100
#define MAX_ELEMENTS 50

typedef struct {
    char tag[MAX_CHARS];
    char value[MAX_CHARS];
} element;

int parseXML(char* filename, element* elements, int max_elements) {
    FILE* xml_file;
    char line[MAX_CHARS];
    char tag[MAX_CHARS];
    char value[MAX_CHARS];
    int num_elements = 0;
    int is_tag = 0;
    int is_closing_tag = 0;
    int is_value = 0;

    xml_file = fopen(filename, "r");
    if (xml_file == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    while (fgets(line, MAX_CHARS, xml_file) != NULL) {
        int len = strlen(line);
        for (int i=0; i<len; i++) {
            if (line[i] == '<') {
                is_tag = 1;
                is_closing_tag = (line[i+1] == '/');
                memset(tag, 0, MAX_CHARS);
                continue;
            }
            if (line[i] == '>') {
                is_tag = 0;
                is_value = 1;
                if (!is_closing_tag) {
                    strcpy(elements[num_elements].tag, tag);
                    num_elements++;
                    if (num_elements == max_elements) {
                        printf("Too many elements\n");
                        return -1;
                    }
                }
                continue;
            }
            if (is_tag) {
                int tag_len = strlen(tag);
                if (tag_len < MAX_CHARS-1) {
                    tag[tag_len] = line[i];
                }
            }
            if (is_value) {
                int value_len = strlen(value);
                if (value_len < MAX_CHARS-1) {
                    value[value_len] = line[i];
                }
            }
        }
    }

    fclose(xml_file);
    return num_elements;
}

void printElements(element* elements, int num_elements) {
    for (int i=0; i<num_elements; i++) {
        printf("%s: %s\n", elements[i].tag, elements[i].value);
    }
}

int main(int argc, char** argv) {

    // Configurable filename and max number of elements
    char* filename = "example.xml";
    int max_elements = MAX_ELEMENTS;

    element* elements = (element*) malloc(sizeof(element) * max_elements);
    memset(elements, 0, sizeof(element) * max_elements);

    int num_elements = parseXML(filename, elements, max_elements);
    if (num_elements >= 0) {
        printElements(elements, num_elements);
    }

    free(elements);
    return 0;
}