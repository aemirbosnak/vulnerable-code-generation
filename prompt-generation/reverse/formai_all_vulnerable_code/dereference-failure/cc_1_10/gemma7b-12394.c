//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode
{
    char *key;
    struct JsonNode *next;
    union
    {
        int integerValue;
        double doubleValue;
        char *stringValue;
    } data;
} JsonNode;

void parseJson(char *jsonStr)
{
    // Allocate memory for the JSON parser
    JsonNode *rootNode = malloc(sizeof(JsonNode));
    rootNode->key = NULL;
    rootNode->next = NULL;
    rootNode->data.stringValue = strdup(jsonStr);

    // Traverse the JSON string
    char *ptr = jsonStr;
    while (ptr)
    {
        // Find the key-value pair
        char *key = strchr(ptr, ':');
        if (key)
        {
            // Allocate memory for the key
            char *keyStr = malloc(strlen(key) + 1);
            memcpy(keyStr, key, strlen(key) + 1);

            // Create a new JSON node
            JsonNode *newNode = malloc(sizeof(JsonNode));
            newNode->key = keyStr;
            newNode->next = NULL;

            // Insert the new node into the JSON tree
            if (rootNode->next)
            {
                rootNode->next->next = newNode;
            }
            else
            {
                rootNode->next = newNode;
            }

            // Move the pointer to the value
            ptr = key + 1;
        }
        else
        {
            // End of the JSON string
            break;
        }
    }

    // Print the JSON data
    for (JsonNode *node = rootNode; node; node = node->next)
    {
        printf("%s: %s\n", node->key, node->data.stringValue);
    }

    // Free the memory allocated for the JSON parser
    free(rootNode);
}

int main()
{
    char *jsonStr = "{ 'name': 'John Doe', 'age': 30, 'interests': ['music', 'reading', 'coding'] }";
    parseJson(jsonStr);

    return 0;
}