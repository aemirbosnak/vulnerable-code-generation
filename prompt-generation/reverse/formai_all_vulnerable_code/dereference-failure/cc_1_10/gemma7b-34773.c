//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    struct Node* next;
    char* data;
} Node;

void parse_xml(char* xml_data) {
    Node* head = NULL;
    Node* tail = NULL;

    // Convert XML data into tokens
    char* token = strtok(xml_data, "<");
    while (token) {
        char* element_name = strtok(token, ">");
        char* closing_tag = strstr(token, "</");

        // Create a new node
        Node* new_node = malloc(sizeof(Node));
        new_node->data = malloc(MAX_BUFFER_SIZE);
        snprintf(new_node->data, MAX_BUFFER_SIZE, "%s", element_name);

        // Add the new node to the end of the list
        if (head == NULL) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }

        // Tokenize the remaining part of the element
        token = strtok(closing_tag, ">");
    }

    // Print the nodes
    Node* current = head;
    while (current) {
        printf("%s\n", current->data);
        current = current->next;
    }

    // Free the memory
    free(head);
}

int main() {
    char* xml_data = "<foo><bar>baz</bar></foo>";
    parse_xml(xml_data);

    return 0;
}