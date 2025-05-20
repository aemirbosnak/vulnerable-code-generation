//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JSONValue {
    enum { JSON_NULL, JSON_BOOLEAN, JSON_NUMBER, JSON_STRING, JSON_OBJECT, JSON_ARRAY } type;
    union {
        int boolean; // assumed bool (0/1)
        double number;
        char *string;
        struct JSONObject *object;
        struct JSONArray *array;
    } value;
} JSONValue;

typedef struct JSONPair {
    char *key;
    JSONValue *value;
} JSONPair;

typedef struct JSONObject {
    JSONPair **pairs;
    size_t size;
} JSONObject;

typedef struct JSONArray {
    JSONValue **values;
    size_t size;
} JSONArray;

void free_json_value(JSONValue *value);
void free_json_object(JSONObject *object);
void free_json_array(JSONArray *array);

void ignore_whitespace(const char **json) {
    while (isspace(**json)) (*json)++;
}

JSONValue *parse_json_value(const char **json);

JSONValue *parse_json_string(const char **json) {
    const char *start = ++(*json); // Skip the opening quote
    while (**json != '"' && **json != '\0') {
        if (**json == '\\') (*json)++; // Skip escaped character
        (*json)++;
    }
    if (**json == '\0') {
        fprintf(stderr, "Error: Unclosed string\n");
        return NULL;
    }
    size_t length = *json - start;
    JSONValue *value = malloc(sizeof(JSONValue));
    value->type = JSON_STRING;
    value->value.string = malloc(length + 1);
    strncpy(value->value.string, start, length);
    value->value.string[length] = '\0';
    (*json)++; // Skip closing quote
    return value;
}

JSONValue *parse_json_number(const char **json) {
    char *end;
    double number = strtod(*json, &end);
    if (end == *json) {
        fprintf(stderr, "Error: Invalid number\n");
        return NULL;
    }
    JSONValue *value = malloc(sizeof(JSONValue));
    value->type = JSON_NUMBER;
    value->value.number = number;
    *json = end; // Move pointer to the next position
    return value;
}

JSONValue *parse_json_boolean(const char **json) {
    JSONValue *value = malloc(sizeof(JSONValue));
    if (strncmp(*json, "true", 4) == 0) {
        value->type = JSON_BOOLEAN;
        value->value.boolean = 1;
        *json += 4;
    } else if (strncmp(*json, "false", 5) == 0) {
        value->type = JSON_BOOLEAN;
        value->value.boolean = 0;
        *json += 5;
    } else {
        fprintf(stderr, "Error: Invalid boolean\n");
        free(value);
        return NULL;
    }
    return value;
}

JSONValue *parse_json_null(const char **json) {
    if (strncmp(*json, "null", 4) == 0) {
        *json += 4; // Move past "null"
        JSONValue *value = malloc(sizeof(JSONValue));
        value->type = JSON_NULL;
        return value;
    }
    return NULL;
}

JSONValue *parse_json_array(const char **json) {
    JSONArray *array = malloc(sizeof(JSONArray));
    array->size = 0;
    array->values = NULL;

    (*json)++; // Consuming the '['
    ignore_whitespace(json);
    while (**json != ']' && **json != '\0') {
        array->values = realloc(array->values, sizeof(JSONValue *) * (array->size + 1));
        JSONValue *value = parse_json_value(json);
        if (!value) {
            free(array->values);
            free(array);
            return NULL;
        }
        array->values[array->size++] = value;

        ignore_whitespace(json);
        if (**json == ',') {
            (*json)++;
        } else if (**json != ']') {
            fprintf(stderr, "Error: Expected ',' or ']'\n");
            free(array->values);
            free(array);
            return NULL;
        }
        ignore_whitespace(json);
    }
    (*json)++; // Consuming the ']'

    JSONValue *value = malloc(sizeof(JSONValue));
    value->type = JSON_ARRAY;
    value->value.array = array;
    return value;
}

JSONValue *parse_json_object(const char **json) {
    JSONObject *object = malloc(sizeof(JSONObject));
    object->size = 0;
    object->pairs = NULL;

    (*json)++; // Consuming the '{'
    ignore_whitespace(json);
    while (**json != '}' && **json != '\0') {
        JSONPair *pair = malloc(sizeof(JSONPair));
        pair->key = parse_json_string(json)->value.string; // Fetch key
        ignore_whitespace(json);
        if (**json != ':') {
            fprintf(stderr, "Error: Expected ':'\n");
            free(pair);
            return NULL;
        }
        (*json)++; // Skip the ':'
        ignore_whitespace(json);
        pair->value = parse_json_value(json);
        object->pairs = realloc(object->pairs, sizeof(JSONPair *) * (object->size + 1));
        object->pairs[object->size++] = pair;

        ignore_whitespace(json);
        if (**json == ',') {
            (*json)++;
        } else if (**json != '}') {
            fprintf(stderr, "Error: Expected ',' or '}'\n");
            free(pair->key);
            free(pair->value);
            free(pair);
            return NULL;
        }
        ignore_whitespace(json);
    }
    (*json)++; // Consuming the '}'

    JSONValue *value = malloc(sizeof(JSONValue));
    value->type = JSON_OBJECT;
    value->value.object = object;
    return value;
}

JSONValue *parse_json_value(const char **json) {
    ignore_whitespace(json);
    switch (**json) {
        case '"': return parse_json_string(json);
        case '0' ... '9': return parse_json_number(json);
        case 't': case 'f': return parse_json_boolean(json);
        case 'n': return parse_json_null(json);
        case '{': return parse_json_object(json);
        case '[': return parse_json_array(json);
        default:
            fprintf(stderr, "Error: Unexpected character '%c'\n", **json);
            return NULL;
    }
}

void free_json_value(JSONValue *value) {
    if (!value) return;
    switch (value->type) {
        case JSON_STRING:
            free(value->value.string);
            break;
        case JSON_OBJECT:
            free_json_object(value->value.object);
            break;
        case JSON_ARRAY:
            free_json_array(value->value.array);
            break;
        default:
            break;
    }
    free(value);
}

void free_json_object(JSONObject *object) {
    for (size_t i = 0; i < object->size; i++) {
        JSONPair *pair = object->pairs[i];
        free(pair->key);
        free_json_value(pair->value);
        free(pair);
    }
    free(object->pairs);
    free(object);
}

void free_json_array(JSONArray *array) {
    for (size_t i = 0; i < array->size; i++) {
        free_json_value(array->values[i]);
    }
    free(array->values);
    free(array);
}

int main() {
    const char *json_data = "{\"name\":\"John\",\"age\":30,\"is_student\":false,\"courses\":[\"Math\",\"Science\"]}";
    const char *json_ptr = json_data;

    JSONValue *parsed_value = parse_json_value(&json_ptr);
    if (parsed_value) {
        printf("JSON parsed successfully.\n");
        // To do: Further work with parsed_value
    }

    free_json_value(parsed_value);
    return 0;
}