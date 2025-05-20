//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: expert-level
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
    JsonNode *tail = NULL;
    char *buffer = malloc(MAX_BUFFER_SIZE);
    char *ptr = buffer;
    int idx = 0;

    // Allocate memory for the first node
    head = malloc(sizeof(JsonNode));
    tail = head;
    tail->key = NULL;
    tail->value = NULL;
    tail->next = NULL;

    // Iterate over the JSON string
    while (jsonStr[idx] != '\0') {
        // Key-value pair
        if (jsonStr[idx] == '"') {
            // Allocate memory for the key
            tail->key = malloc(MAX_BUFFER_SIZE);
            tail->key = strcpy(tail->key, jsonStr + idx + 1);

            // Move to the value
            idx += strlen(tail->key) + 2;
        }

        // Value
        if (jsonStr[idx] == '{' || jsonStr[idx] == '[') {
            // Allocate memory for the value
            tail->value = malloc(MAX_BUFFER_SIZE);
            tail->value = strcpy(tail->value, jsonStr + idx);

            // Move to the next node
            tail->next = malloc(sizeof(JsonNode));
            tail = tail->next;
            tail->key = NULL;
            tail->value = NULL;
            tail->next = NULL;
        }

        // Comma
        if (jsonStr[idx] == ',') {
            idx++;
        }

        // Closing bracket
        if (jsonStr[idx] == '}' || jsonStr[idx] == ']') {
            tail = head;
            break;
        }

        idx++;
    }

    free(buffer);
    return head;
}

int main() {
    char *jsonStr = "{ 'name': 'John Doe', 'age': 30 }";
    JsonNode *head = parseJson(jsonStr);

    // Print the JSON data
    while (head) {
        printf("%s: %s\n", head->key, head->value);
        head = head->next;
    }

    return 0;
}