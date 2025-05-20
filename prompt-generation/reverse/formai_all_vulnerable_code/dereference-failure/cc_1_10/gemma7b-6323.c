//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

struct Node *parseXML(char *xml_data) {
    // Allocate memory for the root node
    struct Node *root = (struct Node *)malloc(sizeof(struct Node));
    root->data = NULL;
    root->next = NULL;

    // Parse the XML data
    char *buffer = xml_data;
    char *tag_start = NULL;
    char *tag_end = NULL;
    char *data_start = NULL;
    char *data_end = NULL;

    // Iterate over the XML data until a closing tag is found
    while (buffer) {
        tag_start = strstr(buffer, "<");
        tag_end = strstr(buffer, ">");
        data_start = strstr(buffer, ">");
        data_end = strstr(buffer, "</");

        // If a tag and data start are found, create a new node
        if (tag_start && data_start) {
            struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
            new_node->data = malloc(MAX_BUFFER_SIZE);
            memcpy(new_node->data, data_start, data_end - data_start);
            new_node->next = NULL;

            // Add the new node to the root node
            if (root->data == NULL) {
                root->data = new_node->data;
            } else {
                struct Node *current = root;
                while (current->next) {
                    current = current->next;
                }
                current->next = new_node;
            }
        }

        // Move to the next part of the XML data
        buffer = data_end + 1;
    }

    // Return the root node
    return root;
}

int main() {
    char *xml_data = "<person><name>Sherlock Holmes</name><age>45</age></person>";

    struct Node *root = parseXML(xml_data);

    // Print the data from the nodes
    struct Node *current = root;
    while (current) {
        printf("Data: %s\n", current->data);
        current = current->next;
    }

    return 0;
}