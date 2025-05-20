//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a JSON data structure
typedef struct json_node {
    char *key;
    char *value;
    struct json_node *next;
} json_node;

// Function to parse a JSON string
json_node *parse_json(char *json_str) {
    // Allocate memory for the JSON node
    json_node *root = malloc(sizeof(json_node));

    // Initialize the JSON node
    root->key = NULL;
    root->value = NULL;
    root->next = NULL;

    // Iterate over the JSON string
    char *ptr = json_str;
    while (*ptr) {
        // Check if the current character is a key-value separator
        if (*ptr == ':') {
            // Allocate memory for the key
            root->key = malloc(sizeof(char) * 256);

            // Copy the key from the JSON string
            int i = 0;
            while (*ptr != ':') {
                root->key[i] = *ptr;
                ptr++;
                i++;
            }
            root->key[i] = '\0';

            // Allocate memory for the value
            root->value = malloc(sizeof(char) * 256);

            // Copy the value from the JSON string
            i = 0;
            ptr++;
            while (*ptr) {
                root->value[i] = *ptr;
                ptr++;
                i++;
            }
            root->value[i] = '\0';

            // Create a new JSON node
            json_node *new_node = malloc(sizeof(json_node));

            // Initialize the new JSON node
            new_node->key = NULL;
            new_node->value = NULL;
            new_node->next = NULL;

            // Add the new JSON node to the end of the linked list
            if (root->next) {
                root->next->next = new_node;
            } else {
                root->next = new_node;
            }
        }
    }

    // Return the root node of the JSON tree
    return root;
}

int main() {
    // Parse a JSON string
    char *json_str = "{ 'name': 'John Doe', 'age': 30 }";
    json_node *root = parse_json(json_str);

    // Print the JSON data
    printf("Name: %s\n", root->key);
    printf("Value: %s\n", root->value);

    // Free the JSON data
    free(root);

    return 0;
}