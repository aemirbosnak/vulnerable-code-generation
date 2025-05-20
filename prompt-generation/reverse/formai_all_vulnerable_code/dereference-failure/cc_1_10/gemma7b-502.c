//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSON_Node {
    char type;
    union {
        struct JSON_Node* array_node;
        struct JSON_Node* object_node;
        char* string_node;
        int number_node;
    } data;
    struct JSON_Node* next;
} JSON_Node;

JSON_Node* parse_json(char* json_string) {
    JSON_Node* head = NULL;
    JSON_Node* tail = NULL;

    // Allocate memory for the first node
    head = malloc(sizeof(JSON_Node));
    tail = head;

    // Parse the JSON string
    char* current_pointer = json_string;
    while (*current_pointer) {
        // Check if the current character is the beginning of an object or array
        if (*current_pointer == '{') {
            tail->type = 'o';
            tail->data.object_node = malloc(sizeof(JSON_Node));
            tail = tail->data.object_node;
        } else if (*current_pointer == '[') {
            tail->type = 'a';
            tail->data.array_node = malloc(sizeof(JSON_Node));
            tail = tail->data.array_node;
        } else if (*current_pointer == '"') {
            // Allocate memory for the string node
            tail->type = 's';
            tail->data.string_node = malloc(MAX_BUFFER_SIZE);
            char* string_pointer = tail->data.string_node;

            // Copy the string value
            while (*current_pointer != '"') {
                *string_pointer = *current_pointer;
                string_pointer++;
                current_pointer++;
            }

            *string_pointer = '\0';

            tail = tail->next;
        } else if (*current_pointer >= '0' && *current_pointer <= '9') {
            tail->type = 'n';
            tail->data.number_node = atoi(current_pointer);
            tail = tail->next;
        } else if (*current_pointer == ',') {
            tail = tail->next;
        }
    }

    // Return the head node
    return head;
}

int main() {
    char* json_string = "{ 'name': 'John Doe', 'age': 30, 'interests': ['music', 'reading'] }";

    JSON_Node* parsed_json = parse_json(json_string);

    // Print the parsed JSON data
    printf("Name: %s\n", parsed_json->data.object_node->data.string_node);
    printf("Age: %d\n", parsed_json->data.object_node->data.number_node);
    printf("Interests: ");
    for (JSON_Node* interest = parsed_json->data.object_node->data.array_node; interest; interest = interest->next) {
        printf("%s, ", interest->data.string_node);
    }

    return 0;
}