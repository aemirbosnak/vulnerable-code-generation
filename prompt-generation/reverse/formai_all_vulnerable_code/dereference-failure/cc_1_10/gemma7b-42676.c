//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char **data;
    struct Node* next;
} Node;

void parseXML(char* xml_data) {
    char* buffer = malloc(MAX_BUFFER_SIZE);
    int index = 0;
    Node* head = NULL;

    while (*xml_data) {
        switch (*xml_data) {
            case '<':
                // Extract tag name and allocate memory for data
                buffer = xml_data + 1;
                int tag_length = 0;
                while (*buffer && *buffer != '>') {
                    tag_length++;
                    buffer++;
                }
                char* tag_name = malloc(tag_length + 1);
                memcpy(tag_name, buffer, tag_length);
                tag_name[tag_length] = '\0';

                Node* new_node = malloc(sizeof(Node));
                new_node->data = tag_name;
                new_node->next = head;
                head = new_node;

                break;
            case ' ':
            case '\n':
            case '\t':
                // Skip whitespace
                break;
            default:
                // Append data to current node
                index++;
                buffer = xml_data;
                break;
        }
        xml_data++;
    }

    // Print data from nodes
    Node* current_node = head;
    while (current_node) {
        printf("%s\n", current_node->data);
        current_node = current_node->next;
    }

    free(buffer);
    free(head);
}

int main() {
    char xml_data[] = "<root><person><name>John Doe</name><age>30</age></person></root>";
    parseXML(xml_data);

    return 0;
}