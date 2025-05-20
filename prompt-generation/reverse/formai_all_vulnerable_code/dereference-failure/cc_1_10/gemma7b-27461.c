//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char *key;
    char *value;
    struct JsonNode *next;
} JsonNode;

JsonNode *parseJson(char *jsonString) {
    JsonNode *head = NULL;
    char *buffer = malloc(MAX_BUFFER_SIZE);
    strcpy(buffer, jsonString);

    // Parse the JSON string into key-value pairs
    char *key = NULL;
    char *value = NULL;
    int i = 0;
    while (buffer[i] != '\0') {
        // Find the key-value pair
        key = strchr(buffer, '"') + 1;
        value = strchr(key, ':') + 1;

        // Create a new JSON node
        JsonNode *newNode = malloc(sizeof(JsonNode));
        newNode->key = strdup(key);
        newNode->value = strdup(value);
        newNode->next = NULL;

        // Add the node to the head
        if (head == NULL) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }

        // Skip the colon and quotes
        i += 3;
    }

    // Free the buffer
    free(buffer);

    return head;
}

int main() {
    char *jsonString = "{ 'name': 'John Doe', 'age': 30 }";
    JsonNode *head = parseJson(jsonString);

    // Print the key-value pairs
    for (JsonNode *node = head; node; node = node->next) {
        printf("%s: %s\n", node->key, node->value);
    }

    // Free the JSON node
    free(head);

    return 0;
}