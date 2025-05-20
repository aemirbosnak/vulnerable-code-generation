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

JsonNode *jsonStringParser(char *jsonString) {
    JsonNode *head = NULL;
    char *buffer = malloc(MAX_BUFFER_SIZE);
    char *p = buffer;
    char *start = NULL;
    char *end = NULL;

    // Allocate memory for the JSON node
    JsonNode *newNode = malloc(sizeof(JsonNode));
    newNode->key = NULL;
    newNode->value = NULL;
    newNode->next = NULL;

    // Parse the JSON string
    while (*jsonString) {
        switch (*jsonString) {
            case '"':
                start = jsonString;
                end = strchr(jsonString, '"');
                newNode->key = malloc(end - start + 1);
                memcpy(newNode->key, start, end - start);
                newNode->key[end - start] = '\0';
                break;
            case ':':
                start = end + 1;
                newNode->value = malloc(MAX_BUFFER_SIZE);
                end = strchr(start, ',') ? strchr(start, ',') : NULL;
                memcpy(newNode->value, start, end - start);
                newNode->value[end - start] = '\0';
                if (head) {
                    head->next = newNode;
                } else {
                    head = newNode;
                }
                break;
            case ',':
                break;
            default:
                break;
        }

        jsonString++;
    }

    free(buffer);
    return head;
}

int main() {
    char *jsonString = "{ 'name': 'John Doe', 'age': 30 }";
    JsonNode *head = jsonStringParser(jsonString);

    // Print the JSON data
    for (JsonNode *node = head; node; node = node->next) {
        printf("%s: %s\n", node->key, node->value);
    }

    return 0;
}