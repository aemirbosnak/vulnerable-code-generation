//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char *key;
    char *value;
    struct JsonNode *next;
} JsonNode;

void parseJson(char *jsonString) {
    JsonNode *head = NULL;
    JsonNode *currentNode = NULL;
    char *buffer = malloc(MAX_BUFFER_SIZE);
    char *p = buffer;
    int i = 0;

    // Allocate memory for the first node
    head = malloc(sizeof(JsonNode));
    head->key = NULL;
    head->value = NULL;
    head->next = NULL;
    currentNode = head;

    // Loop over the JSON string
    for (; i < strlen(jsonString); i++) {
        // Handle quotes and commas
        if (jsonString[i] == '"' || jsonString[i] == ',') {
            *p = jsonString[i];
            p++;
        }

        // Handle key-value pairs
        if (jsonString[i] == ':') {
            *p = jsonString[i];
            p++;
            currentNode->key = malloc(strlen(p) + 1);
            strcpy(currentNode->key, p);
            currentNode->value = malloc(MAX_BUFFER_SIZE);
            p = currentNode->value;
        }

        // Handle closing bracket
        if (jsonString[i] == '}') {
            currentNode->next = NULL;
            break;
        }
    }

    // Free memory
    free(buffer);
    free(head);
}

int main() {
    char *jsonString = "{ 'name': 'John Doe', 'age': 30 }";
    parseJson(jsonString);

    return 0;
}