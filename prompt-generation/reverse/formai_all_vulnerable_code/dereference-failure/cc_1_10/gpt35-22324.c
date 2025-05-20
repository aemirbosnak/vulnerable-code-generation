//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    TYPE_NULL,
    TYPE_BOOL,
    TYPE_NUMBER,
    TYPE_STRING,
    TYPE_OBJECT,
    TYPE_ARRAY
} json_type;

typedef struct json_value json_value;
typedef struct json_object json_object;
typedef struct json_array json_array;

struct json_object {
    char **keys;
    json_value **values;
    size_t size;
};

struct json_array {
    json_value **items;
    size_t size;
};

struct json_value {
    json_type type;
    union {
        double number;
        int boolean;
        char *string;
        json_object object;
        json_array array;
    } data;
};

int parse_value(char **ptr, json_value **value);

int parse_string(char **ptr, char **str) {
    *str = NULL;
    if (**ptr != '"') {
        return 0;
    }
    *ptr += 1;
    size_t len = 0;
    while (**ptr != '"') {
        len++;
        *str = realloc(*str, len);
        (*str)[len - 1] = **ptr;
        *ptr += 1;
    }
    *ptr += 1;
    return 1;
}

int parse_number(char **ptr, double *number) {
    *number = 0;
    int sign = 1;
    if (**ptr == '-') {
        sign = -1;
        *ptr += 1;
    }
    while (**ptr >= '0' && **ptr <= '9') {
        *number = *number * 10 + (**ptr - '0');
        *ptr += 1;
    }
    if (**ptr == '.') {
        double fraction = 0.1;
        *ptr += 1;
        while (**ptr >= '0' && **ptr <= '9') {
            *number += (**ptr - '0') * fraction;
            fraction *= 0.1;
            *ptr += 1;
        }
    }
    *number *= sign;
    return 1;
}

int parse_bool(char **ptr, int *boolean) {
    if (**ptr == 't' && *(*ptr + 1) == 'r' && *(*ptr + 2) == 'u' && *(*ptr + 3) == 'e') {
        *boolean = 1;
        *ptr += 4;
    } else if (**ptr == 'f' && *(*ptr + 1) == 'a' && *(*ptr + 2) == 'l' && *(*ptr + 3) == 's' && *(*ptr + 4) == 'e') {
        *boolean = 0;
        *ptr += 5;
    } else {
        return 0;
    }
    return 1;
}

int parse_array(char **ptr, json_array *array) {
    array->items = NULL;
    array->size = 0;
    if (**ptr != '[') {
        return 0;
    }
    *ptr += 1;
    while (**ptr != ']') {
        json_value *value = NULL;
        if (parse_value(ptr, &value)) {
            array->size++;
            array->items = realloc(array->items, array->size * sizeof(json_value *));
            array->items[array->size - 1] = value;
            if (**ptr == ',') {
                *ptr += 1;
            }
        } else {
            return 0;
        }
    }
    *ptr += 1;
    return 1;
}

int parse_object(char **ptr, json_object *object) {
    object->keys = NULL;
    object->values = NULL;
    object->size = 0;
    if (**ptr != '{') {
        return 0;
    }
    *ptr += 1;
    while (**ptr != '}') {
        char *key = NULL;
        json_value *value = NULL;
        if (parse_string(ptr, &key)) {
            if (**ptr == ':') {
                *ptr += 1;
                if (parse_value(ptr, &value)) {
                    object->size++;
                    object->keys = realloc(object->keys, object->size * sizeof(char *));
                    object->keys[object->size - 1] = key;
                    object->values = realloc(object->values, object->size * sizeof(json_value *));
                    object->values[object->size - 1] = value;
                    if (**ptr == ',') {
                        *ptr += 1;
                    }
                } else {
                    free(key);
                    return 0;
                }
            } else {
                free(key);
                return 0;
            }
        } else {
            return 0;
        }
    }
    *ptr += 1;
    return 1;
}

