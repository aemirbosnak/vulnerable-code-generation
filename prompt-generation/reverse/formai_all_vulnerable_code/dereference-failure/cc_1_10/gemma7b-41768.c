//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char *data;
    struct JsonNode *next;
    struct JsonNode *child;
} JsonNode;

JsonNode *parseJson(char *jsonStr) {
    JsonNode *head = NULL;
    JsonNode *currentNode = NULL;
    int i = 0;
    char buffer[MAX_BUFFER_SIZE];

    // Allocate memory for the root node
    if (head == NULL) {
        head = (JsonNode *)malloc(sizeof(JsonNode));
        currentNode = head;
    }

    // Loop over the JSON string
    while (jsonStr[i] != '\0') {
        // Check for quotes, braces, and commas
        if (jsonStr[i] == '"' || jsonStr[i] == '{' || jsonStr[i] == '}') {
            // Allocate memory for the child node
            JsonNode *child = (JsonNode *)malloc(sizeof(JsonNode));
            child->data = malloc(MAX_BUFFER_SIZE);

            // Copy the child's data
            memcpy(child->data, jsonStr + i, MAX_BUFFER_SIZE);

            // Insert the child node into the current node
            if (currentNode->child != NULL) {
                currentNode->next = child;
            } else {
                currentNode->child = child;
            }

            // Update the current node
            currentNode = child;
        }

        // Increment the index
        i++;
    }

    // Return the root node
    return head;
}

int main() {
    char *jsonStr = "{ 'name': 'John Doe', 'age': 30 }";
    JsonNode *head = parseJson(jsonStr);

    // Print the JSON data
    printf("Name: %s\n", head->child->child->data);
    printf("Age: %d\n", head->child->child->next->data - '0');

    return 0;
}