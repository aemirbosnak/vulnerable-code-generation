//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: multiplayer
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

    // Allocate memory for the first node
    head = malloc(sizeof(JsonNode));
    tail = head;

    // Parse the JSON string
    char *key = NULL;
    char *value = NULL;
    int i = 0;
    for (i = 0; jsonString[i] != '\0'; i++) {
        // Check if the current character is a key-value separator
        if (jsonString[i] == ':') {
            // Allocate memory for the key and value
            key = malloc(MAX_BUFFER_SIZE);
            value = malloc(MAX_BUFFER_SIZE);

            // Copy the key and value from the JSON string
            int j = 0;
            for (j = 0; jsonString[i - 1] != ':'; j++) {
                key[j] = jsonString[i - 1];
            }
            key[j] = '\0';

            for (j = 0; jsonString[i + 1] != '\0'; j++) {
                value[j] = jsonString[i + 1];
            }
            value[j] = '\0';

            // Add the node to the linked list
            tail->next = malloc(sizeof(JsonNode));
            tail = tail->next;
            tail->key = key;
            tail->value = value;
            tail->next = NULL;
        }
    }

    // Print the JSON data
    JsonNode *current = head;
    while (current) {
        printf("%s: %s\n", current->key, current->value);
        current = current->next;
    }
}

int main() {
    char jsonString[] = "{ 'name': 'John Doe', 'age': 30, 'interests': [ 'music', 'reading', 'coding' ] }";
    parseJson(jsonString);

    return 0;
}