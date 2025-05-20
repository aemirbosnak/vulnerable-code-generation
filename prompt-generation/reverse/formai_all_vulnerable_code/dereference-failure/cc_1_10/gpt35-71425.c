//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct json_value json_value;

typedef struct json_object {
    char **keys;
    json_value **values;
    int size;
} json_object;

typedef struct json_array {
    json_value **values;
    int size;
} json_array;

typedef enum {
    JSON_STRING,
    JSON_INT,
    JSON_BOOL,
    JSON_NULL,
    JSON_OBJECT,
    JSON_ARRAY
} json_type;

struct json_value {
    json_type type;
    union {
        char *string;
        int integer;
        int boolean;
        json_object *object;
        json_array *array;
    };
};

void json_value_free(json_value *value) {
    switch (value->type) {
        case JSON_STRING:
            free(value->string);
            break;
        case JSON_OBJECT:
            for (int i = 0; i < value->object->size; i++) {
                free(value->object->keys[i]);
                json_value_free(value->object->values[i]);
            }
            free(value->object->keys);
            free(value->object->values);
            free(value->object);
            break;
        case JSON_ARRAY:
            for (int i = 0; i < value->array->size; i++) {
                json_value_free(value->array->values[i]);
            }
            free(value->array->values);
            free(value->array);
            break;
        default:
            break;
    }
    free(value);
}

json_value *parse_value(char **json);

json_value *parse_object(char **json) {
    json_object *object = malloc(sizeof(json_object));
    object->keys = NULL;
    object->values = NULL;
    object->size = 0;
    (*json)++;
    while (**json != '}') {
        if (object->size > 0) {
            (*json)++;
        }
        object->size++;
        object->keys = realloc(object->keys, sizeof(char*) * object->size);
        object->values = realloc(object->values, sizeof(json_value*) * object->size);
        object->keys[object->size-1] = *json;
        while (**json != ':') {
            (*json)++;
        }
        **json = '\0';
        (*json)++;
        object->values[object->size-1] = parse_value(json);
    }
    (*json)++;
    json_value *value = malloc(sizeof(json_value));
    value->type = JSON_OBJECT;
    value->object = object;
    return value;
}

json_value *parse_array(char **json) {
    json_array *array = malloc(sizeof(json_array));
    array->values = NULL;
    array->size = 0;
    (*json)++;
    while (**json != ']') {
        if (array->size > 0) {
            (*json)++;
        }
        array->size++;
        array->values = realloc(array->values, sizeof(json_value*) * array->size);
        array->values[array->size-1] = parse_value(json);
    }
    (*json)++;
    json_value *value = malloc(sizeof(json_value));
    value->type = JSON_ARRAY;
    value->array = array;
    return value;
}

json_value *parse_string(char **json) {
    char *string = ++(*json);
    while (**json != '\"') {
        if (**json == '\\') {
            (*json)++;
        }
        (*json)++;
    }
    **json = '\0';
    (*json)++;
    json_value *value = malloc(sizeof(json_value));
    value->type = JSON_STRING;
    value->string = string;
    return value;
}

json_value *parse_number(char **json) {
    char *string = *json;
    while (**json >= '-' && **json <= '9' || **json == 'e' || **json == 'E' || **json == '+' || **json == '-') {
        (*json)++;
    }
    char backup = **json;
    **json = '\0';
    int number = atoi(string);
    **json = backup;
    json_value *value = malloc(sizeof(json_value));
    value->type = JSON_INT;
    value->integer = number;
    return value;
}

json_value *parse_boolean(char **json) {
    json_value *value = malloc(sizeof(json_value));
    value->type = JSON_BOOL;
    if (strncmp(*json, "true", 4) == 0) {
        value->boolean = 1;
        *json += 4;
    } else {
        value->boolean = 0;
        *json += 5;
    }
    return value;
}

json_value *parse_null(char **json) {
    json_value *value = malloc(sizeof(json_value));
    value->type = JSON_NULL;
    *json += 4;
    return value;
}

json_value *parse_value(char **json) {
    while (**json == ' ' || **json == '\t' || **json == '\n' || **json == '\r') {
        (*json)++;
    }
    switch (**json) {
        case '\"':
            return parse_string(json);
        case '{':
            return parse_object(json);
        case '[':
            return parse_array(json);
        case 't':
        case 'f':
            return parse_boolean(json);
        case 'n':
            return parse_null(json);
        default:
            return parse_number(json);
    }
}

int main() {
    char *json = "{\"name\":\"John\",\"age\":30,\"languages\":[\"English\",\"French\"],\"address\":{\"street\":\"123 Main St.\",\"city\":\"Anytown\",\"state\":\"CA\",\"zip\":12345},\"married\":true}";
    json_value *value = parse_value(&json);
    printf("Name: %s\n", value->object->values[0]->string);
    printf("Age: %d\n", value->object->values[1]->integer);
    printf("Languages: %s, %s\n", value->object->values[2]->array->values[0]->string, value->object->values[2]->array->values[1]->string);
    printf("Street: %s\n", value->object->values[3]->object->values[0]->string);
    printf("City: %s\n", value->object->values[3]->object->values[1]->string);
    printf("State: %s\n", value->object->values[3]->object->values[2]->string);
    printf("Zip: %d\n", value->object->values[3]->object->values[3]->integer);
    printf("Married: %d\n", value->object->values[4]->boolean);
    json_value_free(value);
    return 0;
}