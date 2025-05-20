//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char *key;
    struct JsonNode *next;
    union {
        int number;
        double decimal;
        char *string;
    } data;
} JsonNode;

void parseJson(char *jsonStr) {
    int i = 0;
    int length = strlen(jsonStr);
    JsonNode *head = NULL;
    JsonNode *tail = NULL;

    // Allocate memory for the JSON node.
    JsonNode *newNode = malloc(sizeof(JsonNode));
    newNode->key = NULL;
    newNode->next = NULL;
    newNode->data.number = 0;

    // Traverse the JSON string.
    for (i = 0; i < length; i++) {
        // Check if the current character is a key-value pair separator.
        if (jsonStr[i] == ':') {
            // Create a new JSON node.
            newNode = malloc(sizeof(JsonNode));
            newNode->key = malloc(MAX_BUFFER_SIZE);
            newNode->next = NULL;
            newNode->data.number = 0;

            // Copy the key from the JSON string.
            int j = 0;
            for (j = i + 1; jsonStr[j] != ':'; j++) {
                newNode->key[j - i - 1] = jsonStr[j];
            }

            // Insert the new JSON node into the linked list.
            if (head == NULL) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
    }

    // Free the memory allocated for the JSON nodes.
    free(newNode);
}

int main() {
    char jsonStr[] = "{ 'name': 'John Doe', 'age': 30 }";
    parseJson(jsonStr);

    return 0;
}