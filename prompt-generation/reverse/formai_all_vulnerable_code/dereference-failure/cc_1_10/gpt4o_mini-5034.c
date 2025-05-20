//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 8192
#define MAX_TOKEN_SIZE 256

typedef enum {
    JSON_NULL,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NUMBER,
    JSON_STRING,
    JSON_OBJECT,
    JSON_ARRAY
} json_type;

typedef struct json_value {
    json_type type;
    union {
        double number;
        char *string;
        struct json_value *object; // Placeholder for potential key-value pairs in objects
        struct json_value *array; // Placeholder for potential values in arrays
    };
} json_value;

void skip_whitespace(const char **json) {
    while (isspace(**json)) {
        (*json)++;
    }
}

json_value *parse_value(const char **json);
json_value *parse_object(const char **json);
json_value *parse_array(const char **json);
json_value *parse_string(const char **json);
json_value *parse_number(const char **json);
void free_json_value(json_value *value);

json_value *parse_json(const char *json) {
    json_value *value = parse_value(&json);
    return value;
}

json_value *parse_object(const char **json) {
    json_value *obj = (json_value *)malloc(sizeof(json_value));
    obj->type = JSON_OBJECT;

    (*json)++; // skip '{'
    skip_whitespace(json);
    // Implement parsing of key-value pairs in this method
    // This is a placeholder for simplicity
    if (**json == '}') {
        (*json)++;
        return obj;
    }

    // In a complete implementation, you would parse key-value pairs here
    // For the purpose of this illustration, just return the empty object.
    
    return obj; 
}

json_value *parse_array(const char **json) {
    json_value *arr = (json_value *)malloc(sizeof(json_value));
    arr->type = JSON_ARRAY;

    (*json)++; // skip '['
    skip_whitespace(json);
    // Implement parsing of array values in this method
    // This is a placeholder for simplicity
    if (**json == ']') {
        (*json)++;
        return arr;
    }

    // In a complete implementation, you would parse array values here.
    
    return arr; 
}

json_value *parse_string(const char **json) {
    json_value *str_value = (json_value *)malloc(sizeof(json_value));
    str_value->type = JSON_STRING;

    const char *start = ++(*json); // skip '"'
    while (**json && **json != '"') {
        (*json)++;
    }
    
    size_t length = *json - start;
    str_value->string = (char *)malloc(length + 1);
    strncpy(str_value->string, start, length);
    str_value->string[length] = '\0';
    (*json)++; // skip '"'

    return str_value;
}

json_value *parse_number(const char **json) {
    json_value *num_value = (json_value *)malloc(sizeof(json_value));
    num_value->type = JSON_NUMBER;

    char buffer[MAX_TOKEN_SIZE];
    int i = 0;
    while (isdigit(**json) || **json == '.' || **json == '-') {
        buffer[i++] = *(*json)++;
    }
    buffer[i] = '\0';
    num_value->number = atof(buffer);

    return num_value;
}

json_value *parse_value(const char **json) {
    skip_whitespace(json);
    
    switch (**json) {
        case '{':
            return parse_object(json);
        case '[':
            return parse_array(json);
        case '"':
            return parse_string(json);
        case 't':
            (*json) += 4; // Skip "true"
            json_value *true_val = (json_value *)malloc(sizeof(json_value));
            true_val->type = JSON_TRUE;
            return true_val;
        case 'f':
            (*json) += 5; // Skip "false"
            json_value *false_val = (json_value *)malloc(sizeof(json_value));
            false_val->type = JSON_FALSE;
            return false_val;
        default:
            if (isdigit(**json) || **json == '-') {
                return parse_number(json);
            }
            break;
    }
    return NULL;
}

void free_json_value(json_value *value) {
    if (value) {
        if (value->type == JSON_STRING) {
            free(value->string);
        }
        free(value);
    }
}

int main() {
    const char *json_example = "{\"key1\": \"value1\", \"key2\": 100}";
    json_value *parsed_json = parse_json(json_example);
    // Further processing can occur here...
    free_json_value(parsed_json);
    return 0;
}