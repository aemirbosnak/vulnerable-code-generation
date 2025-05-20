//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSONNode {
    char *key;
    char *value;
    struct JSONNode *next;
} JSONNode;

JSONNode *parseJSON(char *jsonString) {
    JSONNode *head = NULL;
    JSONNode *tail = NULL;

    // 1. Allocate memory for the JSONNode structure
    JSONNode *newNode = (JSONNode *)malloc(sizeof(JSONNode));

    // 2. Copy the key and value from the JSON string
    newNode->key = strdup(jsonString);
    newNode->value = NULL;

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    // 3. Loop over the remaining JSON string to parse nested objects and arrays
    int i = 0;
    for (i = 0; jsonString[i] != '\0'; i++) {
        if (jsonString[i] == '{') {
            // Parse nested object
            newNode = parseJSON(&jsonString[i + 1]);
            tail->next = newNode;
            tail = newNode;
        } else if (jsonString[i] == '[') {
            // Parse nested array
            newNode = parseJSON(&jsonString[i + 1]);
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

int main() {
    char jsonString[] = "{ 'name': 'John Doe', 'age': 30, 'interests': [ 'music', 'reading', 'coding' ] }";

    JSONNode *rootNode = parseJSON(jsonString);

    // Print the parsed JSON data
    printf("Key: %s\n", rootNode->key);
    printf("Value: %s\n", rootNode->value);

    printf("Interests: ");
    for (JSONNode *node = rootNode->next; node; node = node->next) {
        printf("%s, ", node->key);
    }

    printf("\n");

    return 0;
}