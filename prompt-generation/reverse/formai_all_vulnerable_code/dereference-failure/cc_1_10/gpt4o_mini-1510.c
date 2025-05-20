//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JSONNode {
    char *key;
    char *value;
    struct JSONNode *next;
} JSONNode;

typedef struct JSONObject {
    JSONNode *head;
} JSONObject;

JSONObject *createJSONObject() {
    JSONObject *obj = (JSONObject *)malloc(sizeof(JSONObject));
    obj->head = NULL;
    return obj;
}

void addKeyValue(JSONObject *obj, const char *key, const char *value) {
    JSONNode *newNode = (JSONNode *)malloc(sizeof(JSONNode));
    newNode->key = strdup(key);
    newNode->value = strdup(value);
    newNode->next = obj->head;
    obj->head = newNode;
}

void freeJSONObject(JSONObject *obj) {
    JSONNode *current = obj->head;
    JSONNode *tmp;
    while (current) {
        tmp = current;
        current = current->next;
        free(tmp->key);
        free(tmp->value);
        free(tmp);
    }
    free(obj);
}

void printJSONObject(const JSONObject *obj) {
    JSONNode *current = obj->head;
    printf("{\n");
    while (current) {
        printf("  \"%s\": \"%s\"", current->key, current->value);
        current = current->next;
        if (current) {
            printf(",");
        }
        printf("\n");
    }
    printf("}\n");
}

void skipWhitespace(const char **json) {
    while (**json && isspace(**json)) {
        (*json)++;
    }
}

char *parseString(const char **json) {
    const char *start = ++(*json); // skip opening quote
    while (**json && **json != '"') {
        (*json)++;
    }
    size_t length = *json - start;
    char *str = (char *)malloc(length + 1);
    strncpy(str, start, length);
    str[length] = '\0';
    (*json)++; // skip closing quote
    return str;
}

JSONObject *parseJSON(const char *json) {
    JSONObject *obj = createJSONObject();
    skipWhitespace(&json);
    if (*json != '{') return NULL; // expected opening brace
    json++; // skip '{'
    skipWhitespace(&json);
    
    while (*json) {
        skipWhitespace(&json);
        if (*json == '}') break; // end of object
        char *key = parseString(&json);
        skipWhitespace(&json);
        if (*json != ':') {
            free(key);
            freeJSONObject(obj);
            return NULL; // expected colon
        }
        json++; // skip ':'
        skipWhitespace(&json);
        char *value = parseString(&json);
        addKeyValue(obj, key, value);
        free(key);
        
        skipWhitespace(&json);
        if (*json == ',') json++; // skip comma
        
        skipWhitespace(&json);
    }
    
    if (*json != '}') {
        freeJSONObject(obj);
        return NULL; // expected closing brace
    }
    json++; // skip '}'
    
    return obj;
}

int main() {
    const char *jsonData = "{\"name\": \"John\", \"age\": \"30\", \"city\": \"New York\"}";
    JSONObject *jsonObject = parseJSON(jsonData);
    
    if (jsonObject) {
        printJSONObject(jsonObject);
        freeJSONObject(jsonObject);
    } else {
        printf("Error parsing JSON\n");
    }
    
    return 0;
}