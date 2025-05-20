//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data[MAX_BUFFER_SIZE];
    struct Node* next;
} Node;

Node* newNode(char* data) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void parseXML(char* xml) {
    Node* head = newNode(xml);
    Node* current = head;
    char* tag = NULL;
    char* attribute = NULL;
    int state = 0;

    for (int i = 0; xml[i] != '\0'; i++) {
        switch (state) {
            case 0:
                if (xml[i] == '<') {
                    state = 1;
                    tag = malloc(MAX_BUFFER_SIZE);
                }
                break;
            case 1:
                if (xml[i] == '>') {
                    state = 0;
                    tag[0] = '\0';
                    current->next = newNode(tag);
                } else {
                    tag = realloc(tag, MAX_BUFFER_SIZE * 2);
                    tag[0] = xml[i];
                }
                break;
            case 2:
                if (xml[i] == '"') {
                    attribute = malloc(MAX_BUFFER_SIZE);
                    state = 3;
                }
                break;
            case 3:
                if (xml[i] == '"') {
                    attribute[0] = '\0';
                    current->next->next = newNode(attribute);
                    state = 0;
                } else {
                    attribute = realloc(attribute, MAX_BUFFER_SIZE * 2);
                    attribute[0] = xml[i];
                }
                break;
        }
    }

    free(head);
}

int main() {
    parseXML("<foo bar='baz'>Hello, world!</foo>");
    return 0;
}