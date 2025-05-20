//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: real-life
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
    // Allocate memory for the JSON parser
    JsonNode *root = (JsonNode *)malloc(sizeof(JsonNode));
    root->key = NULL;
    root->value = NULL;
    root->next = NULL;

    // Parse the JSON string
    char *token = strtok(jsonString, ":");
    while (token) {
        // Extract the key-value pair
        char *key = strtok(token, ",");
        char *value = strtok(NULL, ",");

        // Create a new JSON node
        JsonNode *newNode = (JsonNode *)malloc(sizeof(JsonNode));
        newNode->key = strdup(key);
        newNode->value = strdup(value);
        newNode->next = NULL;

        // Add the new node to the root
        if (root->key) {
            newNode->next = root;
            root = newNode;
        } else {
            root = newNode;
        }
    }

    // Print the JSON data
    printf("JSON data:\n");
    for (JsonNode *node = root; node; node = node->next) {
        printf("%s: %s\n", node->key, node->value);
    }

    // Free the memory
    free(root);
}

int main() {
    char jsonString[] = "{ 'name': 'John Doe', 'age': 30, 'interests': ['music', 'reading', 'coding'] }";
    parseJson(jsonString);

    return 0;
}