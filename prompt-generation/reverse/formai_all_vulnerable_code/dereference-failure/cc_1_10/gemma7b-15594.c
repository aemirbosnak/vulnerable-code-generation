//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSON_Node {
    char type;
    union {
        int integer_value;
        double double_value;
        char *string_value;
        struct JSON_Node *array_value;
        struct JSON_Node *object_value;
    } data;
    struct JSON_Node *next;
} JSON_Node;

JSON_Node *parse_json(char *json_string) {
    JSON_Node *head = NULL;
    JSON_Node *current = NULL;
    char *buffer = malloc(MAX_BUFFER_SIZE);
    int i = 0;

    // Copy the JSON string into the buffer
    strcpy(buffer, json_string);

    // Iterate over the JSON string
    for (i = 0; buffer[i] != '\0'; i++) {
        // Check if the current character is the beginning of a new object or array
        if (buffer[i] == '{' || buffer[i] == '[') {
            // Create a new JSON node
            current = malloc(sizeof(JSON_Node));
            current->type = buffer[i];
            current->next = NULL;

            // If the head of the list is NULL, make it the head
            if (head == NULL) {
                head = current;
            } else {
                // Otherwise, add the node to the end
                current->next = head;
                head = current;
            }
        }

        // Check if the current character is a colon
        if (buffer[i] == ':') {
            // Move to the next character and store the key-value pair
            i++;
            current->data.string_value = malloc(MAX_BUFFER_SIZE);
            strcpy(current->data.string_value, buffer + i);
            i++;
        }

        // Check if the current character is a comma or closing brace
        if (buffer[i] == ',' || buffer[i] == '}') {
            // Move to the next character
            i++;
        }
    }

    // Return the head of the JSON node list
    return head;
}

int main() {
    char *json_string = "{ 'name': 'John Doe', 'age': 30 }";
    JSON_Node *head = parse_json(json_string);

    // Print the JSON data
    for (JSON_Node *node = head; node; node = node->next) {
        switch (node->type) {
            case 'o':
                printf("Object:\n");
                break;
            case 'a':
                printf("Array:\n");
                break;
            case '"':
                printf("String: %s\n", node->data.string_value);
                break;
            case 'i':
                printf("Integer: %d\n", node->data.integer_value);
                break;
            case 'd':
                printf("Double: %f\n", node->data.double_value);
                break;
        }
    }

    return 0;
}