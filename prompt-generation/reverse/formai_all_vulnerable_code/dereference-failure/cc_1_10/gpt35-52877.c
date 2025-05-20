//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

// Structure to store XML element information
struct xml_element {
    char tag[50];
    char attributes[100];
    char value[100];
    struct xml_element *child;
};

// Function prototype for XML parser
struct xml_element* parse_xml(char *xml);

int main() {
    char xml[BUFFER_SIZE];
    FILE *fp;

    // Open XML file for reading
    fp = fopen("sample.xml", "r");
    if(fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Read XML file into buffer
    fgets(xml, BUFFER_SIZE, fp);

    // Close file
    fclose(fp);

    // Parse XML
    struct xml_element *root = parse_xml(xml);

    // Print XML elements
    printf("Root element: <%s>", root->tag);
    printf("\n\tAttributes: %s", root->attributes);
    printf("\n\tValue: %s\n", root->value);

    // Free memory
    free(root->child);
    free(root);

    return 0;
}

// Recursive function to parse XML
struct xml_element* parse_xml(char *xml) {
    char *end_tag;
    struct xml_element *ele = (struct xml_element*) malloc(sizeof(struct xml_element));
    ele->child = NULL;

    // Extract tag name
    char *start_tag = strchr(xml, '<') + 1;
    end_tag = strchr(start_tag, '>');
    *end_tag = '\0';
    strncpy(ele->tag, start_tag, sizeof(ele->tag));
    xml = end_tag + 1;

    // Extract attributes
    start_tag = strstr(xml, "=\"") + 2;
    end_tag = strstr(start_tag, "\"");
    *end_tag = '\0';
    strncpy(ele->attributes, start_tag, sizeof(ele->attributes));
    xml = end_tag + 1;

    // Extract value
    start_tag = strchr(xml, '>') + 1;
    end_tag = strstr(start_tag, "</");
    *end_tag = '\0';
    strncpy(ele->value, start_tag, sizeof(ele->value));

    // Parse child elements
    char *start_child = strstr(xml, "<");
    while(start_child != NULL) {
        struct xml_element *child = parse_xml(start_child);
        if(ele->child == NULL)
            ele->child = child;
        else {
            struct xml_element *temp = ele->child;
            while(temp->child != NULL)
                temp = temp->child;
            temp->child = child;
        }
        start_child = strstr(start_child + 1, "<");
    }

    return ele;
}