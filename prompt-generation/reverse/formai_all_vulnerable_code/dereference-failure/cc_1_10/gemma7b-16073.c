//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: enthusiastic
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
    int i = 0;

    // Allocate memory for the JSON node
    JsonNode *newNode = malloc(sizeof(JsonNode));
    newNode->key = NULL;
    newNode->value = NULL;
    newNode->next = NULL;

    // Loop over the JSON string
    for (i = 0; jsonString[i] != '\0'; i++) {
        // Check if the current character is a key-value separator
        if (jsonString[i] == ':') {
            // Extract the key from the string
            newNode->key = malloc(MAX_BUFFER_SIZE);
            int j = 0;
            for (j = i + 1; jsonString[j] != ',' && jsonString[j] != '}'; j++) {
                newNode->key[j - i - 1] = jsonString[j];
            }
            newNode->key[j - i - 1] = '\0';

            // Allocate memory for the value
            newNode->value = malloc(MAX_BUFFER_SIZE);
            j = 0;
            for (j = j + 1; jsonString[j] != ',' && jsonString[j] != '}'; j++) {
                newNode->value[j - i - 1] = jsonString[j];
            }
            newNode->value[j - i - 1] = '\0';

            // Add the node to the head
            if (head == NULL) {
                head = newNode;
            } else {
                newNode->next = head;
                head = newNode;
            }
        }
    }

    // Free the memory allocated for the buffer
    free(buffer);

    // Return the head of the JSON node
    return head;
}

int main() {
    char *jsonString = "{ 'name': 'John Doe', 'age': 30 }";
    JsonNode *head = parseJson(jsonString);

    // Print the key-value pairs
    for (JsonNode *node = head; node != NULL; node = node->next) {
        printf("%s: %s\n", node->key, node->value);
    }

    // Free the memory allocated for the JSON node
    free(head);

    return 0;
}