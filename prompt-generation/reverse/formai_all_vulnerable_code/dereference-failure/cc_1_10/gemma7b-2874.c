//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSON_Node {
    char *key;
    char *value;
    struct JSON_Node *next;
} JSON_Node;

JSON_Node *parse_json(char *json_string) {
    JSON_Node *head = NULL;
    JSON_Node *tail = NULL;

    // Allocate memory for the JSON node
    JSON_Node *new_node = malloc(sizeof(JSON_Node));

    // Parse the JSON string
    char *key = NULL;
    char *value = NULL;
    int i = 0;
    for (; i < strlen(json_string); i++) {
        // Check if the current character is a key-value separator
        if (json_string[i] == ':') {
            // Allocate memory for the key and value
            key = malloc(MAX_BUFFER_SIZE);
            value = malloc(MAX_BUFFER_SIZE);

            // Copy the key and value from the JSON string
            int j = 0;
            for (; j < MAX_BUFFER_SIZE && json_string[i + 1] != ','; j++) {
                key[j] = json_string[i + 1];
            }
            key[j] = '\0';

            for (j = 0; json_string[i + 2] != '\0'; j++) {
                value[j] = json_string[i + 2];
            }
            value[j] = '\0';

            // Add the key-value pair to the JSON node
            new_node->key = key;
            new_node->value = value;

            // If the head of the JSON node is NULL, make it the head
            if (head == NULL) {
                head = new_node;
            }

            // If the tail of the JSON node is not NULL, make it the tail
            if (tail) {
                tail->next = new_node;
            }

            tail = new_node;
        }
    }

    return head;
}

int main() {
    char *json_string = "{ 'name': 'John Doe', 'age': 30, 'interests': ['music', 'reading', 'coding'] }";

    JSON_Node *head = parse_json(json_string);

    // Print the JSON data
    while (head) {
        printf("Key: %s, Value: %s\n", head->key, head->value);
        head = head->next;
    }

    return 0;
}