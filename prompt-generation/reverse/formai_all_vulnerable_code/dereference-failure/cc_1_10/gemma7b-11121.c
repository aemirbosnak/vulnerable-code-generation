//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 256

typedef struct Node {
    char* data;
    struct Node* next;
} Node;

void xml_parser(char* xml_data) {
    Node* head = NULL;
    char* buffer = malloc(MAX_BUFFER_SIZE);
    char* current = xml_data;
    int state = 0;

    while (*current) {
        switch (state) {
            case 0:
                if (*current == '<') {
                    state = 1;
                    buffer = current;
                } else {
                    buffer = NULL;
                }
                break;
            case 1:
                if (*current == '>') {
                    state = 0;
                    Node* node = malloc(sizeof(Node));
                    node->data = strdup(buffer);
                    node->next = head;
                    head = node;
                } else {
                    buffer = current;
                }
                break;
            default:
                break;
        }

        current++;
    }

    free(buffer);
    free(head);
}

int main() {
    xml_parser("<foo><bar>baz</bar></foo>");

    return 0;
}