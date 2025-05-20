//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char type;
    union {
        int number;
        char *string;
        struct JsonNode *object;
        struct JsonNode **array;
    } data;
    struct JsonNode *next;
} JsonNode;

JsonNode *parseJson(char *jsonStr) {
    JsonNode *head = NULL;
    JsonNode *tail = NULL;

    // Allocate memory for the JSON node
    JsonNode *newNode = (JsonNode *)malloc(sizeof(JsonNode));
    newNode->type = 'o';
    newNode->data.object = NULL;
    newNode->next = NULL;

    tail = newNode;
    head = newNode;

    // Parse the JSON string
    char *p = jsonStr;
    while (*p) {
        // Check for object start
        if (*p == '{') {
            // Allocate memory for an object node
            newNode = (JsonNode *)malloc(sizeof(JsonNode));
            newNode->type = 'o';
            newNode->data.object = NULL;
            newNode->next = NULL;

            tail->next = newNode;
            tail = newNode;
        }

        // Check for array start
        else if (*p == '[') {
            // Allocate memory for an array node
            newNode = (JsonNode *)malloc(sizeof(JsonNode));
            newNode->type = 'a';
            newNode->data.array = NULL;
            newNode->next = NULL;

            tail->next = newNode;
            tail = newNode;
        }

        // Check for string
        else if (*p >= 'a' && *p <= 'z') {
            // Allocate memory for a string node
            newNode = (JsonNode *)malloc(sizeof(JsonNode));
            newNode->type = 's';
            newNode->data.string = malloc(MAX_BUFFER_SIZE);

            char *q = newNode->data.string;
            while (*p && *p != '"') {
                *q++ = *p;
                p++;
            }
            *q = '\0';

            tail->next = newNode;
            tail = newNode;
        }

        // Check for number
        else if (*p >= '0' && *p <= '9') {
            // Allocate memory for a number node
            newNode = (JsonNode *)malloc(sizeof(JsonNode));
            newNode->type = 'n';
            newNode->data.number = atoi(p);

            tail->next = newNode;
            tail = newNode;
        }

        p++;
    }

    return head;
}

int main() {
    char jsonStr[] = "{ 'name': 'John Doe', 'age': 30, 'interests': ['music', 'reading', 'coding'] }";
    JsonNode *head = parseJson(jsonStr);

    // Print the JSON data
    for (JsonNode *node = head; node; node = node->next) {
        switch (node->type) {
            case 'o':
                printf("Object:\n");
                break;
            case 'a':
                printf("Array:\n");
                break;
            case 's':
                printf("String: %s\n", node->data.string);
                break;
            case 'n':
                printf("Number: %d\n", node->data.number);
                break;
        }
    }

    return 0;
}