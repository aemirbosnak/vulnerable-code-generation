//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER_SIZE 1024

typedef enum {
    JSON_STRING,
    JSON_NUMBER,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_TRUE,
    JSON_FALSE,
    JSON_NULL,
    JSON_INVALID
} JSONType;

typedef struct {
    JSONType type;
    char *stringValue;
    double numberValue;
} JSONValue;

void trimWhitespace(char **str) {
    while (isspace((unsigned char)**str)) (*str)++;
}

int parseString(char **str, JSONValue *value) {
    if (**str != '\"') return 0;  // Expected a quote
    (*str)++;
    
    char *start = *str;
    
    while (**str && **str != '\"') {
        if (**str == '\\') (*str)++;  // Skip the escape character
        (*str)++;
    }

    if (**str != '\"') return 0;  // Closing quote not found

    size_t length = *str - start;
    value->stringValue = (char *)malloc(length + 1);
    strncpy(value->stringValue, start, length);
    value->stringValue[length] = '\0';
    value->type = JSON_STRING;
    
    (*str)++;  // Skip the closing quote
    return 1;
}

int parseNumber(char **str, JSONValue *value) {
    char *end;
    value->numberValue = strtod(*str, &end);
    
    if (*str == end) return 0;  // No valid number found
    
    *str = end;  // Move the pointer to the end of the number
    value->type = JSON_NUMBER;
    return 1;
}

int parseValue(char **str, JSONValue *value);

int parseObject(char **str, JSONValue *value) {
    // For simplicity, we'll skip the contents and treat it as valid object.
    if (**str != '{') return 0;
    (*str)++;  // Skip the opening brace

    while (**str) {
        trimWhitespace(str);
        if (**str == '}') {
            (*str)++;  // Skip the closing brace
            value->type = JSON_OBJECT;
            return 1;
        }

        JSONValue key;
        if (!parseString(str, &key)) return 0;

        // Skip the colon
        trimWhitespace(str);
        if (**str != ':') return 0;
        (*str)++;

        // Parse the value
        JSONValue childValue;
        if (!parseValue(str, &childValue)) return 0;

        // Optionally free allocated memory of key and childValue if needed

        trimWhitespace(str);
        if (**str == ',') (*str)++;  // Allow for more keys
    }

    return 0;  // Unfinished object
}

int parseArray(char **str, JSONValue *value) {
    // For simplicity, we'll skip the contents and treat it as valid array.
    if (**str != '[') return 0;
    (*str)++;  // Skip the opening bracket

    while (**str) {
        trimWhitespace(str);
        if (**str == ']') {
            (*str)++;  // Skip the closing bracket
            value->type = JSON_ARRAY;
            return 1;
        }

        JSONValue itemValue;
        if (!parseValue(str, &itemValue)) return 0;

        // Optionally free allocated memory of itemValue if needed

        trimWhitespace(str);
        if (**str == ',') (*str)++;  // Allow for more items
    }

    return 0;  // Unfinished array
}

int parseValue(char **str, JSONValue *value) {
    trimWhitespace(str);
    if (**str == '\"') return parseString(str, value);
    if (isdigit(**str) || **str == '-') return parseNumber(str, value);
    if (**str == '{') return parseObject(str, value);
    if (**str == '[') return parseArray(str, value);
    if (strncmp(*str, "true", 4) == 0) {
        (*str) += 4;
        value->type = JSON_TRUE;
        return 1;
    }
    if (strncmp(*str, "false", 5) == 0) {
        (*str) += 5;
        value->type = JSON_FALSE;
        return 1;
    }
    if (strncmp(*str, "null", 4) == 0) {
        (*str) += 4;
        value->type = JSON_NULL;
        return 1;
    }
    return 0;  // Invalid value
}

void freeJSONValue(JSONValue *value) {
    if (value->type == JSON_STRING) {
        free(value->stringValue);
    }
}

int main() {
    char jsonInput[MAX_BUFFER_SIZE];
    printf("Enter JSON:\n");
    fgets(jsonInput, MAX_BUFFER_SIZE, stdin);
    char *str = jsonInput;
    
    JSONValue parsedValue;
    if (parseValue(&str, &parsedValue)) {
        printf("Parsed JSON successfully!\n");
    } else {
        printf("Failed to parse JSON.\n");
    }

    freeJSONValue(&parsedValue);
    return 0;
}