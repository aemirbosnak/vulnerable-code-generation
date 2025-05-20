//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JSONValue {
    enum { JSON_NULL, JSON_STRING, JSON_NUMBER, JSON_OBJECT, JSON_ARRAY, JSON_BOOL } type;
    union {
        char *string;
        double number;
        struct JSONValue *object; // For object, it will point to key-value pairs
        struct JSONValue *array;   // For array, it will point to the elements
        int boolean;               // For boolean true/false
    };
} JSONValue;

void parseWhitespace(const char **json) {
    while (isspace(**json)) (*json)++;
}

JSONValue *parseValue(const char **json);

JSONValue *parseString(const char **json) {
    if (**json != '"') return NULL;
    (*json)++; // Skip the opening quote
    JSONValue *value = malloc(sizeof(JSONValue));
    value->type = JSON_STRING;
    value->string = malloc(256); // Allocate enough space for simplicity
    int index = 0;
    while (**json != '"' && **json != '\0' && index < 255) {
        if (**json == '\\') { // Escape character
            (*json)++;
            if (**json == '\"' || **json == '\\' || **json == '/') {
                value->string[index++] = **json;
            } else if (**json == 'b') {
                value->string[index++] = '\b';
            } else if (**json == 'f') {
                value->string[index++] = '\f';
            } else if (**json == 'n') {
                value->string[index++] = '\n';
            } else if (**json == 'r') {
                value->string[index++] = '\r';
            } else if (**json == 't') {
                value->string[index++] = '\t';
            }
        } else {
            value->string[index++] = **json;
        }
        (*json)++;
    }
    value->string[index] = '\0'; // Null-terminate the string
    if (**json == '"') (*json)++; // Skip the closing quote
    return value;
}

double parseNumber(const char **json) {
    char *end;
    double number = strtod(*json, &end);
    *json = end; // Move to the character after the number
    return number;
}

JSONValue *parseArray(const char **json) {
    if (**json != '[') return NULL;
    (*json)++; // Skip the opening bracket
    JSONValue *array = malloc(sizeof(JSONValue));
    array->type = JSON_ARRAY;
    array->array = NULL; // In a real implementation this should be a list of values
    while (1) {
        parseWhitespace(json);
        if (**json == ']') {
            (*json)++; // Skip closing bracket
            break;
        }
        JSONValue *value = parseValue(json);
        if (value) {
            // Add value to array (not implemented)
        }
        parseWhitespace(json);
        if (**json == ']') {
            (*json)++;
            break;
        }
        if (**json != ',') break; // Expecting comma
        (*json)++;
    }
    return array;
}

JSONValue *parseObject(const char **json) {
    if (**json != '{') return NULL;
    (*json)++; // Skip the opening brace
    JSONValue *object = malloc(sizeof(JSONValue));
    object->type = JSON_OBJECT;
    object->object = NULL; // In a real implementation this should be a list of key-value pairs
    while (1) {
        parseWhitespace(json);
        if (**json == '}') {
            (*json)++; // Skip closing brace
            break;
        }
        JSONValue *key = parseString(json);
        if (!key) break; // Error in parsing key
        parseWhitespace(json);
        if (**json != ':') break; // Expecting colon
        (*json)++;
        parseWhitespace(json);
        JSONValue *value = parseValue(json);
        if (value) {
            // Add key-value pair to object (not implemented)
        }
        parseWhitespace(json);
        if (**json == '}') {
            (*json)++;
            break;
        }
        if (**json != ',') break; // Expecting comma
        (*json)++;
    }
    return object;
}

JSONValue *parseValue(const char **json) {
    parseWhitespace(json);
    if (**json == 'n') {
        *json += 4; // Skip "null"
        JSONValue *value = malloc(sizeof(JSONValue));
        value->type = JSON_NULL;
        return value;
    } else if (**json == 't' || **json == 'f') {
        JSONValue *value = malloc(sizeof(JSONValue));
        value->type = JSON_BOOL;
        value->boolean = (**json == 't');
        *json += (value->boolean) ? 4 : 5; // Skip "true" or "false"
        return value;
    } else if (**json == '"') {
        return parseString(json);
    } else if (isdigit(**json) || **json == '-') {
        JSONValue *value = malloc(sizeof(JSONValue));
        value->type = JSON_NUMBER;
        value->number = parseNumber(json);
        return value;
    } else if (**json == '{') {
        return parseObject(json);
    } else if (**json == '[') {
        return parseArray(json);
    }
    return NULL; // Invalid value
}

void freeJSONValue(JSONValue *value) {
    if (!value) return;
    if (value->type == JSON_STRING) free(value->string);
    // Add freeing for other value types (not implemented)
    free(value);
}

int main() {
    const char *json = "{\"name\": \"John\", \"age\": 30, \"isStudent\": false, \"courses\": [\"CS101\", \"CS102\"]}";
    const char *jsonPtr = json;

    JSONValue *parsedValue = parseValue(&jsonPtr);
    if (parsedValue) {
        printf("JSON parsed successfully!\n");
        // Processing parsed JSONValue structure (not implemented)
    } else {
        printf("Failed to parse JSON.\n");
    }

    freeJSONValue(parsedValue);
    return 0;
}