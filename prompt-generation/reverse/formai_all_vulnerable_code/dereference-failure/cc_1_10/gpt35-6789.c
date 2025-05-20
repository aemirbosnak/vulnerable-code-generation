//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { JSON_STRING, JSON_NUMBER, JSON_OBJECT, JSON_ARRAY, JSON_TRUE, JSON_FALSE, JSON_NULL } json_type;

/* Data structure representing a JSON value */
typedef struct json_value {
    json_type type;
    union {
        char* string_value;
        double number_value;
        struct json_object* object_value;
        struct json_array* array_value;
    } value;
} json_value;

/* Data structure representing a JSON object */
typedef struct json_object {
    char* name;
    json_value* value;
    struct json_object* next;
} json_object;

/* Data structure representing a JSON array */
typedef struct json_array {
    json_value* value;
    struct json_array* next;
} json_array;

/* Forward declarations */
static json_value* parse_json_value(const char** input);
static json_object* parse_json_object(const char** input);
static json_array* parse_json_array(const char** input);

/* Parses a JSON string */
static char* parse_json_string(const char** input) {
    size_t str_len = 0;
    const char* str_start = ++(*input);

    while (**input != '"') {
        if (**input == '\\') {
            ++(*input);
        }
        ++(*input);
    }
    str_len = *input - str_start;
    ++(*input);

    char* str = (char*)malloc(sizeof(char) * (str_len + 1));
    memcpy(str, str_start, str_len);
    str[str_len] = '\0';

    return str;
}

/* Parses a JSON number */
static double parse_json_number(const char** input) {
    double num;
    sscanf(*input, "%lf", &num);
    while (**input && (**input == '-' || (**input >= '0' && **input <= '9') || **input == '.')) {
        ++(*input);
    }
    return num;
}

/* Parses a JSON value */
static json_value* parse_json_value(const char** input) {
    json_value* value = (json_value*)malloc(sizeof(json_value));

    switch (**input) {
        case '"':
            value->type = JSON_STRING;
            value->value.string_value = parse_json_string(input);
            break;
        case '-': // fallthrough
        case '0': // fallthrough
        case '1': // fallthrough
        case '2': // fallthrough
        case '3': // fallthrough
        case '4': // fallthrough
        case '5': // fallthrough
        case '6': // fallthrough
        case '7': // fallthrough
        case '8': // fallthrough
        case '9':
            value->type = JSON_NUMBER;
            value->value.number_value = parse_json_number(input);
            break;
        case '{':
            value->type = JSON_OBJECT;
            value->value.object_value = parse_json_object(input);
            break;
        case '[':
            value->type = JSON_ARRAY;
            value->value.array_value = parse_json_array(input);
            break;
        case 't':
            value->type = JSON_TRUE;
            ++(*input);
            break;
        case 'f':
            value->type = JSON_FALSE;
            ++(*input);
            break;
        case 'n':
            value->type = JSON_NULL;
            ++(*input);
            break;
    }

    return value;
}

/* Parses a JSON object */
static json_object* parse_json_object(const char** input) {
    json_object* object = NULL;
    json_object* prev = NULL;

    ++(*input); // skip '{'

    while (**input != '}') {
        if (**input == ',') {
            ++(*input);
        }

        json_object* cur = (json_object*)malloc(sizeof(json_object));
        cur->name = parse_json_string(input);
        ++(*input); // skip ':'
        cur->value = parse_json_value(input);
        cur->next = NULL;

        if (prev) {
            prev->next = cur;
        } else {
            object = cur;
        }
        prev = cur;
    }

    ++(*input); // skip '}'

    return object;
}

/* Parses a JSON array */
static json_array* parse_json_array(const char** input) {
    json_array* array = NULL;
    json_array* prev = NULL;

    ++(*input); // skip '['

    while (**input != ']') {
        if (**input == ',') {
            ++(*input);
        }

        json_array* cur = (json_array*)malloc(sizeof(json_array));
        cur->value = parse_json_value(input);
        cur->next = NULL;

        if (prev) {
            prev->next = cur;
        } else {
            array = cur;
        }
        prev = cur;
    }

    ++(*input); // skip ']'

    return array;
}

/* Example program using the JSON parser */
int main(void) {
    const char* json_str = "{\"foo\": [1,2,3], \"bar\": {\"baz\": true, \"qux\": null}}";
    printf("Original JSON string:\n%s\n", json_str);

    json_object* obj = parse_json_object(&json_str);
    printf("Parsed JSON object:\n{\n");
    json_object* cur_obj = obj;
    while (cur_obj) {
        printf("  \"%s\": ", cur_obj->name);
        json_value* value = cur_obj->value;
        switch (value->type) {
            case JSON_STRING:
                printf("\"%s\"", value->value.string_value);
                break;
            case JSON_NUMBER:
                printf("%g", value->value.number_value);
                break;
            case JSON_OBJECT:
                // recurse on value->object_value
                break;
            case JSON_ARRAY:
                // recurse on value->array_value
                break;
            case JSON_TRUE:
                printf("true");
                break;
            case JSON_FALSE:
                printf("false");
                break;
            case JSON_NULL:
                printf("null");
                break;
        }
        printf(",\n");
        cur_obj = cur_obj->next;
    }
    printf("}\n");

    return 0;
}