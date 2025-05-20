//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define JSON_BUFFER_SIZE 1024

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
        double number;
        char *string;
        struct JsonValue *object; // Simplified for this example
        struct JsonValue *array;   // Simplified for this example
    } as;
} JsonValue;

void skipWhitespace(const char **json) {
    while (isspace(**json)) {
        (*json)++;
    }
}

JsonValue *parseValue(const char **json);

JsonValue *createJsonValue(JsonType type) {
    JsonValue *value = (JsonValue *)malloc(sizeof(JsonValue));
    value->type = type;
    return value;
}

void freeJsonValue(JsonValue *value) {
    if (!value) return;
    if (value->type == JSON_STRING) {
        free(value->as.string);
    }
    free(value);
}

JsonValue *parseString(const char **json) {
    (*json)++; // Skip the opening quote
    const char *start = *json;
    while (**json != '"' && **json != '\0') {
        if (**json == '\\') {
            (*json)++; // Skip the escape character
        }
        (*json)++;
    }
    
    size_t length = *json - start;
    JsonValue *value = createJsonValue(JSON_STRING);
    value->as.string = (char *)malloc(length + 1);
    strncpy(value->as.string, start, length);
    value->as.string[length] = '\0';
    
    (*json)++; // Skip the closing quote
    return value;
}

JsonValue *parseNumber(const char **json) {
    char buffer[JSON_BUFFER_SIZE];
    int i = 0;

    while (isdigit(**json) || **json == '.' || **json == '-') {
        buffer[i++] = **json;
        (*json)++;
    }
    buffer[i] = '\0';
    
    JsonValue *value = createJsonValue(JSON_NUMBER);
    value->as.number = atof(buffer);
    return value;
}

JsonValue *parseObject(const char **json) {
    JsonValue *value = createJsonValue(JSON_OBJECT);
    // Simplified: not implemented in this example
    (*json)++; // Skip opening brace
    return value;
}

JsonValue *parseArray(const char **json) {
    JsonValue *value = createJsonValue(JSON_ARRAY);
    // Simplified: not implemented in this example
    (*json)++; // Skip opening bracket
    return value;
}

JsonValue *parseValue(const char **json) {
    skipWhitespace(json);
    
    switch (**json) {
        case '"':
            return parseString(json);
        case '0': case '1': case '2': case '3': case '4': 
        case '5': case '6': case '7': case '8': case '9':
        case '-':
            return parseNumber(json);
        case '{':
            return parseObject(json);
        case '[':
            return parseArray(json);
        case 't':
            (*json) += 4; // Skip "true"
            return createJsonValue(JSON_TRUE);
        case 'f':
            (*json) += 5; // Skip "false"
            return createJsonValue(JSON_FALSE);
        case 'n':
            (*json) += 4; // Skip "null"
            return createJsonValue(JSON_NULL);
        default:
            return NULL; // Error: invalid JSON
    }
}

void printJsonValue(JsonValue *value) {
    switch (value->type) {
        case JSON_NULL:
            printf("null");
            break;
        case JSON_TRUE:
            printf("true");
            break;
        case JSON_FALSE:
            printf("false");
            break;
        case JSON_NUMBER:
            printf("%f", value->as.number);
            break;
        case JSON_STRING:
            printf("\"%s\"", value->as.string);
            break;
        case JSON_OBJECT:
            printf("{...}"); // Not implemented
            break;
        case JSON_ARRAY:
            printf("[...]"); // Not implemented
            break;
    }
}

int main() {
    const char *jsonData = "{\"name\": \"John\", \"age\": 30, \"is_student\": false}";
    const char *json = jsonData;

    JsonValue *jsonValue = parseValue(&json);
    
    printJsonValue(jsonValue);
    printf("\n");

    freeJsonValue(jsonValue);
    return 0;
}