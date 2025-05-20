//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char type;
    union {
        int integerValue;
        double doubleValue;
        char *stringValue;
        struct JsonNode *arrayValue;
        struct JsonNode *objectValue;
    } data;
    struct JsonNode *next;
} JsonNode;

void jsonParser(char *jsonString) {
    JsonNode *head = NULL;
    int i = 0;
    int bufferSize = 0;
    char buffer[MAX_BUFFER_SIZE];

    while (jsonString[i] != '\0') {
        switch (jsonString[i]) {
            case '"':
                if (bufferSize > 0) {
                    struct JsonNode *newNode = malloc(sizeof(struct JsonNode));
                    newNode->type = 's';
                    newNode->data.stringValue = malloc(bufferSize);
                    memcpy(newNode->data.stringValue, buffer, bufferSize);
                    newNode->next = head;
                    head = newNode;
                }
                bufferSize = 0;
                break;
            case ':':
                if (bufferSize > 0) {
                    struct JsonNode *newNode = malloc(sizeof(struct JsonNode));
                    newNode->type = 'a';
                    newNode->data.arrayValue = head;
                    newNode->next = head;
                    head = newNode;
                }
                bufferSize = 0;
                break;
            case ',':
                if (bufferSize > 0) {
                    struct JsonNode *newNode = malloc(sizeof(struct JsonNode));
                    newNode->type = 'o';
                    newNode->data.objectValue = head;
                    newNode->next = head;
                    head = newNode;
                }
                bufferSize = 0;
                break;
            default:
                buffer[bufferSize++] = jsonString[i];
                break;
        }
        i++;
    }

    if (bufferSize > 0) {
        struct JsonNode *newNode = malloc(sizeof(struct JsonNode));
        newNode->type = 's';
        newNode->data.stringValue = malloc(bufferSize);
        memcpy(newNode->data.stringValue, buffer, bufferSize);
        newNode->next = head;
        head = newNode;
    }

    printf("JSON data:\n");
    for (struct JsonNode *node = head; node; node = node->next) {
        switch (node->type) {
            case 'i':
                printf("Integer: %d\n", node->data.integerValue);
                break;
            case 'd':
                printf("Double: %.2lf\n", node->data.doubleValue);
                break;
            case 's':
                printf("String: %s\n", node->data.stringValue);
                break;
            case 'a':
                printf("Array: ");
                for (struct JsonNode *arrayNode = node->data.arrayValue; arrayNode; arrayNode = arrayNode->next) {
                    printf("%s, ", arrayNode->data.stringValue);
                }
                printf("\n");
                break;
            case 'o':
                printf("Object: ");
                for (struct JsonNode *objectNode = node->data.objectValue; objectNode; objectNode = objectNode->next) {
                    printf("%s: %s, ", objectNode->data.stringValue, objectNode->data.stringValue);
                }
                printf("\n");
                break;
        }
    }

    free(jsonString);
}

int main() {
    char *jsonString = "{'name': 'John Doe', 'age': 30, 'interests': ['music', 'reading', 'coding']}";
    jsonParser(jsonString);

    return 0;
}