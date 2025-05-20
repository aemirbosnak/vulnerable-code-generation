//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: Claude Shannon
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
    char *buffer = NULL;
    int buffer_size = 0;
    int i = 0;

    // Allocate memory for the buffer
    buffer = malloc(MAX_BUFFER_SIZE);

    // Loop over the XML data
    for (i = 0; xml_data[i] != '\0'; i++) {
        // Check if the buffer is full
        if (buffer_size == MAX_BUFFER_SIZE - 1) {
            // Double the buffer size
            buffer_size *= 2;
            buffer = realloc(buffer, buffer_size);
        }

        // Add the character to the buffer
        buffer[buffer_size++] = xml_data[i];

        // If the character is a closing tag, create a new node
        if (xml_data[i] == '>' && curr) {
            XMLNode *newNode = malloc(sizeof(XMLNode));
            newNode->data = strdup(buffer);
            newNode->next = NULL;

            if (head == NULL) {
                head = newNode;
            } else {
                curr->next = newNode;
            }

            curr = newNode;
        }
    }

    // Free the buffer
    free(buffer);

    return head;
}

int main() {
    char *xml_data = "<foo>bar</foo>";
    XMLNode *head = parseXML(xml_data);

    // Print the XML data
    XMLNode *curr = head;
    while (curr) {
        printf("%s\n", curr->data);
        curr = curr->next;
    }

    return 0;
}