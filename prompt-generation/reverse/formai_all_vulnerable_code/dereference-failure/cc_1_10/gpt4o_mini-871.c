//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum { JSON_NULL, JSON_TRUE, JSON_FALSE, JSON_NUMBER, JSON_STRING, JSON_OBJECT, JSON_ARRAY } JsonType;

typedef struct JsonValue {
    JsonType type;
    union {
        double number;              // for JSON_NUMBER
        char *string;              // for JSON_STRING
        struct JsonObject *object;  // for JSON_OBJECT
        struct JsonArray *array;    // for JSON_ARRAY
    } value;
} JsonValue;

typedef struct JsonPair {
    char *key;
    JsonValue *value;
    struct JsonPair *next;
} JsonPair;

typedef struct JsonObject {
    JsonPair *pairs;
} JsonObject;

typedef struct JsonArray {
    JsonValue **items;
    size_t size;
} JsonArray;

void free_json_value(JsonValue *value);

// Function to allocate memory for JsonValue
JsonValue *create_json_value(JsonType type) {
    JsonValue *value = (JsonValue *)malloc(sizeof(JsonValue));
    value->type = type;
    return value;
}

// Function to parse whitespace
void skip_whitespace(const char **json) {
    while (isspace(**json)) (*json)++;
}

// Function to parse string
JsonValue *parse_string(const char **json) {
    const char *start = ++(*json);
    while (**json != '"' && **json != '\0') {
        if (**json == '\\') (*json)++; // Skip escape character
        (*json)++;
    }
    size_t length = *json - start;
    JsonValue *value = create_json_value(JSON_STRING);
    value->value.string = (char *)malloc(length + 1);
    strncpy(value->value.string, start, length);
    value->value.string[length] = '\0';
    (*json)++;  // Skip closing quote
    return value;
}

// Function to parse number
JsonValue *parse_number(const char **json) {
    const char *start = *json;
    while (isdigit(**json) || **json == '-' || **json == '.') (*json)++;
    
    size_t length = *json - start;
    char *num_str = (char *)malloc(length + 1);
    strncpy(num_str, start, length);
    num_str[length] = '\0';
    
    JsonValue *value = create_json_value(JSON_NUMBER);
    value->value.number = atof(num_str);
    free(num_str);
    return value;
}

// Function to parse boolean
JsonValue *parse_boolean(const char **json) {
    if (strncmp(*json, "true", 4) == 0) {
        (*json) += 4;
        JsonValue *value = create_json_value(JSON_TRUE);
        return value;
    } else if (strncmp(*json, "false", 5) == 0) {
        (*json) += 5;
        JsonValue *value = create_json_value(JSON_FALSE);
        return value;
    }
    return NULL; // Error
}

// Function to parse JSON value
JsonValue *parse_value(const char **json) {
    skip_whitespace(json);
    JsonValue *value = NULL;
    char c = **json;

    if (c == '"') {
        value = parse_string(json);
    } else if (isdigit(c) || c == '-') {
        value = parse_number(json);
    } else if (c == 't' || c == 'f') {
        value = parse_boolean(json);
    } else if (c == '{') {
        // Object parsing not implemented for brevity
        value = create_json_value(JSON_OBJECT);
        (*json)++;
    } else if (c == '[') {
        // Array parsing not implemented for brevity
        value = create_json_value(JSON_ARRAY);
        (*json)++;
    }

    return value;
}

// Function to free JsonValue
void free_json_value(JsonValue *value) {
    if (!value) return;
    if (value->type == JSON_STRING) {
        free(value->value.string);
    } else if (value->type == JSON_OBJECT) {
        // Free object items here
    } else if (value->type == JSON_ARRAY) {
        // Free array items here
    }
    free(value);
}

int main() {
    const char *json = "{\"name\": \"John\", \"age\": 30, \"isStudent\": false}";
    const char *json_ptr = json;

    JsonValue *value = parse_value(&json_ptr);
    
    if (value) {
        printf("Parsed JSON value type: %d\n", value->type);
        free_json_value(value);
    } else {
        printf("Error parsing JSON value.\n");
    }

    return 0;
}