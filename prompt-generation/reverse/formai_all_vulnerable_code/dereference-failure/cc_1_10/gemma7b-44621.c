//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char *key;
    char *value;
    struct JsonNode *next;
} JsonNode;

JsonNode *parseJson(char *jsonStr) {
    JsonNode *head = NULL;
    char *buffer = malloc(MAX_BUFFER_SIZE);
    int i = 0;
    int state = 0; // 0 - start, 1 - key, 2 - value

    while (jsonStr[i] != '\0') {
        switch (state) {
            case 0:
                if (jsonStr[i] == '"') {
                    state = 1;
                } else if (jsonStr[i] == '{') {
                    state = 3;
                }
                break;
            case 1:
                if (jsonStr[i] == '"') {
                    state = 2;
                } else {
                    buffer[i] = jsonStr[i];
                    i++;
                }
                break;
            case 2:
                if (jsonStr[i] == ':') {
                    state = 0;
                    JsonNode *newNode = malloc(sizeof(JsonNode));
                    newNode->key = buffer;
                    newNode->value = NULL;
                    newNode->next = head;
                    head = newNode;
                } else {
                    buffer[i] = jsonStr[i];
                    i++;
                }
                break;
            case 3:
                if (jsonStr[i] == '}') {
                    state = 0;
                } else {
                    buffer[i] = jsonStr[i];
                    i++;
                }
                break;
        }
    }

    free(buffer);

    return head;
}

int main() {
    char *jsonStr = "{ 'name': 'John Doe', 'age': 30 }";
    JsonNode *head = parseJson(jsonStr);

    while (head) {
        printf("Key: %s, Value: %s\n", head->key, head->value);
        head = head->next;
    }

    return 0;
}