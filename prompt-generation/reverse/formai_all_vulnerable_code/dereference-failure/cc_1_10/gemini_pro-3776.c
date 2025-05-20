//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} JSONPair;

typedef struct {
    size_t size;
    size_t capacity;
    JSONPair *pairs;
} JSONObject;

JSONObject *JSONObject_new() {
    JSONObject *object = malloc(sizeof(JSONObject));
    object->size = 0;
    object->capacity = 10;
    object->pairs = malloc(sizeof(JSONPair) * object->capacity);
    return object;
}

void JSONObject_free(JSONObject *object) {
    for (size_t i = 0; i < object->size; i++) {
        free(object->pairs[i].key);
        free(object->pairs[i].value);
    }
    free(object->pairs);
    free(object);
}

void JSONObject_add(JSONObject *object, char *key, char *value) {
    if (object->size == object->capacity) {
        object->capacity *= 2;
        object->pairs = realloc(object->pairs, sizeof(JSONPair) * object->capacity);
    }
    object->pairs[object->size].key = strdup(key);
    object->pairs[object->size].value = strdup(value);
    object->size++;
}

char *JSONObject_get(JSONObject *object, char *key) {
    for (size_t i = 0; i < object->size; i++) {
        if (strcmp(object->pairs[i].key, key) == 0) {
            return object->pairs[i].value;
        }
    }
    return NULL;
}

void JSONParser_parse(char *json, JSONObject *object) {
    char *key = NULL;
    char *value = NULL;
    char *start = json;
    char *end = json;
    while (*end != '\0') {
        if (*end == ':') {
            key = strndup(start, end - start);
            start = end + 1;
        } else if (*end == ',') {
            value = strndup(start, end - start);
            JSONObject_add(object, key, value);
            free(key);
            free(value);
            key = NULL;
            value = NULL;
            start = end + 1;
        }
        end++;
    }
    value = strndup(start, end - start);
    JSONObject_add(object, key, value);
    free(key);
    free(value);
}

int main() {
    char *json = "{ \"name\": \"John Doe\", \"age\": 30, \"city\": \"New York\" }";
    JSONObject *object = JSONObject_new();
    JSONParser_parse(json, object);
    printf("Name: %s\n", JSONObject_get(object, "name"));
    printf("Age: %s\n", JSONObject_get(object, "age"));
    printf("City: %s\n", JSONObject_get(object, "city"));
    JSONObject_free(object);
    return 0;
}