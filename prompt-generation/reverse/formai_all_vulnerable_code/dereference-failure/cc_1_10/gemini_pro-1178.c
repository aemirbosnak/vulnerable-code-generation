//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// A fun, dynamic, and flexible JSON parser written in C.

// Represents a JSON value.
typedef struct JSONValue {
    enum {
        JSON_NULL,
        JSON_STRING,
        JSON_NUMBER,
        JSON_BOOLEAN,
        JSON_ARRAY,
        JSON_OBJECT
    } type;
    union {
        char *string;
        double number;
        int boolean;
        struct JSONValue **array;
        size_t array_size;
        struct JSONPair **object;
        size_t object_size;
    };
} JSONValue;

// Represents a key-value pair in a JSON object.
typedef struct JSONPair {
    char *key;
    JSONValue *value;
} JSONPair;

// Parses a JSON string into a JSONValue.
JSONValue *parse_json(char *json) {
    JSONValue *value = malloc(sizeof(JSONValue));
    if (json[0] == 'n') {
        value->type = JSON_NULL;
    } else if (json[0] == '"') {
        value->type = JSON_STRING;
        value->string = strdup(json + 1);
    } else if (json[0] >= '0' && json[0] <= '9') {
        value->type = JSON_NUMBER;
        value->number = strtod(json, NULL);
    } else if (json[0] == 't') {
        value->type = JSON_BOOLEAN;
        value->boolean = 1;
    } else if (json[0] == 'f') {
        value->type = JSON_BOOLEAN;
        value->boolean = 0;
    } else if (json[0] == '[') {
        value->type = JSON_ARRAY;
        json++;
        value->array = NULL;
        value->array_size = 0;
        while (*json != ']') {
            value->array = realloc(value->array, sizeof(JSONValue *) * (value->array_size + 1));
            value->array[value->array_size] = parse_json(json);
            json += strlen(value->array[value->array_size++]->string) + 1;
        }
    } else if (json[0] == '{') {
        value->type = JSON_OBJECT;
        json++;
        value->object = NULL;
        value->object_size = 0;
        while (*json != '}') {
            char *key = json;
            while (*json != ':') json++;
            *json++ = '\0';
            value->object = realloc(value->object, sizeof(JSONPair *) * (value->object_size + 1));
            value->object[value->object_size] = malloc(sizeof(JSONPair));
            value->object[value->object_size]->key = strdup(key);
            value->object[value->object_size++]->value = parse_json(json);
            json += strlen(value->object[value->object_size - 1]->value->string) + 1;
        }
    }
    return value;
}

// Frees the memory allocated for a JSONValue.
void free_json(JSONValue *value) {
    switch (value->type) {
        case JSON_STRING:
            free(value->string);
            break;
        case JSON_ARRAY:
            for (size_t i = 0; i < value->array_size; i++) {
                free_json(value->array[i]);
            }
            free(value->array);
            break;
        case JSON_OBJECT:
            for (size_t i = 0; i < value->object_size; i++) {
                free(value->object[i]->key);
                free_json(value->object[i]->value);
                free(value->object[i]);
            }
            free(value->object);
            break;
    }
    free(value);
}

// Prints a JSONValue to a file.
void print_json(JSONValue *value, FILE *fp) {
    switch (value->type) {
        case JSON_NULL:
            fputs("null", fp);
            break;
        case JSON_STRING:
            fprintf(fp, "\"%s\"", value->string);
            break;
        case JSON_NUMBER:
            fprintf(fp, "%f", value->number);
            break;
        case JSON_BOOLEAN:
            fputs(value->boolean ? "true" : "false", fp);
            break;
        case JSON_ARRAY:
            fputc('[', fp);
            for (size_t i = 0; i < value->array_size; i++) {
                if (i > 0) fputc(',', fp);
                print_json(value->array[i], fp);
            }
            fputc(']', fp);
            break;
        case JSON_OBJECT:
            fputc('{', fp);
            for (size_t i = 0; i < value->object_size; i++) {
                if (i > 0) fputc(',', fp);
                fprintf(fp, "\"%s\":", value->object[i]->key);
                print_json(value->object[i]->value, fp);
            }
            fputc('}', fp);
            break;
    }
}

// The main function.
int main() {
    // Parse the JSON string.
    JSONValue *value = parse_json("{\"name\":\"John Doe\",\"age\":30,\"occupation\":\"Software Engineer\"}");

    // Print the JSONValue to a file.
    print_json(value, stdout);

    // Free the memory allocated for the JSONValue.
    free_json(value);

    return 0;
}