//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} key_value_pair;

typedef struct {
    key_value_pair *pairs;
    int num_pairs;
    int capacity;
} json_object;

json_object *json_object_new() {
    json_object *obj = malloc(sizeof(json_object));
    obj->pairs = NULL;
    obj->num_pairs = 0;
    obj->capacity = 0;
    return obj;
}

void json_object_free(json_object *obj) {
    for (int i = 0; i < obj->num_pairs; i++) {
        free(obj->pairs[i].key);
        free(obj->pairs[i].value);
    }
    free(obj->pairs);
    free(obj);
}

void json_object_add_pair(json_object *obj, char *key, char *value) {
    if (obj->num_pairs == obj->capacity) {
        obj->capacity = obj->capacity == 0 ? 1 : obj->capacity * 2;
        obj->pairs = realloc(obj->pairs, sizeof(key_value_pair) * obj->capacity);
    }
    obj->pairs[obj->num_pairs].key = strdup(key);
    obj->pairs[obj->num_pairs].value = strdup(value);
    obj->num_pairs++;
}

char *json_object_to_string(json_object *obj) {
    char *str = malloc(1);
    *str = '\0';
    for (int i = 0; i < obj->num_pairs; i++) {
        char *pair = malloc(strlen(obj->pairs[i].key) + strlen(obj->pairs[i].value) + 3);
        sprintf(pair, "\"%s\": \"%s\"", obj->pairs[i].key, obj->pairs[i].value);
        str = realloc(str, strlen(str) + strlen(pair) + 1);
        strcat(str, pair);
        free(pair);
        if (i < obj->num_pairs - 1) {
            strcat(str, ", ");
        }
    }
    char *final = malloc(strlen(str) + 3);
    sprintf(final, "{%s}", str);
    free(str);
    return final;
}

int main() {
    json_object *obj = json_object_new();
    json_object_add_pair(obj, "name", "John Doe");
    json_object_add_pair(obj, "age", "30");
    json_object_add_pair(obj, "occupation", "Software Engineer");
    char *json_str = json_object_to_string(obj);
    printf("%s\n", json_str);
    free(json_str);
    json_object_free(obj);
    return 0;
}