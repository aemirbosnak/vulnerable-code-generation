//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: innovative
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
        struct JsonNode *array;
        struct JsonNode *object;
    } data;
    struct JsonNode *next;
} JsonNode;

void parseJson(char *jsonStr) {
    JsonNode *head = NULL;
    JsonNode *tail = NULL;

    // Allocate memory for the first node
    head = malloc(sizeof(JsonNode));
    tail = head;
    tail->type = 'o';
    tail->data.object = malloc(sizeof(struct JsonNode));
    tail->next = NULL;

    // Parse the JSON string
    char *p = jsonStr;
    while (*p) {
        // Handle quotes
        if (*p == '"') {
            tail->type = 's';
            tail->data.string = malloc(MAX_BUFFER_SIZE);
            char *q = tail->data.string;
            p++;
            while (*p != '"') {
                *q = *p;
                q++;
                p++;
            }
            *q = '\0';
        }
        // Handle brackets
        else if (*p == '{' || *p == '[') {
            tail->type = 'a';
            tail->data.array = malloc(sizeof(struct JsonNode));
            tail->next = tail->data.array;
            tail = tail->next;
            tail->type = 'o';
            tail->data.object = malloc(sizeof(struct JsonNode));
            tail->next = NULL;
        }
        // Handle other characters
        else if (*p != ',') {
            switch (*p) {
                case ':':
                    tail->type = 'n';
                    break;
                case ',':
                    tail->type = 'n';
                    tail = tail->next;
                    break;
                default:
                    tail->type = 'n';
                    break;
            }
            tail->data.number = atoi(p);
        }
        p++;
    }

    // Print the JSON data
    JsonNode *node = head;
    while (node) {
        switch (node->type) {
            case 'o':
                printf("Object:\n");
                break;
            case 'a':
                printf("Array:\n");
                break;
            case 's':
                printf("String: %s\n", node->data.string);
                break;
            case 'n':
                printf("Number: %d\n", node->data.number);
                break;
        }
        node = node->next;
    }
}

int main() {
    char jsonStr[] = "{ 'name': 'John Doe', 'age': 30, 'interests': [ 'music', 'reading', 'coding' ] }";
    parseJson(jsonStr);
    return 0;
}