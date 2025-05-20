//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    JSON_STRING,
    JSON_NUMBER,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL
} JsonType;

typedef struct JsonNode {
    JsonType type;
    union {
        char *stringValue;
        double numberValue;
        struct JsonNode **children; // for arrays and objects
    } value;
    size_t childCount; // number of children for objects and arrays
} JsonNode;

void freeJsonNode(JsonNode *node) {
    if (node->type == JSON_STRING) {
        free(node->value.stringValue);
    } else if (node->type == JSON_ARRAY || node->type == JSON_OBJECT) {
        for (size_t i = 0; i < node->childCount; i++) {
            freeJsonNode(node->value.children[i]);
        }
        free(node->value.children);
    }
    free(node);
}

JsonNode *parse_value(const char **str);
JsonNode *parse_object(const char **str);
JsonNode *parse_array(const char **str);
JsonNode *parse_string(const char **str);
JsonNode *parse_number(const char **str);
JsonNode *parse_true(const char **str);
JsonNode *parse_false(const char **str);
JsonNode *parse_null(const char **str);

void skip_whitespace(const char **str) {
    while (isspace(**str)) (*str)++;
}

JsonNode *parse_value(const char **str) {
    skip_whitespace(str);
    if (**str == '{') return parse_object(str);
    if (**str == '[') return parse_array(str);
    if (**str == '"') return parse_string(str);
    if (isdigit(**str) || **str == '-') return parse_number(str);
    if (strncmp(*str, "true", 4) == 0) return parse_true(str);
    if (strncmp(*str, "false", 5) == 0) return parse_false(str);
    if (strncmp(*str, "null", 4) == 0) return parse_null(str);
    return NULL;
}

JsonNode *parse_object(const char **str) {
    JsonNode *node = malloc(sizeof(JsonNode));
    node->type = JSON_OBJECT;
    node->childCount = 0;
    node->value.children = NULL;

    (*str)++; // Skip '{'
    skip_whitespace(str);

    while (**str != '}') {
        if (**str == '\0') {
            freeJsonNode(node);
            return NULL; // unclosed json object
        }

        // Parse key
        JsonNode *keyNode = parse_string(str);
        if (!keyNode) {
            freeJsonNode(node);
            return NULL;
        }

        skip_whitespace(str);
        if (**str != ':') {
            freeJsonNode(keyNode);
            freeJsonNode(node);
            return NULL; // colon missing
        }
        (*str)++; // Skip ':'
        
        // Parse value
        JsonNode *valueNode = parse_value(str);
        if (!valueNode) {
            freeJsonNode(keyNode);
            freeJsonNode(node);
            return NULL; // value parsing error
        }

        // Add key-value pair to node
        node->childCount++;
        node->value.children = realloc(node->value.children, node->childCount * sizeof(JsonNode *));
        node->value.children[node->childCount - 1] = keyNode;
        node->value.children[node->childCount - 1] = valueNode;

        // Optional comma
        skip_whitespace(str);
        if (**str == ',') (*str)++; // Skip ','
        skip_whitespace(str);
    }

    (*str)++; // Skip '}'
    return node;
}

JsonNode *parse_array(const char **str) {
    JsonNode *node = malloc(sizeof(JsonNode));
    node->type = JSON_ARRAY;
    node->childCount = 0;
    node->value.children = NULL;

    (*str)++; // Skip '['
    skip_whitespace(str);
    
    while (**str != ']') {
        if (**str == '\0') {
            freeJsonNode(node);
            return NULL; // unclosed json array
        }

        JsonNode *valueNode = parse_value(str);
        if (!valueNode) {
            freeJsonNode(node);
            return NULL; // value parsing error
        }

        node->childCount++;
        node->value.children = realloc(node->value.children, node->childCount * sizeof(JsonNode *));
        node->value.children[node->childCount - 1] = valueNode;

        skip_whitespace(str);
        if (**str == ',') (*str)++; // Skip ','
        skip_whitespace(str);
    }

    (*str)++; // Skip ']'
    return node;
}

JsonNode *parse_string(const char **str) {
    JsonNode *node = malloc(sizeof(JsonNode));
    node->type = JSON_STRING;

    (*str)++; // Skip '"'
    const char *start = *str;

    while (**str != '"' && **str != '\0') {
        (*str)++;
    }

    size_t length = *str - start;
    node->value.stringValue = malloc(length + 1);
    strncpy(node->value.stringValue, start, length);
    node->value.stringValue[length] = '\0';

    (*str)++; // Skip '"'
    return node;
}

JsonNode *parse_number(const char **str) {
    JsonNode *node = malloc(sizeof(JsonNode));
    node->type = JSON_NUMBER;
    
    char *end;
    node->value.numberValue = strtod(*str, &end);
    *str = end;

    return node;
}

JsonNode *parse_true(const char **str) {
    JsonNode *node = malloc(sizeof(JsonNode));
    node->type = JSON_TRUE;
    (*str) += 4; // Skip "true"
    return node;
}

JsonNode *parse_false(const char **str) {
    JsonNode *node = malloc(sizeof(JsonNode));
    node->type = JSON_FALSE;
    (*str) += 5; // Skip "false"
    return node;
}

JsonNode *parse_null(const char **str) {
    JsonNode *node = malloc(sizeof(JsonNode));
    node->type = JSON_NULL;
    (*str) += 4; // Skip "null"
    return node;
}

void printJsonNode(JsonNode *node, int indent) {
    if (!node) return;

    for (int i = 0; i < indent; i++) printf("  ");
    
    switch (node->type) {
        case JSON_STRING:
            printf("\"%s\"\n", node->value.stringValue);
            break;
        case JSON_NUMBER:
            printf("%f\n", node->value.numberValue);
            break;
        case JSON_OBJECT:
            printf("{\n");
            for (size_t i = 0; i < node->childCount; i++) {
                printJsonNode(node->value.children[i], indent + 1);
            }
            for (int i = 0; i < indent; i++) printf("  ");
            printf("}\n");
            break;
        case JSON_ARRAY:
            printf("[\n");
            for (size_t i = 0; i < node->childCount; i++) {
                printJsonNode(node->value.children[i], indent + 1);
            }
            for (int i = 0; i < indent; i++) printf("  ");
            printf("]\n");
            break;
        case JSON_TRUE:
            printf("true\n");
            break;
        case JSON_FALSE:
            printf("false\n");
            break;
        case JSON_NULL:
            printf("null\n");
            break;
    }
}

int main() {
    const char *jsonStr = "{\"name\": \"John\", \"age\": 30, \"isEmployee\": true, \"address\": null, \"hobbies\": [\"reading\", \"travelling\"]}";
    const char *p = jsonStr;

    JsonNode *jsonNode = parse_value(&p);
    if (jsonNode) {
        printJsonNode(jsonNode, 0);
        freeJsonNode(jsonNode);
    } else {
        printf("Error parsing JSON.\n");
    }

    return 0;
}