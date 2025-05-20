//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 4096
#define MAX_KEY_SIZE 256
#define MAX_VALUE_SIZE 256

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOL,
    JSON_NULL
} JsonType;

typedef struct JsonNode {
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
    JsonType type;
    struct JsonNode *next;
    struct JsonNode *child;
} JsonNode;

void skipWhitespace(const char **json) {
    while (**json && (isspace(**json))) (*json)++;
}

JsonNode* createJsonNode() {
    JsonNode *node = (JsonNode *)malloc(sizeof(JsonNode));
    node->key[0] = '\0';
    node->value[0] = '\0';
    node->type = JSON_NULL;
    node->next = NULL;
    node->child = NULL;
    return node;
}

void freeJsonNode(JsonNode *node) {
    if (node) {
        freeJsonNode(node->child); // Free children
        freeJsonNode(node->next);  // Free next sibling
        free(node);
    }
}

JsonNode* parseValue(const char **json);
JsonNode* parseObject(const char **json);
JsonNode* parseArray(const char **json);
JsonNode* parseString(const char **json);
JsonNode* parseNumber(const char **json);
JsonNode* parseBool(const char **json);
JsonNode* parseNull(const char **json);

JsonNode* parseValue(const char **json) {
    skipWhitespace(json);
    JsonNode *node = NULL;

    if (**json == '{') {
        node = parseObject(json);
    } else if (**json == '[') {
        node = parseArray(json);
    } else if (**json == '"') {
        node = parseString(json);
    } else if (isdigit(**json) || **json == '-') {
        node = parseNumber(json);
    } else if (strncmp(*json, "true", 4) == 0 || strncmp(*json, "false", 5) == 0) {
        node = parseBool(json);
    } else if (strncmp(*json, "null", 4) == 0) {
        node = parseNull(json);
    }

    return node;
}

JsonNode* parseObject(const char **json) {
    JsonNode *root = createJsonNode();
    JsonNode *current = root;

    (*json)++; // Skip '{'
    while (**json != '}') {
        skipWhitespace(json);

        // Key
        JsonNode *newNode = createJsonNode();
        newNode->type = JSON_OBJECT;

        if ((newNode->key[0] = parseString(json)->value[0]) == '\0') {
            freeJsonNode(root);
            return NULL;
        }

        skipWhitespace(json); // Skip ':'
        (*json)++;
        newNode->child = parseValue(json);
        if (current->child == NULL) {
            current->child = newNode;
        } else {
            current->next = newNode;
        }
        current = newNode;

        skipWhitespace(json);
        if (**json == ',') (*json)++; // Skip ','
    }
    (*json)++; // Skip '}'
    return root;
}

JsonNode* parseArray(const char **json) {
    JsonNode *root = createJsonNode();
    JsonNode *current = root;

    (*json)++; // Skip '['
    while (**json != ']') {
        JsonNode *newNode = parseValue(json);
        if (current->child == NULL) {
            current->child = newNode;
        } else {
            current->next = newNode;
        }
        current = newNode;

        skipWhitespace(json);
        if (**json == ',') (*json)++; // Skip ','
    }
    (*json)++; // Skip ']'
    return root;
}

JsonNode* parseString(const char **json) {
    JsonNode *node = createJsonNode();
    (*json)++; // Skip the opening '"'
    char *str_start = (char *)*json;
    while (**json != '"' && **json != '\0') (*json)++;
    strncpy(node->value, str_start, *json - str_start);
    node->value[*json - str_start] = '\0';
    node->type = JSON_STRING;
    (*json)++; // Skip closing '"'
    return node;
}

JsonNode* parseNumber(const char **json) {
    JsonNode *node = createJsonNode();
    char *num_start = (char *)*json;

    while (isdigit(**json) || **json == '-' || **json == '.') (*json)++;
    strncpy(node->value, num_start, *json - num_start);
    node->value[*json - num_start] = '\0';
    node->type = JSON_NUMBER;
    return node;
}

JsonNode* parseBool(const char **json) {
    JsonNode *node = createJsonNode();
    if (strncmp(*json, "true", 4) == 0) {
        strcpy(node->value, "true");
        node->type = JSON_BOOL;
        (*json) += 4;
    } else {
        strcpy(node->value, "false");
        node->type = JSON_BOOL;
        (*json) += 5;
    }
    return node;
}

JsonNode* parseNull(const char **json) {
    JsonNode *node = createJsonNode();
    strcpy(node->value, "null");
    node->type = JSON_NULL;
    (*json) += 4;
    return node;
}

void printJson(JsonNode *node, int indent) {
    if (node == NULL) return;
    for (int i = 0; i < indent; i++) printf("  ");
    switch (node->type) {
        case JSON_OBJECT:
            printf("{\n");
            printJson(node->child, indent + 1);
            printf("}\n");
            break;
        case JSON_ARRAY:
            printf("[\n");
            printJson(node->child, indent + 1);
            printf("]\n");
            break;
        case JSON_STRING:
            printf("\"%s\"\n", node->value);
            break;
        case JSON_NUMBER:
            printf("%s\n", node->value);
            break;
        case JSON_BOOL:
            printf("%s\n", node->value);
            break;
        case JSON_NULL:
            printf("null\n");
            break;
    }
    printJson(node->next, indent);
}

int main() {
    const char *json_str = "{\"name\": \"John\", \"age\": 30, \"is_alive\": true, \"children\": [\"Jane\", \"Doe\"], \"address\": null}";
    const char *json = json_str;

    JsonNode *root = parseValue(&json);
    if (root) {
        printJson(root, 0);
        freeJsonNode(root);
    } else {
        printf("Failed to parse JSON\n");
    }
    return 0;
}