//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char *value;
    struct JsonNode *next;
    struct JsonNode *child;
    struct JsonNode **parent;
} JsonNode;

struct JsonNode *parseJson(char *jsonStr) {
    struct JsonNode *head = NULL;
    struct JsonNode *newNode = NULL;
    struct JsonNode *tempNode = NULL;
    char *buffer = NULL;
    int i = 0;
    int bufferSize = 0;

    buffer = malloc(MAX_BUFFER_SIZE);
    if (buffer == NULL) {
        return NULL;
    }

    while (jsonStr[i] != '\0') {
        if (newNode == NULL) {
            newNode = malloc(sizeof(struct JsonNode));
            if (newNode == NULL) {
                return NULL;
            }
            newNode->value = malloc(MAX_BUFFER_SIZE);
            if (newNode->value == NULL) {
                return NULL;
            }
            newNode->next = NULL;
            newNode->child = NULL;
            newNode->parent = NULL;
            if (head == NULL) {
                head = newNode;
            } else {
                tempNode->next = newNode;
            }
            tempNode = newNode;
        }

        bufferSize = 0;
        while (jsonStr[i] != '\0' && jsonStr[i] != ',' && jsonStr[i] != '}') {
            buffer[bufferSize++] = jsonStr[i];
            i++;
        }
        newNode->value = buffer;
        bufferSize = 0;
        i++;
    }

    return head;
}

int main() {
    char *jsonStr = "{ 'name': 'John Doe', 'age': 30, 'interests': ['music', 'reading', 'coding'] }";
    struct JsonNode *head = parseJson(jsonStr);

    printf("Name: %s\n", head->child->child->value);
    printf("Age: %d\n", head->child->next->value - '0');
    printf("Interests: ");
    for (struct JsonNode *node = head->child->next->next; node; node = node->next) {
        printf("%s, ", node->value);
    }
    printf("\n");

    return 0;
}