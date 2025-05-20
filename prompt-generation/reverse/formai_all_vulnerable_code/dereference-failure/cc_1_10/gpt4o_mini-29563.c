//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_LENGTH 2048
#define MAX_KEY_LENGTH 128
#define MAX_VALUE_LENGTH 128

typedef struct JsonNode {
    char key[MAX_KEY_LENGTH];
    char value[MAX_VALUE_LENGTH];
    struct JsonNode* next;
} JsonNode;

JsonNode* parseJson(const char** json);
void trimWhitespace(const char** str);
int parseKeyValue(const char** json, JsonNode* node);
int parseString(const char** json, char* value);
int parseNumber(const char** json, char* value);
void printJson(JsonNode* node);
void freeJson(JsonNode* node);

int main() {
    const char* jsonInput = "{\"name\": \"John\", \"age\": 30, \"city\": \"New York\"}";
    JsonNode* jsonData = parseJson(&jsonInput);
    printJson(jsonData);
    freeJson(jsonData);
    return 0;
}

JsonNode* parseJson(const char** json) {
    JsonNode* head = NULL;
    JsonNode* current = NULL;

    while (**json != '\0' && **json != '}') {
        trimWhitespace(json);
        if (**json == '{') (*json)++;

        JsonNode* newNode = (JsonNode*)malloc(sizeof(JsonNode));
        if (parseKeyValue(json, newNode)) {
            newNode->next = NULL;
            if (head == NULL) {
                head = newNode;
                current = newNode;
            } else {
                current->next = newNode;
                current = newNode;
            }
        }
        trimWhitespace(json);
        if (**json == ',') (*json)++;
    }

    return head;
}

void trimWhitespace(const char** str) {
    while (isspace(**str)) (*str)++;
}

int parseKeyValue(const char** json, JsonNode* node) {
    if (!parseString(json, node->key)) {
        free(node);
        return 0;
    }
    trimWhitespace(json);
    if (**json != ':') {
        free(node);
        return 0;
    }
    (*json)++; // consume ':'
    trimWhitespace(json);
    if (!parseString(json, node->value) && !parseNumber(json, node->value)) {
        free(node);
        return 0;
    }
    return 1;
}

int parseString(const char** json, char* value) {
    if (**json != '"') return 0;
    (*json)++; // consume starting quote
    const char* start = *json;
    while (**json != '"' && **json != '\0') {
        (*json)++;
    }
    if (**json == '"') {
        size_t length = *json - start;
        strncpy(value, start, length);
        value[length] = '\0'; // null-terminate
        (*json)++; // consume ending quote
        return 1;
    }
    return 0;
}

int parseNumber(const char** json, char* value) {
    const char* start = *json;
    while (isdigit(**json)) {
        (*json)++;
    }
    if (start != *json) {
        size_t length = *json - start;
        strncpy(value, start, length);
        value[length] = '\0'; // null-terminate
        return 1;
    }
    return 0;
}

void printJson(JsonNode* node) {
    printf("{\n");
    while (node) {
        printf("  \"%s\": \"%s\"", node->key, node->value);
        if (node->next) {
            printf(",");
        }
        printf("\n");
        node = node->next;
    }
    printf("}\n");
}

void freeJson(JsonNode* node) {
    while (node) {
        JsonNode* temp = node;
        node = node->next;
        free(temp);
    }
}