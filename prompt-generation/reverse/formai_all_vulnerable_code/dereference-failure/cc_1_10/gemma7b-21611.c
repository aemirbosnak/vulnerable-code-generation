//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char *key;
    struct JsonNode *next;
    union {
        int number;
        double decimal;
        char *string;
    } data;
} JsonNode;

JsonNode *parseJson(char *jsonStr) {
    // Allocate memory for the JSON parser
    JsonNode *head = malloc(sizeof(JsonNode));
    head->key = NULL;
    head->next = NULL;
    head->data.string = NULL;

    // Parse the JSON string
    char *pJsonStr = jsonStr;
    while (*pJsonStr) {
        // Check if the current character is a key
        if (*pJsonStr >= 'a' && *pJsonStr <= 'z') {
            // Allocate memory for the key
            head->key = malloc(strlen(pJsonStr) + 1);
            strcpy(head->key, pJsonStr);

            // Move to the next character
            pJsonStr++;
        }
        // Check if the current character is a value
        else if (*pJsonStr >= '0' && *pJsonStr <= '9') {
            // Convert the value to an integer
            head->data.number = atoi(pJsonStr);

            // Move to the next character
            pJsonStr++;
        }
        // Check if the current character is a decimal
        else if (*pJsonStr >= '0' && *pJsonStr <= '9') {
            // Convert the value to a decimal
            head->data.decimal = atof(pJsonStr);

            // Move to the next character
            pJsonStr++;
        }
        // Check if the current character is a string
        else if (*pJsonStr == '"') {
            // Allocate memory for the string
            head->data.string = malloc(MAX_BUFFER_SIZE);

            // Copy the string from the JSON string
            int i = 0;
            while (*pJsonStr != '"') {
                head->data.string[i] = *pJsonStr;
                i++;
                pJsonStr++;
            }

            // Null terminate the string
            head->data.string[i] = '\0';

            // Move to the next character
            pJsonStr++;
        }
        // Move to the next character
        pJsonStr++;
    }

    // Return the JSON parser
    return head;
}

int main() {
    // Example JSON string
    char *jsonStr = "{\"name\":\"John Doe\", \"age\":30, \" hobbies\":[\"reading\", \"writing\", \"music\"]}";

    // Parse the JSON string
    JsonNode *head = parseJson(jsonStr);

    // Print the JSON data
    printf("Name: %s\n", head->key);
    printf("Age: %d\n", head->data.number);
    printf("Hobbies: ");
    for (JsonNode *node = head->next; node; node = node->next) {
        printf("%s, ", node->key);
    }
    printf("\n");

    // Free the JSON parser
    free(head);

    return 0;
}