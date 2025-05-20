//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: scalable
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
        struct JsonNode *array;
        struct JsonNode *object;
    } data;
    struct JsonNode *next;
} JsonNode;

JsonNode *parseJson(char *jsonStr) {
    JsonNode *head = NULL;
    JsonNode *tail = NULL;

    // Allocate memory for the first node
    head = (JsonNode *)malloc(sizeof(JsonNode));
    tail = head;

    // Parse the JSON string
    char *ptr = jsonStr;
    while (*ptr) {
        // Check if the current character is a quote, curly brace, or square bracket
        if (*ptr == '"' || *ptr == '{' || *ptr == '[') {
            // Create a new node
            tail->next = (JsonNode *)malloc(sizeof(JsonNode));
            tail = tail->next;

            // Set the node type
            tail->type = *ptr;

            // Increment the pointer
            ptr++;

            // Parse the remaining JSON data
            switch (*ptr) {
                case '"':
                    tail->data.string = malloc(MAX_BUFFER_SIZE);
                    memcpy(tail->data.string, ptr, MAX_BUFFER_SIZE - 1);
                    ptr++;
                    break;
                case '{' :
                    tail->data.object = parseJson(ptr);
                    break;
                case '[' :
                    tail->data.array = parseJson(ptr);
                    break;
                default :
                    tail->data.number = atoi(ptr);
                    ptr++;
                    break;
            }
        } else if (*ptr == ',') {
            // Move to the next node
            tail = tail->next;
        } else if (*ptr == '}') {
            // End of the JSON object
            tail = tail->next;
        } else if (*ptr == ']') {
            // End of the JSON array
            tail = tail->next;
        }

        ptr++;
    }

    return head;
}

int main() {
    char jsonStr[] = "{ 'name': 'John Doe', 'age': 30 }";
    JsonNode *head = parseJson(jsonStr);

    // Print the JSON data
    printf("Name: %s\n", head->data.object->data.string);
    printf("Age: %d\n", head->data.object->data.number);

    return 0;
}