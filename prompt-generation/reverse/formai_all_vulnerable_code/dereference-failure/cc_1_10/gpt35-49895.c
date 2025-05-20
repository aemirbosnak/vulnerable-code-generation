//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TOKENS 100

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY
} json_type;

typedef struct {
    json_type type;
    char **keys;
    int *values;
    int size;
} json_object;

typedef struct {
    json_type type;
    int *values;
    int size;
} json_array;

bool is_digit(char c) {
    return c >= '0' && c <= '9';
}

bool is_whitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}

int get_value(char *s, int start, int end) {
    int value = 0;

    for (int i = start; i <= end; i++) {
        value *= 10;
        value += s[i] - '0';
    }

    return value;
}

void parse_object(char *s, int start, int end, json_object *object) {
    object->type = JSON_OBJECT;
    object->size = 0;
    object->keys = malloc(MAX_TOKENS * sizeof(char *));
    object->values = malloc(MAX_TOKENS * sizeof(int));

    int key_start = -1;

    for (int i = start + 1; i < end; i++) {
        if (s[i] == ':') {
            key_start = i + 1;
        } else if (s[i] == ',') {
            char *key = malloc((i - key_start) * sizeof(char));
            strncpy(key, &s[key_start], i - key_start);

            object->keys[object->size] = key;
            object->values[object->size] = parse_json(s, key_start, i - key_start);
            object->size++;
        }

        if (s[i] == '}') {
            char *key = malloc((i - key_start) * sizeof(char));
            strncpy(key, &s[key_start], i - key_start);

            object->keys[object->size] = key;
            object->values[object->size] = parse_json(s, key_start, i - key_start);
            object->size++;
            break;
        }
    }
}

void parse_array(char *s, int start, int end, json_array *array) {
    array->type = JSON_ARRAY;
    array->size = 0;
    array->values = malloc(MAX_TOKENS * sizeof(int));

    int value_start = -1;

    for (int i = start + 1; i < end; i++) {
        if (is_digit(s[i])) {
            if (value_start == -1) {
                value_start = i;
            }

            if (i == end - 1) {
                array->values[array->size] = get_value(s, value_start, i);
                array->size++;
            }
        } else if (s[i] == ',') {
            array->values[array->size] = get_value(s, value_start, i - 1);
            array->size++;
            value_start = -1;
        } else if (s[i] == ']') {
            if (value_start != -1) {
                array->values[array->size] = get_value(s, value_start, i - 1);
                array->size++;
            }
            break;
        }
    }
}

int parse_json(char *s, int start, int end) {
    if (s[start] == '{') {
        json_object object;
        parse_object(s, start, end, &object);
    } else if (s[start] == '[') {
        json_array array;
        parse_array(s, start, end, &array);
    } else if (is_digit(s[start])) {
        return get_value(s, start, end);
    }
}

int main() {
    char *json_string = "{\"one\":1,\"two\":2,\"three\":3}";
    int parsed_json = parse_json(json_string, 0, strlen(json_string));
    printf("%d\n", parsed_json);

    return 0;
}