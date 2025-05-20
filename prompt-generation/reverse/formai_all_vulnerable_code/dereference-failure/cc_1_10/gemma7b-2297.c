//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

void insertNode(Node **head, char *data) {
    Node *newNode = malloc(sizeof(Node));
    newNode->data = strdup(data);
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void parseXML(char *xml) {
    Node *head = NULL;
    char *buffer = malloc(MAX_BUFFER_SIZE);
    char *start = xml;
    char *end = xml;

    while (start && end) {
        char *tagStart = strstr(start, "<");
        char *tagEnd = strstr(start, ">");

        if (tagStart && tagEnd) {
            insertNode(&head, tagStart + 1);
            start = tagEnd + 1;
        } else {
            strcpy(buffer, start);
            insertNode(&head, buffer);
            start = end;
        }
    }

    printf("Parsed XML:\n");
    for (Node *node = head; node; node = node->next) {
        printf("%s\n", node->data);
    }

    free(buffer);
    free(head);
}

int main() {
    parseXML("<foo><bar>baz</bar></foo>");

    return 0;
}