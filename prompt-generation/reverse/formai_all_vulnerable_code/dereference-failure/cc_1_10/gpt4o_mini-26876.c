//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JsonValue {
    enum { JSON_NULL, JSON_BOOLEAN, JSON_NUMBER, JSON_STRING, JSON_ARRAY, JSON_OBJECT } type;
    union {
        int boolean;        // 0 or 1
        double number;      // For numerical values
        char *string;       // For string values
        struct JsonValue **array; // Pointer to an array of JsonValue
        struct KeyValuePair *object; // Key-value pairs for JSON objects
    } value;
    size_t length; // Length for arrays and strings
} JsonValue;

typedef struct KeyValuePair {
    char *key;
    JsonValue *value;
    struct KeyValuePair *next; // Linked list for multiple key-value pairs
} KeyValuePair;

// Function Prototypes
JsonValue *parse_json(const char *json_str);
static JsonValue *parse_value(const char **str);
static JsonValue *parse_object(const char **str);
static JsonValue *parse_array(const char **str);
static JsonValue *parse_string(const char **str);
static JsonValue *parse_number(const char **str);
static JsonValue *parse_boolean(const char **str);
static JsonValue *parse_null(const char **str);
void free_json_value(JsonValue *value);
void print_json_value(const JsonValue *value, int indent);

// Main function for testing the JSON parser
int main() {
    const char *json_example = "{\"name\":\"John\", \"age\":30, \"is_student\":false, \"courses\":[\"CS101\", \"MATH123\"]}";

    JsonValue *parsed_json = parse_json(json_example);
    if (parsed_json) {
        print_json_value(parsed_json, 0);
        free_json_value(parsed_json);
    } else {
        printf("Failed to parse JSON.\n");
    }
    return 0;
}

// JSON Parsing Functions

// Parse the complete JSON string
JsonValue *parse_json(const char *json_str) {
    const char *current_position = json_str;
    return parse_value(&current_position);
}

// Parse a JSON value - can be an object, array, string, etc.
static JsonValue *parse_value(const char **str) {
    while (isspace(**str)) (*str)++; // Skip whitespace
    if (**str == '{') return parse_object(str);
    if (**str == '[') return parse_array(str);
    if (**str == '\"') return parse_string(str);
    if (isdigit(**str) || **str == '-') return parse_number(str);
    if (strncmp(*str, "true", 4) == 0) return parse_boolean(str);
    if (strncmp(*str, "false", 5) == 0) return parse_boolean(str);
    if (strncmp(*str, "null", 4) == 0) return parse_null(str);
    return NULL; // If none matched
}

// Parse JSON objects
static JsonValue *parse_object(const char **str) {
    JsonValue *obj = malloc(sizeof(JsonValue));
    obj->type = JSON_OBJECT;
    obj->value.object = NULL;

    // Move past the '{'
    (*str)++;
    while (**str != '}') {
        while (isspace(**str)) (*str)++;
        KeyValuePair *pair = malloc(sizeof(KeyValuePair));
        
        // Parsing key
        pair->key = parse_string(str)->value.string; // Assuming string returns correctly
        while (isspace(**str)) (*str)++;
        
        // Move past the colon
        if (**str == ':') (*str)++;
        
        // Parsing value
        pair->value = parse_value(str);
        pair->next = obj->value.object;
        obj->value.object = pair;

        // Check for the closing brace or comma
        while (isspace(**str)) (*str)++;
        if (**str == ',') (*str)++;
        else if (**str != '}') break; // Error handling could be here
    }
    (*str)++;
    return obj;
}

// Parse JSON arrays
static JsonValue *parse_array(const char **str) {
    JsonValue *arr = malloc(sizeof(JsonValue));
    arr->type = JSON_ARRAY;
    arr->length = 0;
    arr->value.array = malloc(10 * sizeof(JsonValue *)); // Initial size

    (*str)++;
    while (**str != ']') {
        arr->value.array[arr->length++] = parse_value(str);
        // Resize if necessary (not implementing for simplicity, just example)
        while (isspace(**str)) (*str)++;
        if (**str == ',') (*str)++;
    }
    (*str)++;
    return arr;
}

