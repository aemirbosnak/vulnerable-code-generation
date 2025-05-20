//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

Node *insert_node(Node *head, char *data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = strdup(data);
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        head->next = new_node;
    }

    return head;
}

void parse_xml(char *xml_data) {
    Node *head = NULL;
    char *buffer = NULL;
    char *ptr = xml_data;

    while (ptr) {
        // Extract tag name
        buffer = strstr(ptr, "<");
        if (buffer) {
            *buffer = '\0';
            insert_node(head, buffer + 1);
            ptr = buffer + 1;
        }

        // Extract data
        buffer = strstr(ptr, ">");
        if (buffer) {
            *buffer = '\0';
            insert_node(head, ptr);
            ptr = buffer + 1;
        }
    }

    // Print nodes
    for (Node *node = head; node; node = node->next) {
        printf("%s\n", node->data);
    }

    free(buffer);
    free(head);
}

int main() {
    char *xml_data = "<foo>bar</foo>";
    parse_xml(xml_data);

    return 0;
}