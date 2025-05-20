//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL
} json_type;

typedef struct _json_value json_value;
struct _json_value {
    json_type type;
    union {
        char *string_value;
        double number_value;
        json_value **array_value;
        struct {
            json_value **keys;
            json_value **values;
        } object_value;
    } value;
    size_t size;
};

json_value *parse_value(const char **json);

static json_value *parse_object(const char **json) {
    json_value *value = malloc(sizeof(json_value));
    value->type = JSON_OBJECT;
    value->size = 0;
    value->value.object_value.keys = NULL;
    value->value.object_value.values = NULL;

    (*json)++;

    while (**json != '}') {
        json_value *key = parse_value(json);
        if (key->type != JSON_STRING) {
            fprintf(stderr, "Error: Expected string as key in object\n");
            exit(1);
        }
        (*json)++;
        json_value *val = parse_value(json);
        value->value.object_value.keys = realloc(value->value.object_value.keys,
                                                             sizeof(json_value *) * (value->size + 1));
        value->value.object_value.values = realloc(value->value.object_value.values,
                                                             sizeof(json_value *) * (value->size + 1));
        value->value.object_value.keys[value->size] = key;
        value->value.object_value.values[value->size] = val;
        value->size++;
        if (**json == '}') {
            break;
        }
        (*json)++;
    }

    (*json)++;
    return value;
}

json_value *parse_value(const char **json) {
    while (**json == ' ' || **json == '\n' || **json == '\t' || **json == '\r') (*json)++;
    switch (**json) {
        case '{':
            return parse_object(json);
        case '[':
            return NULL;
        case '\"':
            {
                (*json)++;
                const char *end = *json;
                while (*end != '\"') {
                    if (*end == '\\') {
                        end++;
                    }
                    end++;
                }
                size_t size = end - *json;
                char *str = malloc(sizeof(char) * (size + 1));
                size_t i = 0;
                while (*json != '\"') {
                    if (*json == '\\') {
                        json++;
                    }
                    str[i++] = *(*json)++;
                }
                str[i] = '\0';
                (*json)++;
                json_value *value = malloc(sizeof(json_value));
                value->type = JSON_STRING;
                value->size = size;
                value->value.string_value = str;
                return value;
            }
        default:
            return NULL;
    }
}

int main() {
    const char *json = "{\"name\":\"John\", \"age\":30, \"city\":\"New York\"}";
    json_value *json_obj = parse_value(&json);
    
    printf("JSON Object:\n");
    for(int i=0; i<json_obj->size; i++) {
        printf("\t%s: ", json_obj->value.object_value.keys[i]->value.string_value);
        if(json_obj->value.object_value.values[i]->type == JSON_STRING) {
            printf("'%s'", json_obj->value.object_value.values[i]->value.string_value);
        }
        else if(json_obj->value.object_value.values[i]->type == JSON_NUMBER) {
            printf("%f", json_obj->value.object_value.values[i]->value.number_value);
        }
        printf("\n");
    }
    return 0;
}