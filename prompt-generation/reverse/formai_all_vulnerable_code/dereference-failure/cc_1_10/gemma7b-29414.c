//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JSONNode {
    char type;
    union {
        int number;
        double decimal;
        char *string;
        struct JSONNode *object;
        struct JSONNode *array;
    } data;
    struct JSONNode *next;
} JSONNode;

JSONNode *parseJSON(char *jsonStr) {
    JSONNode *head = NULL;
    JSONNode *tail = NULL;

    // Allocate memory for the first node
    head = malloc(sizeof(JSONNode));
    tail = head;

    // Parse the JSON string
    int i = 0;
    char currentChar;
    while ((currentChar = jsonStr[i]) != '\0') {
        // Handle quotes, brackets, and commas
        switch (currentChar) {
            case '"':
                tail->type = 's';
                tail->data.string = malloc(MAX_BUFFER_SIZE);
                i++;
                while (jsonStr[i] != '"') {
                    tail->data.string[i - 1] = jsonStr[i];
                    i++;
                }
                tail->data.string[i - 1] = '\0';
                break;
            case '{' :
                tail->type = 'o';
                tail->data.object = malloc(sizeof(JSONNode));
                tail = tail->data.object;
                break;
            case '[' :
                tail->type = 'a';
                tail->data.array = malloc(sizeof(JSONNode));
                tail = tail->data.array;
                break;
            case ',':
                tail->next = malloc(sizeof(JSONNode));
                tail = tail->next;
                break;
            default:
                tail->type = 'n';
                tail->data.number = jsonStr[i] - '0';
                i++;
                break;
        }
    }

    // Return the head of the JSON node
    return head;
}

int main() {
    char *jsonStr = "{ 'name': 'John Doe', 'age': 30 }";
    JSONNode *rootNode = parseJSON(jsonStr);

    // Print the JSON data
    printf("Name: %s\n", rootNode->data.object->data.string);
    printf("Age: %d\n", rootNode->data.object->data.number);

    return 0;
}