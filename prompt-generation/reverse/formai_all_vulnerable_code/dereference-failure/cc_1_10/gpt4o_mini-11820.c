//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    JSON_TYPE_NULL,
    JSON_TYPE_BOOLEAN,
    JSON_TYPE_NUMBER,
    JSON_TYPE_STRING,
    JSON_TYPE_ARRAY,
    JSON_TYPE_OBJECT
} json_type;

typedef struct json_value {
    json_type type;
    union {
        int boolean;       // For boolean values
        double number;     // For numeric values
        char *string;      // For string values
        struct json_value **array; // For array values
        struct json_value **object; // For object key-value pairs
    } data;
    size_t size;         // Size for arrays and objects
} json_value;

void parse_error(const char *message) {
    fprintf(stderr, "JSON Parse Error: %s\n", message);
    exit(EXIT_FAILURE);
}

void skip_whitespace(const char **json) {
    while (isspace(**json)) (*json)++;
}

json_value *parse_value(const char **json);

json_value *parse_object(const char **json) {
    json_value *object = malloc(sizeof(json_value));
    object->type = JSON_TYPE_OBJECT;
    object->size = 0;
    object->data.object = malloc(10 * sizeof(json_value*)); // Initial size for demonstration

    skip_whitespace(json);
    if (**json != '{') {
        parse_error("Expected '{' at the start of an object");
    }
    (*json)++; // Skip '{'

    while (1) {
        skip_whitespace(json);
        if (**json == '}') {
            (*json)++;
            break;
        }
        
        if (object->size >= 10) { // Check capacity
            parse_error("Object capacity exceeded");
        }

        // Parse key
        json_value *key = parse_value(json);
        if (key->type != JSON_TYPE_STRING) {
            parse_error("Key must be a string");
        }

        skip_whitespace(json);
        if (**json != ':') {
            parse_error("Expected ':' after key");
        }
        (*json)++; // Skip ':'

        // Parse value
        json_value *value = parse_value(json);

        // Store the key-value pair
        object->data.object[object->size++] = key;
        object->data.object[object->size++] = value;

        skip_whitespace(json);
        if (**json == '}') {
            (*json)++;
            break;
        } else if (**json != ',') {
            parse_error("Expected ',' or '}' in object");
        }
        (*json)++; // Skip ','
    }
    return object;
}

json_value *parse_array(const char **json) {
    json_value *array = malloc(sizeof(json_value));
    array->type = JSON_TYPE_ARRAY;
    array->size = 0;
    array->data.array = malloc(10 * sizeof(json_value*)); // Initial size for demonstration

    skip_whitespace(json);
    if (**json != '[') {
        parse_error("Expected '[' at the start of an array");
    }
    (*json)++; // Skip '['

    while (1) {
        skip_whitespace(json);
        if (**json == ']') {
            (*json)++;
            break;
        }

        if (array->size >= 10) { // Check capacity
            parse_error("Array capacity exceeded");
        }

        // Parse value
        json_value *value = parse_value(json);
        array->data.array[array->size++] = value;

        skip_whitespace(json);
        if (**json == ']') {
            (*json)++;
            break;
        } else if (**json != ',') {
            parse_error("Expected ',' or ']' in array");
        }
        (*json)++; // Skip ','
    }
    return array;
}

json_value *parse_string(const char **json) {
    json_value *string_value = malloc(sizeof(json_value));
    string_value->type = JSON_TYPE_STRING;

    skip_whitespace(json);
    if (**json != '\"') {
        parse_error("Expected '\"' at the start of a string");
    }
    (*json)++; // Skip '\"'

    const char *start = *json;
    while (**json && **json != '\"') {
        if (**json == '\\') (*json)++; // Skip escape character
        (*json)++;
    }

    if (**json != '\"') {
        parse_error("Expected '\"' at the end of a string");
    }

    size_t length = *json - start;
    string_value->data.string = malloc(length + 1);
    strncpy(string_value->data.string, start, length);
    string_value->data.string[length] = '\0';
    (*json)++; // Skip '\"'
    return string_value;
}

json_value *parse_number(const char **json) {
    json_value *number_value = malloc(sizeof(json_value));
    number_value->type = JSON_TYPE_NUMBER;

    char *end;
    number_value->data.number = strtod(*json, &end);
    if (*json == end) {
        parse_error("Expected a number");
    }
    *json = end; // Move pointer to after the number
    return number_value;
}

json_value *parse_boolean(const char **json) {
    json_value *boolean_value = malloc(sizeof(json_value));
    boolean_value->type = JSON_TYPE_BOOLEAN;

    if (strncmp(*json, "true", 4) == 0) {
        boolean_value->data.boolean = 1;
        *json += 4;
    } else if (strncmp(*json, "false", 5) == 0) {
        boolean_value->data.boolean = 0;
        *json += 5;
    } else {
        parse_error("Expected 'true' or 'false'");
    }
    return boolean_value;
}

json_value *parse_null(const char **json) {
    json_value *null_value = malloc(sizeof(json_value));
    null_value->type = JSON_TYPE_NULL;

    if (strncmp(*json, "null", 4) != 0) {
        parse_error("Expected 'null'");
    }
    *json += 4; // Skip 'null'
    return null_value;
}

json_value *parse_value(const char **json) {
    skip_whitespace(json);
    
    if (**json == '{') {
        return parse_object(json);
    } else if (**json == '[') {
        return parse_array(json);
    } else if (**json == '\"') {
        return parse_string(json);
    } else if (isdigit(**json) || **json == '-') {
        return parse_number(json);
    } else if (strncmp(*json, "true", 4) == 0 || strncmp(*json, "false", 5) == 0) {
        return parse_boolean(json);
    } else if (strncmp(*json, "null", 4) == 0) {
        return parse_null(json);
    }

    parse_error("Unexpected character while parsing value");
    return NULL; // Unreachable
}

void free_json_value(json_value *value) {
    if (!value) return;

    switch (value->type) {
        case JSON_TYPE_STRING:
            free(value->data.string);
            break;
        case JSON_TYPE_ARRAY:
            for (size_t i = 0; i < value->size; i++) {
                free_json_value(value->data.array[i]);
            }
            free(value->data.array);
            break;
        case JSON_TYPE_OBJECT:
            for (size_t i = 0; i < value->size; i += 2) {
                free_json_value(value->data.object[i]);
                free_json_value(value->data.object[i + 1]);
            }
            free(value->data.object);
            break;
        default:
            break;
    }
    free(value);
}

int main() {
    const char *json_input = "{\"name\": \"John\", \"age\": 30, \"is_student\": false, \"courses\": [\"Math\", \"Science\"]}";
    const char *json_pointer = json_input;

    json_value *parsed = parse_value(&json_pointer);
    printf("Parsed JSON successfully!\n");

    // Free allocated memory
    free_json_value(parsed);

    return 0;
}