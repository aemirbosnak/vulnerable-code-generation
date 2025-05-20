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
        struct JsonNode **array;
    } data;
    struct JsonNode *next;
} JsonNode;

JsonNode *parseJson(char *jsonStr) {
    JsonNode *head = NULL;
    JsonNode *tail = NULL;

    // Allocate memory for the JSON node
    JsonNode *node = malloc(sizeof(JsonNode));
    node->type = 'o';
    node->data.object = NULL;
    node->next = NULL;

    tail = node;

    // Parse the JSON string
    char *ptr = jsonStr;
    while (*ptr) {
        // Handle quotes
        if (*ptr == '"') {
            ptr++;
            node->type = 's';
            node->data.string = malloc(MAX_BUFFER_SIZE);
            char *str = node->data.string;
            while (*ptr && *ptr != '"') {
                *str = *ptr;
                str++;
                ptr++;
            }
            *str = '\0';
        }
        // Handle braces
        else if (*ptr == '{' || *ptr == '[') {
            node->type = 'o' == *ptr ? 'o' : 'a';
            node->data.object = parseJson(ptr);
            tail->next = node;
            tail = node;
        }
        // Handle commas
        else if (*ptr == ',') {
            node = malloc(sizeof(JsonNode));
            node->type = 'o';
            node->data.object = NULL;
            node->next = NULL;
            tail->next = node;
            tail = node;
        }
        ptr++;
    }

    return head;
}

int main() {
    char jsonStr[] = "{ 'name': 'John Doe', 'age': 30, 'interests': [ 'reading', 'music', 'coding' ] }";
    JsonNode *head = parseJson(jsonStr);

    // Print the JSON data
    printf("Name: %s\n", head->data.object->data.string);
    printf("Age: %d\n", head->data.object->data.number);
    printf("Interests: ");
    for (JsonNode *node = head->data.object->data.array; node; node = node->next) {
        printf("%s, ", node->data.string);
    }
    printf("\n");

    return 0;
}