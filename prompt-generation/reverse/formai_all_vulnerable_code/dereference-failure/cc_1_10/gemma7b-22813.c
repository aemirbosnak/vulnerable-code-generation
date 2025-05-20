//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSON_Node {
    char type;
    union {
        int number;
        double decimal;
        char *string;
        struct JSON_Node *object;
        struct JSON_Node **array;
    } data;
    struct JSON_Node *next;
} JSON_Node;

JSON_Node *JSON_Parse(char *json_string)
{
    JSON_Node *head = NULL;
    JSON_Node *tail = NULL;
    char *buffer = NULL;
    int buffer_size = 0;
    int i = 0;
    char current_type = '\0';

    // Allocate memory for the buffer
    buffer = malloc(MAX_BUFFER_SIZE);

    // Parse the JSON string
    while (json_string[i] != '\0')
    {
        // Check if the buffer is full
        if (buffer_size == MAX_BUFFER_SIZE - 1)
        {
            // Reallocate the buffer
            buffer = realloc(buffer, MAX_BUFFER_SIZE * 2);
            buffer_size *= 2;
        }

        // Add the character to the buffer
        buffer[buffer_size++] = json_string[i];

        // Check if the character is a comma or a closing brace
        if (json_string[i] == ',' || json_string[i] == '}')
        {
            // Create a new JSON node
            JSON_Node *node = malloc(sizeof(JSON_Node));
            node->type = current_type;
            node->data.string = strdup(buffer);

            // If the head is NULL, make it the head of the JSON tree
            if (head == NULL)
            {
                head = node;
                tail = node;
            }
            // Otherwise, add the node to the tail of the JSON tree
            else
            {
                tail->next = node;
                tail = node;
            }

            // Reset the buffer size and current type
            buffer_size = 0;
            current_type = '\0';
        }
        // Increment the index
        i++;
    }

    // Free the memory allocated for the buffer
    free(buffer);

    // Return the head of the JSON tree
    return head;
}

int main()
{
    char *json_string = "{ 'name': 'John Doe', 'age': 30, 'interests': ['music', 'reading', 'coding'] }";
    JSON_Node *head = JSON_Parse(json_string);

    // Print the JSON data
    printf("Name: %s\n", head->data.string);
    printf("Age: %d\n", head->data.number);
    printf("Interests: ");
    for (JSON_Node *node = head->data.array; node; node = node->next)
    {
        printf("%s, ", node->data.string);
    }
    printf("\n");

    // Free the JSON data
    free(head);

    return 0;
}