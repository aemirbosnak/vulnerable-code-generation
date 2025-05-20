//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Cyberpunk-style JSON parser

typedef struct {
    char *key;
    char *value;
} json_pair;

typedef struct {
    int size;
    int capacity;
    json_pair *pairs;
} json_object;

json_object *json_new() {
    json_object *object = malloc(sizeof(json_object));
    object->size = 0;
    object->capacity = 16;
    object->pairs = malloc(sizeof(json_pair) * object->capacity);
    return object;
}

void json_free(json_object *object) {
    for (int i = 0; i < object->size; i++) {
        free(object->pairs[i].key);
        free(object->pairs[i].value);
    }
    free(object->pairs);
    free(object);
}

void json_add_pair(json_object *object, char *key, char *value) {
    if (object->size == object->capacity) {
        object->capacity *= 2;
        object->pairs = realloc(object->pairs, sizeof(json_pair) * object->capacity);
    }
    object->pairs[object->size].key = key;
    object->pairs[object->size].value = value;
    object->size++;
}

char *json_get_value(json_object *object, char *key) {
    for (int i = 0; i < object->size; i++) {
        if (strcmp(object->pairs[i].key, key) == 0) {
            return object->pairs[i].value;
        }
    }
    return NULL;
}

int main() {
    // Parse a JSON string
    char *json_string = "{ \"name\": \"John Doe\", \"age\": 30, \"city\": \"New York\" }";

    // Create a new JSON object
    json_object *object = json_new();

    // Parse the JSON string and add the pairs to the object
    char *token = strtok(json_string, "\" ,:{}");
    while (token != NULL) {
        if (strcmp(token, "name") == 0 || strcmp(token, "age") == 0 || strcmp(token, "city") == 0) {
            char *key = token;
            token = strtok(NULL, "\" ,:{}");
            char *value = token;
            json_add_pair(object, key, value);
        }
        token = strtok(NULL, "\" ,:{}");
    }

    // Get the value of the "name" key
    char *name = json_get_value(object, "name");

    // Print the value of the "name" key
    printf("Name: %s\n", name);

    // Free the JSON object
    json_free(object);

    return 0;
}