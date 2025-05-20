//Gemma-7B DATASET v1.0 Category: Building a JSON Parser ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct JsonNode {
    char type;
    union {
        int number;
        double decimal;
        char* string;
        struct JsonNode* array;
        struct JsonNode* object;
    } data;
    struct JsonNode* next;
} JsonNode;

int JsonNode_alloc(struct JsonNode** node) {
    *node = malloc(sizeof(struct JsonNode));
    if (*node == NULL) {
        return -1;
    }
    (*node)->type = '\0';
    (*node)->next = NULL;
    return 0;
}

void JsonNode_free(struct JsonNode* node) {
    free(node);
}

int JsonNode_insertAfter(struct JsonNode* node, struct JsonNode** new_node) {
    struct JsonNode* new_node_ptr = *new_node;
    if (node->next != NULL) {
        node->next->next = new_node_ptr;
    } else {
        node->next = new_node_ptr;
    }
    *new_node = node->next;
    return 0;
}

int JsonNode_setNumber(struct JsonNode* node, int number) {
    node->type = 'n';
    node->data.number = number;
    return 0;
}

int JsonNode_setDecimal(struct JsonNode* node, double decimal) {
    node->type = 'd';
    node->data.decimal = decimal;
    return 0;
}

int JsonNode_setString(struct JsonNode* node, char* string) {
    node->type = 's';
    node->data.string = string;
    return 0;
}

int JsonNode_setArray(struct JsonNode* node, struct JsonNode* array) {
    node->type = 'a';
    node->data.array = array;
    return 0;
}

int JsonNode_setObject(struct JsonNode* node, struct JsonNode* object) {
    node->type = 'o';
    node->data.object = object;
    return 0;
}

int main() {
    struct JsonNode* json_node = NULL;
    JsonNode_alloc(&json_node);

    struct JsonNode* new_node = NULL;
    JsonNode_alloc(&new_node);
    JsonNode_insertAfter(json_node, &new_node);

    JsonNode_setNumber(new_node, 10);

    new_node = NULL;
    JsonNode_alloc(&new_node);
    JsonNode_insertAfter(json_node, &new_node);

    JsonNode_setString(new_node, "John Doe");

    new_node = NULL;
    JsonNode_alloc(&new_node);
    JsonNode_insertAfter(json_node, &new_node);

    JsonNode_setObject(new_node, json_node);

    printf("JSON data:\n");
    printf("%s\n", json_node->data.object->data.string);

    JsonNode_free(json_node);

    return 0;
}