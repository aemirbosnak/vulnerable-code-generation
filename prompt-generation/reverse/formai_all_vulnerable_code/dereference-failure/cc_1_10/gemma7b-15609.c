//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char *data;
    struct Node *next;
} Node;

void parseXML(char *xmlStr) {
    int i = 0;
    char buffer[MAX_BUFFER_SIZE];
    Node *head = NULL;

    while (xmlStr[i] != '\0') {
        int j = 0;
        char tag[MAX_BUFFER_SIZE] = "";

        // Extract tag
        while (xmlStr[i] != '<' && xmlStr[i] != '\0') {
            tag[j] = xmlStr[i];
            j++;
            i++;
        }

        // Allocate memory for node
        Node *newNode = malloc(sizeof(Node));
        newNode->data = malloc(MAX_BUFFER_SIZE);

        // Store data and tag in the node
        strcpy(newNode->data, tag);
        newNode->next = head;
        head = newNode;

        // Skip past the tag and any whitespace
        while (xmlStr[i] == '<' || xmlStr[i] == ' ' || xmlStr[i] == '\n') {
            i++;
        }
    }

    // Print the nodes
    Node *currNode = head;
    while (currNode) {
        printf("Tag: %s, Data: %s\n", currNode->data, currNode->data);
        currNode = currNode->next;
    }
}

int main() {
    char xmlStr[] = "<foo>bar</foo>";
    parseXML(xmlStr);

    return 0;
}