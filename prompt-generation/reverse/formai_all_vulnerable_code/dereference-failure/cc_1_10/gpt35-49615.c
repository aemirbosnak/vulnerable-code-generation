//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the JSON data type
enum json_type {
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_NUMBER,
    JSON_STRING,
    JSON_BOOLEAN,
    JSON_NULL
};

// Define the JSON data structure
struct json_data {
    enum json_type type;
    union {
        int boolean;
        double number;
        char *string;
        struct json_data *data;
    } value;
    struct json_data *next;
};

// Parse a JSON object
struct json_data *parse_object(char *json);

// Parse a JSON array
struct json_data *parse_array(char *json);

// Parse a JSON number
struct json_data *parse_number(char *json);

// Parse a JSON string
struct json_data *parse_string(char *json);

// Parse a JSON boolean
struct json_data *parse_boolean(char *json);

// Parse a JSON null
struct json_data *parse_null(char *json);

// Skip whitespace in a JSON string
char *skip_whitespace(char *json);

// Match a character in a JSON string
char *match_character(char *json, char c);

// Main JSON parsing function
struct json_data *parse_json(char *json) {
    json = skip_whitespace(json);
    switch (*json) {
        case '{':
            return parse_object(json);
        case '[':
            return parse_array(json);
        case '"':
            return parse_string(json);
        case 't':
        case 'f':
            return parse_boolean(json);
        case 'n':
            return parse_null(json);
        default:
            return parse_number(json);
    }
}

// Parse a JSON object
struct json_data *parse_object(char *json) {
    json = match_character(json, '{');
    json = skip_whitespace(json);
    struct json_data *object = NULL;
    struct json_data **current = &object;
    while (*json != '}') {
        if (*current != NULL) {
            (*current)->next = malloc(sizeof(struct json_data));
            current = &(*current)->next;
        }
        *current = malloc(sizeof(struct json_data));
        (*current)->type = JSON_STRING;
        char *key_start = json;
        char *key_end = match_character(json, '"');
        (*current)->value.string = malloc(key_end - key_start);
        strncpy((*current)->value.string, key_start + 1, key_end - key_start - 1);
        current = &(*current)->next;
        json = match_character(key_end, ':');
        (*current) = parse_json(json);
        current = &(*current)->next;
        json = skip_whitespace((*current)->next);
        if (*json == ',') {
            json++;
        }
    }
    (*current) = NULL;
    return object;
}

// Parse a JSON array
struct json_data *parse_array(char *json) {
    json = match_character(json, '[');
    json = skip_whitespace(json);
    struct json_data *array = NULL;
    struct json_data **current = &array;
    while (*json != ']') {
        if (*current != NULL) {
            (*current)->next = malloc(sizeof(struct json_data));
            current = &(*current)->next;
        }
        *current = parse_json(json);
        current = &(*current)->next;
        json = skip_whitespace((*current)->next);
        if (*json == ',') {
            json++;
        }
    }
    (*current) = NULL;
    return array;
}

// Parse a JSON number
struct json_data *parse_number(char *json) {
    char *end = json;
    while ((*end >= '0' && *end <= '9') || *end == '-' || *end == '.' || *end == 'e' || *end == 'E') {
        end++;
    }
    char buffer[end - json + 1];
    strncpy(buffer, json, end - json);
    buffer[end - json] = '\0';
    struct json_data *number = malloc(sizeof(struct json_data));
    number->type = JSON_NUMBER;
    number->value.number = atof(buffer);
    number->next = NULL;
    return number;
}

// Parse a JSON string
struct json_data *parse_string(char *json) {
    json = match_character(json, '"');
    char *end = json;
    while (*end != '"') {
        if (*end == '\\') {
            end++;
        }
        end++;
    }
    char *string = malloc(end - json);
    strncpy(string, json + 1, end - json - 1);
    string[end - json - 1] = '\0';
    struct json_data *string_data = malloc(sizeof(struct json_data));
    string_data->type = JSON_STRING;
    string_data->value.string = string;
    string_data->next = NULL;
    return string_data;
}

// Parse a JSON boolean
struct json_data *parse_boolean(char *json) {
    struct json_data *boolean_data = malloc(sizeof(struct json_data));
    boolean_data->type = JSON_BOOLEAN;
    if (*json == 't') {
        boolean_data->value.boolean = 1;
        match_character(json, 't');
        match_character(json, 'r');
        match_character(json, 'u');
        match_character(json, 'e');
    } else {
        boolean_data->value.boolean = 0;
        match_character(json, 'f');
        match_character(json, 'a');
        match_character(json, 'l');
        match_character(json, 's');
        match_character(json, 'e');
    }
    boolean_data->next = NULL;
    return boolean_data;
}

// Parse a JSON null
struct json_data *parse_null(char *json) {
    match_character(json, 'n');
    match_character(json, 'u');
    match_character(json, 'l');
    match_character(json, 'l');
    struct json_data *null_data = malloc(sizeof(struct json_data));
    null_data->type = JSON_NULL;
    null_data->next = NULL;
    return null_data;
}

// Skip whitespace in a JSON string
char *skip_whitespace(char *json) {
    while (*json == ' ' || *json == '\n' || *json == '\r' || *json == '\t') {
        json++;
    }
    return json;
}

// Match a character in a JSON string
char *match_character(char *json, char c) {
    json = skip_whitespace(json);
    if (*json != c) {
        printf("Unexpected character: %c\n", *json);
        exit(1);
    }
    return json + 1;
}

int main() {
    char json[] = "{ \"name\": \"John\", \"age\": 30, \"active\": true }";
    struct json_data *data = parse_json(json);
    printf("Name: %s\n", data->value.data->value.string);
    printf("Age: %lf\n", data->value.data->next->value.number);
    printf("Active: %d\n", data->value.data->next->next->value.boolean);
    return 0;
}