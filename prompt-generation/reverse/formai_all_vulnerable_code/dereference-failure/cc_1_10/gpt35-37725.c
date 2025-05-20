//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

typedef struct {
    char tag[MAX_SIZE];
    char value[MAX_SIZE];
} xml_element;

int parse_xml(char *xml, xml_element **elements) {
    *elements = NULL;
    int count = 0;

    char *start_tag = NULL;
    char *end_tag = NULL;
    char *start_val = NULL;
    char *end_val = NULL;

    while (*xml) {
        if (*xml == '<') {
            if (*(xml+1) != '/') {
                start_tag = xml + 1;
                end_tag = strchr(start_tag, '>');
            }
            else {
                end_val = xml;
                count++;
                *elements = realloc(*elements, count * sizeof(xml_element));
                (*elements)[count-1].value[end_val-start_val] = '\0';
                strcpy((*elements)[count-1].tag, start_tag+1);
                strcpy((*elements)[count-1].value, start_val);
            }
        }
        else if (*xml == '>') {
            if (*(xml-1) == '/') {
                count++;
                *elements = realloc(*elements, count * sizeof(xml_element));
                (*elements)[count-1].tag[end_tag-start_tag] = '\0';
                strcpy((*elements)[count-1].tag, start_tag+1);
                (*elements)[count-1].value[0] = '\0';
            }
            else {
                start_val = xml + 1;
            }
        }
        xml++;
    }

    return count;
}

int main() {
    char xml[] = "<person name=\"John Doe\"><age>30</age><address><street>Main St</street><city>Anytown</city></address></person>";
    xml_element *elements = NULL;
    int count = parse_xml(xml, &elements);

    printf("XML elements found: %d\n", count);
    for (int i = 0; i < count; i++) {
        printf("Tag: %s, Value: %s\n", elements[i].tag, elements[i].value);
    }

    free(elements);

    return 0;
}