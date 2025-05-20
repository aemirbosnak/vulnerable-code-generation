//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER 1024

typedef enum { JSON_NULL, JSON_TRUE, JSON_FALSE, JSON_NUMBER, JSON_STRING, JSON_OBJECT, JSON_ARRAY } json_type;

typedef struct json_value {
    json_type type;
    union {
        double number;
        char *string;
        struct json_object *object;
        struct json_array *array;
    } value;
} json_value;

typedef struct json_pair {
    char *key;
    json_value *value;
    struct json_pair *next;
} json_pair;

typedef struct json_object {
    json_pair *pairs;
} json_object;

typedef struct json_array {
    json_value **elements;
    size_t count;
} json_array;

// Function prototypes
json_value *parse_value(const char **json);
json_value *parse_string(const char **json);
json_value *parse_number(const char **json);
json_object *parse_object(const char **json);
json_array *parse_array(const char **json);
void skip_whitespace(const char **json);
void free_json_value(json_value *value);
void print_json_value(const json_value *value, int indent);

// JSON parsing functions
json_value *parse_value(const char **json) {
    skip_whitespace(json);
    if (**json == '"')
        return parse_string(json);
    else if (isdigit(**json) || **json == '-')
        return parse_number(json);
    else if (**json == '{')
        return (json_value *)parse_object(json);
    else if (**json == '[')
        return (json_value *)parse_array(json);
    else if (strncmp(*json, "true", 4) == 0) {
        *json += 4;
        json_value *value = malloc(sizeof(json_value));
        value->type = JSON_TRUE;
        return value;
    } else if (strncmp(*json, "false", 5) == 0) {
        *json += 5;
        json_value *value = malloc(sizeof(json_value));
        value->type = JSON_FALSE;
        return value;
    } else if (strncmp(*json, "null", 4) == 0) {
        *json += 4;
        json_value *value = malloc(sizeof(json_value));
        value->type = JSON_NULL;
        return value;
    }
    return NULL;
}

json_value *parse_string(const char **json) {
    (*json)++; // skip the opening quote
    const char *start = *json;
    while (**json != '"' && **json != '\0') {
        (*json)++;
    }
    size_t length = *json - start;
    json_value *value = malloc(sizeof(json_value));
    value->type = JSON_STRING;
    value->value.string = malloc(length + 1);
    strncpy(value->value.string, start, length);
    value->value.string[length] = '\0';
    (*json)++; // skip the closing quote
    return value;
}

json_value *parse_number(const char **json) {
    char *end;
    json_value *value = malloc(sizeof(json_value));
    value->type = JSON_NUMBER;
    value->value.number = strtod(*json, &end);
    *json = end; // move the pointer past the number
    return value;
}

json_pair *parse_pair(const char **json) {
    json_pair *pair = malloc(sizeof(json_pair));
    pair->key = parse_string(json)->value.string;
    skip_whitespace(json);
    (*json)++; // Skip the colon
    pair->value = parse_value(json);
    pair->next = NULL;
    return pair;
}

json_object *parse_object(const char **json) {
    (*json)++; // skip the opening brace
    json_object *object = malloc(sizeof(json_object));
    object->pairs = NULL;
    json_pair **current_pair = &(object->pairs);
    
    skip_whitespace(json);
    while (**json != '}' && **json != '\0') {
        json_pair *pair = parse_pair(json);
        *current_pair = pair;
        current_pair = &pair->next;
        skip_whitespace(json);
        if (**json == ',') (*json)++; // Skip the comma
    }
    (*json)++; // Skip the closing brace
    return object;
}

json_array *parse_array(const char **json) {
    (*json)++; // skip the opening bracket
    json_array *array = malloc(sizeof(json_array));
    array->elements = malloc(MAX_BUFFER * sizeof(json_value*));
    array->count = 0;

    skip_whitespace(json);
    while (**json != ']' && **json != '\0') {
        json_value *value = parse_value(json);
        array->elements[array->count++] = value;
        skip_whitespace(json);
        if (**json == ',') (*json)++; // Skip the comma
    }
    (*json)++; // Skip the closing bracket
    return array;
}

void skip_whitespace(const char **json) {
    while (isspace(**json)) {
        (*json)++;
    }
}

void free_json_value(json_value *value) {
    if (value->type == JSON_STRING) {
        free(value->value.string);
    } else if (value->type == JSON_OBJECT) {
        json_pair *pair = value->value.object->pairs;
        while (pair) {
            json_pair *next = pair->next;
            free(pair->key);
            free_json_value(pair->value);
            free(pair);
            pair = next;
        }
        free(value->value.object);
    } else if (value->type == JSON_ARRAY) {
        for (size_t i = 0; i < value->value.array->count; i++) {
            free_json_value(value->value.array->elements[i]);
        }
        free(value->value.array->elements);
        free(value->value.array);
    }
    free(value);
}

void print_json_value(const json_value *value, int indent) {
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
            printf("%lf", value->value.number);
            break;
        case JSON_STRING:
            printf("\"%s\"", value->value.string);
            break;
        case JSON_OBJECT: {
            printf("{\n");
            for (json_pair *pair = value->value.object->pairs; pair != NULL; pair = pair->next) {
                for (int i = 0; i < indent + 1; i++) printf("  ");
                printf("\"%s\": ", pair->key);
                print_json_value(pair->value, indent + 1);
                printf("\n");
            }
            for (int i = 0; i < indent; i++) printf("  ");
            printf("}");
            break;
        }
        case JSON_ARRAY: {
            printf("[\n");
            for (size_t i = 0; i < value->value.array->count; i++) {
                for (int j = 0; j < indent + 1; j++) printf("  ");
                print_json_value(value->value.array->elements[i], indent + 1);
                printf("%s\n", (i < value->value.array->count - 1) ? "," : "");
            }
            for (int i = 0; i < indent; i++) printf("  ");
            printf("]");
            break;
        }
    }
}

int main() {
    const char *json_string = "{\"name\":\"John\",\"age\":30,\"cars\":[\"Ford\",\"BMW\",\"Fiat\"]}";
    const char *cursor = json_string;
    
    json_value *value = parse_value(&cursor);
    
    print_json_value(value, 0);
    printf("\n");

    free_json_value(value);
    return 0;
}