//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_SIZE 256
#define MAX_STACK_SIZE 128

typedef enum { TYPE_NULL, TYPE_FALSE, TYPE_TRUE, TYPE_NUMBER, TYPE_STRING, TYPE_ARRAY, TYPE_OBJECT } ValueType;

typedef struct {
    ValueType type;
    union {
        double number;
        char* string;
        struct JSONArray* array;
        struct JSONObject* object;
    } value;
} JSONValue;

typedef struct JSONArray {
    size_t size;
    JSONValue* values;
} JSONArray;

typedef struct JSONObject {
    size_t size;
    char** keys;
    JSONValue* values;
} JSONObject;

void free_json_value(JSONValue *value);
void free_json_array(JSONArray *array);
void free_json_object(JSONObject *object);

void skip_whitespace(const char **json) {
    while (isspace(**json)) (*json)++;
}

char *get_string(const char **json) {
    const char *start = ++(*json);
    while (**json != '"') {
        if (**json == '\\') (*json)++;  // Skip escaped characters
        (*json)++;
    }
    size_t length = *json - start;
    char *result = malloc(length + 1);
    strncpy(result, start, length);
    result[length] = '\0';
    (*json)++; // Skip the closing quote
    return result;
}

double get_number(const char **json) {
    double value = strtod(*json, (char **)json);
    return value;
}

JSONValue parse_json_value(const char **json);
JSONArray *parse_json_array(const char **json);
JSONObject *parse_json_object(const char **json);

JSONValue parse_json_value(const char **json) {
    skip_whitespace(json);
    JSONValue value = {0};

    if (**json == 'n') {
        (*json) += 4; // Skip "null"
        value.type = TYPE_NULL;
    } else if (**json == 't') {
        (*json) += 4; // Skip "true"
        value.type = TYPE_TRUE;
    } else if (**json == 'f') {
        (*json) += 5; // Skip "false"
        value.type = TYPE_FALSE;
    } else if (**json == '"') {
        value.type = TYPE_STRING;
        value.value.string = get_string(json);
    } else if (isdigit(**json) || **json == '-') {
        value.type = TYPE_NUMBER;
        value.value.number = get_number(json);
    } else if (**json == '[') {
        value.type = TYPE_ARRAY;
        value.value.array = parse_json_array(json);
    } else if (**json == '{') {
        value.type = TYPE_OBJECT;
        value.value.object = parse_json_object(json);
    }

    return value;
}

JSONArray *parse_json_array(const char **json) {
    JSONArray *array = malloc(sizeof(JSONArray));
    array->size = 0;
    array->values = NULL;

    (*json)++; // Skip '['
    skip_whitespace(json);

    while (**json != ']') {
        array->values = realloc(array->values, sizeof(JSONValue) * (array->size + 1));
        array->values[array->size++] = parse_json_value(json);
        skip_whitespace(json);
        if (**json == ',') (*json)++; // Skip comma
        skip_whitespace(json);
    }
    (*json)++; // Skip ']'
    return array;
}

JSONObject *parse_json_object(const char **json) {
    JSONObject *object = malloc(sizeof(JSONObject));
    object->size = 0;
    object->keys = NULL;
    object->values = NULL;

    (*json)++; // Skip '{'
    skip_whitespace(json);

    while (**json != '}') {
        object->keys = realloc(object->keys, sizeof(char*) * (object->size + 1));
        object->values = realloc(object->values, sizeof(JSONValue) * (object->size + 1));

        object->keys[object->size] = get_string(json);
        skip_whitespace(json);
        (*json)++; // Skip ':'
        object->values[object->size] = parse_json_value(json);
        object->size++;
        skip_whitespace(json);
        
        if (**json == ',') (*json)++; // Skip comma
        skip_whitespace(json);
    }

    (*json)++; // Skip '}'
    return object;
}

void print_json_value(JSONValue *value);

void print_json_array(JSONArray *array) {
    printf("[ ");
    for (size_t i = 0; i < array->size; i++) {
        print_json_value(&array->values[i]);
        if (i < array->size - 1) printf(", ");
    }
    printf(" ]");
}

void print_json_object(JSONObject *object) {
    printf("{ ");
    for (size_t i = 0; i < object->size; i++) {
        printf("\"%s\": ", object->keys[i]);
        print_json_value(&object->values[i]);
        if (i < object->size - 1) printf(", ");
    }
    printf(" }");
}

void print_json_value(JSONValue *value) {
    switch (value->type) {
        case TYPE_NULL: printf("null"); break;
        case TYPE_FALSE: printf("false"); break;
        case TYPE_TRUE: printf("true"); break;
        case TYPE_NUMBER: printf("%g", value->value.number); break;
        case TYPE_STRING: printf("\"%s\"", value->value.string); break;
        case TYPE_ARRAY: print_json_array(value->value.array); break;
        case TYPE_OBJECT: print_json_object(value->value.object); break;
    }
}

void free_json_value(JSONValue *value) {
    if (value->type == TYPE_STRING) {
        free(value->value.string);
    } else if (value->type == TYPE_ARRAY) {
        free_json_array(value->value.array);
    } else if (value->type == TYPE_OBJECT) {
        free_json_object(value->value.object);
    }
}

void free_json_array(JSONArray *array) {
    for (size_t i = 0; i < array->size; i++) {
        free_json_value(&array->values[i]);
    }
    free(array->values);
    free(array);
}

void free_json_object(JSONObject *object) {
    for (size_t i = 0; i < object->size; i++) {
        free(object->keys[i]);
        free_json_value(&object->values[i]);
    }
    free(object->keys);
    free(object->values);
    free(object);
}

int main() {
    const char *json_string = "{\"name\": \"John\", \"age\": 30, \"isMarried\": false, \"children\": [\"Ann\", \"Bill\"]}";
    const char *json_current = json_string;

    JSONValue value = parse_json_value(&json_current);
    
    printf("Parsed JSON:\n");
    print_json_value(&value);
    printf("\n");

    free_json_value(&value);
    return 0;
}