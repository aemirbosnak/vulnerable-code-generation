//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

Node *newNode(char *data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = strdup(data);
    node->next = NULL;
    return node;
}

void parseXML(char *xml) {
    char *buffer = malloc(MAX_BUFFER_SIZE);
    int index = 0;
    Node *head = NULL;

    while (*xml) {
        switch (*xml) {
            case '<':
                buffer[index++] = *xml;
                while (*xml && *xml != '>') {
                    xml++;
                    buffer[index++] = *xml;
                }
                buffer[index++] = '\0';
                newNode(buffer);
                head = head ? head->next : head;
                break;
            default:
                xml++;
                break;
        }
    }

    free(buffer);
    free(head);
}

int main() {
    char *xml = "<foo><bar>baz</bar></foo>";
    parseXML(xml);

    return 0;
}