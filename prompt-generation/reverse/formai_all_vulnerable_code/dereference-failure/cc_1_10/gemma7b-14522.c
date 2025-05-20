//Gemma-7B DATASET v1.0 Category: Building a XML Parser ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024

typedef struct Node {
    char data[MAX_BUFFER];
    struct Node* next;
} Node;

Node* insertNode(Node* head, char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void parseXML(char* xmlData) {
    Node* head = NULL;

    // Simulate parsing logic
    for (int i = 0; i < strlen(xmlData); i++) {
        char currentChar = xmlData[i];

        if (currentChar == '<') {
            insertNode(head, xmlData + i);
        }
    }

    // Output parsed data
    for (Node* node = head; node; node = node->next) {
        printf("%s\n", node->data);
    }
}

int main() {
    char xmlData[] = "<foo><bar>Hello, world!</bar></foo>";

    parseXML(xmlData);

    return 0;
}