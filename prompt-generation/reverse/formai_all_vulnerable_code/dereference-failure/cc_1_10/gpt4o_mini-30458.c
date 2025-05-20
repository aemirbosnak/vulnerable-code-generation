//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 1024
#define MAX_KEY_SIZE 256
#define MAX_VALUE_SIZE 256

typedef enum { JSON_OBJECT, JSON_ARRAY, JSON_STRING, JSON_NUMBER, JSON_BOOL, JSON_NULL } JsonType;

typedef struct JsonNode {
    JsonType type;
    char key[MAX_KEY_SIZE];
    union {
        char strValue[MAX_VALUE_SIZE];
        double numValue;
        int boolValue; // 1 for true, 0 for false
    } value;
    struct JsonNode* next;
    struct JsonNode* child;
} JsonNode;

JsonNode* createJsonNode(JsonType type, const char* key) {
    JsonNode* node = (JsonNode*)malloc(sizeof(JsonNode));
    node->type = type;
    strncpy(node->key, key, MAX_KEY_SIZE);
    node->next = NULL;
    node->child = NULL;
    return node;
}

void addChild(JsonNode* parent, JsonNode* child) {
    if (!parent->child) {
        parent->child = child;
    } else {
        JsonNode* temp = parent->child;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = child;
    }
}

void freeJson(JsonNode* node) {
    if (!node) return;
    freeJson(node->child);
    freeJson(node->next);
    free(node);
}

void parseString(const char** json, JsonNode* parent) {
    const char* start = *json;
    (*json)++; // Skip the opening quote
    while (**json != '"' && **json != '\0') {
        (*json)++;
    }
    strncpy(parent->value.strValue, start + 1, *json - start - 1);
    parent->value.strValue[*json - start - 1] = '\0';
    (*json)++; // Skip closing quote
}

void parseValue(const char** json, JsonNode* parent) {
    if (**json == '"') {
        parent->type = JSON_STRING;
        parseString(json, parent);
    } else if (isdigit(**json) || **json == '-') {
        parent->type = JSON_NUMBER;
        parent->value.numValue = strtod(*json, (char**)json);
    } else if (strncmp(*json, "true", 4) == 0) {
        parent->type = JSON_BOOL;
        parent->value.boolValue = 1;
        (*json) += 4;
    } else if (strncmp(*json, "false", 5) == 0) {
        parent->type = JSON_BOOL;
        parent->value.boolValue = 0;
        (*json) += 5;
    } else if (strncmp(*json, "null", 4) == 0) {
        parent->type = JSON_NULL;
        (*json) += 4;
    }
}

void parseJson(const char* json, JsonNode* root) {
    const char* current = json;
    while (*current) {
        if (isspace(*current)) {
            current++;
            continue;
        }

        if (*current == '{') {
            current++;
            while (*current != '}' && *current != '\0') {
                JsonNode* childNode = createJsonNode(JSON_OBJECT, "");
                char key[MAX_KEY_SIZE] = "";
                sscanf(current, "\"%[^\"]\"", key); // Read key
                current += strlen(key) + 3; // Move past the key and the following ":"
                parseValue(&current, childNode); // Read value
                snprintf(childNode->key, MAX_KEY_SIZE, "%s", key);
                addChild(root, childNode);
                
                if (*current == ',') current++; // Move past the comma
            }
            current++; // Move past '}'
        } else {
            current++;
        }
    }
}

void printJson(JsonNode* node, int indent) {
    if (!node) return;
    for (int i = 0; i < indent; i++) printf("  ");
    printf("{\n");
    
    JsonNode* child = node->child;
    while (child) {
        for (int i = 0; i < indent + 1; i++) printf("  ");
        printf("\"%s\": ", child->key);
        
        switch (child->type) {
            case JSON_STRING:
                printf("\"%s\"\n", child->value.strValue);
                break;
            case JSON_NUMBER:
                printf("%lf\n", child->value.numValue);
                break;
            case JSON_BOOL:
                printf("%s\n", child->value.boolValue ? "true" : "false");
                break;
            case JSON_NULL:
                printf("null\n");
                break;
            default:
                break;
        }

        child = child->next;
    }
    
    for (int i = 0; i < indent; i++) printf("  ");
    printf("}\n");
}

int main() {
    const char* jsonStr = "{\"name\": \"Alice\", \"age\": 30, \"isStudent\": false, \"courses\": [\"Math\", \"Science\"]}";

    JsonNode* root = createJsonNode(JSON_OBJECT, "root");
    parseJson(jsonStr, root);
    printJson(root, 0);
    
    freeJson(root);
    return 0;
}