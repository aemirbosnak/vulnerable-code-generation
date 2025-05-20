//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data[MAX_BUFFER_SIZE];
    struct Node* next;
} Node;

Node* newNode(char* data) {
    Node* node = malloc(sizeof(Node));
    strcpy(node->data, data);
    node->next = NULL;
    return node;
}

void parseJson(Node* head) {
    char** keys = NULL;
    int numKeys = 0;
    char* currentKey = NULL;
    char* value = NULL;
    Node* currentNode = head;

    while (currentNode) {
        if (currentNode->data[0] == '{') {
            // Start of object
            keys = realloc(keys, (numKeys + 1) * sizeof(char*));
            keys[numKeys++] = currentKey;
            currentKey = NULL;
        } else if (currentNode->data[0] == '}') {
            // End of object
            free(currentKey);
        } else if (currentNode->data[0] == '"') {
            // Key
            if (!currentKey) {
                currentKey = malloc(MAX_BUFFER_SIZE);
            }
            strcpy(currentKey, currentNode->data);
        } else if (currentNode->data[0] == ':') {
            // Value
            value = malloc(MAX_BUFFER_SIZE);
            strcpy(value, currentNode->data);
            currentKey = NULL;
        } else if (currentNode->data[0] == ',') {
            // Comma between keys
            free(currentKey);
            currentKey = NULL;
        }

        currentNode = currentNode->next;
    }

    free(keys);
}

int main() {
    char* jsonStr = "{ 'name': 'John Doe', 'age': 30 }";
    Node* head = newNode(jsonStr);
    parseJson(head);

    return 0;
}