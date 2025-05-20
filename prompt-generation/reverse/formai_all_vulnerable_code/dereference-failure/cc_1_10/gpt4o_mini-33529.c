//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: brave
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

JSONObject* createJSONObject() {
    JSONObject *obj = (JSONObject *)malloc(sizeof(JSONObject));
    obj->head = NULL;
    return obj;
}

void freeJSONValue(JSONValue *value) {
    if (value) {
        free(value->key);
        free(value->value);
        free(value);
    }
}

void freeJSONObject(JSONObject *obj) {
    if (obj) {
        JSONValue *current = obj->head;
        while (current) {
            JSONValue *next = current->next;
            freeJSONValue(current);
            current = next;
        }
        free(obj);
    }
}

void trimWhitespace(char **json) {
    while (isspace(**json)) (*json)++;
}

char* parseString(char **json) {
    char *start = ++(*json);
    while (**json != '"' && **json != '\0') (*json)++;
    size_t length = *json - start;
    char *string = (char *)malloc(length + 1);
    strncpy(string, start, length);
    string[length] = '\0';
    (*json)++;
    return string;
}

char* parseValue(char **json) {
    trimWhitespace(json);
    if (**json == '"') return parseString(json);
    
    char *start = *json;
    while (**json != ',' && **json != '}' && **json != '\0') (*json)++;
    size_t length = *json - start;

    char *value = (char *)malloc(length + 1);
    strncpy(value, start, length);
    value[length] = '\0';

    return value;
}

void parseJSONObject(char **json, JSONObject *obj) {
    trimWhitespace(json);
    if (**json != '{') return; 
    (*json)++;

    while (**json) {
        trimWhitespace(json);
        if (**json == '}') {
            (*json)++;
            return;
        }

        JSONValue *newValue = (JSONValue *)malloc(sizeof(JSONValue));
        newValue->key = parseString(json);
        trimWhitespace(json);
        if (**json != ':') {
            freeJSONValue(newValue);
            return;
        }
        (*json)++;

        newValue->value = parseValue(json);
        newValue->next = obj->head;
        obj->head = newValue;

        trimWhitespace(json);
        if (**json == ',') (*json)++;
    }
}

void printJSONObject(JSONObject *obj) {
    JSONValue *current = obj->head;
    printf("{\n");
    while (current) {
        printf("\t\"%s\": \"%s\"", current->key, current->value);
        current = current->next;
        if (current) printf(",\n");
        else printf("\n");
    }
    printf("}\n");
}

int main() {
    char jsonString[1024];

    printf("Enter a JSON string:\n");
    fgets(jsonString, sizeof(jsonString), stdin);

    char *jsonPtr = jsonString;
    JSONObject *jsonObject = createJSONObject();
    parseJSONObject(&jsonPtr, jsonObject);
    printf("Parsed JSON:\n");
    printJSONObject(jsonObject);

    freeJSONObject(jsonObject);
    return 0;
}