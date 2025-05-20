//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* createNode(char data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void parseJSON(char* jsonStr) {
    Node* head = NULL;
    char* currentPos = jsonStr;

    while (*currentPos) {
        switch (*currentPos) {
            case '"':
                currentPos++;
                Node* newNode = createNode('"');
                newNode->data = *currentPos;
                if (head) {
                    head->next = newNode;
                } else {
                    head = newNode;
                }
                break;
            case '{' :
            case '[' :
                currentPos++;
                newNode = createNode('{');
                newNode->data = *currentPos;
                if (head) {
                    head->next = newNode;
                } else {
                    head = newNode;
                }
                break;
            case ',':
                currentPos++;
                newNode = createNode(',');
                newNode->data = *currentPos;
                if (head) {
                    head->next = newNode;
                } else {
                    head = newNode;
                }
                break;
            case '}':
            case ']':
                currentPos++;
                newNode = createNode('}');
                newNode->data = *currentPos;
                if (head) {
                    head->next = newNode;
                } else {
                    head = newNode;
                }
                break;
            default:
                currentPos++;
                break;
        }
    }

    // Print the linked list
    Node* current = head;
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    char* jsonStr = "{ 'name': 'John Doe', 'age': 30 }";
    parseJSON(jsonStr);

    return 0;
}