//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: beginner-friendly
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
    JsonNode *tail = NULL;
    int i = 0;
    int length = strlen(jsonString);

    // Allocate memory for the JSON node
    head = malloc(sizeof(JsonNode));
    tail = head;

    // Loop through the JSON string
    for (i = 0; i < length; i++) {
        // Check if the current character is a key-value separator or a colon
        if (jsonString[i] == ':' || jsonString[i] == ',') {
            // Create a new JSON node
            tail = malloc(sizeof(JsonNode));
            tail->key = malloc(MAX_BUFFER_SIZE);
            tail->value = malloc(MAX_BUFFER_SIZE);
            tail->next = NULL;

            // Copy the key and value from the JSON string
            memcpy(tail->key, jsonString + i - MAX_BUFFER_SIZE, MAX_BUFFER_SIZE);
            memcpy(tail->value, jsonString + i + 1, MAX_BUFFER_SIZE);

            // Update the tail of the JSON node
            if (tail->next == NULL) {
                tail = tail->next;
            }

            // Insert the new node into the JSON tree
            if (head == NULL) {
                head = tail;
            }
        }
    }

    // Free the memory allocated for the JSON nodes
    free(head);
}

int main() {
    char jsonString[] = "{ 'name': 'John Doe', 'age': 30 }";
    parseJson(jsonString);

    return 0;
}