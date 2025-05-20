//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 256

typedef struct JSON_Node {
    char *key;
    char *value;
    struct JSON_Node *next;
} JSON_Node;

JSON_Node *parseJSON(char *jsonString) {
    JSON_Node *head = NULL;
    JSON_Node *tail = NULL;

    // Allocate memory for the JSON node
    JSON_Node *newNode = (JSON_Node *)malloc(sizeof(JSON_Node));
    newNode->key = NULL;
    newNode->value = NULL;
    newNode->next = NULL;

    // Parse the JSON string
    char *p = jsonString;
    while (*p) {
        // Check for key-value pair
        if (*p == '"') {
            // Allocate memory for the key
            newNode->key = malloc(MAX_BUFFER_SIZE);
            char *q = newNode->key;
            while (*p != '"') {
                *q++ = *p++;
            }
            *q = NULL;

            // Check for colon
            if (*p == ':') {
                p++;

                // Allocate memory for the value
                newNode->value = malloc(MAX_BUFFER_SIZE);
                q = newNode->value;
                while (*p != ',') {
                    *q++ = *p++;
                }
                *q = NULL;
            }
        }

        // Move to the next character
        p++;
    }

    // Return the head of the JSON node
    return head;
}

int main() {
    char jsonString[] = "{ 'name': 'John Doe', 'age': 30 }";
    JSON_Node *head = parseJSON(jsonString);

    // Print the JSON data
    JSON_Node *current = head;
    while (current) {
        printf("%s: %s\n", current->key, current->value);
        current = current->next;
    }

    return 0;
}