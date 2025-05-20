//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} json_pair;

typedef struct {
    json_pair *pairs;
    int size;
} json_object;

json_object *json_parse(const char *json) {
    json_object *object = malloc(sizeof(json_object));
    object->pairs = NULL;
    object->size = 0;

    const char *start = json;
    while (*start) {
        while (*start && *start != '{') {
            start++;
        }

        if (*start == '{') {
            start++;
            json_object *child = json_parse(start);

            object->pairs = realloc(object->pairs, sizeof(json_pair) * (object->size + 1));
            object->pairs[object->size].key = NULL;
            object->pairs[object->size].value = child;
            object->size++;

            while (*start && *start != '}') {
                start++;
            }

            if (*start == '}') {
                start++;
            }
        } else if (*start && *start != '"') {
            while (*start && *start != ':') {
                start++;
            }

            if (*start == ':') {
                start++;

                char *key = malloc(sizeof(char) * 64);
                int i = 0;
                while (*start && *start != '"') {
                    key[i++] = *start++;
                }
                key[i] = '\0';

                char *value = malloc(sizeof(char) * 64);
                i = 0;
                if (*start == '"') {
                    start++;
                    while (*start && *start != '"') {
                        value[i++] = *start++;
                    }
                    value[i] = '\0';
                } else {
                    while (*start && *start != ',' && *start != '}') {
                        value[i++] = *start++;
                    }
                    value[i] = '\0';
                }

                object->pairs = realloc(object->pairs, sizeof(json_pair) * (object->size + 1));
                object->pairs[object->size].key = key;
                object->pairs[object->size].value = value;
                object->size++;
            }
        }
    }

    return object;
}

void json_print(json_object *object) {
    for (int i = 0; i < object->size; i++) {
        if (object->pairs[i].value == NULL) {
            printf("%s: {\n", object->pairs[i].key);
            json_print(object->pairs[i].value);
            printf("}\n");
        } else {
            printf("%s: %s\n", object->pairs[i].key, object->pairs[i].value);
        }
    }
}

int main() {
    const char *json = "{\"name\": \"John Doe\", \"age\": 30, \"address\": {\"street\": \"123 Main Street\", \"city\": \"Anytown\", \"state\": \"CA\"}, \"hobbies\": [\"reading\", \"writing\", \"coding\"]}";
    json_object *object = json_parse(json);
    json_print(object);
    return 0;
}