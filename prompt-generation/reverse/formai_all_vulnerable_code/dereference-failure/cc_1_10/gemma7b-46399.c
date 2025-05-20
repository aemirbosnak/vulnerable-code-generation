//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

void parse_xml(char *xml_data) {
    Node *head = NULL;
    char *buffer = NULL;
    int buffer_size = 0;
    int i = 0;

    while (xml_data[i] != '\0') {
        if (buffer_size == 0) {
            buffer = malloc(MAX_BUFFER_SIZE);
            buffer_size = MAX_BUFFER_SIZE;
        }

        if (buffer_size - 1 < i) {
            buffer = realloc(buffer, buffer_size * 2);
            buffer_size *= 2;
        }

        buffer[i] = xml_data[i];

        if (xml_data[i] == '<') {
            // Parse tag
            Node *new_node = malloc(sizeof(Node));
            new_node->data = strdup(buffer);
            new_node->next = head;
            head = new_node;
        }

        i++;
    }

    free(buffer);
}

int main() {
    char xml_data[] = "<foo><bar>Hello, world!</bar></foo>";
    parse_xml(xml_data);

    return 0;
}