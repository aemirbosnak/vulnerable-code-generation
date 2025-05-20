//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} json_pair;

typedef struct {
    int size;
    json_pair *pairs;
} json_object;

json_object *json_parse(char *str) {
    json_object *obj = malloc(sizeof(json_object));
    obj->size = 0;
    obj->pairs = NULL;

    char *curr = str;
    while (*curr != '\0') {
        // Skip whitespace
        while (*curr == ' ') {
            curr++;
        }

        // Check for empty object
        if (*curr == '}') {
            return obj;
        }

        // Parse key
        char *key_start = curr;
        while (*curr != ':' && *curr != '\0') {
            curr++;
        }
        int key_len = curr - key_start;
        char *key = malloc(key_len + 1);
        memcpy(key, key_start, key_len);
        key[key_len] = '\0';

        // Skip colon
        if (*curr == ':') {
            curr++;
        }

        // Parse value
        char *value_start = curr;
        while (*curr != ',' && *curr != '}' && *curr != '\0') {
            curr++;
        }
        int value_len = curr - value_start;
        char *value = malloc(value_len + 1);
        memcpy(value, value_start, value_len);
        value[value_len] = '\0';

        // Add pair to object
        json_pair pair;
        pair.key = key;
        pair.value = value;
        obj->pairs = realloc(obj->pairs, (obj->size + 1) * sizeof(json_pair));
        obj->pairs[obj->size] = pair;
        obj->size++;

        // Skip comma
        if (*curr == ',') {
            curr++;
        }
    }

    return obj;
}

void json_free(json_object *obj) {
    for (int i = 0; i < obj->size; i++) {
        free(obj->pairs[i].key);
        free(obj->pairs[i].value);
    }
    free(obj->pairs);
    free(obj);
}

int main() {
    char *json = "{\"name\": \"John Doe\", \"age\": 30}";
    json_object *obj = json_parse(json);

    for (int i = 0; i < obj->size; i++) {
        printf("%s: %s\n", obj->pairs[i].key, obj->pairs[i].value);
    }

    json_free(obj);

    return 0;
}