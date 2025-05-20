//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    JSON_NULL,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NUMBER,
    JSON_STRING,
    JSON_OBJECT,
    JSON_ARRAY
} JsonType;

typedef struct JsonValue {
    JsonType type;
    union {
        double number;
        char *string;
        struct JsonValue *array;
        struct {
            char *key;
            struct JsonValue *value;
        } object;
    };
    struct JsonValue *next; // For linked list structure (arrays and objects)
} JsonValue;

// Function prototypes
JsonValue *parse_json(const char *input);
void free_json(JsonValue *value);
void print_json(const JsonValue *value, int indent);

// Helper functions
void skip_whitespace(const char **json) {
    while (isspace(**json)) (*json)++;
}

JsonValue *parse_null(const char **json) {
    if (strncmp(*json, "null", 4) == 0) {
        *json += 4;
        JsonValue *value = malloc(sizeof(JsonValue));
        value->type = JSON_NULL;
        return value;
    }
    return NULL;
}

JsonValue *parse_true(const char **json) {
    if (strncmp(*json, "true", 4) == 0) {
        *json += 4;
        JsonValue *value = malloc(sizeof(JsonValue));
        value->type = JSON_TRUE;
        return value;
    }
    return NULL;
}

JsonValue *parse_false(const char **json) {
    if (strncmp(*json, "false", 5) == 0) {
        *json += 5;
        JsonValue *value = malloc(sizeof(JsonValue));
        value->type = JSON_FALSE;
        return value;
    }
    return NULL;
}

JsonValue *parse_number(const char **json) {
    char *end;
    double number = strtod(*json, &end);
    if (end != *json) {
        JsonValue *value = malloc(sizeof(JsonValue));
        value->type = JSON_NUMBER;
        value->number = number;
        *json = end;
        return value;
    }
    return NULL;
}

JsonValue *parse_string(const char **json) {
    if (**json != '"') return NULL;
    (*json)++; // Skip the opening quote
    const char *start = *json;
    while (**json != '"' && **json != '\0') {
        (*json)++;
    }
    if (**json != '"') return NULL; // Missing closing quote
    size_t length = *json - start;
    JsonValue *value = malloc(sizeof(JsonValue));
    value->type = JSON_STRING;
    value->string = malloc(length + 1);
    strncpy(value->string, start, length);
    value->string[length] = '\0';
    (*json)++; // Skip the closing quote
    return value;
}

JsonValue *parse_value(const char **json) {
    skip_whitespace(json);
    JsonValue *value = parse_null(json);
    if (value) return value;
    value = parse_true(json);
    if (value) return value;
    value = parse_false(json);
    if (value) return value;
    value = parse_number(json);
    if (value) return value;
    value = parse_string(json);
    if (value) return value;
    // TODO: Add array and object parsing
    return NULL;
}

JsonValue *parse_json(const char *input) {
    const char *json = input;
    JsonValue *value = parse_value(&json);
    skip_whitespace(&json);
    if (*json != '\0') { // If everything has not been consumed properly
        free_json(value);
        return NULL;
    }
    return value;
}

void free_json(JsonValue *value) {
    if (!value) return;
    if (value->type == JSON_STRING) free(value->string);
    // TODO: Free array and object values
    free(value);
}

void print_json(const JsonValue *value, int indent) {
    if (value == NULL) return;
    switch (value->type) {
        case JSON_NULL:
            printf("null");
            break;
        case JSON_TRUE:
            printf("true");
            break;
        case JSON_FALSE:
            printf("false");
            break;
        case JSON_NUMBER:
            printf("%f", value->number);
            break;
        case JSON_STRING:
            printf("\"%s\"", value->string);
            break;
        case JSON_OBJECT:
        case JSON_ARRAY:
            // TODO: Handle printing objects and arrays
            break;
    }
}

int main() {
    const char *json_input = "{\"key1\": \"value1\", \"key2\": null}";
    JsonValue *parsed_json = parse_json(json_input);
    if (parsed_json) {
        print_json(parsed_json, 0);
        printf("\n");
        free_json(parsed_json);
    } else {
        printf("Failed to parse JSON.\n");
    }
    return 0;
}