int parse_value(char **ptr, json_value **value) {
    *value = malloc(sizeof(json_value));
    (*value)->type = TYPE_NULL;
    if (**ptr == 'n' && *(*ptr + 1) == 'u' && *(*ptr + 2) == 'l' && *(*ptr + 3) == 'l') {
        *ptr += 4;
    } else if (parse_bool(ptr, &(*value)->data.boolean)) {
        (*value)->type = TYPE_BOOL;
    } else if (parse_number(ptr, &(*value)->data.number)) {
        (*value)->type = TYPE_NUMBER;
    } else if (parse_string(ptr, &(*value)->data.string)) {
        (*value)->type = TYPE_STRING;
    } else if (parse_object(ptr, &(*value)->data.object)) {
        (*value)->type = TYPE_OBJECT;
    } else if (parse_array(ptr, &(*value)->data.array)) {
        (*value)->type = TYPE_ARRAY;
    } else {
        free(*value);
        *value = NULL;
        return 0;
    }
    return 1;
}

int main() {
    char *json_string = "{\n"
                        "  \"name\": \"John Doe\",\n"
                        "  \"age\": 25,\n"
                        "  \"gender\": \"male\",\n"
                        "  \"isMarried\": false,\n"
                        "  \"hobbies\": [\n"
                        "    \"reading\",\n"
                        "    \"listening to music\",\n"
                        "    \"playing video games\"\n"
                        "  ],\n"
                        "  \"address\": {\n"
                        "    \"street\": \"123 Main St\",\n"
                        "    \"city\": \"Anytown\",\n"
                        "    \"state\": \"CA\",\n"
                        "    \"zip\": \"98765\"\n"
                        "  }\n"
                        "}";
    json_value *value = NULL;
    char *ptr = json_string;
    parse_value(&ptr, &value);
    printf("JSON Object:\n");
    for (int i = 0; i < value->data.object.size; i++) {
        printf("Key: %s\n", value->data.object.keys[i]);
        printf("Value:\n");
        switch (value->data.object.values[i]->type) {
            case TYPE_NULL:
                printf("null\n");
                break;
            case TYPE_BOOL:
                printf(value->data.object.values[i]->data.boolean ? "true\n" : "false\n");
                break;
            case TYPE_NUMBER:
                printf("%g\n", value->data.object.values[i]->data.number);
                break;
            case TYPE_STRING:
                printf("%s\n", value->data.object.values[i]->data.string);
                break;
            case TYPE_OBJECT:
                printf("Object:\n");
                for (int j = 0; j < value->data.object.values[i]->data.object.size; j++) {
                    printf("    Key: %s\n", value->data.object.values[i]->data.object.keys[j]);
                    printf("    Value:\n");
                    switch (value->data.object.values[i]->data.object.values[j]->type) {
                        case TYPE_NULL:
                            printf("    null\n");
                            break;
                        case TYPE_BOOL:
                            printf(value->data.object.values[i]->data.object.values[j]->data.boolean ? "    true\n" : "    false\n");
                            break;
                        case TYPE_NUMBER:
                            printf("    %g\n", value->data.object.values[i]->data.object.values[j]->data.number);
                            break;
                        case TYPE_STRING:
                            printf("    %s\n", value->data.object.values[i]->data.object.values[j]->data.string);
                            break;
                        case TYPE_OBJECT:
                        case TYPE_ARRAY:
                            printf("    Not implemented\n");
                            break;
                    }
                }
                break;
            case TYPE_ARRAY:
                printf("Array:\n");
                for (int j = 0; j < value->data.object.values[i]->data.array.size; j++) {
                    printf("    Item:\n");
                    switch (value->data.object.values[i]->data.array.items[j]->type) {
                        case TYPE_NULL:
                            printf("    null\n");
                            break;
                        case TYPE_BOOL:
                            printf(value->data.object.values[i]->data.array.items[j]->data.boolean ? "    true\n" : "    false\n");
                            break;
                        case TYPE_NUMBER:
                            printf("    %g\n", value->data.object.values[i]->data.array.items[j]->data.number);
                            break;
                        case TYPE_STRING:
                            printf("    %s\n", value->data.object.values[i]->data.array.items[j]->data.string);
                            break;
                        case TYPE_OBJECT:
                        case TYPE_ARRAY:
                            printf("    Not implemented\n");
                            break;
                    }
                }
                break;
        }
    }
    return 0;
}