// Parse JSON strings
static JsonValue *parse_string(const char **str) {
    JsonValue *str_value = malloc(sizeof(JsonValue));
    str_value->type = JSON_STRING;

    // Move past the initial quote
    (*str)++;
    const char *start = *str;

    while (**str != '\"') {
        if (**str == '\\') (*str)++; // Handle escape sequences
        (*str)++;
    }
    
    size_t length = *str - start;
    str_value->value.string = malloc(length + 1);
    strncpy(str_value->value.string, start, length);
    str_value->value.string[length] = '\0';
    
    // Move past the closing quote
    (*str)++;
    return str_value;
}

// Parse JSON numbers
static JsonValue *parse_number(const char **str) {
    JsonValue *num_value = malloc(sizeof(JsonValue));
    num_value->type = JSON_NUMBER;
    
    char *end;
    num_value->value.number = strtod(*str, &end);
    *str = end; // Update the position in the string after number
    return num_value;
}

// Parse JSON booleans
static JsonValue *parse_boolean(const char **str) {
    JsonValue *bool_value = malloc(sizeof(JsonValue));
    bool_value->type = JSON_BOOLEAN;

    if (strncmp(*str, "true", 4) == 0) {
        bool_value->value.boolean = 1;
        *str += 4;
    } else {
        bool_value->value.boolean = 0;
        *str += 5;
    }
    return bool_value;
}

// Parse JSON null
static JsonValue *parse_null(const char **str) {
    JsonValue *null_value = malloc(sizeof(JsonValue));
    null_value->type = JSON_NULL;
    *str += 4; // Move past "null"
    return null_value;
}

// Free memory allocated for JSON value
void free_json_value(JsonValue *value) {
    if (!value) return;
    switch (value->type) {
        case JSON_STRING:
            free(value->value.string);
            break;
        case JSON_ARRAY:
            for (size_t i = 0; i < value->length; i++) {
                free_json_value(value->value.array[i]);
            }
            free(value->value.array);
            break;
        case JSON_OBJECT:
            for (KeyValuePair *pair = value->value.object; pair != NULL; ) {
                KeyValuePair *next = pair->next;
                free(pair->key);
                free_json_value(pair->value);
                free(pair);
                pair = next;
            }
            break;
        default:
            break;
    }
    free(value);
}

// Printing for visual representation
void print_json_value(const JsonValue *value, int indent) {
    if (!value) {
        printf("null\n");
        return;
    }
    for (int i = 0; i < indent; i++) printf("  ");
    switch (value->type) {
        case JSON_NULL:
            printf("null\n");
            break;
        case JSON_BOOLEAN:
            printf(value->value.boolean ? "true\n" : "false\n");
            break;
        case JSON_NUMBER:
            printf("%f\n", value->value.number);
            break;
        case JSON_STRING:
            printf("\"%s\"\n", value->value.string);
            break;
        case JSON_ARRAY:
            printf("[\n");
            for (size_t i = 0; i < value->length; i++) {
                print_json_value(value->value.array[i], indent + 1);
                if (i < value->length - 1) {
                    for (int j = 0; j < indent + 1; j++) printf("  ");
                    printf(",\n");
                }
            }
            for (int j = 0; j < indent; j++) printf("  ");
            printf("]\n");
            break;
        case JSON_OBJECT:
            printf("{\n");
            for (KeyValuePair *pair = value->value.object; pair != NULL; pair = pair->next) {
                for (int j = 0; j < indent + 1; j++) printf("  ");
                printf("\"%s\": ", pair->key);
                print_json_value(pair->value, indent + 1);
                if (pair->next) {
                    printf(",\n");
                }
            }
            for (int j = 0; j < indent; j++) printf("  ");
            printf("}\n");
            break;
    }
}