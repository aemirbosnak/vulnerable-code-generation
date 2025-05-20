//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENT 100
#define MAX_STRING 100

typedef struct xml_element {
    char* name;
    struct xml_element* child[MAX_ELEMENT];
} xml_element;

xml_element* parse_xml(FILE* xml_file) {
    char c;
    char* text_buffer = (char*) malloc(sizeof(char) * MAX_STRING);
    xml_element* root_element = (xml_element*) malloc(sizeof(xml_element));

    if (xml_file == NULL || text_buffer == NULL || root_element == NULL) {
        return NULL;
    }

    xml_element* curr_element = root_element;

    while ((c = fgetc(xml_file)) != EOF) {
        if (c == '<') {
            if (strcmp(text_buffer, "") != 0) {
                xml_element* text_element = (xml_element*) malloc(sizeof(xml_element));
                text_element->name = (char*) malloc(sizeof(char) * (strlen(text_buffer) + 1));
                strcpy(text_element->name, text_buffer);
                curr_element->child[0] = text_element;
                curr_element = text_element;
                memset(text_buffer, 0, MAX_STRING);
            }
            char* name_buffer = (char*) malloc(sizeof(char) * MAX_STRING);
            int i = 0;
            while ((c = fgetc(xml_file)) != '>') {
                name_buffer[i++] = c;
            }
            name_buffer[i] = '\0';
            curr_element->name = (char*) malloc(sizeof(char) * (strlen(name_buffer) + 1));
            strcpy(curr_element->name, name_buffer);
            free(name_buffer);
        }
        else if (c == '/') {
            if (strcmp(text_buffer, "") != 0) {
                xml_element* text_element = (xml_element*) malloc(sizeof(xml_element));
                text_element->name = (char*) malloc(sizeof(char) * (strlen(text_buffer) + 1));
                strcpy(text_element->name, text_buffer);
                curr_element->child[0] = text_element;
                memset(text_buffer, 0, MAX_STRING);
            }
            xml_element* parent = curr_element;
            curr_element = (xml_element*) malloc(sizeof(xml_element));
            parent->child[1] = curr_element;
            memset(curr_element, 0, sizeof(xml_element));
        }
        else {
            strncat(text_buffer, &c, 1);
        }
    }

    free(text_buffer);
    return root_element;
}

int main() {
    FILE* xml_file = fopen("example.xml", "r");
    xml_element* root = parse_xml(xml_file);

    if (root == NULL) {
        printf("Failed to parse XML.\n");
        return -1;
    }

    printf("XML tree:\n");
    printf("%s\n", root->name); // print root element name
    printf("%s\n", root->child[0]->name); // print root element text

    fclose(xml_file);
    return 0;
}