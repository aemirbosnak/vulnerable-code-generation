//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_LENGTH 256
#define MAX_JSON_LENGTH 1024

typedef enum {
    JSON_NULL,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NUMBER,
    JSON_STRING,
    JSON_OBJECT,
    JSON_ARRAY
} JsonType;

typedef struct JsonNode {
    JsonType type;
    union {
        double number;
        char string[MAX_TOKEN_LENGTH];
        struct JsonNode* object;
        struct JsonNode* array;
    } value;
    struct JsonNode* next;
} JsonNode;

void skipWhitespace(const char **json) {
    while (**json && isspace(**json)) {
        (*json)++;
    }
}

JsonNode* createNode(JsonType type) {
    JsonNode* node = (JsonNode*)malloc(sizeof(JsonNode));
    node->type = type;
    node->next = NULL;
    return node;
}

void parseString(const char **json, JsonNode *node) {
    const char *start = ++(*json); // Skip initial quote
    while (**json && **json != '"') {
        if (**json == '\\') (*json)++; // Skip escape character
        (*json)++;
    }
    size_t length = *json - start;
    strncpy(node->value.string, start, length);
    node->value.string[length] = '\0'; // Null-terminate
    (*json)++; // Skip closing quote
}

void parseNumber(const char **json, JsonNode *node) {
    char *end;
    node->value.number = strtod(*json, &end);
    *json = end; // Move past the number
}

JsonNode* parseJson(const char **json);

JsonNode* parseObject(const char **json) {
    JsonNode *head = NULL, *tail = NULL;
    (*json)++; // Skip '{'
    skipWhitespace(json);
    
    while (**json && **json != '}') {
        JsonNode *keyNode = createNode(JSON_STRING);
        parseString(json, keyNode);
        
        skipWhitespace(json);
        if (**json != ':') {
            printf("Error: Expected ':' after key\n");
            return NULL;
        }
        (*json)++; // Skip ':'
        
        skipWhitespace(json);
        JsonNode *valueNode = parseJson(json);
        if (!valueNode) {
            printf("Error: Invalid JSON value\n");
            return NULL;
        }
        
        // Link nodes in the linked list
        if (!head) {
            head = tail = keyNode;
        } else {
            tail->next = keyNode;
            tail = keyNode;
        }
        tail->next = valueNode;
        
        skipWhitespace(json);
        if (**json == ',') {
            (*json)++;
            skipWhitespace(json);
        }
    }
    (*json)++; // Skip '}'
    return head;
}

JsonNode* parseArray(const char **json) {
    JsonNode *head = NULL, *tail = NULL;
    (*json)++; // Skip '['
    skipWhitespace(json);
    
    while (**json && **json != ']') {
        JsonNode *valueNode = parseJson(json);
        if (!valueNode) {
            printf("Error: Invalid JSON value\n");
            return NULL;
        }
        
        if (!head) {
            head = tail = valueNode;
        } else {
            tail->next = valueNode;
            tail = valueNode;
        }
        
        skipWhitespace(json);
        if (**json == ',') {
            (*json)++;
            skipWhitespace(json);
        }
    }
    (*json)++; // Skip ']'
    return head;
}

JsonNode* parseJson(const char **json) {
    skipWhitespace(json);
    if (**json == '"') {
        JsonNode *node = createNode(JSON_STRING);
        parseString(json, node);
        return node;
    } else if (isdigit(**json) || **json == '-') {
        JsonNode *node = createNode(JSON_NUMBER);
        parseNumber(json, node);
        return node;
    } else if (strncmp(*json, "true", 4) == 0) {
        (*json) += 4;
        JsonNode *node = createNode(JSON_TRUE);
        return node;
    } else if (strncmp(*json, "false", 5) == 0) {
        (*json) += 5;
        JsonNode *node = createNode(JSON_FALSE);
        return node;
    } else if (strncmp(*json, "null", 4) == 0) {
        (*json) += 4;
        JsonNode *node = createNode(JSON_NULL);
        return node;
    } else if (**json == '{') {
        return parseObject(json);
    } else if (**json == '[') {
        return parseArray(json);
    }
    return NULL; // Invalid JSON
}

void printJson(JsonNode* node) {
    if (!node) return;
    if (node->type == JSON_STRING) {
        printf("\"%s\"", node->value.string);
    } else if (node->type == JSON_NUMBER) {
        printf("%f", node->value.number);
    } else if (node->type == JSON_TRUE) {
        printf("true");
    } else if (node->type == JSON_FALSE) {
        printf("false");
    } else if (node->type == JSON_NULL) {
        printf("null");
    } else if (node->type == JSON_OBJECT) {
        // Handle objects
    } else if (node->type == JSON_ARRAY) {
        // Handle arrays
    }
    // Print the next element in JSON
    printJson(node->next);
}

int main() {
    const char *jsonString = "{\"name\":\"John\", \"age\":30, \"isStudent\":false, \"courses\":[\"Math\", \"Science\"]}";
    const char *json = jsonString;
    
    JsonNode *parsedJson = parseJson(&json);
    if (parsedJson) {
        printf("Parsed JSON:\n");
        printJson(parsedJson);
    } else {
        printf("Failed to parse JSON\n");
    }
    
    // Free memory logic should go here for all allocated nodes
    return 0;
}