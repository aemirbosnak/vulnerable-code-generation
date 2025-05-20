//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JSONValue {
    enum { JSON_NULL, JSON_BOOL, JSON_NUMBER, JSON_STRING, JSON_ARRAY, JSON_OBJECT } type;
    union {
        int boolean;
        double number;
        char* string;
        struct JSONValue* array;
        struct JSONValue* object;
    } value;
} JSONValue;

void free_json_value(JSONValue* val);

JSONValue* parse_value(const char** json);
JSONValue* parse_string(const char** json);
JSONValue* parse_number(const char** json);
JSONValue* parse_array(const char** json);
JSONValue* parse_object(const char** json);
void skip_whitespace(const char** json);

JSONValue* parse_json(const char* json) {
    skip_whitespace(&json);
    return parse_value(&json);
}

void skip_whitespace(const char** json) {
    while (isspace(**json)) (*json)++;
}

JSONValue* parse_value(const char** json) {
    if (**json == 'n') {
        if (strncmp(*json, "null", 4) == 0) {
            *json += 4;
            JSONValue* value = malloc(sizeof(JSONValue));
            value->type = JSON_NULL;
            return value;
        }
    } else if (**json == 't' || **json == 'f') {
        JSONValue* value = malloc(sizeof(JSONValue));
        if (strncmp(*json, "true", 4) == 0) {
            value->type = JSON_BOOL;
            value->value.boolean = 1;
            *json += 4;
            return value;
        } else if (strncmp(*json, "false", 5) == 0) {
            value->type = JSON_BOOL;
            value->value.boolean = 0;
            *json += 5;
            return value;
        }
    } else if (**json == '\"') {
        return parse_string(json);
    } else if (isdigit(**json) || **json == '-') {
        return parse_number(json);
    } else if (**json == '[') {
        return parse_array(json);
    } else if (**json == '{') {
        return parse_object(json);
    }
    return NULL;
}

JSONValue* parse_string(const char** json) {
    (*json)++; // Skip the opening quote
    const char* start = *json;
    while (**json != '\"' && **json != '\0') {
        if (**json == '\\') (*json)++; // Handle escape characters
        (*json)++;
    }
    
    size_t length = *json - start;
    char* str = malloc(length + 1);
    strncpy(str, start, length);
    str[length] = '\0';
    
    (*json)++; // Skip the closing quote
    JSONValue* value = malloc(sizeof(JSONValue));
    value->type = JSON_STRING;
    value->value.string = str;
    return value;
}

JSONValue* parse_number(const char** json) {
    char* end;
    JSONValue* value = malloc(sizeof(JSONValue));
    value->type = JSON_NUMBER;
    value->value.number = strtod(*json, &end);
    *json = end;
    return value;
}

JSONValue* parse_array(const char** json) {
    JSONValue* array = malloc(sizeof(JSONValue));
    array->type = JSON_ARRAY;
    // Allocate memory for a simple array with a fixed size
    array->value.array = malloc(sizeof(JSONValue) * 10); // Example size
    int count = 0;

    (*json)++; // Skip the opening bracket
    skip_whitespace(json);
    while (**json != ']' && **json != '\0') {
        if (count >= 10) break; // Prevent overflow

        JSONValue* value = parse_value(json);
        array->value.array[count++] = *value; // Move value into array
        free(value);

        skip_whitespace(json);
        if (**json == ',') (*json)++; // Skip the comma
        skip_whitespace(json);
    }
    (*json)++; // Skip the closing bracket
    return array;
}

JSONValue* parse_object(const char** json) {
    JSONValue* object = malloc(sizeof(JSONValue));
    object->type = JSON_OBJECT;
    object->value.object = malloc(sizeof(JSONValue) * 10); // Example size
    int count = 0;

    (*json)++; // Skip the opening brace
    skip_whitespace(json);
    while (**json != '}' && **json != '\0') {
        if (count >= 10) break; // Prevent overflow

        JSONValue* key = parse_string(json);
        skip_whitespace(json);
        if (**json != ':') break; // Expected a colon
        (*json)++; // Skip the colon
        skip_whitespace(json);

        JSONValue* value = parse_value(json);
        // Store in object (key and value, simplified)
        object->value.object[count++] = *key; // Move key into object
        object->value.object[count++] = *value; // Move value into object
        free(key); // Free key

        skip_whitespace(json);
        if (**json == ',') (*json)++; // Skip the comma
        skip_whitespace(json);
    }
    (*json)++; // Skip the closing brace
    return object;
}

void free_json_value(JSONValue* val) {
    if (!val) return;
    if (val->type == JSON_STRING) {
        free(val->value.string);
    } else if (val->type == JSON_ARRAY || val->type == JSON_OBJECT) {
        // Handle array or object cleanup
        free(val->value.array);
    }
    free(val);
}

void print_json_value(const JSONValue* val) {
    if (!val) {
        printf("null");
        return;
    }
    switch (val->type) {
        case JSON_NULL:
            printf("null");
            break;
        case JSON_BOOL:
            printf(val->value.boolean ? "true" : "false");
            break;
        case JSON_NUMBER:
            printf("%lf", val->value.number);
            break;
        case JSON_STRING:
            printf("\"%s\"", val->value.string);
            break;
        case JSON_ARRAY:
            printf("[");
            // Print values in the array...
            printf("]");
            break;
        case JSON_OBJECT:
            printf("{");
            // Print key-value pairs in the object...
            printf("}");
            break;
    }
}

int main() {
    const char* json_string = "{\"name\":\"John\", \"age\":30, \"isStudent\":false, \"courses\":[\"math\",\"science\"]}";
    const char* json_start = json_string;
    
    JSONValue* json_value = parse_json(json_start);
    
    printf("Parsed JSON value:\n");
    print_json_value(json_value);
    
    free_json_value(json_value);
    return 0;
}