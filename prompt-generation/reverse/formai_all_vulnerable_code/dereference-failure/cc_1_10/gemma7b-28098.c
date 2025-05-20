//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char type;
    union {
        int number;
        char *string;
        struct JsonNode *object;
        struct JsonNode **array;
    } data;
    struct JsonNode *next;
} JsonNode;

JsonNode *parseJson(char *jsonStr) {
    JsonNode *head = NULL;
    JsonNode *currentNode = NULL;
    int i = 0;

    while (jsonStr[i] != '\0') {
        switch (jsonStr[i]) {
            case '"':
                currentNode = malloc(sizeof(JsonNode));
                currentNode->type = 's';
                currentNode->data.string = malloc(MAX_BUFFER_SIZE);
                i++;
                for (; jsonStr[i] != '"' && jsonStr[i] != '\0'; i++) {
                    currentNode->data.string[i - 1] = jsonStr[i];
                }
                currentNode->data.string[i - 1] = '\0';
                if (head == NULL) {
                    head = currentNode;
                } else {
                    currentNode->next = head;
                    head = currentNode;
                }
                break;
            case '{' :
                currentNode = malloc(sizeof(JsonNode));
                currentNode->type = 'o';
                currentNode->data.object = NULL;
                if (head == NULL) {
                    head = currentNode;
                } else {
                    currentNode->next = head;
                    head = currentNode;
                }
                break;
            case '[' :
                currentNode = malloc(sizeof(JsonNode));
                currentNode->type = 'a';
                currentNode->data.array = NULL;
                if (head == NULL) {
                    head = currentNode;
                } else {
                    currentNode->next = head;
                    head = currentNode;
                }
                break;
            case ',':
            case ':':
            case '}':
            case ']':
                i++;
                break;
            default:
                i++;
                break;
        }
    }

    return head;
}

int main() {
    char jsonStr[] = "{ 'name': 'John Doe', 'age': 30 }";
    JsonNode *head = parseJson(jsonStr);

    printf("Name: %s\n", head->data.object->data.string);
    printf("Age: %d\n", head->data.object->data.number);

    return 0;
}