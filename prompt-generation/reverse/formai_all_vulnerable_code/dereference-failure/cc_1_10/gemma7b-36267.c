//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 512

typedef struct JSONNode {
    char type;
    union {
        struct JSONNode* child;
        int number;
        char* string;
    } data;
    struct JSONNode* next;
} JSONNode;

JSONNode* parseJSON(char* jsonStr) {
    JSONNode* head = NULL;
    JSONNode* tail = NULL;

    // Allocate memory for the JSON node
    JSONNode* newNode = malloc(sizeof(JSONNode));
    newNode->type = 'o';

    // Extract the JSON data from the string
    char* dataStr = strchr(jsonStr, '{') + 1;
    char* endStr = strchr(dataStr, '}');

    // Create a child node for each key-value pair
    char* keyStr = dataStr;
    while (keyStr && keyStr < endStr) {
        newNode = malloc(sizeof(JSONNode));
        newNode->type = 'k';
        newNode->data.string = strdup(keyStr);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        keyStr = strchr(keyStr, ',') + 1;
    }

    // Return the head of the JSON node
    return head;
}

int main() {
    char* jsonStr = "{ 'name': 'John Doe', 'age': 30, 'interests': ['music', 'reading', 'coding'] }";
    JSONNode* head = parseJSON(jsonStr);

    // Print the JSON data
    for (JSONNode* node = head; node; node = node->next) {
        switch (node->type) {
            case 'o':
                printf("Object:\n");
                break;
            case 'k':
                printf("Key: %s, ", node->data.string);
                break;
            case 'n':
                printf("Number: %d, ", node->data.number);
                break;
            case 's':
                printf("String: %s, ", node->data.string);
                break;
        }
    }

    return 0;
}