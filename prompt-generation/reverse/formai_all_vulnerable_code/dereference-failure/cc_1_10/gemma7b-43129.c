//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: romantic
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
    char *jsonStringPtr = jsonString;
    char *key = NULL;
    char *value = NULL;

    while (jsonStringPtr) {
        // Detect key-value pair
        if (*jsonStringPtr == '"') {
            key = jsonStringPtr + 1;
            // Allocate memory for key and value
            key = malloc(strlen(key) + 1);
            strcpy(key, key);

            // Find end of value
            value = strchr(key, ':');
            if (value) {
                *value++ = '\0';
            }

            // Allocate memory for value
            value = malloc(strlen(value) + 1);
            strcpy(value, value);

            // Create new JSON node
            JsonNode *newNode = malloc(sizeof(JsonNode));
            newNode->key = key;
            newNode->value = value;
            newNode->next = head;
            head = newNode;
        }

        // Move to next character
        jsonStringPtr++;
    }

    return head;
}

int main() {
    char jsonString[] = "{ 'name': 'John Doe', 'age': 30 }";
    JsonNode *head = parseJson(jsonString);

    // Print JSON data
    printf("Name: %s\n", head->key);
    printf("Value: %s\n", head->value);

    return 0;
}