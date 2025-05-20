//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char *key;
    char *value;
    struct JsonNode *next;
} JsonNode;

void parseJson(char *jsonString) {
    JsonNode *head = NULL;
    JsonNode *tail = NULL;

    // Allocate memory for the JSON node
    JsonNode *newNode = (JsonNode *)malloc(sizeof(JsonNode));
    newNode->key = NULL;
    newNode->value = NULL;
    newNode->next = NULL;

    // Parse the JSON string
    char *p = jsonString;
    while (*p) {
        // Key-value pair
        if (*p == '"') {
            newNode->key = malloc(MAX_BUFFER_SIZE);
            newNode->key = strcpy(newNode->key, p + 1);

            // Move to the colon
            p += 2;
            while (*p != ':') {
                p++;
            }

            // Value
            newNode->value = malloc(MAX_BUFFER_SIZE);
            newNode->value = strcpy(newNode->value, p + 1);

            // Add the node to the linked list
            if (head == NULL) {
                head = tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        // Move to the next character
        p++;
    }

    // Print the JSON data
    tail = head;
    while (tail) {
        printf("%s: %s\n", tail->key, tail->value);
        tail = tail->next;
    }
}

int main() {
    char jsonString[] = "{ 'name': 'John Doe', 'age': 30 }";
    parseJson(jsonString);

    return 0;
}