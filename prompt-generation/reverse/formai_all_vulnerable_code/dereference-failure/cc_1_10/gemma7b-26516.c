//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char *key;
    char *value;
    struct JsonNode *next;
} JsonNode;

JsonNode *jsonStringParser(char *jsonString) {
    JsonNode *head = NULL;
    char *buffer = NULL;
    int bufferSize = 0;
    int i = 0;
    int quotes = 0;
    char currentKey[MAX_BUFFER_SIZE] = "";

    while (jsonString[i] != '\0') {
        if (bufferSize == 0) {
            bufferSize = MAX_BUFFER_SIZE;
            buffer = malloc(bufferSize);
        }

        if (jsonString[i] == '"') {
            quotes++;
            if (quotes % 2 == 0) {
                // End of key, store key in JsonNode
                JsonNode *newNode = malloc(sizeof(JsonNode));
                newNode->key = strdup(currentKey);
                newNode->value = NULL;
                newNode->next = head;
                head = newNode;

                // Reset currentKey and quotes
                memset(currentKey, '\0', MAX_BUFFER_SIZE);
                quotes = 0;
            } else {
                // Add character to currentKey
                strcat(currentKey, &jsonString[i]);
            }
        } else if (jsonString[i] == '{' || jsonString[i] == '}') {
            // Start or end of object, store key-value pairs
            JsonNode *newNode = malloc(sizeof(JsonNode));
            newNode->key = strdup("null");
            newNode->value = NULL;
            newNode->next = head;
            head = newNode;
        } else {
            // Add character to currentKey
            strcat(currentKey, &jsonString[i]);
        }

        i++;
    }

    return head;
}

int main() {
    char *jsonString = "{ \"name\": \"John Doe\", \"age\": 30 }";
    JsonNode *head = jsonStringParser(jsonString);

    // Print JSON data
    for (JsonNode *node = head; node; node = node->next) {
        printf("%s: %s\n", node->key, node->value);
    }

    return 0;
}