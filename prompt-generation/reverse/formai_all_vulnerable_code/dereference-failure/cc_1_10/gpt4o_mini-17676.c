//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_DEPTH 64
#define MAX_SIZE 8192

typedef enum { JSON_NULL, JSON_TRUE, JSON_FALSE, JSON_NUMBER, JSON_STRING, JSON_OBJECT, JSON_ARRAY } JsonType;

typedef struct JsonValue {
    JsonType type;
    union {
        double number;
        char *string;
        struct JsonObject *object;
        struct JsonArray *array;
    } as;
} JsonValue;

typedef struct JsonObject {
    char **keys;
    JsonValue *values;
    size_t size;
} JsonObject;

typedef struct JsonArray {
    JsonValue *elements;
    size_t size;
} JsonArray;

void free_json_value(JsonValue *value);
JsonValue parse_json(const char *json);
void parse_value(const char **json, JsonValue *value);
JsonValue parse_object(const char **json);
JsonValue parse_array(const char **json);
JsonValue parse_string(const char **json);
JsonValue parse_number(const char **json);
JsonValue parse_literal(const char **json, const char *literal, JsonType type);
char *json_clone_string(const char *start, const char *end);
void print_json(const JsonValue *value, int depth);
void free_json_object(JsonObject *object);
void free_json_array(JsonArray *array);

// Main function to test the JSON parser
int main() {
    const char *test_json = "{\"name\": \"John\", \"age\": 30, \"isStudent\": false, \"courses\": [\"Math\", \"Science\"]}";
    
    JsonValue parsed_json = parse_json(test_json);

    print_json(&parsed_json, 0);
    
    free_json_value(&parsed_json);
    
    return 0;
}

JsonValue parse_json(const char *json) {
    JsonValue value;
    parse_value(&json, &value);
    return value;
}

void parse_value(const char **json, JsonValue *value) {
    while (isspace(**json)) (*json)++; // Skip whitespace
    if (**json == '{') {
        *value = parse_object(json);
    } else if (**json == '[') {
        *value = parse_array(json);
    } else if (**json == '"') {
        *value = parse_string(json);
    } else if (isdigit(**json) || **json == '-') {
        *value = parse_number(json);
    } else if (strncmp(*json, "true", 4) == 0) {
        *value = parse_literal(json, "true", JSON_TRUE);
    } else if (strncmp(*json, "false", 5) == 0) {
        *value = parse_literal(json, "false", JSON_FALSE);
    } else if (strncmp(*json, "null", 4) == 0) {
        *value = parse_literal(json, "null", JSON_NULL);
    } else {
        fprintf(stderr, "Error parsing JSON value.\n");
        exit(EXIT_FAILURE);
    }
}

JsonValue parse_object(const char **json) {
    JsonObject *object = malloc(sizeof(JsonObject));
    object->keys = malloc(sizeof(char *) * MAX_SIZE);
    object->values = malloc(sizeof(JsonValue) * MAX_SIZE);
    object->size = 0;

    (*json)++; // Skip '{'
    
    while (**json != '}') {
        while (isspace(**json)) (*json)++; // Skip whitespace
        char *key = parse_string(json).as.string;

        while (isspace(**json)) (*json)++; // Skip whitespace
        (*json)++; // Skip ':'

        JsonValue value;
        parse_value(json, &value);
        
        object->keys[object->size] = key;
        object->values[object->size] = value;
        object->size++;

        while (isspace(**json)) (*json)++; // Skip whitespace
        if (**json == ',') (*json)++; // Skip ','
    }

    (*json)++; // Skip '}'

    JsonValue result;
    result.type = JSON_OBJECT;
    result.as.object = object;
    return result;
}

JsonValue parse_array(const char **json) {
    JsonArray *array = malloc(sizeof(JsonArray));
    array->elements = malloc(sizeof(JsonValue) * MAX_SIZE);
    array->size = 0;

    (*json)++; // Skip '['
    
    while (**json != ']') {
        JsonValue value;
        parse_value(json, &value);
        
        array->elements[array->size] = value;
        array->size++;

        while (isspace(**json)) (*json)++; // Skip whitespace
        if (**json == ',') (*json)++; // Skip ','
    }

    (*json)++; // Skip ']'

    JsonValue result;
    result.type = JSON_ARRAY;
    result.as.array = array;
    return result;
}

JsonValue parse_string(const char **json) {
    (*json)++; // Skip '"'
    const char *start = *json;

    while (**json != '"' && **json != '\0') {
        (*json)++;
    }

    if (**json == '\0') {
        fprintf(stderr, "Unterminated string.\n");
        exit(EXIT_FAILURE);
    }

    char *string_value = json_clone_string(start, *json);
    (*json)++; // Skip '"'

    JsonValue result;
    result.type = JSON_STRING;
    result.as.string = string_value;
    return result;
}

char *json_clone_string(const char *start, const char *end) {
    size_t length = end - start;
    char *string = malloc(length + 1);
    strncpy(string, start, length);
    string[length] = '\0';
    return string;
}

JsonValue parse_number(const char **json) {
    char *end;
    double number = strtod(*json, &end);
    *json = end;

    JsonValue result;
    result.type = JSON_NUMBER;
    result.as.number = number;
    return result;
}

JsonValue parse_literal(const char **json, const char *literal, JsonType type) {
    *json += strlen(literal);
    JsonValue result;
    result.type = type;
    return result;
}

void print_json(const JsonValue *value, int depth) {
    for (int i = 0; i < depth; i++) printf("  ");
    switch (value->type) {
        case JSON_NULL:
            printf("null\n");
            break;
        case JSON_TRUE:
            printf("true\n");
            break;
        case JSON_FALSE:
            printf("false\n");
            break;
        case JSON_NUMBER:
            printf("%f\n", value->as.number);
            break;
        case JSON_STRING:
            printf("\"%s\"\n", value->as.string);
            break;
        case JSON_OBJECT: {
            printf("{\n");
            JsonObject *object = value->as.object;
            for (size_t i = 0; i < object->size; i++) {
                printf("  \"%s\": ", object->keys[i]);
                print_json(&object->values[i], depth + 1);
            }
            for (size_t i = 0; i < object->size; i++) {
                free(object->keys[i]); // Free keys
            }
            free(object->keys);
            free(object->values);
            free(object);
            printf("}\n");
            break;
        }
        case JSON_ARRAY: {
            printf("[\n");
            JsonArray *array = value->as.array;
            for (size_t i = 0; i < array->size; i++) {
                print_json(&array->elements[i], depth + 1);
            }
            free(array->elements);
            free(array);
            printf("]\n");
            break;
        }
    }
}

void free_json_value(JsonValue *value) {
    switch (value->type) {
        case JSON_STRING:
            free(value->as.string);
            break;
        case JSON_OBJECT:
            free_json_object(value->as.object);
            break;
        case JSON_ARRAY:
            free_json_array(value->as.array);
            break;
        default:
            break;
    }
}

void free_json_object(JsonObject *object) {
    for (size_t i = 0; i < object->size; i++) {
        free(object->keys[i]); // Free keys
        free_json_value(&object->values[i]);
    }
    free(object->keys);
    free(object->values);
    free(object);
}

void free_json_array(JsonArray *array) {
    for (size_t i = 0; i < array->size; i++) {
        free_json_value(&array->elements[i]);
    }
    free(array->elements);
    free(array);
}