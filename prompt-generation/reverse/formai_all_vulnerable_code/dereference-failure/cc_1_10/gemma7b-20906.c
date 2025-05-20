//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char type;
    union {
        int number;
        double dnumber;
        char *string;
        struct JsonNode *object;
        struct JsonNode *array;
    } data;
    struct JsonNode *next;
} JsonNode;

void json_parser(char *json_string) {
    JsonNode *head = NULL;
    JsonNode *tail = NULL;

    // Allocate memory for the first node
    head = malloc(sizeof(JsonNode));
    tail = head;
    head->type = 'o';
    head->data.object = NULL;
    head->next = NULL;

    // Parse the JSON string
    char *p = json_string;
    while (*p) {
        // Handle quotes
        if (*p == '"') {
            p++;
            tail->type = 's';
            tail->data.string = malloc(MAX_BUFFER_SIZE);
            char *q = tail->data.string;
            while (*p != '"') {
                *q = *p;
                q++;
                p++;
            }
            *q = '\0';
            tail->next = malloc(sizeof(JsonNode));
            tail = tail->next;
            tail->type = 'o';
            tail->data.object = NULL;
            tail->next = NULL;
        }
        // Handle numbers
        else if (*p >= '0' && *p <= '9') {
            tail->type = 'n';
            tail->data.number = atoi(p);
            p += strlen(p);
            tail->next = malloc(sizeof(JsonNode));
            tail = tail->next;
            tail->type = 'o';
            tail->data.object = NULL;
            tail->next = NULL;
        }
        // Handle other characters
        else {
            p++;
        }
    }

    // Free the memory allocated for the JSON parser
    free(head);
}

int main() {
    char *json_string = "{ 'name': 'John Doe', 'age': 30, 'interests': ['music', 'reading', 'coding'] }";
    json_parser(json_string);

    return 0;
}