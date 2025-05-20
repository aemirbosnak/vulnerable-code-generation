//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: innovative
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
    JsonNode *tail = NULL;

    // Allocate memory for the JSON node
    JsonNode *newNode = malloc(sizeof(JsonNode));
    newNode->key = NULL;
    newNode->value = NULL;
    newNode->next = NULL;

    // Parse the JSON string
    char *p = jsonString;
    while (*p) {
        // Check if the current character is a key-value separator
        if (*p == ':') {
            // Allocate memory for the key
            newNode->key = malloc(MAX_BUFFER_SIZE);
            newNode->key = strcpy(newNode->key, p + 1);

            // Move to the value
            p += 2;
        }
        // Check if the current character is a closing brace
        else if (*p == '}') {
            // Null terminate the key and value
            newNode->value = malloc(MAX_BUFFER_SIZE);
            newNode->value = strcpy(newNode->value, p);
            newNode->value[0] = '\0';

            // Insert the node into the list
            if (head == NULL) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            // Allocate memory for the next node
            newNode = malloc(sizeof(JsonNode));
            newNode->key = NULL;
            newNode->value = NULL;
            newNode->next = NULL;
        }
        p++;
    }

    // Return the head of the JSON node list
    return head;
}

int main() {
    char *jsonString = "{ 'name': 'John Doe', 'age': 30 }";
    JsonNode *head = parseJson(jsonString);

    // Traverse the JSON nodes
    for (JsonNode *node = head; node; node = node->next) {
        printf("Key: %s, Value: %s\n", node->key, node->value);
    }

    return 0;
}