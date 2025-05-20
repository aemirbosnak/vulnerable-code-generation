//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: optimized
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
    JSON_ARRAY,
    JSON_OBJECT
} json_type;

typedef struct json_value {
    json_type type;
    union {
        double number;
        char *string;
        struct json_value **array; // For JSON Arrays
        struct json_object *object; // For JSON Objects
    } value;
    size_t size;  // Used for array & object
} json_value;

typedef struct json_object {
    char **keys;
    json_value **values;
    size_t size;
} json_object;

json_value* parse_value(const char **json);
json_value* parse_number(const char **json);
json_value* parse_string(const char **json);
json_object* parse_object(const char **json);
json_value* parse_array(const char **json);

void skip_whitespace(const char **json) {
    while (isspace(**json)) (*json)++;
}

json_value* parse_json(const char *json_string) {
    const char *json = json_string;
    skip_whitespace(&json);
    json_value *value = parse_value(&json);
    skip_whitespace(&json);
    if (*json != '\0') {
        fprintf(stderr, "Unexpected character at the end of JSON input\n");
        free(value); // Clean up if parsing failed
        return NULL;
    }
    return value;
}

json_value* parse_value(const char **json) {
    skip_whitespace(json);
    if (**json == 'n') return parse_string(json); // handle "null", "true", "false", numbers, strings
    if (**json == '"') return parse_string(json);
    if (**json == '{') return (json_value*)parse_object(json);
    if (**json == '[') return parse_array(json);
    if (isdigit(**json) || **json == '-') return parse_number(json);
    return NULL;
}

json_value* parse_number(const char **json) {
    json_value *value = malloc(sizeof(json_value));
    value->type = JSON_NUMBER;
    char *end;
    value->value.number = strtod(*json, &end);
    *json = end;
    return value;
}

json_value* parse_string(const char **json) {
    json_value *value = malloc(sizeof(json_value));
    if (**json != '"') return NULL;

    (*json)++; // skip the opening quote
    const char *start = *json;
    while (**json != '"' && **json != '\0') {
        (*json)++;
    }
    size_t length = *json - start;
    value->value.string = malloc(length + 1);
    strncpy(value->value.string, start, length);
    value->value.string[length] = '\0';
    value->type = JSON_STRING;
    (*json)++; // skip the closing quote
    return value;
}

json_object* parse_object(const char **json) {
    json_object *obj = malloc(sizeof(json_object));
    obj->keys = NULL;
    obj->values = NULL;
    obj->size = 0;
    
    (*json)++; // skip '{'
    skip_whitespace(json);

    while (**json != '}') {
        skip_whitespace(json);
        json_value *key_value = parse_string(json);
        if (!key_value || key_value->type != JSON_STRING) {
            free(key_value);
            fprintf(stderr, "Failed to parse key\n");
            free(obj);
            return NULL;
        }

        skip_whitespace(json);
        if (**json != ':') {
            free(key_value->value.string);
            free(key_value);
            fprintf(stderr, "Expected ':' after key\n");
            free(obj);
            return NULL;
        }
        (*json)++; // skip ':'
        
        skip_whitespace(json);
        json_value *value = parse_value(json);
        if (!value) {
            free(key_value->value.string);
            free(key_value);
            free(obj);
            fprintf(stderr, "Failed to parse value\n");
            return NULL;
        }

        // Store the key-value pair
        obj->size++;
        obj->keys = realloc(obj->keys, obj->size * sizeof(char*));
        obj->values = realloc(obj->values, obj->size * sizeof(json_value*));
        obj->keys[obj->size - 1] = key_value->value.string;  // Store key
        obj->values[obj->size - 1] = value; // Store value
        
        skip_whitespace(json);
        if (**json == ',') {
            (*json)++; // skip ','
        } else {
            break; // end of object
        }
    }

    (*json)++; // skip '}'
    return obj;
}

json_value* parse_array(const char **json) {
    // Similar logic can go here to parse arrays
    return NULL; // Placeholder
}

void free_json_value(json_value *value) {
    if (value == NULL) return;
    if (value->type == JSON_STRING) {
        free(value->value.string);
    } else if (value->type == JSON_ARRAY) {
        // Free array values
    } else if (value->type == JSON_OBJECT) {
        // Free object keys and values
    }
    free(value);
}

int main() {
    const char *json_string = "{\"name\": \"John\", \"age\": 30, \"isStudent\": false}";
    json_value *parsed_json = parse_json(json_string);

    if (parsed_json) {
        printf("JSON parsed successfully.\n");
        // Further logic can be implemented here to utilize the parsed result
        free_json_value(parsed_json);
    } else {
        printf("Failed to parse JSON.\n");
    }

    return 0;
}