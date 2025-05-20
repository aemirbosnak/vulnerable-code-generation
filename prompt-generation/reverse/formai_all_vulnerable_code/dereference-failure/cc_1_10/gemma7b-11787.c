//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode
{
    char *key;
    char **values;
    struct JsonNode *next;
} JsonNode;

JsonNode *parseJson(char *jsonStr)
{
    JsonNode *head = NULL;
    JsonNode *newNode = NULL;

    // Allocate memory for the JSON parser
    if ((newNode = malloc(sizeof(JsonNode))) == NULL)
    {
        return NULL;
    }

    // Parse the JSON string
    char *key = NULL;
    char **values = NULL;
    int i = 0;
    int flag = 0;
    for (key = strtok(jsonStr, ","); key; key = strtok(NULL, ","))
    {
        // Allocate memory for the key and values
        if ((newNode->key = malloc(strlen(key) + 1)) == NULL)
        {
            return NULL;
        }
        memcpy(newNode->key, key, strlen(key) + 1);

        values = malloc(MAX_BUFFER_SIZE);
        newNode->values = values;

        flag = 0;
        for (values[0] = strtok(key, ":"); values[0] != NULL; values[0] = strtok(NULL, ":"))
        {
            flag = 1;
            values[i++] = malloc(MAX_BUFFER_SIZE);
            memcpy(values[i - 1], strtok(NULL, ","), MAX_BUFFER_SIZE);
        }

        if (flag)
        {
            newNode->next = parseJson(values);
        }

        free(values);
    }

    return head;
}

int main()
{
    char *jsonStr = "{ 'name': 'John Doe', 'age': 30, 'interests': ['music', 'reading', 'coding'] }";
    JsonNode *head = parseJson(jsonStr);

    // Print the JSON data
    printf("Key: %s\n", head->key);
    printf("Values: ");
    for (int i = 0; head->values[i]; i++)
    {
        printf("%s, ", head->values[i]);
    }
    printf("\n");

    return 0;
}