//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char *key;
    char *value;
    struct JsonNode *next;
} JsonNode;

int main()
{
    char json_string[] = "{ 'name': 'John Doe', 'age': 30, 'interests': [ 'reading', 'writing', 'music' ] }";
    int json_string_length = sizeof(json_string) - 1;

    // Allocate memory for the JSON parser
    JsonNode *root = malloc(sizeof(JsonNode));
    root->key = NULL;
    root->value = NULL;
    root->next = NULL;

    // Parse the JSON string
    char *current_pointer = json_string;
    char *key_pointer = NULL;
    char *value_pointer = NULL;

    // Loop over the JSON string character by character
    for (int i = 0; i < json_string_length; i++)
    {
        // Check if the character is a key-value separator
        if (*current_pointer == ':')
        {
            // Allocate memory for the key
            key_pointer = malloc(MAX_BUFFER_SIZE);
            key_pointer = strcpy(key_pointer, current_pointer + 1);

            // Check if the character is a comma
            if (*(current_pointer - 1) == ',')
            {
                // Allocate memory for the value
                value_pointer = malloc(MAX_BUFFER_SIZE);
                value_pointer = strcpy(value_pointer, current_pointer + 2);

                // Create a new JSON node
                JsonNode *new_node = malloc(sizeof(JsonNode));
                new_node->key = key_pointer;
                new_node->value = value_pointer;
                new_node->next = NULL;

                // Add the new JSON node to the root
                if (root->key == NULL)
                {
                    root = new_node;
                }
                else
                {
                    root->next = new_node;
                    root = new_node;
                }
            }
        }
        current_pointer++;
    }

    // Print the JSON data
    printf("Name: %s\n", root->key);
    printf("Age: %d\n", atoi(root->value));
    printf("Interests: ");
    for (JsonNode *node = root->next; node; node = node->next)
    {
        printf("%s, ", node->key);
    }
    printf("\n");

    // Free the memory allocated for the JSON parser
    free(root);

    return 0;
}