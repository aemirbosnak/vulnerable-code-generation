//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSONNode {
    char type;
    union {
        int number;
        double decimal;
        char* string;
        struct JSONNode* object;
        struct JSONNode* array;
    } data;
    struct JSONNode* next;
} JSONNode;

JSONNode* parseJSON(char* json_string) {
    JSONNode* head = NULL;
    JSONNode* tail = NULL;
    char* buffer = NULL;
    int buffer_size = 0;
    int i = 0;

    // Allocate memory for the buffer
    buffer = (char*)malloc(MAX_BUFFER_SIZE);

    // Copy the JSON string into the buffer
    strcpy(buffer, json_string);

    // Loop over the JSON string
    while (buffer[i] != '\0') {
        // Check if the current character is a quote or a curly brace
        if (buffer[i] == '"' || buffer[i] == '{' || buffer[i] == '}') {
            // Create a new JSON node
            JSONNode* new_node = (JSONNode*)malloc(sizeof(JSONNode));

            // Set the node's type
            new_node->type = buffer[i];

            // Set the node's data
            switch (buffer[i]) {
                case '"':
                    new_node->data.string = strdup(buffer + i + 1);
                    break;
                case '{' :
                    new_node->data.object = parseJSON(buffer + i + 1);
                    break;
                case '[':
                    new_node->data.array = parseJSON(buffer + i + 1);
                    break;
                default:
                    new_node->data.number = atoi(buffer + i);
                    break;
            }

            // Add the new node to the end of the list
            if (tail) {
                tail->next = new_node;
            } else {
                head = new_node;
            }

            tail = new_node;
        }

        i++;
    }

    // Free the memory allocated for the buffer
    free(buffer);

    // Return the head of the JSON node list
    return head;
}

int main() {
    char* json_string = "{ 'name': 'John Doe', 'age': 30, 'interests': ['music', 'reading', 'coding'] }";
    JSONNode* head = parseJSON(json_string);

    // Print the JSON data
    printf("Name: %s\n", head->data.object->data.string);
    printf("Age: %d\n", head->data.object->data.number);
    printf("Interests: ");
    for (JSONNode* node = head->data.object->data.array; node; node = node->next) {
        printf("%s, ", node->data.string);
    }

    return 0;
}