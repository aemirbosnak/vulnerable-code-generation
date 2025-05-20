//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char type;
    union {
        int number;
        double decimal;
        char *string;
        struct JsonNode *object;
        struct JsonNode *array;
    } value;
    struct JsonNode *next;
} JsonNode;

void parseJson(char *jsonStr) {
    JsonNode *head = NULL;
    JsonNode *currentNode = NULL;

    // Allocate memory for the first node
    head = (JsonNode *)malloc(sizeof(JsonNode));
    head->type = 'o';
    head->value.object = NULL;
    head->next = NULL;

    currentNode = head;

    // Parse the JSON string
    char *p = jsonStr;
    while (*p) {
        // Handle quotes
        if (*p == '"') {
            p++;
            currentNode->type = 's';
            currentNode->value.string = malloc(MAX_BUFFER_SIZE);
            char *q = currentNode->value.string;
            while (*p != '"') {
                *q = *p;
                q++;
                p++;
            }
            *q = '\0';
        }
        // Handle numbers
        else if (*p >= '0' && *p <= '9') {
            currentNode->type = 'n';
            currentNode->value.number = atoi(p);
            p += 1;
        }
        // Handle objects and arrays
        else if (*p == '{' || *p == '[') {
            JsonNode *newNode = malloc(sizeof(JsonNode));
            newNode->type = *p;
            newNode->value.object = NULL;
            newNode->next = NULL;

            if (currentNode->type == 'o') {
                currentNode->value.object = newNode;
            } else if (currentNode->type == 'a') {
                currentNode->value.array = newNode;
            }

            currentNode = newNode;
        }
        // Handle commas and colons
        else if (*p == ',' || *p == ':') {
            p++;
        }

        // Move to the next node
        if (*p == '}' || *p == ']') {
            currentNode = currentNode->next;
        }
    }

    // Free the memory allocated for the JSON node
    free(head);
}

int main() {
    char jsonStr[] = "{ 'name': 'John Doe', 'age': 30, 'interests': ['music', 'reading', 'coding'] }";

    parseJson(jsonStr);

    return 0;
}