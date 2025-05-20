//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char *value;
    struct JsonNode *next;
} JsonNode;

JsonNode *parseJson(char *jsonString) {
    JsonNode *head = NULL;
    char *buffer = malloc(MAX_BUFFER_SIZE);
    int i = 0;
    int state = 0; // 0: outside, 1: inside quote, 2: inside brace

    for (; i < strlen(jsonString); i++) {
        switch (state) {
            case 0:
                if (jsonString[i] == '"') {
                    state = 1;
                    buffer = realloc(buffer, MAX_BUFFER_SIZE * 2);
                    buffer[0] = jsonString[i];
                    buffer[1] = '\0';
                    head = malloc(sizeof(JsonNode));
                    head->value = buffer;
                    head->next = NULL;
                    if (head) {
                        head = head;
                    }
                } else if (jsonString[i] == '{') {
                    state = 2;
                    buffer = realloc(buffer, MAX_BUFFER_SIZE * 2);
                    buffer[0] = jsonString[i];
                    buffer[1] = '\0';
                    head = malloc(sizeof(JsonNode));
                    head->value = buffer;
                    head->next = NULL;
                    if (head) {
                        head = head;
                    }
                }
                break;
            case 1:
                if (jsonString[i] == '"') {
                    state = 0;
                    buffer = realloc(buffer, MAX_BUFFER_SIZE);
                    buffer[0] = jsonString[i];
                    buffer[1] = '\0';
                    head = malloc(sizeof(JsonNode));
                    head->value = buffer;
                    head->next = NULL;
                    if (head) {
                        head = head;
                    }
                }
                break;
            case 2:
                if (jsonString[i] == '}') {
                    state = 0;
                    buffer = realloc(buffer, MAX_BUFFER_SIZE);
                    buffer[0] = jsonString[i];
                    buffer[1] = '\0';
                    head = malloc(sizeof(JsonNode));
                    head->value = buffer;
                    head->next = NULL;
                    if (head) {
                        head = head;
                    }
                }
                break;
        }
    }

    free(buffer);

    return head;
}

int main() {
    char *jsonString = "{ 'name': 'John Doe', 'age': 30 }";
    JsonNode *head = parseJson(jsonString);

    while (head) {
        printf("%s: %s\n", head->value, head->value);
        head = head->next;
    }

    return 0;
}