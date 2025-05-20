//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char type;
    union {
        struct JsonNode *child;
        char *string_value;
        int number_value;
    } data;
} JsonNode;

void parseJson(char *json_string) {
    int i = 0;
    char buffer[MAX_BUFFER_SIZE];
    JsonNode *root = NULL;

    // Allocate memory for the root node
    root = (JsonNode *)malloc(sizeof(JsonNode));
    root->type = 'r';

    // Loop over the JSON string
    while (json_string[i] != '\0') {
        // Extract the key-value pair
        char *key = NULL;
        char *value = NULL;
        int key_length = 0;
        int value_length = 0;

        // Find the key-value pair
        for (int j = i; json_string[j] != ':' && json_string[j] != ','; j++) {
            key_length++;
        }

        // Allocate memory for the key and value
        key = (char *)malloc(key_length + 1);
        value = (char *)malloc(MAX_BUFFER_SIZE);

        // Copy the key and value
        memcpy(key, json_string, key_length);
        memcpy(value, json_string + key_length + 1, MAX_BUFFER_SIZE);

        // Create a child node
        JsonNode *child = (JsonNode *)malloc(sizeof(JsonNode));
        child->type = 'c';
        child->data.string_value = value;

        // Add the child node to the root node
        root->data.child = child;

        // Increment the index
        i += key_length + 2;
    }

    // Free the memory
    free(root);
}

int main() {
    char json_string[] = "{ 'name': 'John Doe', 'age': 30 }";
    parseJson(json_string);

    return 0;
}