//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JsonNode {
    char *key;
    char *value;
    struct JsonNode *next;
} JsonNode;

typedef struct JsonObject {
    JsonNode *head;
} JsonObject;

void skipWhitespace(const char **json) {
    while (isspace(**json)) (*json)++;
}

void parseKeyValue(const char **json, JsonObject *obj) {
    JsonNode *node = (JsonNode *)malloc(sizeof(JsonNode));
    node->key = NULL;
    node->value = NULL;
    node->next = NULL;

    skipWhitespace(json);
    if (**json != '\"') return;

    (*json)++; // skip the opening quote
    const char *start = *json; 
    while (**json != '\"') (*json)++;

    size_t keyLength = *json - start;
    node->key = (char *)malloc(keyLength + 1);
    strncpy(node->key, start, keyLength);
    node->key[keyLength] = '\0';
    
    (*json)++; // skip the closing quote

    skipWhitespace(json);
    if (**json != ':') return;
    
    (*json)++; // skip the colon
    skipWhitespace(json);
    
    if (**json != '\"') return;

    (*json)++; // skip the opening quote
    start = *json; 
    while (**json != '\"') (*json)++;

    size_t valueLength = *json - start;
    node->value = (char *)malloc(valueLength + 1);
    strncpy(node->value, start, valueLength);
    node->value[valueLength] = '\0';

    (*json)++; // skip the closing quote

    if (obj->head == NULL) {
        obj->head = node;
    } else {
        JsonNode *current = obj->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

JsonObject *parseJson(const char *json) {
    JsonObject *obj = (JsonObject *)malloc(sizeof(JsonObject));
    obj->head = NULL;
    
    skipWhitespace(&json);
    
    if (*json != '{') return NULL; // Invalid JSON

    json++; // skip '{'
    while (*json) {
        skipWhitespace(&json);
        if (*json == '}') {
            json++; // skip '}'
            break;
        }
        
        parseKeyValue(&json, obj);
        
        skipWhitespace(&json);
        if (*json == ',') {
            json++; // skip ','
        } else if (*json == '}') {
            json++; // skip '}'
            break;
        } else {
            break; // Invalid JSON
        }
    }
    
    return obj;
}

void freeJsonObject(JsonObject *obj) {
    JsonNode *current = obj->head;
    while (current) {
        JsonNode *next = current->next;
        free(current->key);
        free(current->value);
        free(current);
        current = next;
    }
    free(obj);
}

void printJsonObject(JsonObject *obj) {
    JsonNode *current = obj->head;
    while (current) {
        printf("Key: %s, Value: %s\n", current->key, current->value);
        current = current->next;
    }
}

int main() {
    const char *jsonString = "{\"name\":\"John\",\"age\":\"30\",\"city\":\"New York\"}";
    
    JsonObject *jsonObject = parseJson(jsonString);
    if (jsonObject) {
        printJsonObject(jsonObject);
        freeJsonObject(jsonObject);
    } else {
        printf("Failed to parse JSON.\n");
    }
    
    return 0;
}