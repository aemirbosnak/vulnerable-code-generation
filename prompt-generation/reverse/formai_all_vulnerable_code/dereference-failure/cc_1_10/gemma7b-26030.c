//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char *key;
    char *value;
    struct JsonNode *next;
} JsonNode;

void JsonNode_create(JsonNode **node) {
    *node = malloc(sizeof(JsonNode));
    (*node)->key = NULL;
    (*node)->value = NULL;
    (*node)->next = NULL;
}

void JsonNode_addKey(JsonNode *node, char *key) {
    node->key = strdup(key);
}

void JsonNode_addValue(JsonNode *node, char *value) {
    node->value = strdup(value);
}

void JsonNode_insertAfter(JsonNode **node, JsonNode *newNode) {
    if (*node) {
        ((*node)->next = newNode);
        *node = newNode;
    } else {
        *node = newNode;
    }
}

void jsonParser(char *jsonString) {
    JsonNode *head = NULL;
    JsonNode *tail = NULL;

    // Allocate memory for the JSON parser
    JsonNode_create(&head);
    tail = head;

    // Parse the JSON string
    char *token = strtok(jsonString, ":");
    while (token) {
        // Extract the key-value pair
        char *key = strtok(token, ",");
        char *value = strtok(NULL, ",");

        // Add the key-value pair to the JSON node
        JsonNode_addKey(tail, key);
        JsonNode_addValue(tail, value);

        // Insert a new node if necessary
        if (tail->next) {
            JsonNode_insertAfter(&tail, tail->next);
        }

        // Get the next token
        token = strtok(NULL, ":");
    }

    // Print the JSON data
    printf("JSON data:\n");
    for (JsonNode *node = head; node; node = node->next) {
        printf("%s: %s\n", node->key, node->value);
    }
}

int main() {
    char jsonString[] = "{ 'name': 'John Doe', 'age': 30, 'interests': [ 'music', 'reading', 'coding' ] }";

    jsonParser(jsonString);

    return 0;
}