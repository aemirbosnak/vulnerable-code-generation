//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JSONValue {
    enum { JSON_NULL, JSON_TRUE, JSON_FALSE, JSON_NUMBER, JSON_STRING, JSON_ARRAY, JSON_OBJECT } type;
    union {
        double number;
        char *string;
        struct JSONValue *array;
        struct { char **keys; struct JSONValue *values; } object;
    } value;
    size_t count;
} JSONValue;

JSONValue *parseValue(const char **input);
JSONValue *parseString(const char **input);
JSONValue *parseNumber(const char **input);
JSONValue *parseArray(const char **input);
JSONValue *parseObject(const char **input);
void skipWhitespace(const char **input);
void freeJSONValue(JSONValue *value);
void printJSONValue(JSONValue *value, int indent);

int main(void) {
    const char *jsonInput = "{\"name\": \"John\", \"age\": 30, \"isStudent\": false, \"courses\": [\"Math\", \"Science\"]}";
    const char **input = &jsonInput;
    JSONValue *jsonValue = parseValue(input);
    
    printJSONValue(jsonValue, 0);
    freeJSONValue(jsonValue);

    return 0;
}

JSONValue *parseValue(const char **input) {
    skipWhitespace(input);

    if (**input == '{') return parseObject(input);
    if (**input == '[') return parseArray(input);
    if (**input == '\"') return parseString(input);
    if (isdigit(**input) || **input == '-') return parseNumber(input);
    if (strncmp(*input, "true", 4) == 0) {
        *input += 4;
        JSONValue *value = malloc(sizeof(JSONValue));
        value->type = JSON_TRUE;
        return value;
    }
    if (strncmp(*input, "false", 5) == 0) {
        *input += 5;
        JSONValue *value = malloc(sizeof(JSONValue));
        value->type = JSON_FALSE;
        return value;
    }
    if (strncmp(*input, "null", 4) == 0) {
        *input += 4;
        JSONValue *value = malloc(sizeof(JSONValue));
        value->type = JSON_NULL;
        return value;
    }

    return NULL; // Error condition
}

JSONValue *parseString(const char **input) {
    JSONValue *value = malloc(sizeof(JSONValue));
    value->type = JSON_STRING;
    
    (*input)++; // Skip the initial quote
    const char *start = *input;
    while (**input && **input != '\"') {
        (*input)++;
    }
    
    size_t length = *input - start;
    value->value.string = malloc(length + 1);
    strncpy(value->value.string, start, length);
    value->value.string[length] = '\0';
    (*input)++; // Skip the closing quote
    return value;
}

JSONValue *parseNumber(const char **input) {
    JSONValue *value = malloc(sizeof(JSONValue));
    value->type = JSON_NUMBER;

    char *end;
    value->value.number = strtod(*input, &end);
    *input = end; // Update input pointer
    return value;
}

JSONValue *parseArray(const char **input) {
    JSONValue *value = malloc(sizeof(JSONValue));
    value->type = JSON_ARRAY;
    value->count = 0;

    (*input)++; // Skip the opening bracket
    while (**input) {
        skipWhitespace(input);
        if (**input == ']') {
            (*input)++;
            return value;
        }
        value->count++;
        value->value.array = realloc(value->value.array, sizeof(JSONValue) * value->count);
        value->value.array[value->count - 1] = *parseValue(input); // Parse and assign
        skipWhitespace(input);
        if (**input == ',') {
            (*input)++;
        }
    }
    return NULL; // Error condition
}

JSONValue *parseObject(const char **input) {
    JSONValue *value = malloc(sizeof(JSONValue));
    value->type = JSON_OBJECT;
    value->count = 0;
    value->value.object.keys = NULL;
    value->value.object.values = NULL;

    (*input)++; // Skip the opening brace
    while (**input) {
        skipWhitespace(input);
        if (**input == '}') {
            (*input)++;
            return value;
        }
        value->count++;
        value->value.object.keys = realloc(value->value.object.keys, sizeof(char *) * value->count);
        value->value.object.values = realloc(value->value.object.values, sizeof(JSONValue) * value->count);

        value->value.object.keys[value->count - 1] = parseString(input)->value.string;
        skipWhitespace(input); // Skip to colon
        (*input)++; // Skip the colon
        value->value.object.values[value->count - 1] = *parseValue(input); // Parse and assign
        skipWhitespace(input);
        if (**input == ',') {
            (*input)++;
        }
    }
    return NULL; // Error condition
}

void skipWhitespace(const char **input) {
    while (isspace(**input)) {
        (*input)++;
    }
}

void freeJSONValue(JSONValue *value) {
    if (!value) return;
    switch (value->type) {
        case JSON_STRING:
            free(value->value.string);
            break;
        case JSON_ARRAY:
            for (size_t i = 0; i < value->count; i++) {
                freeJSONValue(&value->value.array[i]);
            }
            free(value->value.array);
            break;
        case JSON_OBJECT:
            for (size_t i = 0; i < value->count; i++) {
                free(value->value.object.keys[i]);
                freeJSONValue(&value->value.object.values[i]);
            }
            free(value->value.object.keys);
            free(value->value.object.values);
            break;
        default:
            break;
    }
    free(value);
}

void printJSONValue(JSONValue *value, int indent) {
    if (!value) {
        printf("null\n");
        return;
    }

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
            printf("%f", value->value.number);
            break;
        case JSON_STRING:
            printf("\"%s\"", value->value.string);
            break;
        case JSON_ARRAY:
            printf("[\n");
            for (size_t i = 0; i < value->count; i++) {
                printJSONValue(&value->value.array[i], indent + 2);
                if (i < value->count - 1) printf(",\n");
            }
            printf("\n]");
            break;
        case JSON_OBJECT:
            printf("{\n");
            for (size_t i = 0; i < value->count; i++) {
                for (int j = 0; j < indent + 2; j++) printf(" ");
                printf("\"%s\": ", value->value.object.keys[i]);
                printJSONValue(&value->value.object.values[i], indent + 2);
                if (i < value->count - 1) printf(",\n");
            }
            printf("\n}");
            break;
    }
}