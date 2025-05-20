//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char type;
    union {
        struct JsonNode* child;
        struct JsonNode** siblings;
        char* value;
    } data;
} JsonNode;

JsonNode* parseJson(char* jsonStr) {
    JsonNode* root = NULL;
    int pos = 0;
    int bufferSize = MAX_BUFFER_SIZE;
    char* buffer = malloc(bufferSize);

    while (pos < strlen(jsonStr) && bufferSize > 0) {
        switch (jsonStr[pos]) {
            case '"':
                buffer = realloc(buffer, bufferSize * 2);
                bufferSize *= 2;
                pos++;
                break;
            case ':':
                root = malloc(sizeof(JsonNode));
                root->type = 'o';
                root->data.child = NULL;
                root->data.siblings = NULL;
                root->data.value = malloc(MAX_BUFFER_SIZE);
                memcpy(root->data.value, jsonStr + pos, MAX_BUFFER_SIZE - 1);
                pos++;
                break;
            case ',':
                break;
            default:
                pos++;
                break;
        }
    }

    free(buffer);

    return root;
}

int main() {
    char* jsonStr = "{\"name\":\"John Doe\", \"age\":30}";
    JsonNode* root = parseJson(jsonStr);

    printf("Name: %s\n", root->data.value);
    printf("Age: %d\n", atoi(root->data.value + 6));

    return 0;
}