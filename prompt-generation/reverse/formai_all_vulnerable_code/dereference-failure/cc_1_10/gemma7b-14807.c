//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: lively
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

    // Allocate memory for the JSON node
    JsonNode *newNode = malloc(sizeof(JsonNode));

    // Parse the JSON string character by character
    for (i = 0; jsonStr[i] != '\0'; i++) {
        // Handle quotes and commas
        if (jsonStr[i] == '"' || jsonStr[i] == ',') {
            // Allocate memory for the key and value
            newNode->key = malloc(MAX_BUFFER_SIZE);
            newNode->value = malloc(MAX_BUFFER_SIZE);

            // Copy the key and value from the JSON string
            int j = 0;
            for (j = i + 1; jsonStr[j] != '"' && jsonStr[j] != ','; j++) {
                newNode->key[j - i - 1] = jsonStr[j];
            }

            for (j = i + 1; jsonStr[j] != '"'; j++) {
                newNode->value[j - i - 1] = jsonStr[j];
            }

            // Add the node to the head of the JSON tree
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

    // Return the head of the JSON tree
    return head;
}

int main() {
    char *jsonStr = "{ 'name': 'John Doe', 'age': 30 }";
    JsonNode *head = parseJson(jsonStr);

    // Traverse the JSON tree
    JsonNode *currNode = head;
    while (currNode) {
        printf("Key: %s, Value: %s\n", currNode->key, currNode->value);
        currNode = currNode->next;
    }

    // Free the memory allocated for the JSON nodes
    free(head);

    return 0;
}