//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char *key;
    char *value;
    struct JsonNode *next;
} JsonNode;

void parseJson(char *jsonString) {
    // Allocate memory for the JSON parser
    JsonNode *head = malloc(sizeof(JsonNode));
    head->key = NULL;
    head->value = NULL;
    head->next = NULL;

    // Create a JSON parser state machine
    int state = 0;
    char currentKey[MAX_BUFFER_SIZE] = "";
    char currentValue[MAX_BUFFER_SIZE] = "";

    // Iterate over the JSON string
    for (int i = 0; jsonString[i] != '\0'; i++) {
        switch (state) {
            case 0: // Start state
                if (jsonString[i] == '"') {
                    state = 1;
                    currentKey[0] = '"';
                } else if (jsonString[i] == '{' || jsonString[i] == '[') {
                    state = 2;
                }
                break;
            case 1: // Key state
                if (jsonString[i] == '"') {
                    state = 2;
                    currentKey[strlen(currentKey)] = '\0';
                    JsonNode *newNode = malloc(sizeof(JsonNode));
                    newNode->key = malloc(strlen(currentKey) + 1);
                    strcpy(newNode->key, currentKey);
                    newNode->value = NULL;
                    newNode->next = head->next;
                    head->next = newNode;
                    currentKey[0] = '"';
                } else {
                    currentKey[strlen(currentKey) + 1] = jsonString[i];
                }
                break;
            case 2: // Value state
                if (jsonString[i] == '"') {
                    state = 0;
                    currentValue[strlen(currentValue)] = '\0';
                    JsonNode *newNode = malloc(sizeof(JsonNode));
                    newNode->key = head->next->key;
                    newNode->value = malloc(strlen(currentValue) + 1);
                    strcpy(newNode->value, currentValue);
                    newNode->next = NULL;
                    head->next->next = newNode;
                } else if (jsonString[i] == ',') {
                    state = 0;
                    currentValue[strlen(currentValue)] = '\0';
                    JsonNode *newNode = malloc(sizeof(JsonNode));
                    newNode->key = head->next->key;
                    newNode->value = malloc(strlen(currentValue) + 1);
                    strcpy(newNode->value, currentValue);
                    newNode->next = NULL;
                    head->next->next = newNode;
                } else {
                    currentValue[strlen(currentValue) + 1] = jsonString[i];
                }
                break;
        }
    }

    // Free the JSON parser memory
    free(head);
}

int main() {
    char jsonString[] = "{ 'name': 'John Doe', 'age': 30 }";
    parseJson(jsonString);

    return 0;
}