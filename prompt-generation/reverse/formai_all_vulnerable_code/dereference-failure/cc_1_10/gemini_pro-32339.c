//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: retro
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} json_pair;

typedef struct {
    json_pair *pairs;
    int num_pairs;
} json_object;

json_object *json_parse(const char *json) {
    json_object *obj = malloc(sizeof(json_object));
    obj->pairs = NULL;
    obj->num_pairs = 0;

    char *start = (char *)json;
    while (*start != '\0') {
        // Skip whitespace
        while (*start == ' ' || *start == '\t' || *start == '\n' || *start == '\r') {
            start++;
        }

        // Check for the start of a pair
        if (*start != '"') {
            break;
        }

        // Parse the key
        char *key_start = start + 1;
        char *key_end = strchr(start + 1, '"');
        if (key_end == NULL) {
            break;
        }
        int key_length = key_end - key_start;
        char *key = malloc(key_length + 1);
        memcpy(key, key_start, key_length);
        key[key_length] = '\0';

        // Skip the colon
        start = key_end + 1;
        while (*start == ' ' || *start == '\t' || *start == '\n' || *start == '\r') {
            start++;
        }
        if (*start != ':') {
            free(key);
            break;
        }

        // Parse the value
        char *value_start = start + 1;
        char *value_end = NULL;
        switch (*value_start) {
            case '"':
                value_end = strchr(value_start + 1, '"');
                break;
            case '{':
                value_end = strchr(value_start + 1, '}');
                break;
            case '[':
                value_end = strchr(value_start + 1, ']');
                break;
        }
        if (value_end == NULL) {
            free(key);
            break;
        }
        int value_length = value_end - value_start;
        char *value = malloc(value_length + 1);
        memcpy(value, value_start, value_length);
        value[value_length] = '\0';

        // Add the pair to the object
        obj->pairs = realloc(obj->pairs, (obj->num_pairs + 1) * sizeof(json_pair));
        obj->pairs[obj->num_pairs].key = key;
        obj->pairs[obj->num_pairs].value = value;
        obj->num_pairs++;

        // Skip the comma
        start = value_end + 1;
        while (*start == ' ' || *start == '\t' || *start == '\n' || *start == '\r') {
            start++;
        }
        if (*start == ',') {
            start++;
        }
    }

    return obj;
}

void json_free(json_object *obj) {
    for (int i = 0; i < obj->num_pairs; i++) {
        free(obj->pairs[i].key);
        free(obj->pairs[i].value);
    }
    free(obj->pairs);
    free(obj);
}

int main() {
    const char *json = "{\"name\": \"John Doe\", \"age\": 30, \"occupation\": \"software engineer\"}";
    json_object *obj = json_parse(json);

    for (int i = 0; i < obj->num_pairs; i++) {
        printf("%s: %s\n", obj->pairs[i].key, obj->pairs[i].value);
    }

    json_free(obj);

    return 0;
}