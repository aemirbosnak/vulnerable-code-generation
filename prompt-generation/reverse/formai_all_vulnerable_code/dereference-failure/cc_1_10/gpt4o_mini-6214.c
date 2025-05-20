//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_SIZE 256

typedef struct JSONValue {
    enum { JSON_NULL, JSON_TRUE, JSON_FALSE, JSON_NUMBER, JSON_STRING, JSON_OBJECT, JSON_ARRAY } type;
    union {
        double number;
        char *string;
        struct JSONValue **object;
        struct JSONValue **array;
    } value;
    size_t size; // for object or array
} JSONValue;

void skipWhitespace(const char **str) {
    while (isspace(**str)) (*str)++;
}

JSONValue *createJSONValue() {
    JSONValue *val = (JSONValue *)malloc(sizeof(JSONValue));
    val->type = JSON_NULL;
    return val;
}

void freeJSONValue(JSONValue *value) {
    if (!value) return;
    if (value->type == JSON_STRING) free(value->value.string);
    if (value->type == JSON_ARRAY) {
        for (size_t i = 0; i < value->size; i++) {
            freeJSONValue(value->value.array[i]);
        }
        free(value->value.array);
    }
    if (value->type == JSON_OBJECT) {
        for (size_t i = 0; i < value->size; i++) {
            freeJSONValue(value->value.object[i]);
        }
        free(value->value.object);
    }
    free(value);
}

JSONValue *parseValue(const char **str);

JSONValue *parseString(const char **str) {
    const char *start = ++(*str);
    while (**str && **str != '\"') {
        if (**str == '\\') (*str)++; // Skip escape character
        (*str)++;
    }
    size_t len = *str - start;
    JSONValue *val = createJSONValue();
    val->type = JSON_STRING;
    val->value.string = (char *)malloc(len + 1);
    strncpy(val->value.string, start, len);
    val->value.string[len] = '\0';
    (*str)++;
    return val;
}

JSONValue *parseNumber(const char **str) {
    char buffer[MAX_STRING_SIZE];
    size_t len = 0;

    while (isdigit(**str) || **str == '-' || **str == '.') {
        buffer[len++] = **str;
        (*str)++;
    }
    buffer[len] = '\0';

    JSONValue *val = createJSONValue();
    val->type = JSON_NUMBER;
    val->value.number = strtod(buffer, NULL);
    return val;
}

JSONValue *parseArray(const char **str) {
    JSONValue *val = createJSONValue();
    val->type = JSON_ARRAY;
    val->value.array = (JSONValue **)malloc(sizeof(JSONValue *) * 10);
    val->size = 0;

    (*str)++;
    skipWhitespace(str);

    while (**str != ']') {
        if (val->size % 10 == 0) {
            val->value.array = (JSONValue **)realloc(val->value.array, sizeof(JSONValue *) * (val->size + 10));
        }
        val->value.array[val->size++] = parseValue(str);
        skipWhitespace(str);
        if (**str == ',') (*str)++;
        skipWhitespace(str);
    }
    (*str)++;
    return val;
}

JSONValue *parseObject(const char **str) {
    JSONValue *val = createJSONValue();
    val->type = JSON_OBJECT;
    val->value.object = (JSONValue **)malloc(sizeof(JSONValue *) * 10);
    val->size = 0;

    (*str)++;
    skipWhitespace(str);

    while (**str != '}') {
        JSONValue *key = parseString(str);
        skipWhitespace(str);
        if (**str != ':') { freeJSONValue(key); break; }
        (*str)++;
        skipWhitespace(str);
        JSONValue *value = parseValue(str);

        val->value.object[val->size++] = key;
        val->value.object[val->size++] = value;

        skipWhitespace(str);
        if (**str == ',') (*str)++;
        skipWhitespace(str);
    }
    (*str)++;
    return val;
}

JSONValue *parseValue(const char **str) {
    skipWhitespace(str);
    if (**str == '\"') return parseString(str);
    if (isdigit(**str) || **str == '-') return parseNumber(str);
    if (**str == '[') return parseArray(str);
    if (**str == '{') return parseObject(str);
    if (strncmp(*str, "true", 4) == 0) {
        (*str) += 4;
        JSONValue *val = createJSONValue();
        val->type = JSON_TRUE;
        return val;
    }
    if (strncmp(*str, "false", 5) == 0) {
        (*str) += 5;
        JSONValue *val = createJSONValue();
        val->type = JSON_FALSE;
        return val;
    }
    if (strncmp(*str, "null", 4) == 0) {
        (*str) += 4;
        JSONValue *val = createJSONValue();
        val->type = JSON_NULL;
        return val;
    }
    return NULL;
}

JSONValue *parseJSON(const char *str) {
    return parseValue(&str);
}

void printJSONValue(JSONValue *value) {
    if (!value) return;
    switch (value->type) {
        case JSON_NULL: printf("null"); break;
        case JSON_TRUE: printf("true"); break;
        case JSON_FALSE: printf("false"); break;
        case JSON_NUMBER: printf("%f", value->value.number); break;
        case JSON_STRING: printf("\"%s\"", value->value.string); break;
        case JSON_ARRAY: 
            printf("[");
            for (size_t i = 0; i < value->size; i++) {
                printJSONValue(value->value.array[i]);
                if (i < value->size - 1) printf(", ");
            }
            printf("]");
            break;
        case JSON_OBJECT: 
            printf("{");
            for (size_t i = 0; i < value->size; i += 2) {
                printJSONValue(value->value.object[i]);
                printf(": ");
                printJSONValue(value->value.object[i + 1]);
                if (i + 2 < value->size) printf(", ");
            }
            printf("}");
            break;
    }
}

int main() {
    const char *jsonString = "{\"name\": \"John\", \"age\": 30, \"isStudent\": false, \"courses\": [\"Math\", \"Science\"]}";
    JSONValue *value = parseJSON(jsonString);
    printJSONValue(value);
    printf("\n");
    freeJSONValue(value);
    return 0;
}