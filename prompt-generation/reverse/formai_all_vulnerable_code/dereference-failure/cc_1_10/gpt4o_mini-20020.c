//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JSONValue {
    enum { JSON_NULL, JSON_BOOL, JSON_NUMBER, JSON_STRING, JSON_OBJECT, JSON_ARRAY } type;
    union {
        int boolean;
        double number;
        char *string;
        struct JSONObject *object;
        struct JSONArray *array;
    };
} JSONValue;

typedef struct JSONObject {
    char **keys;
    JSONValue **values;
    size_t length;
} JSONObject;

typedef struct JSONArray {
    JSONValue **values;
    size_t length;
} JSONArray;

JSONValue *parseValue(const char **input);
JSONObject *parseObject(const char **input);
JSONArray *parseArray(const char **input);
char *parseString(const char **input);
double parseNumber(const char **input);
int parseBoolean(const char **input);
void skipSpaces(const char **input);
void freeJSONValue(JSONValue *value);
void printJSONValue(const JSONValue *value);

int main() {
    const char *json = "{\"name\":\"John\", \"age\":30, \"isStudent\":false, \"courses\":[\"Math\", \"Science\"]}";
    
    const char *input = json;
    JSONValue *value = parseValue(&input);
    
    if (value) {
        printJSONValue(value);
        freeJSONValue(value);
    } else {
        fprintf(stderr, "Failed to parse JSON\n");
    }
    
    return 0;
}

void skipSpaces(const char **input) {
    while (isspace(**input)) (*input)++;
}

JSONValue *parseValue(const char **input) {
    skipSpaces(input);
    switch (**input) {
        case '{': return (JSONValue *)parseObject(input);
        case '[': return (JSONValue *)parseArray(input);
        case '\"': {
            JSONValue *value = malloc(sizeof(JSONValue));
            value->type = JSON_STRING;
            value->string = parseString(input);
            return value;
        }
        case 't':
        case 'f': {
            JSONValue *value = malloc(sizeof(JSONValue));
            value->type = JSON_BOOL;
            value->boolean = parseBoolean(input);
            return value;
        }
        case 'n': {
            JSONValue *value = malloc(sizeof(JSONValue));
            value->type = JSON_NULL;
            (*input) += 4; // Skip "null"
            return value;
        }
        default:
            if (isdigit(**input) || **input == '-') {
                JSONValue *value = malloc(sizeof(JSONValue));
                value->type = JSON_NUMBER;
                value->number = parseNumber(input);
                return value;
            }
            break;
    }
    return NULL;
}

JSONObject *parseObject(const char **input) {
    JSONObject *obj = malloc(sizeof(JSONObject));
    obj->keys = NULL;
    obj->values = NULL;
    obj->length = 0;

    (*input)++; // Skip '{'
    skipSpaces(input);

    while (**input != '}') {
        obj->keys = realloc(obj->keys, sizeof(char*) * (obj->length + 1));
        obj->values = realloc(obj->values, sizeof(JSONValue*) * (obj->length + 1));
        
        obj->keys[obj->length] = parseString(input);
        skipSpaces(input);
        (*input)++; // Skip ':'
        
        obj->values[obj->length] = parseValue(input);
        obj->length++;

        skipSpaces(input);
        if (**input == ',') (*input)++; // Skip ','
    }
    
    (*input)++; // Skip '}'
    return obj;
}

JSONArray *parseArray(const char **input) {
    JSONArray *array = malloc(sizeof(JSONArray));
    array->values = NULL;
    array->length = 0;

    (*input)++; // Skip '['
    skipSpaces(input);

    while (**input != ']') {
        array->values = realloc(array->values, sizeof(JSONValue*) * (array->length + 1));
        array->values[array->length] = parseValue(input);
        array->length++;

        skipSpaces(input);
        if (**input == ',') (*input)++; // Skip ','
    }
    
    (*input)++; // Skip ']'
    return array;
}

char *parseString(const char **input) {
    (*input)++; // Skip initial quote
    const char *start = *input;

    while (**input != '\"' && **input != '\0') {
        (*input)++;
    }

    size_t length = *input - start;
    char *string = malloc(length + 1);
    strncpy(string, start, length);
    string[length] = '\0';
    
    (*input)++; // Skip closing quote
    return string;
}

double parseNumber(const char **input) {
    char *end;
    double number = strtod(*input, &end);
    *input = end;
    return number;
}

int parseBoolean(const char **input) {
    if (strncmp(*input, "true", 4) == 0) {
        *input += 4;
        return 1;
    } else {
        *input += 5;
        return 0;
    }
}

void freeJSONValue(JSONValue *value) {
    if (!value) return;
    
    switch (value->type) {
        case JSON_STRING:
            free(value->string);
            break;
        case JSON_OBJECT:
            for (size_t i = 0; i < value->object->length; i++) {
                free(value->object->keys[i]);
                freeJSONValue(value->object->values[i]);
            }
            free(value->object->keys);
            free(value->object->values);
            free(value->object);
            break;
        case JSON_ARRAY:
            for (size_t i = 0; i < value->array->length; i++) {
                freeJSONValue(value->array->values[i]);
            }
            free(value->array->values);
            free(value->array);
            break;
        default:
            break;
    }
    
    free(value);
}

void printJSONValue(const JSONValue *value) {
    switch (value->type) {
        case JSON_NULL:
            printf("null\n");
            break;
        case JSON_BOOL:
            printf(value->boolean ? "true\n" : "false\n");
            break;
        case JSON_NUMBER:
            printf("%f\n", value->number);
            break;
        case JSON_STRING:
            printf("\"%s\"\n", value->string);
            break;
        case JSON_OBJECT: {
            printf("{\n");
            for (size_t i = 0; i < value->object->length; i++) {
                printf("  \"%s\": ", value->object->keys[i]);
                printJSONValue(value->object->values[i]);
            }
            printf("}\n");
            break;
        }
        case JSON_ARRAY: {
            printf("[\n");
            for (size_t i = 0; i < value->array->length; i++) {
                printf("  ");
                printJSONValue(value->array->values[i]);
            }
            printf("]\n");
            break;
        }
    }
}