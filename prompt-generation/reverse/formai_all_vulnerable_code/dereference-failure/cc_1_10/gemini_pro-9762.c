//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: dynamic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} json_pair;

typedef struct {
    json_pair *pairs;
    size_t size;
} json_object;

json_object *json_parse(char *json) {
    json_object *object = malloc(sizeof(json_object));
    object->size = 0;
    object->pairs = NULL;

    char *start = json;
    char *end = json;
    char *key = NULL;
    char *value = NULL;

    while (*end != '\0') {
        if (*end == '"') {
            if (key == NULL) {
                key = start + 1;
            } else {
                value = start + 1;
            }
        } else if (*end == ':' && key != NULL) {
            *end = '\0';
            json_pair pair;
            pair.key = key;
            pair.value = value;
            object->pairs = realloc(object->pairs, sizeof(json_pair) * (object->size + 1));
            object->pairs[object->size++] = pair;
            key = NULL;
            value = NULL;
        } else if (*end == ',' && value != NULL) {
            *end = '\0';
            start = end + 1;
        }

        end++;
    }

    return object;
}

void json_print(json_object *object) {
    for (size_t i = 0; i < object->size; i++) {
        printf("%s: %s\n", object->pairs[i].key, object->pairs[i].value);
    }
}

int main() {
    char *json = "{ \"name\": \"John Doe\", \"age\": 30, \"occupation\": \"Software Engineer\" }";
    json_object *object = json_parse(json);
    json_print(object);
    free(object->pairs);
    free(object);
    return 0;
}