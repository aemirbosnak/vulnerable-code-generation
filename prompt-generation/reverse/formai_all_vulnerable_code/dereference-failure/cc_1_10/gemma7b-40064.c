//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: Romeo and Juliet
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
    char *buffer = NULL;
    char *jsonStringPtr = jsonString;
    int bufferSize = 0;

    while (*jsonStringPtr) {
        // Allocate memory for the buffer if needed
        if (bufferSize == 0) {
            buffer = (char *)malloc(MAX_BUFFER_SIZE);
            bufferSize = MAX_BUFFER_SIZE;
        }

        // Read the next character from the JSON string
        char character = *jsonStringPtr++;

        // Insert the character into the buffer
        buffer[bufferSize++] = character;

        // If the character is a comma or a closing brace, parse the JSON node
        if (character == ',' || character == '}') {
            JsonNode *newNode = (JsonNode *)malloc(sizeof(JsonNode));

            // Set the key and data of the node
            newNode->key = buffer;
            newNode->next = head;

            switch (character) {
                case ',':
                    newNode->data.number = atoi(buffer);
                    break;
                case '}':
                    newNode->data.string = buffer;
                    break;
                default:
                    printf("Error parsing JSON string.\n");
                    return NULL;
            }

            head = newNode;
        }
    }

    return head;
}

int main() {
    char *jsonString = "{ 'name': 'Romeo', 'age': 16, 'interests': [ 'music', 'reading', 'football' ] }";

    JsonNode *head = parseJson(jsonString);

    // Print the JSON data
    printf("Name: %s\n", head->key);
    printf("Age: %d\n", head->data.number);
    printf("Interests: ");
    for (JsonNode *node = head->data.string; node; node = node->next) {
        printf("%s, ", node->key);
    }
    printf("\n");

    return 0;
}