//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: expert-level
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
    } data;
    struct JsonNode *next;
} JsonNode;

void parseJson(char *jsonStr) {
    JsonNode *head = NULL;
    JsonNode *tail = NULL;

    // Allocate memory for the first node
    head = malloc(sizeof(JsonNode));
    tail = head;

    // Parse the JSON string
    char *p = jsonStr;
    while (*p) {
        // Handle quotes and strings
        if (*p == '"') {
            tail->type = 's';
            tail->data.string = malloc(MAX_BUFFER_SIZE);
            p++;
            char *q = tail->data.string;
            while (*p != '"') {
                *q++ = *p++;
            }
            *q = NULL;
        }
        // Handle numbers
        else if (isdigit(*p)) {
            tail->type = 'n';
            tail->data.number = atoi(p);
            p += 1;
        }
        // Handle braces and square brackets
        else if (*p == '{' || *p == '[') {
            tail->type = 'o' == *p ? 'o' : 'a';
            tail->data.object = malloc(sizeof(JsonNode));
            tail->data.object->next = NULL;
            tail = tail->data.object;
        }
        // Handle commas and colons
        else if (*p == ',' || *p == ':') {
            p++;
        }
        // Handle the end of the JSON string
        else if (*p == '}') {
            tail->type = 'e';
            tail->next = NULL;
            return;
        }
        p++;
    }

    // Free memory
    free(head);
}

int main() {
    char jsonStr[] = "{ 'name': 'John Doe', 'age': 30, 'interests': [ 'music', 'reading', 'coding' ] }";
    parseJson(jsonStr);

    return 0;
}