//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

Node *newNode(char *data) {
    Node *node = malloc(sizeof(Node));
    node->data = strdup(data);
    node->next = NULL;
    return node;
}

void parseXML(char *xml) {
    Node *head = NULL;
    char *buffer = malloc(MAX_BUFFER_SIZE);
    char *ptr = buffer;
    int index = 0;
    int state = 0;

    for (ptr = xml; *ptr; ptr++) {
        switch (state) {
            case 0:
                if (*ptr == '<') {
                    state = 1;
                    ptr++;
                } else {
                    head = newNode(ptr);
                    index = 0;
                }
                break;
            case 1:
                if (*ptr == '>') {
                    state = 0;
                    head = newNode(buffer);
                    index = 0;
                } else {
                    buffer[index++] = *ptr;
                }
                break;
            default:
                break;
        }
    }

    free(buffer);
}

int main() {
    char xml[] = "<foo><bar>baz</bar></foo>";
    parseXML(xml);
    return 0;
}