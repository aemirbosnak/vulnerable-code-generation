//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: light-weight
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
    char *buffer = NULL;
    int buffer_size = 0;
    int i = 0;

    while (xml_data[i] != '\0') {
        if (buffer_size == 0) {
            buffer = (char *)malloc(MAX_BUFFER_SIZE);
            buffer_size = MAX_BUFFER_SIZE;
        }

        if (xml_data[i] == '<' && xml_data[i + 1] == '>' && xml_data[i + 2] == '/') {
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->data = buffer;
            newNode->next = head;
            head = newNode;
        } else {
            buffer[buffer_size - 1] = xml_data[i];
            buffer_size--;
        }

        i++;
    }

    // Print the nodes
    Node *current = head;
    while (current) {
        printf("%s\n", current->data);
        current = current->next;
    }

    free(buffer);
    free(head);
}

int main() {
    char xml_data[] = "<root><child>Hello, world!</child></root>";
    parseXML(xml_data);

    return 0;
}