//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef enum { JSON_NULL, JSON_BOOL, JSON_NUMBER, JSON_STRING, JSON_ARRAY, JSON_OBJECT } json_type;

typedef struct json_value {
    json_type type;
    union {
        int boolean;
        double number;
        char *string;
        struct json_value **array; // dynamically allocated array of json_value pointers
        struct json_object *object; // struct for object type
    } value;
    size_t value_count; // number of values in array/object
} json_value;

typedef struct json_object {
    char **keys;          // dynamically allocated array of string keys
    json_value **values;  // dynamically allocated array of json_value pointers
    size_t count;         // number of key-value pairs
} json_object;

// Function Declarations
void free_json_value(json_value *value);
json_value *parse_json(const char *json);
json_object *parse_object(const char **json);
json_value *parse_value(const char **json);
json_value *parse_array(const char **json);
json_value *parse_string(const char **json);
void ignore_whitespace(const char **json);
int is_end_of_json(const char **json);

void free_json_value(json_value *value) {
    if (value->type == JSON_STRING) {
        free(value->value.string);
    } else if (value->type == JSON_ARRAY) {
        for (size_t i = 0; i < value->value_count; i++) {
            free_json_value(value->value.array[i]);
        }
        free(value->value.array);
    } else if (value->type == JSON_OBJECT) {
        json_object *obj = value->value.object;
        for (size_t i = 0; i < obj->count; i++) {
            free(obj->keys[i]);
            free_json_value(obj->values[i]);
        }
        free(obj->keys);
        free(obj->values);
        free(obj);
    }
    free(value);
}

void ignore_whitespace(const char **json) {
    while (isspace(**json)) {
        (*json)++;
    }
}

int is_end_of_json(const char **json) {
    return **json == '\0' || **json == '\r' || **json == '\n';
}

json_value *parse_string(const char **json) {
    const char *start = ++(*json); // Skip opening quote
    while (**json != '\"') {
        if (**json == '\\') (*json)++; // Skip escape character
        (*json)++;
    }
    json_value *value = malloc(sizeof(json_value));
    value->type = JSON_STRING;
    value->value.string = strndup(start, *json - start); // Duplicate string
    (*json)++; // Skip closing quote
    return value;
}

json_value *parse_value(const char **json) {
    ignore_whitespace(json);
    
    json_value *value = malloc(sizeof(json_value));

    if (**json == '\"') {
        value = parse_string(json);
    } else if (isdigit(**json) || **json == '-') {
        char *endptr;
        value->type = JSON_NUMBER;
        value->value.number = strtod(*json, &endptr);
        *json = endptr;
    } else if (strncmp(*json, "true", 4) == 0) {
        value->type = JSON_BOOL;
        value->value.boolean = 1;
        *json += 4;
    } else if (strncmp(*json, "false", 5) == 0) {
        value->type = JSON_BOOL;
        value->value.boolean = 0;
        *json += 5;
    } else if (strncmp(*json, "null", 4) == 0) {
        value->type = JSON_NULL;
        *json += 4;
    } else if (**json == '[') {
        // To parse an array
        value->type = JSON_ARRAY;
        value->value.array = NULL;
        value->value_count = 0;
        (*json)++; // Skip '['
        while (!is_end_of_json(json) && **json != ']') {
            value->value.array = realloc(value->value.array, sizeof(json_value*) * (value->value_count + 1));
            value->value.array[value->value_count++] = parse_value(json);
            ignore_whitespace(json);
            if (**json == ',') (*json)++; // Skip comma
        }
        (*json)++; // Skip ']'
    } else if (**json == '{') {
        // To parse an object
        value->type = JSON_OBJECT;
        value->value.object = parse_object(json);
        return value;
    }

    return value;
}

json_object *parse_object(const char **json) {
    json_object *obj = malloc(sizeof(json_object));
    obj->keys = NULL;
    obj->values = NULL;
    obj->count = 0;
    (*json)++; // Skip '{'
    while (!is_end_of_json(json) && **json != '}') {
        ignore_whitespace(json);
        json_value *key = parse_string(json);
        ignore_whitespace(json);
        (*json)++; // Skip ':'
        json_value *value = parse_value(json);
        
        obj->keys = realloc(obj->keys, sizeof(char*) * (obj->count + 1));
        obj->values = realloc(obj->values, sizeof(json_value*) * (obj->count + 1));
        
        obj->keys[obj->count] = key->value.string;
        obj->values[obj->count] = value;
        obj->count++;
        ignore_whitespace(json);
        if (**json == ',') (*json)++; // Skip comma
    }
    (*json)++; // Skip '}'
    return obj;
}

json_value *parse_json(const char *json) {
    json_value *value = parse_value(&json);
    ignore_whitespace(&json);
    return value;
}

void print_json_value(json_value *value, int indent) {
    if (!value) {
        return;
    }

    switch (value->type) {
        case JSON_NULL:
            printf("null");
            break;
        case JSON_BOOL:
            printf(value->value.boolean ? "true" : "false");
            break;
        case JSON_NUMBER:
            printf("%lf", value->value.number);
            break;
        case JSON_STRING:
            printf("\"%s\"", value->value.string);
            break;
        case JSON_ARRAY:
            printf("[");
            for (size_t i = 0; i < value->value_count; i++) {
                print_json_value(value->value.array[i], indent + 1);
                if (i < value->value_count - 1) printf(", ");
            }
            printf("]");
            break;
        case JSON_OBJECT:
            printf("{");
            for (size_t i = 0; i < value->value.object->count; i++) {
                printf("\"%s\": ", value->value.object->keys[i]);
                print_json_value(value->value.object->values[i], indent + 1);
                if (i < value->value.object->count - 1) printf(", ");
            }
            printf("}");
            break;
    }
}

int main() {
    const char *json_input = "{\"name\": \"John\", \"age\": 30, \"isStudent\": false, \"courses\": [\"Math\", \"Science\"]}";
    json_value *parsed_json = parse_json(json_input);

    printf("Parsed JSON:\n");
    print_json_value(parsed_json, 0);
    printf("\n");

    free_json_value(parsed_json);
    return 0;
}