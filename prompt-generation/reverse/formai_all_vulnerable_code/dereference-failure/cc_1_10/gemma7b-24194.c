//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char type;
    union {
        int number;
        double decimal;
        char* string;
        struct JsonNode* array;
        struct JsonNode* object;
    } data;
    struct JsonNode* next;
} JsonNode;

void parseJson(char* jsonStr) {
    JsonNode* head = NULL;
    JsonNode* current = NULL;

    // Allocate memory for the first node
    head = malloc(sizeof(JsonNode));
    current = head;

    // Loop over the JSON string
    char* p = jsonStr;
    while (*p) {
        // Check for quotes, brackets, or commas
        if (*p == '"') {
            current->type = 's';
            current->data.string = malloc(MAX_BUFFER_SIZE);
            p++;
            char* q = current->data.string;
            while (*p && *p != '"') {
                *q = *p;
                q++;
                p++;
            }
            *q = '\0';
        } else if (*p == '[') {
            current->type = 'a';
            current->data.array = malloc(sizeof(JsonNode));
            current->next = current->data.array;
            current = current->next;
        } else if (*p == '{') {
            current->type = 'o';
            current->data.object = malloc(sizeof(JsonNode));
            current->next = current->data.object;
            current = current->next;
        } else if (*p == ',') {
            // Allocate memory for the next node
            current->next = malloc(sizeof(JsonNode));
            current = current->next;
        } else if (*p == '}') {
            // End of object or array
            current = NULL;
        } else if (*p == ':') {
            // Key-value pair
            current->type = 'k';
        } else if (*p >= 'a' && *p <= 'z') {
            // Key
            current->type = 'k';
            current->data.string = malloc(MAX_BUFFER_SIZE);
            p++;
            char* q = current->data.string;
            while (*p && *p != ':') {
                *q = *p;
                q++;
                p++;
            }
            *q = '\0';
        } else {
            // Ignore other characters
        }
    }

    // Free memory
    free(head);
}

int main() {
    char* jsonStr = "{ 'name': 'John Doe', 'age': 30, 'interests': [ 'music', 'reading', 'coding' ] }";
    parseJson(jsonStr);

    return 0;
}