//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: Cyberpunk
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

JsonNode *parseJson(char *jsonString) {
    JsonNode *head = NULL;
    char *buffer = malloc(MAX_BUFFER_SIZE);
    strcpy(buffer, jsonString);

    // Eat the opening brace
    buffer = strchr(buffer, '{');
    buffer++;

    // Parse key-value pairs
    while ((buffer = strchr(buffer, '"')) != NULL) {
        char *key = strdup(buffer);
        buffer++;

        // Eat the colon
        buffer = strchr(buffer, ':');
        buffer++;

        // Parse value
        JsonNode *newNode = malloc(sizeof(JsonNode));
        newNode->key = key;
        newNode->next = head;

        switch (*buffer) {
            case 'n':
                newNode->data.number = atoi(buffer + 1);
                break;
            case 'd':
                newNode->data.decimal = atof(buffer + 1);
                break;
            case '"':
                newNode->data.string = strdup(buffer + 1);
                break;
            default:
                break;
        }

        head = newNode;
    }

    // Eat the closing brace
    buffer = strchr(buffer, '}');
    buffer++;

    return head;
}

int main() {
    char *jsonString = "{ 'name': 'John Doe', 'age': 30, 'occupation': 'Software Engineer' }";
    JsonNode *head = parseJson(jsonString);

    printf("Name: %s\n", head->key);
    printf("Age: %d\n", head->data.number);
    printf("Occupation: %s\n", head->data.string);

    return 0;
}