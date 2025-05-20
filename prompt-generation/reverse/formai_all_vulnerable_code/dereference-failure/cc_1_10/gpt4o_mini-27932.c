//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 1024
#define MAX_KEY_SIZE 100

typedef enum {
    JSON_TYPE_STRING,
    JSON_TYPE_NUMBER,
    JSON_TYPE_OBJECT,
    JSON_TYPE_ARRAY,
    JSON_TYPE_BOOLEAN,
    JSON_TYPE_NULL
} json_type;

typedef struct JsonValue {
    json_type type;
    char *key;
    union {
        char *string_value;
        double number_value;
        struct JsonValue *object_value;
        struct JsonValue *array_value;
        int boolean_value;
    };
    struct JsonValue *next;
} JsonValue;

JsonValue* create_json_value(json_type type, const char *key) {
    JsonValue *value = (JsonValue*) malloc(sizeof(JsonValue));
    value->type = type;
    value->key = key ? strdup(key) : NULL;
    value->next = NULL;
    return value;
}

void free_json_value(JsonValue *value) {
    if (value) {
        if (value->key) free(value->key);
        if (value->type == JSON_TYPE_STRING && value->string_value) {
            free(value->string_value);
        }
        free(value);
    }
}

void print_json_value(JsonValue *value) {
    if (!value) return;

    switch (value->type) {
        case JSON_TYPE_STRING:
            printf("\"%s\": \"%s\"\n", value->key, value->string_value);
            break;
        case JSON_TYPE_NUMBER:
            printf("\"%s\": %f\n", value->key, value->number_value);
            break;
        case JSON_TYPE_BOOLEAN:
            printf("\"%s\": %s\n", value->key, value->boolean_value ? "true" : "false");
            break;
        case JSON_TYPE_NULL:
            printf("\"%s\": null\n", value->key);
            break;
        case JSON_TYPE_OBJECT:
        case JSON_TYPE_ARRAY:
            printf("\"%s\": ", value->key);
            // Print nested objects or arrays here (not implemented in this snippet)
            break;
        default:
            printf("Unknown type\n");
    }
}

char* skip_whitespace(char *str) {
    while (*str && isspace(*str)) str++;
    return str;
}

char* parse_string(char **json) {
    char *start = ++(*json); // Skip the opening quote
    while (**json && **json != '\"') {
        (*json)++;
    }
    if (**json == '\"') {
        size_t len = *json - start;
        char *str = (char*) malloc(len + 1);
        strncpy(str, start, len);
        str[len] = '\0';
        (*json)++;
        return str;
    }
    return NULL;
}

JsonValue* parse_json(char *json) {
    json = skip_whitespace(json);
    if (*json != '{') return NULL; // Simplified; we expect an object

    JsonValue *head = NULL, *current = NULL;
    json++; // Skip the opening curly brace

    while (*json != '}') {
        json = skip_whitespace(json);
        char *key = parse_string(&json);
        json = skip_whitespace(json);
        if (*json++ != ':') return NULL; // Expect colon

        json = skip_whitespace(json);
        JsonValue *value = create_json_value(JSON_TYPE_STRING, key);
        value->string_value = parse_string(&json);

        // Link the value to the list
        if (!head) {
            head = value;
        } else {
            current->next = value;
        }
        current = value;

        json = skip_whitespace(json);
        if (*json == ',') json++; // skip comma for the next pair
    }
    json++; // Skip the closing curly brace
    return head;
}

void free_json_list(JsonValue *head) {
    JsonValue *current = head;
    while (current) {
        JsonValue *next = current->next;
        free_json_value(current);
        current = next;
    }
}

int main() {
    char json[MAX_JSON_SIZE] = "{\"name\": \"John Doe\", \"age\": 30, \"alive\": true}";

    JsonValue *parsed_json = parse_json(json);
    if (parsed_json) {
        printf("Parsed JSON:\n");
        print_json_value(parsed_json);
        free_json_list(parsed_json);
    } else {
        printf("Failed to parse JSON.\n");
    }

    return 0;
}