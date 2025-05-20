//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

void insert_node(Node **head, char *data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = strdup(data);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void xml_parser(char *xml_data) {
    char *buffer = malloc(MAX_BUFFER_SIZE);
    int index = 0;
    Node *head = NULL;

    while (*xml_data) {
        char current_char = *xml_data++;
        buffer[index++] = current_char;

        if (current_char == '<') {
            insert_node(&head, buffer);
            index = 0;
        }
    }

    insert_node(&head, buffer);

    // Process the data stored in the linked list
    for (Node *node = head; node; node = node->next) {
        printf("%s\n", node->data);
    }

    free(buffer);
    free(head);
}

int main() {
    char xml_data[] = "<abc>123</abc>";
    xml_parser(xml_data);

    return 0;
}