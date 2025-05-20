//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: expert-level
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
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_ERROR
} JsonType;

typedef struct JsonValue {
    JsonType type;
    union {
        double number;
        char *string;
        struct JsonValue *object;
        struct JsonValue *array;
    } value;
    struct JsonValue *next; // For linked structures
} JsonValue;

// Function prototypes
JsonValue *parse_json(const char *json);
JsonValue *parse_value(const char **json);
JsonValue *parse_object(const char **json);
JsonValue *parse_array(const char **json);
JsonValue *parse_string(const char **json);
JsonValue *parse_number(const char **json);
void trim_whitespace(const char **json);
void free_json(JsonValue *value);
void print_json(JsonValue *value, int indent);

// Entry point of the program
int main() {
    const char *json_input = "{\"name\": \"John\", \"age\": 30, \"isStudent\": false, \"courses\": [\"Math\", \"Science\"]}";
    
    JsonValue *json_value = parse_json(json_input);
    if (json_value && json_value->type != JSON_ERROR) {
        print_json(json_value, 0);
    } else {
        printf("Error parsing JSON.\n");
    }
    
    free_json(json_value);
    return 0;
}

// Function to parse JSON string and return the root value
JsonValue *parse_json(const char *json) {
    return parse_value(&json);
}

// Parse the main value based on its type
JsonValue *parse_value(const char **json) {
    trim_whitespace(json);
    if (**json == '{') {
        return parse_object(json);
    } else if (**json == '[') {
        return parse_array(json);
    } else if (**json == '"') {
        return parse_string(json);
    } else if (isdigit(**json) || **json == '-') {
        return parse_number(json);
    } else if (strncmp(*json, "true", 4) == 0) {
        *json += 4;
        JsonValue *value = malloc(sizeof(JsonValue));
        value->type = JSON_TRUE;
        return value;
    } else if (strncmp(*json, "false", 5) == 0) {
        *json += 5;
        JsonValue *value = malloc(sizeof(JsonValue));
        value->type = JSON_FALSE;
        return value;
    } else if (strncmp(*json, "null", 4) == 0) {
        *json += 4;
        JsonValue *value = malloc(sizeof(JsonValue));
        value->type = JSON_NULL;
        return value;
    }
    
    return NULL; // Error
}

// Parse JSON objects
JsonValue *parse_object(const char **json) {
    JsonValue *object = malloc(sizeof(JsonValue));
    object->type = JSON_OBJECT;
    object->next = NULL;

    (*json)++; // Skip '{'
    trim_whitespace(json);
    
    while (**json != '}') {
        JsonValue *key = parse_string(json);
        if (!key) return NULL;
        
        trim_whitespace(json);
        
        if (**json != ':') return NULL;
        (*json)++;
        
        JsonValue *value = parse_value(json);
        if (!value) return NULL;
        
        // Link key-value pairs
        key->next = value;
        object->next = key; // First key-value pair is the head

        trim_whitespace(json);
        if (**json == ',') {
            (*json)++;
        }
        trim_whitespace(json);
    }
    
    (*json)++; // Skip '}'
    return object;
}

// Parse JSON arrays
JsonValue *parse_array(const char **json) {
    JsonValue *array = malloc(sizeof(JsonValue));
    array->type = JSON_ARRAY;
    array->next = NULL;

    (*json)++; // Skip '['
    trim_whitespace(json);
    
    while (**json != ']') {
        JsonValue *value = parse_value(json);
        if (!value) return NULL;

        value->next = array->next; // Add to the start of the list
        array->next = value;

        trim_whitespace(json);
        if (**json == ',') {
            (*json)++;
        }
        trim_whitespace(json);
    }
    
    (*json)++; // Skip ']'
    return array;
}

// Parse JSON strings
JsonValue *parse_string(const char **json) {
    (*json)++; // Skip '"'
    const char *start = *json;
    while (**json != '"' && **json != '\0') {
        (*json)++;
    }
    
    if (**json != '"') return NULL; // Error: Unmatched quote
    
    size_t length = *json - start;
    JsonValue *string_value = malloc(sizeof(JsonValue));
    string_value->type = JSON_STRING;
    string_value->value.string = malloc(length + 1);
    strncpy(string_value->value.string, start, length);
    string_value->value.string[length] = '\0';
    
    (*json)++; // Skip closing '"'
    return string_value;
}

// Parse JSON numbers
JsonValue *parse_number(const char **json) {
    char *end;
    JsonValue *number_value = malloc(sizeof(JsonValue));
    number_value->type = JSON_NUMBER;
    number_value->value.number = strtod(*json, &end);
    *json = end; // Point to the character after the number
    return number_value;
}

// Trim whitespace in the JSON string
void trim_whitespace(const char **json) {
    while (isspace(**json)) {
        (*json)++;
    }
}

// Free allocated JSON value
void free_json(JsonValue *value) {
    if (value) {
        if (value->type == JSON_STRING) {
            free(value->value.string);
        } else if (value->type == JSON_OBJECT || value->type == JSON_ARRAY) {
            JsonValue *current = value->next;
            while (current) {
                JsonValue *next = current->next;
                free_json(current);
                current = next;
            }
        }
        free(value);
    }
}

// Print JSON values in a readable format
void print_json(JsonValue *value, int indent) {
    if (!value) return;

    for (int i = 0; i < indent; i++) putchar(' ');

    switch (value->type) {
        case JSON_OBJECT:
            putchar('{');
            for (JsonValue *current = value->next; current; current = current->next) {
                print_json(current, indent + 2);
                if (current->next) printf(", ");
            }
            putchar('}');
            break;
        case JSON_ARRAY:
            putchar('[');
            for (JsonValue *current = value->next; current; current = current->next) {
                print_json(current, indent + 2);
                if (current->next) printf(", ");
            }
            putchar(']');
            break;
        case JSON_STRING:
            printf("\"%s\"", value->value.string);
            break;
        case JSON_NUMBER:
            printf("%f", value->value.number);
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
        default:
            break;
    }
}