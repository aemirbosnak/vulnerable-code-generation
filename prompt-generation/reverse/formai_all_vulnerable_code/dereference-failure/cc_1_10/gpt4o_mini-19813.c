//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structures for JSON parsing
typedef enum { JSON_NULL, JSON_TRUE, JSON_FALSE, JSON_NUMBER, JSON_STRING, JSON_OBJECT, JSON_ARRAY } JsonType;

typedef struct JsonValue {
    JsonType type;
    union {
        double number;
        char *string;
        struct JsonValue *object;  // Simplified for illustration
        struct JsonValue *array;    // Simplified for illustration
    } value;
    struct JsonValue *next; // For chaining values in arrays and objects
} JsonValue;

// Function prototypes
JsonValue *parse_json(const char *json);
void free_json(JsonValue *value);
void print_json(const JsonValue *value, int indent);

// Error handling
void throw_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}

JsonValue *create_value(JsonType type) {
    JsonValue *value = malloc(sizeof(JsonValue));
    if (!value) throw_error("Memory allocation failed");
    value->type = type;
    value->next = NULL;
    return value;
}

// Function to trim white space
char *trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate string
    end[1] = '\0';

    return str;
}

// Function to parse numbers
JsonValue *parse_number(const char **json) {
    char *end;
    double number = strtod(*json, &end);
    *json = end;

    JsonValue *value = create_value(JSON_NUMBER);
    value->value.number = number;
    return value;
}

// Function to parse strings
JsonValue *parse_string(const char **json) {
    if (**json != '"') throw_error("Expected '\"' at the start of a string");
    
    (*json)++; // Skip opening quote
    const char *start = *json;

    while (**json && **json != '"') {
        if (**json == '\\') (*json)++; // Skip escaped character
        (*json)++;
    }

    if (**json != '"') throw_error("Expected '\"' at the end of a string");

    size_t length = *json - start;
    char *string = malloc(length + 1);
    strncpy(string, start, length);
    string[length] = '\0';
    
    (*json)++; // Skip closing quote

    JsonValue *value = create_value(JSON_STRING);
    value->value.string = string;
    return value;
}

// Function to parse JSON values
JsonValue *parse_value(const char **json) {
    *json = trim_whitespace((char *)*json);

    if (**json == 'n') { // null
        (*json) += 4;
        JsonValue *value = create_value(JSON_NULL);
        return value;
    } 
    if (**json == 't') { // true
        (*json) += 4;
        JsonValue *value = create_value(JSON_TRUE);
        return value;
    } 
    if (**json == 'f') { // false
        (*json) += 5;
        JsonValue *value = create_value(JSON_FALSE);
        return value;
    } 
    if (isdigit(**json) || **json == '-') {
        return parse_number(json);
    } 
    if (**json == '"') {
        return parse_string(json);
    }

    throw_error("Unexpected character in JSON");
    return NULL; // Unreachable but prevents warnings
}

// Parsing function that consumes the entire JSON string
JsonValue *parse_json(const char *json) {
    return parse_value(&json);
}

// Free JSON value memory
void free_json(JsonValue *value) {
    if (!value) return;

    if (value->type == JSON_STRING) {
        free(value->value.string);
    } else if (value->type == JSON_ARRAY || value->type == JSON_OBJECT) {
        // Memory freeing for arrays/objects would be implemented here
    }
    
    free(value);
}

// Print JSON value
void print_json(const JsonValue *value, int indent) {
    if (!value) return;

    for (int i = 0; i < indent; i++) printf("  ");
    
    switch (value->type) {
        case JSON_NULL:
            printf("null\n");
            break;
        case JSON_TRUE:
            printf("true\n");
            break;
        case JSON_FALSE:
            printf("false\n");
            break;
        case JSON_NUMBER:
            printf("%lf\n", value->value.number);
            break;
        case JSON_STRING:
            printf("\"%s\"\n", value->value.string);
            break;
        // Cases for object and arrays would go here
        default:
            printf("Unknown type\n");
            break;
    }
}

// Main function for testing the parser
int main() {
    const char *json_string = "{\"key1\":\"value1\", \"key2\":42, \"key3\":null}";
    JsonValue *json_value = parse_json(json_string);

    print_json(json_value, 0);
    free_json(json_value);
    
    return 0;
}