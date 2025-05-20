//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    char *content;
} element;

void parse_element(char *start_tag, char *end_tag, char *xml, element *elem) {
    int start_index = strstr(xml, start_tag) - xml;
    int end_index = strstr(xml, end_tag) - xml;
    int length = end_index - (start_index + strlen(start_tag));

    elem->name = start_tag + 1;
    elem->name[strlen(elem->name) - 1] = '\0';
    elem->content = (char*) malloc(length * sizeof(char));
    strncpy(elem->content, xml + start_index + strlen(start_tag), length);
    elem->content[length - 1] = '\0';
}

int main() {
    FILE *fp;
    char *xml;
    element parsed_element;

    // Open the XML file
    fp = fopen("example.xml", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Calculate the file size and read the file into memory
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    rewind(fp);
    xml = (char*) malloc(size * sizeof(char));
    fread(xml, sizeof(char), size, fp);

    // Parse the XML file
    parse_element("<name>", "</name>", xml, &parsed_element);
    printf("Name: %s\n", parsed_element.content);

    parse_element("<age>", "</age>", xml, &parsed_element);
    printf("Age: %s\n", parsed_element.content);

    // Clean up memory and close the file
    free(xml);
    free(parsed_element.content);
    fclose(fp);

    return 0;
}