//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DEPTH 10

typedef struct Node {
    struct Node* next;
    char* data;
    int level;
} Node;

Node* createNode(char* data, int level) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = strdup(data);
    newNode->level = level;
    return newNode;
}

void parseJson(Node* node, char* json) {
    int i = 0;
    char* key = NULL;
    char* value = NULL;

    switch (node->level) {
        case 0:
            // Root node, parse the entire JSON string
            for (; i < strlen(json); i++) {
                if (json[i] == '{' || json[i] == '[') {
                    node = createNode(&json[i], node->level + 1);
                    parseJson(node, json);
                } else if (json[i] == '"') {
                    key = strdup(&json[i + 1]);
                    i += 2;
                } else if (json[i] == ':') {
                    value = strdup(&json[i + 1]);
                    i += 2;
                    printf("Key: %s, Value: %s\n", key, value);
                }
            }
            break;
        default:
            // Child node, parse the key-value pair
            for (; i < strlen(json); i++) {
                if (json[i] == '}' || json[i] == ']') {
                    return;
                } else if (json[i] == '"') {
                    key = strdup(&json[i + 1]);
                    i += 2;
                } else if (json[i] == ':') {
                    value = strdup(&json[i + 1]);
                    i += 2;
                    printf("Key: %s, Value: %s\n", key, value);
                }
            }
    }
}

int main() {
    char* json = "{ 'name': 'John Doe', 'age': 30, 'interests': [ 'music', 'reading', 'coding' ] }";
    Node* root = createNode(json, 0);
    parseJson(root, json);
    return 0;
}