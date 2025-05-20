//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} json_pair;

typedef struct {
    int count;
    json_pair **pairs;
} json_object;

typedef struct {
    int count;
    json_object **objects;
} json_array;

json_object *json_parse_object(char *json) {
    json_object *object = malloc(sizeof(json_object));
    object->count = 0;
    object->pairs = NULL;

    char *start = json;
    while (*start != '\0') {
        char *key = start;
        while (*start != ':' && *start != '\0') {
            start++;
        }
        *start = '\0';
        start++;

        char *value = start;
        while (*start != ',' && *start != '}' && *start != '\0') {
            start++;
        }
        *start = '\0';
        start++;

        json_pair *pair = malloc(sizeof(json_pair));
        pair->key = key;
        pair->value = value;

        object->pairs = realloc(object->pairs, (object->count + 1) * sizeof(json_pair *));
        object->pairs[object->count++] = pair;
    }

    return object;
}

json_array *json_parse_array(char *json) {
    json_array *array = malloc(sizeof(json_array));
    array->count = 0;
    array->objects = NULL;

    char *start = json;
    while (*start != '\0') {
        char *object_start = start;
        while (*start != '}' && *start != '\0') {
            start++;
        }
        *start = '\0';
        start++;

        json_object *object = json_parse_object(object_start);

        array->objects = realloc(array->objects, (array->count + 1) * sizeof(json_object *));
        array->objects[array->count++] = object;
    }

    return array;
}

void json_print_object(json_object *object) {
    printf("{");
    for (int i = 0; i < object->count; i++) {
        printf("\"%s\": \"%s\"", object->pairs[i]->key, object->pairs[i]->value);
        if (i < object->count - 1) {
            printf(", ");
        }
    }
    printf("}");
}

void json_print_array(json_array *array) {
    printf("[");
    for (int i = 0; i < array->count; i++) {
        json_print_object(array->objects[i]);
        if (i < array->count - 1) {
            printf(", ");
        }
    }
    printf("]");
}

int main() {
    char *json = "{ \"name\": \"Alan Turing\", \"age\": 41, \"occupation\": \"computer scientist\" }";
    json_object *object = json_parse_object(json);
    json_print_object(object);
    printf("\n");

    json = "[{ \"name\": \"Alan Turing\", \"age\": 41, \"occupation\": \"computer scientist\" },{ \"name\": \"Ada Lovelace\", \"age\": 36, \"occupation\": \"computer programmer\" }]";
    json_array *array = json_parse_array(json);
    json_print_array(array);
    printf("\n");

    return 0;
}