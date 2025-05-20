//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char *key;
    char *value;
    struct JsonNode *next;
} JsonNode;

JsonNode *parseJson(char *jsonStr) {
    JsonNode *head = NULL;
    char *buffer = malloc(MAX_BUFFER_SIZE);
    int i = 0;

    // Allocate memory for the key and value pointers
    buffer = malloc(MAX_BUFFER_SIZE);

    // Loop over the JSON string
    for (; jsonStr[i] != '\0'; i++) {
        // Check if the current character is a key-value separator
        if (jsonStr[i] == ':' || jsonStr[i] == ',') {
            // Create a new JSON node
            JsonNode *newNode = malloc(sizeof(JsonNode));
            newNode->key = malloc(MAX_BUFFER_SIZE);
            newNode->value = malloc(MAX_BUFFER_SIZE);

            // Copy the key and value from the JSON string
            memcpy(newNode->key, buffer, strlen(buffer));
            newNode->value = malloc(MAX_BUFFER_SIZE);
            memcpy(newNode->value, jsonStr + i + 1, strlen(jsonStr + i + 1));

            // Add the new node to the head of the JSON tree
            if (head == NULL) {
                head = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }

            // Free the memory allocated for the key and value pointers
            free(newNode->key);
            free(newNode->value);
            free(newNode);

            // Reset the buffer and continue looping over the JSON string
            buffer = malloc(MAX_BUFFER_SIZE);
            i--;
        } else {
            // Store the character in the buffer
            buffer[i] = jsonStr[i];
        }
    }

    // Free the memory allocated for the buffer
    free(buffer);

    // Return the head of the JSON tree
    return head;
}

int main() {
    char *jsonStr = "{ 'name': 'John Doe', 'age': 30 }";
    JsonNode *head = parseJson(jsonStr);

    // Print the JSON data
    printf("Name: %s\n", head->key);
    printf("Value: %s\n", head->value);

    // Free the memory allocated for the JSON node
    free(head);

    return 0;
}