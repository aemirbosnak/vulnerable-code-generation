//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} json_type;

typedef struct json_value_t json_value;
struct json_value_t {
    json_type type;
    union {
        int boolean;
        double number;
        char *string;
        struct {
            json_value **values;
            size_t size;
        } array;
        struct {
            char **keys;
            json_value **values;
            size_t size;
        } object;
    } data;
};

void json_parse_whitespace(const char **json) {
    while (**json == ' ' || **json == '\t' || **json == '\n' || **json == '\r') {
        (*json)++;
    }
}

json_value* json_parse_value(const char **json);

char *json_parse_string(const char **json) {
    size_t len = 0;
    const char *start = *json;
    while (**json != '\"') {
        if (**json == '\\') {
            (*json)++;   
        }
        (*json)++;
        len++;
    }
    char *string = (char*) malloc(len + 1);
    memcpy(string, start, len);
    string[len] = '\0';
    (*json)++;
    return string;
}

json_value* json_parse_array(const char **json) {
    json_parse_whitespace(json);
    if (**json != '[') {
        printf("Expected '['.");
        return NULL;
    }
    (*json)++;
    json_parse_whitespace(json);
    if (**json == ']') {
        (*json)++;
        return NULL;
    }
    size_t size = 0, capacity = 4;
    json_value **values = malloc(capacity * sizeof(json_value*));
    while (1) {
        json_parse_whitespace(json);
        values[size++] = json_parse_value(json);
        json_parse_whitespace(json);
        if (**json == ']') {
            (*json)++;
            break;
        }
        if (**json != ',') {
            printf("Expected ',' or ']'.");
            return NULL;
        }
        (*json)++;
        if (size == capacity) {
            capacity *= 2;
            values = realloc(values, capacity * sizeof(json_value*));
        }
    }
    values = realloc(values, size * sizeof(json_value*));
    json_value *array = (json_value*)malloc(sizeof(json_value));
    array->type = JSON_ARRAY;
    array->data.array.values = values;
    array->data.array.size = size;
    return array;
}

json_value* json_parse_object(const char **json) {
    json_parse_whitespace(json);
    if (**json != '{') {
        printf("Expected '{'.");
        return NULL;
    }
    (*json)++;
    json_parse_whitespace(json);
    if (**json == '}') {
        (*json)++;
        return NULL;
    }
    size_t size = 0, capacity = 4;
    char **keys = malloc(capacity * sizeof(char*));
    json_value **values = malloc(capacity * sizeof(json_value*));
    while (1) {
        keys[size] = json_parse_string(json);
        json_parse_whitespace(json);
        if (**json != ':') {
            printf("Expected ':'.");
            return NULL;
        }
        (*json)++;
        json_parse_whitespace(json);
        values[size] = json_parse_value(json);
        size++;
        json_parse_whitespace(json);
        if (**json == '}') {
            (*json)++;
            break;
        }
        if (**json != ',') {
            printf("Expected ',' or '}'.");
            return NULL;
        }
        (*json)++;
        json_parse_whitespace(json);
        if (size == capacity) {
            capacity *= 2;
            keys = realloc(keys, capacity * sizeof(char*));
            values = realloc(values, capacity * sizeof(json_value*));
        }
    }
    keys = realloc(keys, size * sizeof(char*));
    values = realloc(values, size * sizeof(json_value*));
    json_value *object = (json_value*)malloc(sizeof(json_value));
    object->type = JSON_OBJECT;
    object->data.object.keys = keys;
    object->data.object.values = values;
    object->data.object.size = size;
    return object;
}

json_value* json_parse_value(const char **json) {
    json_parse_whitespace(json);
    switch (**json) {
        case 'n': return NULL;
        case 'f': case 't': {
            if (strncmp(*json, "true", 4) == 0) {
                (*json) += 4;
                json_value *boolean = (json_value*)malloc(sizeof(json_value));
                boolean->type = JSON_BOOLEAN;
                boolean->data.boolean = 1;
                return boolean;
            } else if (strncmp(*json, "false", 5) == 0) {
                (*json) += 5;
                json_value *boolean = (json_value*)malloc(sizeof(json_value));
                boolean->type = JSON_BOOLEAN;
                boolean->data.boolean = 0;
                return boolean;
            }
            break;
        }
        case '\"': {
            return (json_value*)json_parse_string(json);
        }
        case '[': {
            return json_parse_array(json);
        }
        case '{': {
            return json_parse_object(json);
        }
        default: {
            if (**json == '-' || (**json >= '0' && **json <= '9')) {
                char *end;
                double number = strtod(*json, &end);
                *json = end;
                json_value *value = (json_value*)malloc(sizeof(json_value));
                value->type = JSON_NUMBER;
                value->data.number = number;
                return value;
            }
            break;
        }
    }
    printf("Invalid JSON.");
    return NULL;
}

int main() {
    const char *json = "{\"name\": \"John Doe\", \"age\": 42}";
    json_value *object = json_parse_value(&json);
    printf("Object type: %d\n", object->type);
    printf("Object size: %ld\n", object->data.object.size);
    for (size_t i = 0; i < object->data.object.size; i++) {
        printf("%s: %s\n", object->data.object.keys[i], object->data.object.values[i]->data.string);
    }
    return 0;
}