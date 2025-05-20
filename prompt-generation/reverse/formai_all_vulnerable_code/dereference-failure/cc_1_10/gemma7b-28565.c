//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char *data;
    struct JsonNode *next;
} JsonNode;

JsonNode *parseJson(char *jsonString) {
    JsonNode *head = NULL;
    char *buffer = malloc(MAX_BUFFER_SIZE);
    int i = 0;
    int state = 0;

    while (jsonString[i] != '\0') {
        switch (state) {
            case 0:
                if (jsonString[i] == '{') {
                    head = malloc(sizeof(JsonNode));
                    head->data = malloc(MAX_BUFFER_SIZE);
                    head->next = NULL;
                    state = 1;
                } else if (jsonString[i] == '"') {
                    state = 2;
                } else {
                    state = 0;
                }
                break;
            case 1:
                if (jsonString[i] == '"') {
                    state = 2;
                } else {
                    head->data = realloc(head->data, MAX_BUFFER_SIZE * (i + 1));
                    head->data[i] = jsonString[i];
                    i++;
                }
                break;
            case 2:
                if (jsonString[i] == '"') {
                    state = 0;
                } else {
                    head->data = realloc(head->data, MAX_BUFFER_SIZE * (i + 1));
                    head->data[i] = jsonString[i];
                    i++;
                }
                break;
        }
    }

    return head;
}

int main() {
    char *jsonString = "{ 'name': 'John Doe', 'age': 30 }";
    JsonNode *head = parseJson(jsonString);

    printf("Name: %s\n", head->data);
    printf("Age: %d\n", atoi(head->data + 8));

    free(head);
    return 0;
}