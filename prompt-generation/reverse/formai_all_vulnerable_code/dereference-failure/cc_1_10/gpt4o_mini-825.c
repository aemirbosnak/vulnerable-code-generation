//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct JsonValue {
    enum { JSON_NULL, JSON_BOOL, JSON_NUMBER, JSON_STRING, JSON_ARRAY, JSON_OBJECT } type;
    union {
        int boolean; // for JSON boolean
        double number; // for JSON number
        char *string; // for JSON string
    } value;
    struct JsonValue **array; // for JSON array
    size_t array_size;
    struct JsonKeyValuePair *object; // for JSON object
} JsonValue;

typedef struct JsonKeyValuePair {
    char *key;
    JsonValue *value;
    struct JsonKeyValuePair *next;
} JsonKeyValuePair;

void json_free(JsonValue *value) {
    if (value) {
        switch (value->type) {
            case JSON_STRING:
                free(value->value.string);
                break;
            case JSON_ARRAY:
                for (size_t i = 0; i < value->array_size; i++) {
                    json_free(value->array[i]);
                }
                free(value->array);
                break;
            case JSON_OBJECT:
                for (JsonKeyValuePair *pair = value->object; pair;) {
                    JsonKeyValuePair *temp = pair;
                    pair = pair->next;
                    free(temp->key);
                    json_free(temp->value);
                    free(temp);
                }
                break;
            default:
                break;
        }
        free(value);
    }
}

void skipWhitespace(const char **json) {
    while (isspace(**json)) (*json)++;
}

char *parse_string(const char **json) {
    char buffer[256];
    size_t index = 0;
    (*json)++; // Skip the opening quote
    while (**json != '"' && **json != '\0') {
        buffer[index++] = **json;
        (*json)++;
    }
    buffer[index] = '\0';
    (*json)++; // Skip the closing quote
    char *str = malloc(strlen(buffer) + 1);
    strcpy(str, buffer);
    return str;
}

JsonValue *parse_value(const char **json);

JsonValue *parse_array(const char **json) {
    JsonValue *array = malloc(sizeof(JsonValue));
    array->type = JSON_ARRAY;
    array->array_size = 0;
    array->array = NULL;

    (*json)++; // Skip the opening bracket
    skipWhitespace(json);

    while (**json != ']' && **json != '\0') {
        array->array = realloc(array->array, (array->array_size + 1) * sizeof(JsonValue *));
        array->array[array->array_size++] = parse_value(json);
        skipWhitespace(json);
        
        if (**json == ',') (*json)++;
        skipWhitespace(json);
    }
    (*json)++; // Skip the closing bracket
    return array;
}

JsonValue *parse_object(const char **json) {
    JsonValue *object = malloc(sizeof(JsonValue));
    object->type = JSON_OBJECT;
    object->object = NULL;

    (*json)++; // Skip the opening brace
    skipWhitespace(json);

    while (**json != '}' && **json != '\0') {
        JsonKeyValuePair *pair = malloc(sizeof(JsonKeyValuePair));
        pair->key = parse_string(json);
        skipWhitespace(json);
        (*json)++; // Skip the colon
        skipWhitespace(json);
        pair->value = parse_value(json);
        pair->next = object->object;
        object->object = pair;

        skipWhitespace(json);
        if (**json == ',') (*json)++;
        skipWhitespace(json);
    }
    (*json)++; // Skip the closing brace
    return object;
}

JsonValue *parse_value(const char **json) {
    skipWhitespace(json);
    JsonValue *value = malloc(sizeof(JsonValue));

    if (**json == 'n') {
        value->type = JSON_NULL;
        (*json) += 4; // Skip "null"
    } else if (**json == 't' || **json == 'f') {
        value->type = JSON_BOOL;
        value->value.boolean = (**json == 't');
        (*json) += (value->value.boolean) ? 4 : 5; // Skip "true" or "false"
    } else if (isdigit(**json) || **json == '-') {
        value->type = JSON_NUMBER;
        value->value.number = strtod(*json, (char **)json);
    } else if (**json == '"') {
        value->type = JSON_STRING;
        value->value.string = parse_string(json);
    } else if (**json == '[') {
        value = parse_array(json);
    } else if (**json == '{') {
        value = parse_object(json);
    }

    return value;
}

JsonValue *json_parse(const char *json) {
    const char *p = json;
    return parse_value(&p);
}

void print_json(JsonValue *value) {
    if (value->type == JSON_NULL) {
        printf("null");
    } else if (value->type == JSON_BOOL) {
        printf(value->value.boolean ? "true" : "false");
    } else if (value->type == JSON_NUMBER) {
        printf("%f", value->value.number);
    } else if (value->type == JSON_STRING) {
        printf("\"%s\"", value->value.string);
    } else if (value->type == JSON_ARRAY) {
        printf("[");
        for (size_t i = 0; i < value->array_size; i++) {
            print_json(value->array[i]);
            if (i < value->array_size - 1) printf(", ");
        }
        printf("]");
    } else if (value->type == JSON_OBJECT) {
        printf("{");
        for (JsonKeyValuePair *pair = value->object; pair; pair = pair->next) {
            printf("\"%s\": ", pair->key);
            print_json(pair->value);
            if (pair->next) printf(", ");
        }
        printf("}");
    }
}

int main() {
    const char *json_str = "{\"name\":\"Alice\", \"age\":30, \"is_student\":false, \"courses\":[\"Math\",\"Science\"]}";
    JsonValue *value = json_parse(json_str);
    print_json(value);
    printf("\n");
    json_free(value);
    return 0;
}