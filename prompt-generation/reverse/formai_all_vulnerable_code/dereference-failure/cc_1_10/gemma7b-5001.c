//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: light-weight
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
        struct JsonNode **array;
    } data;
    struct JsonNode *next;
} JsonNode;

void json_parser(char *json_str) {
    JsonNode *head = NULL;
    JsonNode *tail = NULL;

    // Allocate memory for the first node
    head = malloc(sizeof(JsonNode));
    tail = head;

    // Parse the JSON string
    char *p = json_str;
    while (*p) {
        // Check for quotes, curly braces, or square brackets
        if (*p == '"') {
            // String
            tail->type = 's';
            tail->data.string = malloc(MAX_BUFFER_SIZE);
            p++;
            char *q = tail->data.string;
            while (*p != '"' && *p) {
                *q = *p;
                q++;
                p++;
            }
            *q = '\0';
            tail->next = malloc(sizeof(JsonNode));
            tail = tail->next;
        } else if (*p == '{') {
            // Object
            tail->type = 'o';
            tail->data.object = malloc(MAX_BUFFER_SIZE);
            p++;
            tail = tail->data.object;
        } else if (*p == '[') {
            // Array
            tail->type = 'a';
            tail->data.array = malloc(MAX_BUFFER_SIZE);
            p++;
            tail = tail->data.array;
        } else if (*p == ':') {
            // Key-value pair
            p++;
            tail->type = 'k';
            tail->data.string = malloc(MAX_BUFFER_SIZE);
            char *q = tail->data.string;
            while (*p != ':') {
                *q = *p;
                q++;
                p++;
            }
            *q = '\0';
            p++;
            tail->type = 'v';
            tail->data.string = malloc(MAX_BUFFER_SIZE);
            q = tail->data.string;
            while (*p != '}') {
                *q = *p;
                q++;
                p++;
            }
            *q = '\0';
            tail->next = malloc(sizeof(JsonNode));
            tail = tail->next;
        } else {
            // Ignore whitespace and comments
            p++;
        }
    }

    // Free the memory allocated for the JSON nodes
    free(head);
}

int main() {
    char json_str[] = "{ \"name\": \"John Doe\", \"age\": 30 }";

    json_parser(json_str);

    return 0;
}