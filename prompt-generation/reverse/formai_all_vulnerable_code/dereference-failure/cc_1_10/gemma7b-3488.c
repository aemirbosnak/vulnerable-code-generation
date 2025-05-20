//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: high level of detail
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
    JSONNode *currNode = NULL;

    // Allocate memory for the first node
    if (head == NULL) {
        head = malloc(sizeof(JSONNode));
        currNode = head;
    }

    // Parse the JSON string
    int i = 0;
    while (jsonStr[i] != '\0') {
        // Handle quotes
        if (jsonStr[i] == '"') {
            // Allocate memory for the string
            currNode->data.string = malloc(MAX_BUFFER_SIZE);
            int j = 0;
            while (jsonStr[i + 1] != '"' && jsonStr[i + 1] != '\0') {
                currNode->data.string[j] = jsonStr[i + 1];
                j++;
                i++;
            }
            currNode->data.string[j] = '\0';
            currNode->type = 's';
        }
        // Handle numbers
        else if (jsonStr[i] >= '0' && jsonStr[i] <= '9') {
            currNode->data.number = atoi(jsonStr + i);
            currNode->type = 'n';
            i += 1;
        }
        // Handle braces and commas
        else if (jsonStr[i] == '{' || jsonStr[i] == '}') {
            // Allocate memory for the object or array
            currNode->data.object = malloc(sizeof(JSONNode));
            currNode->type = 'o';
            currNode->next = parseJSON(jsonStr + i + 1);
            currNode = currNode->data.object;
        } else if (jsonStr[i] == ',') {
            // Allocate memory for the next node
            currNode->next = malloc(sizeof(JSONNode));
            currNode = currNode->next;
        }

        i++;
    }

    return head;
}

int main() {
    char *jsonStr = "{ 'name': 'John Doe', 'age': 30, 'interests': ['music', 'reading', 'coding'] }";
    JSONNode *head = parseJSON(jsonStr);

    // Print the JSON data
    JSONNode *currNode = head;
    while (currNode) {
        switch (currNode->type) {
            case 'n':
                printf("Number: %d\n", currNode->data.number);
                break;
            case 's':
                printf("String: %s\n", currNode->data.string);
                break;
            case 'o':
                printf("Object:\n");
                currNode = currNode->data.object;
                break;
            case 'a':
                printf("Array:\n");
                currNode = currNode->data.array;
                break;
        }
        currNode = currNode->next;
    }

    return 0;
}