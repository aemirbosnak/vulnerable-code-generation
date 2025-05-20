//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JSONValue {
    char *key;
    char *value;
    struct JSONValue *next;
} JSONValue;

typedef struct JSONObject {
    JSONValue *head;
} JSONObject;

JSONObject *createJSONObject() {
    JSONObject *json = malloc(sizeof(JSONObject));
    json->head = NULL;
    return json;
}

void freeJSONObject(JSONObject *json) {
    JSONValue *current = json->head;
    while (current) {
        JSONValue *next = current->next;
        free(current->key);
        free(current->value);
        free(current);
        current = next;
    }
    free(json);
}

void skipWhitespace(const char **jsonStr) {
    while (isspace(**jsonStr)) {
        (*jsonStr)++;
    }
}

char *extractString(const char **jsonStr) {
    skipWhitespace(jsonStr);
    if (**jsonStr != '\"') return NULL;

    (*jsonStr)++;
    const char *start = *jsonStr;

    while (**jsonStr && **jsonStr != '\"') {
        if (**jsonStr == '\\') {
            (*jsonStr)++; // Skip the escape character
        }
        (*jsonStr)++;
    }

    if (**jsonStr != '\"') return NULL;

    size_t length = *jsonStr - start;
    char *result = malloc(length + 1);
    strncpy(result, start, length);
    result[length] = '\0';

    (*jsonStr)++; // Skip the closing quote
    return result;
}

void addKeyValue(JSONObject *json, const char *key, const char *value) {
    JSONValue *newValue = malloc(sizeof(JSONValue));
    newValue->key = strdup(key);
    newValue->value = strdup(value);
    newValue->next = json->head;
    json->head = newValue;
}

void parseJSONObject(JSONObject *json, const char **jsonStr) {
    skipWhitespace(jsonStr);

    if (**jsonStr != '{') return;

    (*jsonStr)++;
    while (1) {
        skipWhitespace(jsonStr);
        char *key = extractString(jsonStr);
        if (!key) break;

        skipWhitespace(jsonStr);
        if (**jsonStr != ':') {
            free(key);
            break;
        }

        (*jsonStr)++; // Skip ':'
        char *value = extractString(jsonStr);
        if (!value) {
            free(key);
            break;
        }

        addKeyValue(json, key, value);
        free(key);
        free(value);

        skipWhitespace(jsonStr);
        if (**jsonStr == ',') {
            (*jsonStr)++; // Skip ','
            continue;
        } else if (**jsonStr == '}') {
            (*jsonStr)++; // Skip '}'
            break;
        } else {
            break;
        }
    }
}

void printJSONObject(JSONObject *json) {
    JSONValue *current = json->head;
    printf("{\n");
    while (current) {
        printf("  \"%s\": \"%s\"", current->key, current->value);
        current = current->next;
        if (current) {
            printf(",\n");
        }
    }
    printf("\n}\n");
}

int main() {
    const char *jsonStr = "{\"name\":\"John\", \"age\":\"30\", \"city\":\"New York\"}";
    JSONObject *json = createJSONObject();

    parseJSONObject(json, &jsonStr);
    printJSONObject(json);

    freeJSONObject(json);
    return 0;
}