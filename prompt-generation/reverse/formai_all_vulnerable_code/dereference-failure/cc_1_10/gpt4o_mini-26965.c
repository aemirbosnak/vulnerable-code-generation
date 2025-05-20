//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: single-threaded
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
    JSON_OBJECT,
    JSON_ARRAY
} JsonType;

typedef struct JsonValue {
    JsonType type;
    union {
        char *stringValue;
        double numberValue;
        struct JsonValue *object; // For simplicity, only one value allowed
    } value;
} JsonValue;

void skipWhitespace(const char **json) {
    while (isspace(**json)) {
        (*json)++;
    }
}

JsonValue *parseValue(const char **json);

JsonValue *parseString(const char **json) {
    JsonValue *val = malloc(sizeof(JsonValue));
    val->type = JSON_STRING;
    const char *start = ++(*json);
    while (**json != '"' && **json != '\0') {
        // Simple handling: does not handle escape characters.
        (*json)++;
    }
    if (**json == '\0') {
        fprintf(stderr, "Error: Unexpected end of string\n");
        free(val);
        return NULL;
    }
    size_t length = *json - start;
    val->value.stringValue = malloc(length + 1);
    strncpy(val->value.stringValue, start, length);
    val->value.stringValue[length] = '\0';
    (*json)++; // Skip closing "
    return val;
}

JsonValue *parseNumber(const char **json) {
    JsonValue *val = malloc(sizeof(JsonValue));
    val->type = JSON_NUMBER;
    
    char *end;
    val->value.numberValue = strtod(*json, &end);
    *json = end;
    return val;
}

JsonValue *parseLiteral(const char **json) {
    JsonValue *val = malloc(sizeof(JsonValue));
    if (strncmp(*json, "null", 4) == 0) {
        (*json) += 4;
        val->type = JSON_NULL;
    } else if (strncmp(*json, "true", 4) == 0) {
        (*json) += 4;
        val->type = JSON_TRUE;
    } else if (strncmp(*json, "false", 5) == 0) {
        (*json) += 5;
        val->type = JSON_FALSE;
    } else {
        fprintf(stderr, "Error: Invalid literal\n");
        free(val);
        return NULL;
    }
    return val;
}

JsonValue *parseArray(const char **json) {
    JsonValue *val = malloc(sizeof(JsonValue));
    val->type = JSON_ARRAY;
    // For simplicity, we won't store the array's contents here
    (*json)++; // Skip '['
    skipWhitespace(json);
    while (**json != ']' && **json != '\0') {
        JsonValue *element = parseValue(json);
        if (element == NULL) {
            free(val);
            return NULL;
        }
        // For simplifications, we're ignoring elements, should link them in a real parser
        skipWhitespace(json);
        if (**json == ',') {
            (*json)++;
            skipWhitespace(json);
        }
    }
    if (**json == '\0') {
        fprintf(stderr, "Error: Unexpected end of array\n");
        free(val);
        return NULL;
    }
    (*json)++; // Skip ']'
    return val;
}

JsonValue *parseObject(const char **json) {
    JsonValue *val = malloc(sizeof(JsonValue));
    val->type = JSON_OBJECT;
    (*json)++; // Skip '{'
    skipWhitespace(json);
    while (**json != '}' && **json != '\0') {
        if (**json != '"') {
            fprintf(stderr, "Error: Expected string key in object\n");
            free(val);
            return NULL;
        }
        JsonValue *key = parseString(json);
        if (key == NULL) {
            free(val);
            return NULL;
        }
        skipWhitespace(json);
        if (**json != ':') {
            fprintf(stderr, "Error: Expected ':' after key\n");
            free(key->value.stringValue);
            free(key);
            free(val);
            return NULL;
        }
        (*json)++; // Skip ':'
        skipWhitespace(json);
        JsonValue *value = parseValue(json);
        if (value == NULL) {
            free(key->value.stringValue);
            free(key);
            free(val);
            return NULL;
        }
        skipWhitespace(json);
        if (**json == ',') {
            (*json)++;
            skipWhitespace(json);
        }
        free(key->value.stringValue);
        free(key);
        // Free value or store them in a real parser,
        // here we ignore storage for simplicity.
    }
    if (**json == '\0') {
        fprintf(stderr, "Error: Unexpected end of object\n");
        free(val);
        return NULL;
    }
    (*json)++; // Skip '}'
    return val;
}

JsonValue *parseValue(const char **json) {
    skipWhitespace(json);
    if (**json == '"') {
        return parseString(json);
    } else if (isdigit(**json) || **json == '-') {
        return parseNumber(json);
    } else if (strncmp(*json, "null", 4) == 0 || 
               strncmp(*json, "true", 4) == 0 || 
               strncmp(*json, "false", 5) == 0) {
        return parseLiteral(json);
    } else if (**json == '[') {
        return parseArray(json);
    } else if (**json == '{') {
        return parseObject(json);
    }
    fprintf(stderr, "Error: Invalid JSON starting at '%c'\n", **json);
    return NULL;
}

void freeJson(JsonValue *json) {
    if (json == NULL) return;
    switch (json->type) {
        case JSON_STRING:
            free(json->value.stringValue);
            break;
        case JSON_OBJECT:
            // Should free all keys and values
            break;
        case JSON_ARRAY:
            // Should free all elements
            break;
        default:
            break;
    }
    free(json);
}

int main() {
    const char *jsonString = "{\"name\": \"John\", \"age\": 30, \"is_student\": false, \"courses\": [\"C\", \"C++\"]}";
    const char *json = jsonString;
    
    JsonValue *value = parseValue(&json);
    if (value == NULL) {
        fprintf(stderr, "Parsing failed\n");
        return EXIT_FAILURE;
    }
    
    printf("Parsing succeeded\n");
    freeJson(value);
    return EXIT_SUCCESS;
}