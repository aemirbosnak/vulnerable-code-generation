//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 8192

typedef enum {
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOL,
    JSON_NULL,
    JSON_OBJECT,
    JSON_ARRAY
} JsonType;

typedef struct JsonNode {
    JsonType type;
    char *key;
    union {
        char *stringValue;
        double numberValue;
        int boolValue; // 1 for true, 0 for false
        struct JsonNode *objectValue;
        struct JsonNode *arrayValue;
    } value;
    struct JsonNode *next; // For linked representation (lists of items)
} JsonNode;

char *jsonString = NULL;
size_t jsonLength = 0;

void skipWhitespace(size_t *index) {
    while (isspace(jsonString[*index])) {
        (*index)++;
    }
}

void parseString(size_t *index, JsonNode *node) {
    (*index)++; // Skip the opening quote
    size_t start = *index;

    while (jsonString[*index] != '"' && jsonString[*index] != '\0') {
        if (jsonString[*index] == '\\') { // Handle escape characters
            (*index)++; // Skip the escape character
        }
        (*index)++;
    }

    size_t length = *index - start;
    node->value.stringValue = (char *)malloc(length + 1);
    strncpy(node->value.stringValue, jsonString + start, length);
    node->value.stringValue[length] = '\0';
    
    (*index)++; // Skip the closing quote
}

void parseNumber(size_t *index, JsonNode *node) {
    size_t start = *index;

    while (isdigit(jsonString[*index]) || jsonString[*index] == '.' || jsonString[*index] == '-') {
        (*index)++;
    }

    size_t length = *index - start;
    char *numberStr = (char *)malloc(length + 1);
    strncpy(numberStr, jsonString + start, length);
    numberStr[length] = '\0';

    node->value.numberValue = atof(numberStr);
    free(numberStr);
}

void parseBooleanNull(size_t *index, JsonNode *node) {
    if (strncmp(&jsonString[*index], "true", 4) == 0) {
        node->type = JSON_BOOL;
        node->value.boolValue = 1;
        *index += 4;
    } else if (strncmp(&jsonString[*index], "false", 5) == 0) {
        node->type = JSON_BOOL;
        node->value.boolValue = 0;
        *index += 5;
    } else if (strncmp(&jsonString[*index], "null", 4) == 0) {
        node->type = JSON_NULL;
        node->value.stringValue = NULL; // null
        *index += 4;
    }
}

JsonNode *parseJson(size_t *index) {
    JsonNode *node = malloc(sizeof(JsonNode));
    skipWhitespace(index);

    switch (jsonString[*index]) {
        case '"':
            node->type = JSON_STRING;
            parseString(index, node);
            break;
        case '{':
            node->type = JSON_OBJECT; // To be implemented
            break;
        case '[':
            node->type = JSON_ARRAY; // To be implemented
            break;
        default:
            if (isdigit(jsonString[*index]) || jsonString[*index] == '-') {
                node->type = JSON_NUMBER;
                parseNumber(index, node);
            } else {
                node->type = JSON_BOOL; // Assuming it's either true/false or null
                parseBooleanNull(index, node);
            }
    }

    skipWhitespace(index);
    return node;
}

void freeJsonNode(JsonNode *node) {
    if (node->type == JSON_STRING) {
        free(node->value.stringValue);
    }
    free(node);
}

void printJsonNode(JsonNode *node) {
    switch (node->type) {
        case JSON_STRING:
            printf("\"%s\"\n", node->value.stringValue);
            break;
        case JSON_NUMBER:
            printf("%lf\n", node->value.numberValue);
            break;
        case JSON_BOOL:
            printf("%s\n", node->value.boolValue ? "true" : "false");
            break;
        case JSON_NULL:
            printf("null\n");
            break;
        default:
            printf("Unsupported type\n");
    }
}

int main() {
    jsonString = "{\"name\": \"John\", \"age\": 30, \"isStudent\": false, \"courses\": [\"Math\", \"Science\"]}";
    jsonLength = strlen(jsonString);
    size_t index = 0;

    JsonNode *root = parseJson(&index);

    printJsonNode(root);

    freeJsonNode(root);
    return 0;
}