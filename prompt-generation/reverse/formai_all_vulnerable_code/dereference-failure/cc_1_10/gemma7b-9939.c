//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSON_Node {
    char *key;
    char *value;
    struct JSON_Node *next;
} JSON_Node;

JSON_Node *parse_json(char *json_string) {
    JSON_Node *head = NULL;
    JSON_Node *current_node = NULL;
    char *buffer = malloc(MAX_BUFFER_SIZE);
    char *json_pointer = json_string;

    // Loop over the JSON string character by character
    while (*json_pointer) {
        // Check if the character is a key-value separator (:)
        if (*json_pointer == ':') {
            // Allocate a new node
            current_node = malloc(sizeof(JSON_Node));
            current_node->key = malloc(MAX_BUFFER_SIZE);
            current_node->value = malloc(MAX_BUFFER_SIZE);
            current_node->next = NULL;

            // Copy the key from the JSON string
            int i = 0;
            while (*json_pointer != ',') {
                buffer[i] = *json_pointer;
                i++;
                json_pointer++;
            }
            buffer[i] = '\0';
            current_node->key = buffer;

            // Copy the value from the JSON string
            i = 0;
            json_pointer++;
            while (*json_pointer != '}') {
                buffer[i] = *json_pointer;
                i++;
                json_pointer++;
            }
            buffer[i] = '\0';
            current_node->value = buffer;

            // Add the new node to the head of the JSON tree
            if (head == NULL) {
                head = current_node;
            } else {
                current_node->next = head;
                head = current_node;
            }
        }

        // Increment the pointer to the next character in the JSON string
        json_pointer++;
    }

    return head;
}

int main() {
    char *json_string = "{ 'name': 'John Doe', 'age': 30 }";
    JSON_Node *head = parse_json(json_string);

    // Print the key-value pairs in the JSON object
    JSON_Node *current_node = head;
    while (current_node) {
        printf("Key: %s, Value: %s\n", current_node->key, current_node->value);
        current_node = current_node->next;
    }

    return 0;
}