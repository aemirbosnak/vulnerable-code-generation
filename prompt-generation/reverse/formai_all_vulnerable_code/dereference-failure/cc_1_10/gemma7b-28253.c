//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char *data;
    struct JsonNode *next;
} JsonNode;

JsonNode *parseJson(char *jsonStr) {
    JsonNode *head = NULL;
    char *buffer = NULL;
    int bufferSize = 0;
    int i = 0;

    // Allocate memory for the buffer
    buffer = (char *)malloc(MAX_BUFFER_SIZE);

    // Parse the JSON string
    while (jsonStr[i] != '\0') {
        // Check if the buffer is full
        if (bufferSize == MAX_BUFFER_SIZE - 1) {
            // Double the buffer size
            bufferSize *= 2;
            buffer = (char *)realloc(buffer, bufferSize);
        }

        // Add the character to the buffer
        buffer[bufferSize++] = jsonStr[i];

        // Increment the index
        i++;
    }

    // Create a JSON node
    JsonNode *newNode = (JsonNode *)malloc(sizeof(JsonNode));
    newNode->data = buffer;
    newNode->next = head;

    // Update the head of the JSON node list
    head = newNode;

    return head;
}

int main() {
    char *jsonStr = "{ 'name': 'John Doe', 'age': 30 }";
    JsonNode *head = parseJson(jsonStr);

    // Print the JSON data
    printf("Name: %s\n", head->data);
    printf("Age: %d\n", head->next->data);

    return 0;
}