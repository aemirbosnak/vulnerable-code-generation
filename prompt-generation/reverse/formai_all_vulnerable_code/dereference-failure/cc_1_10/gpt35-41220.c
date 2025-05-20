//FormAI DATASET v1.0 Category: Building a XML Parser ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for holding the parsed XML data
typedef struct XMLNode {
    char name[50];
    char value[100];
    struct XMLNode *children[100];
    int num_children;
} XMLNode;

// Function to parse the XML string and return the root node
XMLNode *parseXML(char *xml)
{
    XMLNode *root = NULL, *current = NULL;
    char *start_tag = NULL, *end_tag = NULL, *tag_name = NULL, *tag_value = NULL;
    int i;

    while (*xml) {
        if (*xml == '<') {
            start_tag = xml;
            end_tag = strchr(xml, '>');
            if (!end_tag) {
                fprintf(stderr, "Error: Malformed XML\n");
                exit(1);
            }
            if (*(end_tag - 1) == '/') {
                // Self-closing tag
                tag_name = strndup(start_tag + 1, end_tag - start_tag - 2);
                if (!tag_name) {
                    perror("Error: Memory allocation failed");
                    exit(1);
                }
                XMLNode *new_node = (XMLNode *)malloc(sizeof(XMLNode));
                if (!new_node) {
                    perror("Error: Memory allocation failed");
                    exit(1);
                }
                strcpy(new_node->name, tag_name);
                new_node->value[0] = '\0';
                new_node->num_children = 0;
                current->children[current->num_children++] = new_node;
            } else if (*++end_tag == '<') {
                // Opening tag
                tag_name = strndup(start_tag + 1, end_tag - start_tag - 2);
                if (!tag_name) {
                    perror("Error: Memory allocation failed");
                    exit(1);
                }
                XMLNode *new_node = (XMLNode *)malloc(sizeof(XMLNode));
                if (!new_node) {
                    perror("Error: Memory allocation failed");
                    exit(1);
                }
                strcpy(new_node->name, tag_name);
                new_node->value[0] = '\0';
                new_node->num_children = 0;
                if (!root) {
                    root = new_node;
                    current = new_node;
                } else {
                    current->children[current->num_children++] = new_node;
                    current = new_node;
                }
            } else {
                // Closing tag
                tag_name = strndup(start_tag + 2, end_tag - start_tag - 3);
                if (!tag_name) {
                    perror("Error: Memory allocation failed");
                    exit(1);
                }
                if (strcmp(tag_name, current->name)) {
                    fprintf(stderr, "Error: Mismatched tags\n");
                    exit(1);
                }
                current = (XMLNode *)malloc(sizeof(XMLNode));
                if (!current) {
                    perror("Error: Memory allocation failed");
                    exit(1);
                }
            }
            xml = end_tag + 1;
        } else {
            // Text node
            tag_value = strndup(xml, strcspn(xml, "<"));
            if (!tag_value) {
                perror("Error: Memory allocation failed");
                exit(1);
            }
            strcpy(current->value, tag_value);
            xml += strlen(tag_value);
        }
    }

    return root;
}

int main()
{
    char xml[] = "<root><person><name>John</name><age>30</age></person><person><name>Jane</name><age>25</age></person></root>";
    XMLNode *root = parseXML(xml);
    printf("Root node name: %s\n", root->name);
    for (int i = 0; i < root->num_children; i++) {
        XMLNode *person = root->children[i];
        printf("Person %d:\n", i + 1);
        printf("\tName: %s\n", person->children[0]->value);
        printf("\tAge: %s\n", person->children[1]->value);
    }
    return 0;
}