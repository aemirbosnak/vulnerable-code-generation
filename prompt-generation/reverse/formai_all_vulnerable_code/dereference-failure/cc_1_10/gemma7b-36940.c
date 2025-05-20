//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: minimalist
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
    JsonNode *currNode = NULL;
    char *buffer = malloc(MAX_BUFFER_SIZE);
    char *p = buffer;
    int i = 0;

    // Allocate memory for the first node
    if (head == NULL) {
        head = currNode = malloc(sizeof(JsonNode));
    } else {
        currNode = malloc(sizeof(JsonNode));
        head->next = currNode;
        currNode = head->next;
    }

    // Parse the JSON string
    while (*jsonStr) {
        switch (*jsonStr) {
            case '"':
                p = jsonStr + 1;
                currNode->type = 's';
                currNode->data.string = malloc(MAX_BUFFER_SIZE);
                memcpy(currNode->data.string, p, MAX_BUFFER_SIZE - 1);
                currNode->data.string[MAX_BUFFER_SIZE - 1] = '\0';
                break;
            case '{' :
                currNode->type = 'o';
                currNode->data.object = parseJson(jsonStr + 1);
                break;
            case '[' :
                currNode->type = 'a';
                currNode->data.array = parseJson(jsonStr + 1);
                break;
            case ',':
                currNode = malloc(sizeof(JsonNode));
                currNode->next = head->next;
                head->next = currNode;
                currNode = head->next;
                break;
            case ':':
            case '}':
            case ']':
                break;
            default:
                currNode->type = 'n';
                currNode->data.number = atoi(jsonStr);
                break;
        }

        jsonStr++;
    }

    free(buffer);

    return head;
}

int main() {
    char *jsonStr = "{ 'name': 'John Doe', 'age': 30, 'interests': [ 'music', 'reading', 'coding' ] }";
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