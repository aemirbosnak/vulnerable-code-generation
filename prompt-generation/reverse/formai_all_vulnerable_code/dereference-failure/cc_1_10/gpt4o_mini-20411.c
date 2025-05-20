//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum { JSON_NULL, JSON_BOOLEAN, JSON_NUMBER, JSON_STRING, JSON_ARRAY, JSON_OBJECT } json_type;

typedef struct json_value {
    json_type type;
    union {
        int boolean;
        double number;
        char* string;
        struct json_value* array; // pointer to first element of an array
        struct {
            char** keys;          // keys of the object
            struct json_value* values; // values corresponding to keys
            size_t size;          // number of keys/values
        } object;
    } as;
} json_value;

void skip_whitespace(const char** str) {
    while (isspace(**str)) (*str)++;
}

json_value* parse_null(const char** str) {
    if (strncmp(*str, "null", 4) == 0) {
        *str += 4;
        json_value* value = malloc(sizeof(json_value));
        value->type = JSON_NULL;
        return value;
    }
    return NULL;
}

json_value* parse_boolean(const char** str) {
    if (strncmp(*str, "true", 4) == 0) {
        *str += 4;
        json_value* value = malloc(sizeof(json_value));
        value->type = JSON_BOOLEAN;
        value->as.boolean = 1;
        return value;
    }
    if (strncmp(*str, "false", 5) == 0) {
        *str += 5;
        json_value* value = malloc(sizeof(json_value));
        value->type = JSON_BOOLEAN;
        value->as.boolean = 0;
        return value;
    }
    return NULL;
}

json_value* parse_number(const char** str) {
    char* end;
    json_value* value = malloc(sizeof(json_value));
    value->type = JSON_NUMBER;
    value->as.number = strtod(*str, &end);
    if (*str == end) {
        free(value);
        return NULL; // invalid number
    }
    *str = end;
    return value;
}

json_value* parse_string(const char** str) {
    if (**str != '\"') return NULL;
    (*str)++; // skip the opening quote

    const char* start = *str;
    while (**str && **str != '\"') {
        if (**str == '\\') (*str)++; // escape character
        (*str)++;
    }

    if (**str != '\"') return NULL; // missing closing quote
    size_t length = *str - start;

    json_value* value = malloc(sizeof(json_value));
    value->type = JSON_STRING;
    value->as.string = malloc(length + 1);
    strncpy(value->as.string, start, length);
    value->as.string[length] = '\0';
    
    (*str)++; // skip closing quote
    return value;
}

json_value* parse_value(const char** str) {
    skip_whitespace(str);
    json_value* value;

    if ((value = parse_null(str)) || 
        (value = parse_boolean(str)) ||
        (value = parse_number(str)) ||
        (value = parse_string(str))) {
        return value;
    }
    // Implement parsing for arrays and objects in practice.
    return NULL;
}

void free_json_value(json_value* value) {
    if (!value) return;
    if (value->type == JSON_STRING) {
        free(value->as.string);
    }
    free(value);
}

void print_json_value(const json_value* value) {
    if (!value) return;
    switch (value->type) {
        case JSON_NULL:
            printf("null");
            break;
        case JSON_BOOLEAN:
            printf(value->as.boolean ? "true" : "false");
            break;
        case JSON_NUMBER:
            printf("%f", value->as.number);
            break;
        case JSON_STRING:
            printf("\"%s\"", value->as.string);
            break;
        // Add cases for JSON_ARRAY and JSON_OBJECT if implemented.
        default:
            printf("Unknown type");
    }
}

int main(int argc, char* argv[]) {
    const char* json_string = "{\"key1\":\"value1\", \"key2\":42, \"key3\":true, \"key4\":null}";

    const char* str = json_string;
    json_value* value = parse_value(&str);
    if (value) {
        print_json_value(value);
        printf("\n");
        free_json_value(value);
    } else {
        printf("Failed to parse JSON.\n");
    }

    return 0;
}