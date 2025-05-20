//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct JsonValue {
    char *key;
    char *value;
    struct JsonValue *next;
} JsonValue;

typedef struct JsonObject {
    JsonValue *head;
} JsonObject;

JsonObject* createJsonObject() {
    JsonObject *obj = (JsonObject *)malloc(sizeof(JsonObject));
    obj->head = NULL;
    return obj;
}

JsonValue* createJsonValue(const char *key, const char *value) {
    JsonValue *newValue = (JsonValue *)malloc(sizeof(JsonValue));
    newValue->key = strdup(key);
    newValue->value = strdup(value);
    newValue->next = NULL;
    return newValue;
}

void addJsonValue(JsonObject *obj, const char *key, const char *value) {
    JsonValue *newValue = createJsonValue(key, value);
    newValue->next = obj->head;
    obj->head = newValue;
}

char* findJsonValue(JsonObject *obj, const char *key) {
    JsonValue *current = obj->head;
    while (current) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

void freeJsonObject(JsonObject *obj) {
    JsonValue *current = obj->head;
    JsonValue *next;

    while (current) {
        next = current->next;
        free(current->key);
        free(current->value);
        free(current);
        current = next;
    }
    free(obj);
}

void parseJson(const char *jsonString, JsonObject *obj) {
    const char *pos = jsonString;
    char key[256], value[256];
    
    while (*pos) {
        // Skip white spaces or braces
        while (*pos == ' ' || *pos == '{' || *pos == '}' || *pos == ',') pos++;
        if (*pos == '"') {
            pos++; // skip opening quote
            char *kptr = key;
            while (*pos != '"') {
                *kptr++ = *pos++;
            }
            *kptr = '\0';
            pos++; // skip closing quote

            // Skip ':' character
            while (*pos == ' ' || *pos == ':') pos++;
            if (*pos == '"') {
                pos++; // skip opening quote
                char *vptr = value;
                while (*pos != '"') {
                    *vptr++ = *pos++;
                }
                *vptr = '\0';
                pos++; // skip closing quote
                addJsonValue(obj, key, value);
            }
        }
    }
}

void printJsonObject(JsonObject *obj) {
    JsonValue *current = obj->head;
    while (current) {
        printf("\"%s\": \"%s\"\n", current->key, current->value);
        current = current->next;
    }
}

int main() {
    JsonObject *jsonObj = createJsonObject();
    
    const char *jsonString = "{\"name\": \"John\", \"age\": \"30\", \"city\": \"New York\"}";
    parseJson(jsonString, jsonObj);
    
    printf("Parsed JSON Values:\n");
    printJsonObject(jsonObj);

    char *value = findJsonValue(jsonObj, "age");
    if (value) {
        printf("Found value for 'age': %s\n", value);
    } else {
        printf("Key 'age' not found.\n");
    }

    freeJsonObject(jsonObj);
    return 0;
}