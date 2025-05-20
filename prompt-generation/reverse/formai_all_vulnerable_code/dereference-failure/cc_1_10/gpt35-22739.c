//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef enum {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOLEAN,
    JSON_NULL
} json_type;

typedef struct {
    json_type type;
    union {
        char *str;
        double num;
        int boolean;
        void *obj;
    } data;
} json_value;

json_value *parse_value(const char **string);
json_value *parse_object(const char **string);
json_value *parse_array(const char **string);
json_value *parse_string(const char **string);
json_value *parse_number(const char **string);
json_value *parse_boolean(const char **string);
json_value *parse_null(const char **string);

json_value *parse_value(const char **string) {
    json_value *result;
    switch (**string) {
        case '{':
            result = parse_object(string);
            break;
        case '[':
            result = parse_array(string);
            break;
        case '\"':
            result = parse_string(string);
            break;
        case 't':
        case 'f':
            result = parse_boolean(string);
            break;
        case 'n':
            result = parse_null(string);
            break;
        default:
            if (isdigit(**string) || **string == '-')
                result = parse_number(string);
            else
                result = NULL;
            break;
    }
    return result;
}

json_value *parse_object(const char **string) {
    json_value *result = malloc(sizeof(json_value));
    result->type = JSON_OBJECT;
    (*string)++;
    while (**string != '}') {
        json_value *key = parse_string(string);
        (*string)++; /* Skip the colon */
        json_value *value = parse_value(string);
        /* Store the key-value pair somewhere */
    }
    (*string)++;
    return result;
}

json_value *parse_array(const char **string) {
    json_value *result = malloc(sizeof(json_value));
    result->type = JSON_ARRAY;
    (*string)++;
    while (**string != ']') {
        json_value *value = parse_value(string);
        /* Store the value somewhere */
    }
    (*string)++;
    return result;
}

json_value *parse_string(const char **string) {
    json_value *result = malloc(sizeof(json_value));
    result->type = JSON_STRING;
    (*string)++;
    char *buf = malloc(256);
    int i = 0;
    while (**string != '\"') {
        /* Copy characters to the buffer */
        buf[i++] = **string;
        (*string)++;
    }
    buf[i] = '\0';
    result->data.str = buf;
    return result;
}

json_value *parse_number(const char **string) {
    json_value *result = malloc(sizeof(json_value));
    result->type = JSON_NUMBER;
    char *endptr;
    result->data.num = strtod(*string, &endptr);
    *string = endptr;
    return result;
}

json_value *parse_boolean(const char **string) {
    json_value *result = malloc(sizeof(json_value));
    result->type = JSON_BOOLEAN;
    if (**string == 't') {
        result->data.boolean = 1;
        *string += 4;
    } else {
        result->data.boolean = 0;
        *string += 5;
    }
    return result;
}

json_value *parse_null(const char **string) {
    json_value *result = malloc(sizeof(json_value));
    result->type = JSON_NULL;
    *string += 4;
    return result;
}

int main() {
    const char *test_string = "{\"foo\":\"bar\",\"baz\":42}";
    json_value *result = parse_value(&test_string);
    switch (result->type) {
        case JSON_OBJECT:
            printf("Object\n");
            break;
        case JSON_ARRAY:
            printf("Array\n");
            break;
        case JSON_STRING:
            printf("String: %s\n", result->data.str);
            break;
        case JSON_NUMBER:
            printf("Number: %f\n", result->data.num);
            break;
        case JSON_BOOLEAN:
            printf("Boolean: %d\n", result->data.boolean);
            break;
        case JSON_NULL:
            printf("Null\n");
            break;
    }
    return 0;
}