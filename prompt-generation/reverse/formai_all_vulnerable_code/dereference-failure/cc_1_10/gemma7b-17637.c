//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: protected
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
    JsonNode *head = malloc(sizeof(JsonNode));
    head->key = NULL;
    head->value = NULL;
    head->next = NULL;

    // Parse the JSON string
    char *p = jsonString;
    while (p) {
        // Check for key-value pair
        if (*p == '"') {
            // Allocate memory for the key
            head->key = malloc(MAX_BUFFER_SIZE);
            head->key = strcpy(head->key, p + 1);

            // Move to the value
            p += strlen(head->key) + 2;
        }

        // Check for string value
        if (*p == '"') {
            // Allocate memory for the value
            head->value = malloc(MAX_BUFFER_SIZE);
            head->value = strcpy(head->value, p + 1);

            // Move to the next node
            head->next = malloc(sizeof(JsonNode));
            head->next->key = NULL;
            head->next->value = NULL;
            head->next->next = NULL;

            // Move to the next key-value pair
            p += strlen(head->value) + 2;
        }
    }

    // Print the JSON data
    JsonNode *node = head;
    while (node) {
        printf("%s: %s\n", node->key, node->value);
        node = node->next;
    }

    // Free the memory
    free(head);
}

int main() {
    parseJson("{\"name\": \"John Doe\", \"age\": 30}");
    return 0;
}