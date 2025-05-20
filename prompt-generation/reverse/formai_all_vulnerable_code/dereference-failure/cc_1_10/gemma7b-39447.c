//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSON_Node {
    char type;
    union {
        int number;
        char* string;
        struct JSON_Node* object;
        struct JSON_Node* array;
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
        // Check if the current character is a quote or a brace
        if (*current_pointer == '"' || *current_pointer == '{' || *current_pointer == '[') {
            // Allocate memory for a new node
            tail->next = malloc(sizeof(JSON_Node));
            tail = tail->next;
        }

        // Determine the type of the JSON value
        switch (*current_pointer) {
            case '"':
                tail->type = 's';
                tail->data.string = malloc(MAX_BUFFER_SIZE);
                current_pointer++;
                break;
            case '{' :
                tail->type = 'o';
                tail->data.object = parse_json(current_pointer + 1);
                break;
            case '[':
                tail->type = 'a';
                tail->data.array = parse_json(current_pointer + 1);
                break;
            default:
                tail->type = 'n';
                tail->data.number = atoi(current_pointer);
                current_pointer++;
                break;
        }
    }

    // Return the head of the JSON node
    return head;
}

int main() {
    char* json_string = "{ 'name': 'John Doe', 'age': 30, 'interests': ['music', 'reading', 'coding'] }";

    JSON_Node* head = parse_json(json_string);

    // Print the JSON data
    printf("Name: %s\n", head->data.object->data.string);
    printf("Age: %d\n", head->data.object->data.number);
    printf("Interests: ");
    for (JSON_Node* node = head->data.object->data.array; node; node = node->next) {
        printf("%s, ", node->data.string);
    }
    printf("\n");

    return 0;
}