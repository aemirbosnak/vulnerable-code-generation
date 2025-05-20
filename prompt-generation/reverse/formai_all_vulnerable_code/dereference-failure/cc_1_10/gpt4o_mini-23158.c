//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
void parse_json(const char *json);
void parse_object(const char **json);
void parse_array(const char **json);
void parse_value(const char **json);
void skip_whitespace(const char **json);
void print_indent(int indent);

// Helper function to check if a character is a valid JSON character
int is_json_char(char c) {
    return isalnum(c) || c == '"' || c == '{' || c == '}' || c == '[' || c == ']' || c == ':' || c == ',' || c == 't' || c == 'f' || c == 'n';
}

// Function to skip whitespace characters
void skip_whitespace(const char **json) {
    while (**json && isspace(**json)) {
        (*json)++;
    }
}

// Function to print indentation based on the level
void print_indent(int indent) {
    for (int i = 0; i < indent; i++) {
        printf("  ");
    }
}

// Function to parse a JSON value
void parse_value(const char **json) {
    skip_whitespace(json);
    
    if (**json == '{') {
        parse_object(json);
    } else if (**json == '[') {
        parse_array(json);
    } else if (**json == '"') {
        char *string_start = (char*)(*json + 1);
        while (*(*json)++ != '"'); // Move to the closing "
        size_t len = *json - string_start - 1;
        char *value = (char *)malloc(len + 1);
        strncpy(value, string_start, len);
        value[len] = '\0';
        printf("String: \"%s\"\n", value);
        free(value);
    } else if (isdigit(**json) || **json == '-') {
        char *number_start = (char*)(*json);
        while (isdigit(**json) || **json == '-' || **json == '.') (*json)++;
        size_t len = *json - number_start;
        char *value = (char *)malloc(len + 1);
        strncpy(value, number_start, len);
        value[len] = '\0';
        printf("Number: %s\n", value);
        free(value);
    } else if (strncmp(*json, "true", 4) == 0) {
        printf("Boolean: true\n");
        *json += 4;
    } else if (strncmp(*json, "false", 5) == 0) {
        printf("Boolean: false\n");
        *json += 5;
    } else if (strncmp(*json, "null", 4) == 0) {
        printf("Null: null\n");
        *json += 4;
    } else {
        fprintf(stderr, "Unexpected character: '%c'\n", **json);
        exit(EXIT_FAILURE);
    }
}

// Function to parse a JSON object
void parse_object(const char **json) {
    (*json)++; // Skip '{'
    printf("Object:\n");
    skip_whitespace(json);

    while (**json != '}') {
        char *key_start = (char*)(*json + 1); // Assume we encounter a key
        while (*(*json)++ != '"'); // Move to closing quote
        size_t key_len = *json - key_start - 1;
        char *key = (char *)malloc(key_len + 1);
        strncpy(key, key_start, key_len);
        key[key_len] = '\0';
        printf("  Key: \"%s\"\n", key);
        free(key);
        
        skip_whitespace(json);
        if (**json != ':') {
            fprintf(stderr, "Expected ':' after key\n");
            exit(EXIT_FAILURE);
        }
        (*json)++; // Skip ':'
        skip_whitespace(json);
        parse_value(json); // Parse corresponding value

        skip_whitespace(json);
        if (**json == ',') {
            (*json)++; // Skip ','
            skip_whitespace(json);
        } else if (**json != '}') {
            fprintf(stderr, "Expected ',' or '}'\n");
            exit(EXIT_FAILURE);
        }
    }
    (*json)++; // Skip '}'
}

// Function to parse a JSON array
void parse_array(const char **json) {
    (*json)++; // Skip '['
    printf("Array:\n");
    skip_whitespace(json);

    while (**json != ']') {
        parse_value(json); // Parse each value
        skip_whitespace(json);
        if (**json == ',') {
            (*json)++; // Skip ','
            skip_whitespace(json);
        } else if (**json != ']') {
            fprintf(stderr, "Expected ',' or ']'\n");
            exit(EXIT_FAILURE);
        }
    }
    (*json)++; // Skip ']'
}

// Main JSON parser function
void parse_json(const char *json) {
    const char *cursor = json;
    skip_whitespace(&cursor);
    if (*cursor == '{') {
        parse_object(&cursor);
    } else if (*cursor == '[') {
        parse_array(&cursor);
    } else {
        fprintf(stderr, "Invalid JSON: must start with '{' or '['\n");
    }
}

int main() {
    const char *json_to_parse = "{ \"name\": \"John\", \"age\": 30, \"is_student\": false, \"courses\": [\"Math\", \"Science\"], \"address\": { \"city\": \"New York\", \"zip\": null } }";

    printf("Parsing JSON:\n");
    parse_json(json_to_parse);

    return 0;
}