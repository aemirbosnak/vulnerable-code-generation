//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct json_object json_object;

struct json_object {
    enum { 
        JSON_OBJECT,
        JSON_ARRAY,
        JSON_STRING,
        JSON_NUMBER,
        JSON_TRUE,
        JSON_FALSE,
        JSON_NULL 
    } type;
    void *data;
};

json_object *parse_object(char **input);
json_object *parse_array(char **input);
json_object *parse_string(char **input);
json_object *parse_number(char **input);
json_object *parse_true(char **input);
json_object *parse_false(char **input);
json_object *parse_null(char **input);

int main() {
    char *input = "{ \"name\": \"John Doe\", \"age\": 35, \"isAdmin\": false }";
    json_object *obj = parse_object(&input);
    printf("%s\n", (char*)obj->data);

    return 0;
}

json_object *parse_object(char **input) {
    if (**input != '{') {
        fprintf(stderr, "Error: expected '{', got '%c'\n", **input);
        exit(1);
    }
    (*input)++;
    json_object *object = malloc(sizeof(json_object));
    object->type = JSON_OBJECT;
    object->data = malloc(sizeof(char)*1024);
    char *string_ptr = (char*)(object->data);
    *string_ptr = '{';
    string_ptr++;
    while (**input != '}') {
        object = realloc(object, sizeof(json_object)*(2));
        json_object *key = parse_string(input);
        if (*(*input) != ':') {
            fprintf(stderr, "Error: expected ':', got '%c'\n", *(*input));
            exit(1);
        }
        (*input)++;
        json_object *value = parse_object(input);
        string_ptr += sprintf(string_ptr, "\"%s\":%s,", (char*)(key->data), (char*)(value->data));
        free(key);
        free(value);
    }
    *string_ptr = '}';
    return object;
}

json_object *parse_array(char **input) {
    if (**input != '[') {
        fprintf(stderr, "Error: expected '[', got '%c'\n", **input);
        exit(1);
    }
    (*input)++;
    json_object *array = malloc(sizeof(json_object));
    array->type = JSON_ARRAY;
    array->data = malloc(sizeof(json_object)*10);
    json_object **array_ptr = (json_object**)(array->data);
    int i = 0;
    while (**input != ']') {
        json_object *obj = parse_object(input);
        array_ptr[i] = obj;
        i++;
        if (**input == ',') {
            (*input)++;
        }
    }
    (*input)++;
    return array;
}

json_object *parse_string(char **input) {
    if (**input != '"') {
        fprintf(stderr, "Error: expected '\"', got '%c'\n", **input);
        exit(1);
    }
    (*input)++;
    char *string = calloc(1024, sizeof(char));
    int i = 0;
    while (**input != '"') {
        string[i] = **input;
        i++;
        (*input)++;
    }
    (*input)++;
    json_object *object = malloc(sizeof(json_object));
    object->type = JSON_STRING;
    object->data = string;
    return object;
}

json_object *parse_number(char **input) {
    char *number = calloc(1024, sizeof(char));
    int i = 0;
    while (**input >= '0' && **input <= '9') {
        number[i] = **input;
        i++;
        (*input)++;
    }
    json_object *object = malloc(sizeof(json_object));
    object->type = JSON_NUMBER;
    object->data = number;
    return object;
}

json_object *parse_true(char **input) {
    if (strncmp(*input, "true", 4) != 0) {
        fprintf(stderr, "Error: expected 'true', got '%.*s'\n", 4, *input);
        exit(1);
    }
    (*input) += 4;
    json_object *object = malloc(sizeof(json_object));
    object->type = JSON_TRUE;
    object->data = NULL;
    return object;
}

json_object *parse_false(char **input) {
    if (strncmp(*input, "false", 5) != 0) {
        fprintf(stderr, "Error: expected 'false', got '%.*s'\n", 5, *input);
        exit(1);
    }
    (*input) += 5;
    json_object *object = malloc(sizeof(json_object));
    object->type = JSON_FALSE;
    object->data = NULL;
    return object;
}

json_object *parse_null(char **input) {
    if (strncmp(*input, "null", 4) != 0) {
        fprintf(stderr, "Error: expected 'null', got '%.*s'\n", 4, *input);
        exit(1);
    }
    (*input) += 4;
    json_object *object = malloc(sizeof(json_object));
    object->type = JSON_NULL;
    object->data = NULL;
    return object;
}