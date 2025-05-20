//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JSON_MAX_SIZE 1024

typedef struct Node {
    char *key;
    struct Node *next;
    void *value;
} Node;

Node *newNode(char *key, void *value) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void parseJson(char *jsonString) {
    Node *head = NULL;
    char *jsonStringPtr = jsonString;
    char key[JSON_MAX_SIZE];
    void *value;

    while (jsonStringPtr) {
        // Key
        key[0] = '\0';
        int i = 0;
        while (*jsonStringPtr && *jsonStringPtr != ':') {
            key[i++] = *jsonStringPtr;
            jsonStringPtr++;
        }
        key[i] = '\0';

        // Value
        value = NULL;
        switch (*jsonStringPtr) {
            case '"':
                value = malloc(JSON_MAX_SIZE);
                jsonStringPtr++;
                i = 0;
                while (*jsonStringPtr && *jsonStringPtr != '"') {
                    ((char *)value)[i++] = *jsonStringPtr;
                    jsonStringPtr++;
                }
                ((char *)value)[i] = '\0';
                break;
            case 'n':
                value = NULL;
                break;
            case 't':
                value = NULL;
                break;
            case 'f':
                value = NULL;
                break;
            default:
                value = NULL;
                break;
        }

        newNode(key, value);

        // Move to the next key-value pair
        if (*jsonStringPtr == ',') {
            jsonStringPtr++;
        }
    }

    // Print the JSON data
    Node *current = head;
    while (current) {
        printf("%s: %s\n", current->key, current->value);
        current = current->next;
    }
}

int main() {
    char jsonString[] = "{ 'name': 'John Doe', 'age': 30, 'interests': [ 'music', 'reading', 'coding' ] }";
    parseJson(jsonString);

    return 0;
}