//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *key;
    char *value;
} Tuple;

typedef struct {
    Tuple *tuples;
    int size;
} Object;

typedef struct {
    char *name;
    Object *objects;
    int size;
} JSON;

void skip_whitespace(char **string) {
    while (**string == ' ' || **string == '\t' || **string == '\n' || **string == '\r') {
        (*string)++;
    }
}

Tuple parse_tuple(char **string) {
    char *key = NULL;
    char *value = NULL;

    // Parse key
    int key_len = 0;
    while ((*string)[key_len] != ':') {
        key_len++;
    }
    key = calloc(key_len + 1, sizeof(char));
    strncpy(key, *string, key_len);
    *string += key_len + 1;

    // Parse value
    int value_len = 0;
    if (**string == '\"') {
        // Value is a string
        (*string)++;
        while ((*string)[value_len] != '\"') {
            value_len++;
        }
        value = calloc(value_len + 1, sizeof(char));
        strncpy(value, *string, value_len);
        *string += value_len + 1;
    } else {
        // Value is a number
        while ((*string)[value_len] != ',' && (*string)[value_len] != '}') {
            value_len++;
        }
        value = calloc(value_len + 1, sizeof(char));
        strncpy(value, *string, value_len);
        *string += value_len;
    }

    skip_whitespace(string);

    Tuple tuple = {key, value};
    return tuple;
}

Object parse_object(char **string) {
    Object object = {NULL, 0};
    int capacity = 10;
    object.tuples = calloc(capacity, sizeof(Tuple));

    skip_whitespace(string);

    // Check if object is empty
    if (**string == '}') {
        (*string)++;
        return object;
    }

    // Otherwise parse tuples
    do {
        if (object.size == capacity) {
            capacity *= 2;
            object.tuples = realloc(object.tuples, capacity);
        }
        object.tuples[object.size++] = parse_tuple(string);
    } while (**string == ',' && (*string)++);

    // Skip past object closing brace
    (*string)++;

    return object;
}

JSON parse_json(char *string) {
    JSON json = {NULL, NULL, 0};
    int capacity = 10;
    json.objects = calloc(capacity, sizeof(Object));

    skip_whitespace(&string);

    // Parse JSON name
    int name_len = 0;
    while (string[name_len] != '{') {
        name_len++;
    }
    json.name = calloc(name_len + 1, sizeof(char));
    strncpy(json.name, string, name_len);
    string += name_len;

    // Parse objects
    do {
        if (json.size == capacity) {
            capacity *= 2;
            json.objects = realloc(json.objects, capacity);
        }
        json.objects[json.size++] = parse_object(&string);
    } while (*string == ',' && (*string)++);

    return json;
}

int main() {
    char *json_string = "{\"name\": \"John\", \"age\": 32, \"address\": {\"street\": \"123 Main St\", \"city\": \"Anytown\", \"state\": \"CA\"}}";

    JSON json = parse_json(json_string);

    printf("%s:\n", json.name);
    for (int i = 0; i < json.size; i++) {
        printf("\t%s:\n", json.objects[i].tuples[0].value);
        for (int j = 1; j < json.objects[i].size; j++) {
            printf("\t\t%s: %s\n", json.objects[i].tuples[j].key, json.objects[i].tuples[j].value);
        }
    }

    // Free memory
    free(json.name);
    for (int i = 0; i < json.size; i++) {
        for (int j = 0; j < json.objects[i].size; j++) {
            free(json.objects[i].tuples[j].key);
            free(json.objects[i].tuples[j].value);
        }
        free(json.objects[i].tuples);
    }
    free(json.objects);

    return 0;
}