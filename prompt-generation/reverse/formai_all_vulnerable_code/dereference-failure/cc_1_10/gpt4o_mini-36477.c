//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1024

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
        long boolean; // 0 for false, 1 for true
        double number;
        char *string;
        struct JsonValue *object; // simplified example; you may want to implement a better structure for objects
        struct JsonValue *array;   // simplified example; similarly for arrays
    } value;
    struct JsonValue *next; // For linked structure to keep track of multiple values
} JsonValue;

void skipWhitespace(const char **json) {
    while (isspace(**json)) (*json)++;
}

JsonValue* parseValue(const char **json);

JsonValue* parseString(const char **json) {
    JsonValue *value = (JsonValue *)malloc(sizeof(JsonValue));
    value->type = JSON_STRING;
    const char *start = ++(*json);
    while (**json && **json != '"') {
        if (**json == '\\') (*json)++; // Skip escape character
        (*json)++;
    }
    
    size_t length = *json - start;
    value->value.string = (char *)malloc(length + 1);
    strncpy(value->value.string, start, length);
    value->value.string[length] = '\0';
    
    (*json)++; // Skip closing quote
    return value;
}

JsonValue* parseNumber(const char **json) {
    JsonValue *value = (JsonValue *)malloc(sizeof(JsonValue));
    value->type = JSON_NUMBER;
    value->value.number = strtod(*json, (char **)json);
    return value;
}

JsonValue* parseBoolean(const char **json) {
    JsonValue *value = (JsonValue *)malloc(sizeof(JsonValue));
    if (strncmp(*json, "true", 4) == 0) {
        value->type = JSON_BOOLEAN;
        value->value.boolean = 1; // true
        *json += 4;
    } else {
        value->type = JSON_BOOLEAN;
        value->value.boolean = 0; // false
        *json += 5; // length of "false"
    }
    return value;
}

JsonValue* parseNull(const char **json) {
    JsonValue *value = (JsonValue *)malloc(sizeof(JsonValue));
    value->type = JSON_NULL;
    *json += 4; // length of "null"
    return value;
}

JsonValue* parseArray(const char **json) {
    JsonValue *value = (JsonValue *)malloc(sizeof(JsonValue));
    value->type = JSON_ARRAY;
    value->next = NULL; // For the sake of simplicity, we'll not implement a full array structure
    (*json)++; // Skip opening bracket
    skipWhitespace(json);
    
    while (**json != ']') {
        JsonValue *element = parseValue(json);
        element->next = value->next; // Linked list to hold array elements
        value->next = element;
        skipWhitespace(json);
        if (**json == ',') (*json)++; // Skip comma
        skipWhitespace(json);
    }
    
    (*json)++; // Skip closing bracket
    return value;
}

JsonValue* parseObject(const char **json) {
    JsonValue *value = (JsonValue *)malloc(sizeof(JsonValue));
    value->type = JSON_OBJECT;
    value->next = NULL; // Simple structure
    (*json)++; // Skip opening brace
    skipWhitespace(json);
    
    while (**json != '}') {
        if (**json != '"') {
            fprintf(stderr, "Expected string key in object\n");
            exit(EXIT_FAILURE);
        }
        JsonValue *key = parseString(json);
        
        skipWhitespace(json);
        if (**json != ':') {
            fprintf(stderr, "Expected ':' after key\n");
            exit(EXIT_FAILURE);
        }
        (*json)++; // Skip colon
        
        skipWhitespace(json);
        JsonValue *valuePair = parseValue(json);
        // Note: You should link key and valuePair properly here based on your object representation
        
        free(key->value.string); // Cleanup key string
        free(key);
        
        skipWhitespace(json);
        if (**json == ',') (*json)++; // Skip comma
        skipWhitespace(json);
    }
    
    (*json)++; // Skip closing brace
    return value;
}

JsonValue* parseValue(const char **json) {
    skipWhitespace(json);
    if (**json == '"') return parseString(json);
    if (isdigit(**json) || **json == '-') return parseNumber(json);
    if (strncmp(*json, "true", 4) == 0) return parseBoolean(json);
    if (strncmp(*json, "false", 5) == 0) return parseBoolean(json);
    if (strncmp(*json, "null", 4) == 0) return parseNull(json);
    if (**json == '{') return parseObject(json);
    if (**json == '[') return parseArray(json);

    fprintf(stderr, "Invalid JSON value\n");
    exit(EXIT_FAILURE);
}

JsonValue* parseJson(const char *json) {
    const char *ptr = json;
    return parseValue(&ptr);
}

void freeJsonValue(JsonValue *value) {
    if (value) {
        if (value->type == JSON_STRING) {
            free(value->value.string);
        } else if (value->type == JSON_OBJECT || value->type == JSON_ARRAY) {
            // Free nested structures here properly
        }
        free(value);
    }
}

int main() {
    const char *json = "{\"name\":\"John\",\"age\":30,\"married\":true,\"children\":[\"Ann\",\"Billy\"],\"car\":null}";
    JsonValue *parsedJson = parseJson(json);
    
    // Here you would typically print or process the parsed JSON object
    
    freeJsonValue(parsedJson); // Be sure to free up memory
    return 0;
}