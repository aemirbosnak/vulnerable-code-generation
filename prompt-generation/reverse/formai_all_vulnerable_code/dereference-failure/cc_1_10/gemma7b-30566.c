//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSON_Node
{
    char type;
    union
    {
        int number;
        double decimal;
        char* string;
        struct JSON_Node* object;
        struct JSON_Node* array;
    } data;
    struct JSON_Node* next;
} JSON_Node;

JSON_Node* JSON_Parser(char* json_string)
{
    JSON_Node* head = NULL;
    JSON_Node* tail = NULL;

    // Allocate memory for the JSON node
    JSON_Node* node = malloc(sizeof(JSON_Node));

    // Set the node type to 'o' for object
    node->type = 'o';

    // Set the node data to the JSON string
    node->data.string = strdup(json_string);

    // Link the node to the head if it is the first node
    if (head == NULL)
    {
        head = tail = node;
    }
    else
    {
        tail->next = node;
        tail = node;
    }

    return head;
}

int main()
{
    char* json_string = "{ 'name': 'John Doe', 'age': 30 }";

    JSON_Node* head = JSON_Parser(json_string);

    // Print the JSON data
    printf("Name: %s\n", head->data.string);
    printf("Age: %d\n", head->next->data.number);

    return 0;
}