//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

void parseXML(char *xml_data) {
    Node *head = NULL;
    Node *curr = NULL;
    char *buffer = NULL;
    int buffer_size = 0;
    int i = 0;

    // Allocate memory for the buffer
    buffer = malloc(MAX_BUFFER_SIZE);

    // Parse the XML data
    while (xml_data[i] != '\0') {
        // Check if the buffer is full
        if (buffer_size == MAX_BUFFER_SIZE - 1) {
            // Double the size of the buffer
            buffer_size *= 2;
            buffer = realloc(buffer, buffer_size);
        }

        // Append the character to the buffer
        buffer[buffer_size++] = xml_data[i];

        // If the character is a closing tag, create a new node
        if (buffer[buffer_size - 1] == ')') {
            curr = malloc(sizeof(Node));
            curr->data = strdup(buffer);
            curr->next = NULL;

            // If the head of the list is NULL, make it the head
            if (head == NULL) {
                head = curr;
            } else {
                curr->next = head;
                head = curr;
            }
        }

        i++;
    }

    // Free the memory allocated for the buffer
    free(buffer);

    // Print the nodes of the list
    for (curr = head; curr; curr = curr->next) {
        printf("%s\n", curr->data);
    }
}

int main() {
    char xml_data[] = "<foo>bar</foo>";
    parseXML(xml_data);

    return 0;
}