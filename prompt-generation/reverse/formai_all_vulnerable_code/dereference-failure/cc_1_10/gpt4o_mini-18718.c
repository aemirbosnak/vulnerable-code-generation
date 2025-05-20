//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum {
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_OBJECT,
    JSON_ARRAY
} JsonType;

typedef struct JsonValue {
    JsonType type;
    union {
        int boolean;
        double number;
        char *string;
        struct JsonValue *object; // Could point to actual structure for key-value pairs
        struct JsonValue *array;   // Could point to actual structure for elements
    };
} JsonValue;

void trim_whitespace(char **str) {
    while (isspace(**str)) (*str)++;
}

JsonValue *parse_json_value(char **json);
JsonValue *parse_json_object(char **json);
JsonValue *parse_json_array(char **json);
char *parse_json_string(char **json);

JsonValue *parse_json_value(char **json) {
    trim_whitespace(json);
    if (**json == 'n') {
        (*json) += 4;
        JsonValue *value = malloc(sizeof(JsonValue));
        value->type = JSON_NULL;
        return value;
    } else if (**json == 't' || **json == 'f') {
        JsonValue *value = malloc(sizeof(JsonValue));
        value->type = JSON_BOOLEAN;
        if (**json == 't') {
            value->boolean = 1;
            (*json) += 4;
        } else {
            value->boolean = 0;
            (*json) += 5;
        }
        return value;
    } else if (isdigit(**json) || **json == '-') {
        JsonValue *value = malloc(sizeof(JsonValue));
        value->type = JSON_NUMBER;
        value->number = strtod(*json, json);
        return value;
    } else if (**json == '"') {
        JsonValue *value = malloc(sizeof(JsonValue));
        value->type = JSON_STRING;
        value->string = parse_json_string(json);
        return value;
    } else if (**json == '{') {
        return parse_json_object(json);
    } else if (**json == '[') {
        return parse_json_array(json);
    }
    return NULL; 
}

char *parse_json_string(char **json) {
    char *start = ++(*json);
    while (**json && **json != '"') {
        if (**json == '\\') (*json)++; // Skip escaping character
        (*json)++;
    }
    int length = *json - start;
    char *string = malloc(length + 1);
    strncpy(string, start, length);
    string[length] = '\0';
    (*json)++; // Skip closing quote
    return string;
}

JsonValue *parse_json_object(char **json) {
    (*json)++; // Skip '{'
    JsonValue *object = malloc(sizeof(JsonValue));
    object->type = JSON_OBJECT;
    // In a full implementation, you would structure further for key-value pairs
    while (**json) {
        trim_whitespace(json);
        if (**json == '}') {
            (*json)++;
            break;
        }
        char *key = parse_json_string(json);
        trim_whitespace(json);
        if (**json != ':') {
            free(key);
            return NULL; // Error
        }
        (*json)++; // Skip ':'
        JsonValue *value = parse_json_value(json);
        // Add key-value pair logic here
        free(key);
        trim_whitespace(json);
        if (**json == ',') (*json)++;
    }
    return object;
}

JsonValue *parse_json_array(char **json) {
    (*json)++; // Skip '['
    JsonValue *array = malloc(sizeof(JsonValue)); // Placeholder for array handling
    array->type = JSON_ARRAY;
    // In a full implementation, you would structure further for elements
    while (**json) {
        trim_whitespace(json);
        if (**json == ']') {
            (*json)++;
            break;
        }
        JsonValue *value = parse_json_value(json);
        // Add element to array logic here
        if (**json == ',') (*json)++;
    }
    return array;
}

int main() {
    char json_data[] = "{\"key1\": \"value1\", \"key2\": 100, \"key3\": true, \"key4\": null}";
    char *json_ptr = json_data;

    JsonValue *parsed_json = parse_json_value(&json_ptr);
    
    // Perform operations on parsed_json 
    // (For simplicity, we just clean up memory here)
    
    free(parsed_json); // Extend this to free all nested structures appropriately
    printf("JSON Parsed Successfully!\n");
    return 0;
}