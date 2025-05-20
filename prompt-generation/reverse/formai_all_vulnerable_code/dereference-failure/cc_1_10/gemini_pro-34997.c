//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} json_pair;

typedef struct {
    int size;
    int capacity;
    json_pair *pairs;
} json_object;

json_object *json_object_new(void) {
    json_object *object = malloc(sizeof(json_object));
    object->size = 0;
    object->capacity = 10;
    object->pairs = malloc(sizeof(json_pair) * object->capacity);
    return object;
}

void json_object_free(json_object *object) {
    for (int i = 0; i < object->size; i++) {
        free(object->pairs[i].key);
        free(object->pairs[i].value);
    }
    free(object->pairs);
    free(object);
}

int json_object_add(json_object *object, const char *key, const char *value) {
    if (object->size == object->capacity) {
        object->capacity *= 2;
        object->pairs = realloc(object->pairs, sizeof(json_pair) * object->capacity);
    }
    object->pairs[object->size].key = strdup(key);
    object->pairs[object->size].value = strdup(value);
    object->size++;
    return 0;
}

char *json_object_get(json_object *object, const char *key) {
    for (int i = 0; i < object->size; i++) {
        if (strcmp(object->pairs[i].key, key) == 0) {
            return object->pairs[i].value;
        }
    }
    return NULL;
}

int main(void) {
    json_object *object = json_object_new();
    json_object_add(object, "name", "John Doe");
    json_object_add(object, "age", "30");
    printf("Name: %s\n", json_object_get(object, "name"));
    printf("Age: %s\n", json_object_get(object, "age"));
    json_object_free(object);
    return 0;
}