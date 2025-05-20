//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_SIZE 256

typedef enum {
    JSON_NULL,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JsonType;

typedef struct JsonValue {
    JsonType type;
    union {
        char *string_value;
        double number_value;
        struct JsonValue *array_value; // Dynamic array of JsonValues
        struct JsonValue *object_value; // Dynamic objects 
    } value;
    struct JsonValue *next; // For linked list of array or object elements
} JsonValue;

// Function declarations
JsonValue *parse_json(const char *json);
void free_json(JsonValue *value);
void print_json(JsonValue *value, int indent);

// Utility functions
static void skip_whitespace(const char **json) {
    while (isspace(**json)) (*json)++;
}

static char *parse_string(const char **json) {
    const char *start = ++(*json);
    while (**json != '"' && **json != '\0') {
        if (**json == '\\') (*json)++; // Skip escaped characters
        (*json)++;
    }
    int length = *json - start;
    char *string_value = (char *)malloc(length + 1);
    strncpy(string_value, start, length);
    string_value[length] = '\0';
    (*json)++; // Move past closing quote
    return string_value;
}

static double parse_number(const char **json) {
    char *end;
    double number = strtod(*json, &end);
    *json = end; // Move pointer to the end of parsed number
    return number;
}

// Main parsing function
JsonValue *parse_value(const char **json) {
    skip_whitespace(json);
    
    JsonValue *value = (JsonValue *)malloc(sizeof(JsonValue));
    
    switch (**json) {
        case '"':
            value->type = JSON_STRING;
            value->value.string_value = parse_string(json);
            break;
        case 't':
            value->type = JSON_TRUE;
            (*json) += 4; // Skip "true"
            break;
        case 'f':
            value->type = JSON_FALSE;
            (*json) += 5; // Skip "false"
            break;
        case 'n':
            value->type = JSON_NULL;
            (*json) += 4; // Skip "null"
            break;
        case '[':
            // Handle arrays...
            (*json)++;
            value->type = JSON_ARRAY;
            // For simplicity, just create a placeholder here
            // TODO: Proper array parsing
            break;
        case '{':
            // Handle objects...
            (*json)++;
            value->type = JSON_OBJECT;
            // For simplicity, just create a placeholder here
            // TODO: Proper object parsing
            break;
        default:
            if (isdigit(**json) || **json == '-') {
                value->type = JSON_NUMBER;
                value->value.number_value = parse_number(json);
            } else {
                fprintf(stderr, "Unexpected character: %c\n", **json);
                free(value);
                return NULL;
            }
    }
    return value;
}

// The primary function to parse JSON input
JsonValue *parse_json(const char *json) {
    return parse_value(&json);
}

// Print the parsed JSON (For debugging)
void print_json(JsonValue *value, int indent) {
    if (!value) return;
    
    for (int i = 0; i < indent; i++) printf("  "); // Indentation
    switch (value->type) {
        case JSON_NULL: printf("null\n"); break;
        case JSON_TRUE: printf("true\n"); break;
        case JSON_FALSE: printf("false\n"); break;
        case JSON_NUMBER: printf("%f\n", value->value.number_value); break;
        case JSON_STRING: printf("\"%s\"\n", value->value.string_value); break;
        case JSON_ARRAY:
            printf("[\n");
            // For simplicity, skipping detailed array elements
            for (int i = 0; i < indent + 1; i++) print_json(NULL, indent + 1); // Placeholder
            for (int i = 0; i < indent; i++) printf("  ");
            printf("]\n");
            break;
        case JSON_OBJECT:
            printf("{\n");
            // For simplicity, skipping detailed object elements
            for (int i = 0; i < indent + 1; i++) print_json(NULL, indent + 1); // Placeholder
            for (int i = 0; i < indent; i++) printf("  ");
            printf("}\n");
            break;
    }
}

// Free allocated JSON value
void free_json(JsonValue *value) {
    if (!value) return;
    if (value->type == JSON_STRING) {
        free(value->value.string_value);
    }
    // Freeing logic for arrays and objects would go here...
    free(value);
}

int main() {
    const char *json_input = "{\"key1\":\"value1\", \"key2\":42, \"key3\":true, \"key4\":null}";
    JsonValue *parsed_json = parse_json(json_input);

    // Print the parsed JSON structure
    print_json(parsed_json, 0);

    // Clean up
    free_json(parsed_json);
    return 0;
}