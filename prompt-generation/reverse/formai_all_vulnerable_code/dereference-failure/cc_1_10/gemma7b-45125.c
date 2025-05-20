//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char type;
    union {
        struct JsonNode* array;
        struct JsonNode* object;
        char* string;
        int number;
    } data;
} JsonNode;

void json_parser(char* json_string) {
    JsonNode* root = malloc(sizeof(JsonNode));
    root->type = 'o';
    root->data.object = NULL;

    int i = 0;
    char* current_key = NULL;
    while (i < strlen(json_string)) {
        switch (json_string[i]) {
            case '"':
                if (current_key) {
                    free(current_key);
                }
                current_key = malloc(MAX_BUFFER_SIZE);
                *current_key = json_string[i];
                i++;
                break;
            case ':':
                if (current_key) {
                    root->data.object = malloc(sizeof(JsonNode));
                    root->data.object->type = 'a';
                    root->data.object->data.array = NULL;
                    root->data.object->data.string = current_key;
                    current_key = NULL;
                }
                i++;
                break;
            case ',':
                if (current_key) {
                    free(current_key);
                    current_key = NULL;
                }
                i++;
                break;
            case ' ':
                i++;
                break;
            default:
                i++;
                break;
        }
    }

    if (current_key) {
        free(current_key);
    }

    printf("%s", root->data.object->data.string);
    free(root);
}

int main() {
    json_parser("{\"name\":\"John Doe\", \"age\":30}");
    return 0;
}