//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char type;
    union {
        int number;
        double decimal;
        char *string;
        struct JsonNode *object;
        struct JsonNode *array;
    } data;
    struct JsonNode *next;
} JsonNode;

JsonNode *parseJson(char *jsonStr) {
    JsonNode *head = NULL;
    JsonNode *tail = NULL;
    char *buffer = malloc(MAX_BUFFER_SIZE);
    strcpy(buffer, jsonStr);

    // Parse the JSON string into tokens
    char *token = strtok(buffer, ",");
    while (token) {
        JsonNode *newNode = malloc(sizeof(JsonNode));
        newNode->type = 'o';
        newNode->data.object = NULL;
        newNode->next = NULL;

        // Parse the token into a key-value pair
        char *key = strtok(token, ":");
        newNode->data.string = strdup(key);

        char *value = strtok(NULL, ":");
        newNode->data.string = strdup(value);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        token = strtok(NULL, ",");
    }

    free(buffer);

    return head;
}

int main() {
    char *jsonStr = "{ 'name': 'John Doe', 'age': 30, 'interests': ['music', 'reading'] }";
    JsonNode *head = parseJson(jsonStr);

    // Print the JSON data
    for (JsonNode *node = head; node; node = node->next) {
        switch (node->type) {
            case 'o':
                printf("Key: %s, Value: %s\n", node->data.string, node->data.string);
                break;
            case 'a':
                printf("Element: %s\n", node->data.string);
                break;
        }
    }

    return 0;
}