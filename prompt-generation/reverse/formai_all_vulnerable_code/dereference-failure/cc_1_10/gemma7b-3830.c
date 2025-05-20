//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSON_Node {
    char *key;
    char *value;
    struct JSON_Node *next;
} JSON_Node;

JSON_Node *parse_json(char *json_string) {
    JSON_Node *head = NULL;
    JSON_Node *current = NULL;
    int i = 0;

    // Allocate memory for the first node
    if (head == NULL) {
        head = (JSON_Node *)malloc(sizeof(JSON_Node));
        current = head;
        current->key = NULL;
        current->value = NULL;
        current->next = NULL;
    }

    // Iterate over the JSON string
    for (; i < strlen(json_string); i++) {
        // Handle quotes
        if (json_string[i] == '"') {
            // Allocate memory for key and value
            current->key = (char *)malloc(MAX_BUFFER_SIZE);
            current->value = (char *)malloc(MAX_BUFFER_SIZE);

            // Copy key and value from the JSON string
            int j = 0;
            for (; json_string[i + 1] != '"' && json_string[i + 1] != '\0'; i++) {
                current->key[j] = json_string[i + 1];
                j++;
            }

            current->key[j] = '\0';

            i++;

            // Handle the colon
            if (json_string[i] == ':') {
                i++;

                // Copy the value from the JSON string
                j = 0;
                for (; json_string[i] != '}' && json_string[i] != '\0'; i++) {
                    current->value[j] = json_string[i];
                    j++;
                }

                current->value[j] = '\0';

                // Create a new node if necessary
                if (current->next == NULL) {
                    current->next = (JSON_Node *)malloc(sizeof(JSON_Node));
                    current = current->next;
                    current->key = NULL;
                    current->value = NULL;
                    current->next = NULL;
                }
            }
        }
    }

    return head;
}

int main() {
    char json_string[] = "{ 'name': 'John Doe', 'age': 30 }";
    JSON_Node *head = parse_json(json_string);

    // Print the JSON data
    JSON_Node *current = head;
    while (current) {
        printf("Key: %s, Value: %s\n", current->key, current->value);
        current = current->next;
    }

    return 0;
}