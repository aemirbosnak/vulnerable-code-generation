//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: complete
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
    int index = 0;
    int quote_count = 0;

    // Allocate memory for the first node
    head = malloc(sizeof(JsonNode));
    head->key = NULL;
    head->value = NULL;
    head->next = NULL;

    // Iterate over the JSON string
    for (int i = 0; i < strlen(jsonString); i++) {
        // Check if the current character is a quote
        if (jsonString[i] == '"') {
            quote_count++;
        }

        // If the quote count is even and the character is not a quote or comma,
        // it must be the key-value separator
        if (quote_count % 2 == 0 && jsonString[i] != '"' && jsonString[i] != ',') {
            // Allocate memory for the key and value
            head->key = malloc(MAX_BUFFER_SIZE);
            head->value = malloc(MAX_BUFFER_SIZE);

            // Copy the key and value from the JSON string
            int j = 0;
            for (int k = i + 1; jsonString[k] != '"' && jsonString[k] != ',' && jsonString[k] != '\0'; k++) {
                head->key[j] = jsonString[k];
                j++;
            }

            head->key[j] = '\0';

            j = 0;
            for (int k = i + 2; jsonString[k] != '"' && jsonString[k] != ',' && jsonString[k] != '\0'; k++) {
                head->value[j] = jsonString[k];
                j++;
            }

            head->value[j] = '\0';

            // Insert the node into the linked list
            head->next = malloc(sizeof(JsonNode));
            head = head->next;
        }
    }

    return head;
}

int main() {
    char *jsonString = "{ 'name': 'John Doe', 'age': 30 }";
    JsonNode *head = parseJson(jsonString);

    // Print the JSON data
    for (JsonNode *node = head; node; node = node->next) {
        printf("%s: %s\n", node->key, node->value);
    }

    return 0;
}