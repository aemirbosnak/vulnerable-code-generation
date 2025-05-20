//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: systematic
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

void parseJson(char *jsonStr) {
    JsonNode *head = NULL;
    JsonNode *newNode = NULL;
    char *ptr = jsonStr;
    char quoteFound = 0;

    while (*ptr) {
        switch (*ptr) {
            case '"':
                quoteFound = 1;
                break;
            case '{' :
                if (newNode == NULL) {
                    newNode = (JsonNode *)malloc(sizeof(JsonNode));
                    newNode->type = 'o';
                    newNode->next = head;
                    head = newNode;
                } else {
                    newNode->type = 'o';
                    newNode->next = head;
                    head = newNode;
                }
                break;
            case '[':
                if (newNode == NULL) {
                    newNode = (JsonNode *)malloc(sizeof(JsonNode));
                    newNode->type = 'a';
                    newNode->next = head;
                    head = newNode;
                } else {
                    newNode->type = 'a';
                    newNode->next = head;
                    head = newNode;
                }
                break;
            case ':':
                if (newNode) {
                    newNode->data.string = (char *)malloc(MAX_BUFFER_SIZE);
                    newNode->data.string = ptr + 1;
                }
                break;
            case ',':
                if (quoteFound) {
                    quoteFound = 0;
                } else if (newNode) {
                    newNode->next = (JsonNode *)malloc(sizeof(JsonNode));
                    newNode = newNode->next;
                    newNode->type = 'n';
                    newNode->data.number = atoi(ptr);
                }
                break;
            case '}':
            case ']':
                if (newNode) {
                    newNode->next = NULL;
                }
                return;
            default:
                break;
        }
        ptr++;
    }

    return;
}

int main() {
    char jsonStr[] = "{ 'name': 'John Doe', 'age': 30 }";
    parseJson(jsonStr);

    return 0;
}