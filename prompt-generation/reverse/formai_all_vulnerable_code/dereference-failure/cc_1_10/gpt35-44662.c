//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: mind-bending
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define BUFFERSIZE 1024

enum {
    VALUE_UNKNOWN,
    VALUE_OBJECT,
    VALUE_ARRAY,
    VALUE_STRING,
    VALUE_NUMBER,
    VALUE_BOOLEAN,
    VALUE_NULL
};

typedef struct {
    int type;
    union {
        char *string;
        double number;
        int boolean;
    } value;
} value_t;

typedef struct {
    char *buffer;
    size_t buffer_size;
    size_t cursor;
} json_t;

json_t *json_create(char *buffer) {
    json_t *json = (json_t*) malloc(sizeof(json_t));
    json->buffer_size = strlen(buffer);
    json->buffer = (char*) malloc(sizeof(char) * json->buffer_size);
    json->cursor = 0;
    memcpy(json->buffer, buffer, json->buffer_size);
    return json;
}

void json_destroy(json_t *json) {
    if (json) {
        free(json->buffer);
        free(json);
    }
}

value_t *json_parse_value(json_t *json);

value_t *json_parse_object(json_t *json) {
    value_t *object = (value_t*) malloc(sizeof(value_t));
    object->type = VALUE_OBJECT;
    json->cursor++;
    while (json->cursor < json->buffer_size) {
        char c = json->buffer[json->cursor];
        if (isspace(c)) {
            json->cursor++;
            continue;
        } else if (c == '}') {
            json->cursor++;
            break;
        }
        // parse key
        value_t *key = json_parse_value(json);
        if (isspace(json->buffer[json->cursor])) {
            json->cursor++;
        }
        if (json->buffer[json->cursor] != ':') {
            printf("Error: expected key/value pair in object\n");
            exit(1);
        }
        json->cursor++;
        if (isspace(json->buffer[json->cursor])) {
            json->cursor++;
        }
        // parse value
        value_t *value = json_parse_value(json);
        if (!key->value.string) {
            printf("Error: expected key in object\n");
            exit(1);
        }
        printf("Key: %s, Value: %s\n", key->value.string, value->value.string);
        free(key);
        free(value);
        if (json->buffer[json->cursor] == ',') {
            json->cursor++;
        }
    }
    return object;
}

value_t *json_parse_array(json_t *json) {
    value_t *array = (value_t*) malloc(sizeof(value_t));
    array->type = VALUE_ARRAY;
    json->cursor++;
    while (json->cursor < json->buffer_size) {
        char c = json->buffer[json->cursor];
        if (isspace(c)) {
            json->cursor++;
            continue;
        } else if (c == ']') {
            json->cursor++;
            break;
        }
        value_t *value = json_parse_value(json);
        printf("Value: %s\n", value->value.string);
        free(value);
        if (json->cursor < json->buffer_size && json->buffer[json->cursor] == ',') {
            json->cursor++;
        }
    }
    return array;
}

value_t *json_parse_string(json_t *json) {
    value_t *string = (value_t*) malloc(sizeof(value_t));
    string->type = VALUE_STRING;
    json->cursor++;
    char *start = json->buffer + json->cursor;
    while (json->cursor < json->buffer_size && json->buffer[json->cursor] != '\"') {
        json->cursor++;
    }
    char *end = json->buffer + json->cursor;
    size_t len = end - start;
    string->value.string = (char*) malloc(sizeof(char) * (len + 1));
    memcpy(string->value.string, start, len);
    string->value.string[len] = '\0';
    json->cursor++;
    return string;
}

value_t *json_parse_number(json_t *json) {
    value_t *number = (value_t*) malloc(sizeof(value_t));
    number->type = VALUE_NUMBER;
    char *start = json->buffer + json->cursor;
    while (json->cursor < json->buffer_size && (isdigit(json->buffer[json->cursor]) || json->buffer[json->cursor] == '.')) {
        json->cursor++;
    }
    char *end = json->buffer + json->cursor;
    size_t len = end - start;
    char *str = (char*) malloc(sizeof(char) * (len + 1));
    memcpy(str, start, len);
    str[len] = '\0';
    number->value.number = strtod(str, NULL);
    free(str);
    return number;
}

value_t *json_parse_boolean(json_t *json) {
    value_t *boolean = (value_t*) malloc(sizeof(value_t));
    boolean->type = VALUE_BOOLEAN;
    boolean->value.boolean = 0;
    if (strncmp(json->buffer + json->cursor, "true", 4) == 0) {
        boolean->value.boolean = 1;
        json->cursor += 4;
    } else if (strncmp(json->buffer + json->cursor, "false", 5) == 0) {
        json->cursor += 5;
    } else {
        printf("Error: expected boolean value\n");
        exit(1);
    }
    return boolean;
}

value_t *json_parse_null(json_t *json) {
    value_t *null = (value_t*) malloc(sizeof(value_t));
    null->type = VALUE_NULL;
    null->value.string = NULL;
    if (strncmp(json->buffer + json->cursor, "null", 4) == 0) {
        json->cursor += 4;
    } else {
        printf("Error: expected null value\n");
        exit(1);
    }
    return null;
}

value_t *json_parse_value(json_t *json) {
    value_t *value;
    while (json->cursor < json->buffer_size) {
        char c = json->buffer[json->cursor];
        if (isspace(c)) {
            json->cursor++;
            continue;
        }
        if (c == '{') {
            value = json_parse_object(json);
            break;
        } else if (c == '[') {
            value = json_parse_array(json);
            break;
        } else if (c == '\"') {
            value = json_parse_string(json);
            break;
        } else if (isdigit(c) || c == '-') {
            value = json_parse_number(json);
            break;
        } else if (c == 't' || c == 'f') {
            value = json_parse_boolean(json);
            break;
        } else if (c == 'n') {
            value = json_parse_null(json);
            break;
        } else {
            printf("Error: unexpected character '%c'\n", c);
            exit(1);
        }
    }
    return value;
}

int main() {
    char buffer[BUFFERSIZE] = "{\"foo\": [\"bar\", 42, {\"baz\": true}, null], \"qux\": {\"quux\": {\"corge\": \"grault\", \"garply\": false}}}";
    json_t *json = json_create(buffer);
    value_t *value = json_parse_value(json);
    json_destroy(json);
    free(value);
    return 0;
}