//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: detailed
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

void JsonNode_Create(JsonNode **node) {
    *node = malloc(sizeof(JsonNode));
    (*node)->type = 'o';
    (*node)->data.stringValue = NULL;
    (*node)->next = NULL;
}

void JsonNode_SetInteger(JsonNode *node, int value) {
    node->type = 'i';
    node->data.integerValue = value;
}

void JsonNode_SetDouble(JsonNode *node, double value) {
    node->type = 'd';
    node->data.doubleValue = value;
}

void JsonNode_SetString(JsonNode *node, char *value) {
    node->type = 's';
    node->data.stringValue = strdup(value);
}

void JsonNode_SetArray(JsonNode *node, JsonNode *array) {
    node->type = 'a';
    node->data.arrayValue = array;
}

void JsonNode_SetObject(JsonNode *node, JsonNode *object) {
    node->type = 'o';
    node->data.objectValue = object;
}

void JsonNode_Print(JsonNode *node) {
    switch (node->type) {
        case 'i':
            printf("Integer: %d\n", node->data.integerValue);
            break;
        case 'd':
            printf("Double: %f\n", node->data.doubleValue);
            break;
        case 's':
            printf("String: %s\n", node->data.stringValue);
            break;
        case 'a':
            printf("Array:\n");
            for (JsonNode *child = node->data.arrayValue; child; child = child->next) {
                JsonNode_Print(child);
            }
            break;
        case 'o':
            printf("Object:\n");
            for (JsonNode *child = node->data.objectValue; child; child = child->next) {
                JsonNode_Print(child);
            }
            break;
    }
}

int main() {
    JsonNode *root = NULL;
    JsonNode_Create(&root);

    JsonNode_SetInteger(root, 10);
    JsonNode_SetString(root->next, "John Doe");
    JsonNode_SetArray(root->next->next, NULL);

    JsonNode_Print(root);

    return 0;
}