//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct XMLNode {
    char *data;
    struct XMLNode *next;
} XMLNode;

XMLNode *parseXML(char *xml_data) {
    XMLNode *head = NULL;
    XMLNode *curr = NULL;

    // Allocate memory for the first node
    head = malloc(sizeof(XMLNode));
    head->data = strdup(xml_data);
    head->next = NULL;

    curr = head;

    // Iterate over the XML data and create nodes for each element
    char *start = xml_data;
    char *end = xml_data;
    while (end) {
        // Find the end of the element
        end = strstr(start, ">");

        // Allocate memory for the node
        XMLNode *node = malloc(sizeof(XMLNode));
        node->data = strdup(start);
        node->next = NULL;

        // Add the node to the list
        curr->next = node;
        curr = node;

        // Update the start pointer to the next element
        start = end + 1;
    }

    return head;
}

int main() {
    char xml_data[] = "<foo>bar</foo>";
    XMLNode *head = parseXML(xml_data);

    // Print the XML data
    XMLNode *curr = head;
    while (curr) {
        printf("%s\n", curr->data);
        curr = curr->next;
    }

    return 0;
}