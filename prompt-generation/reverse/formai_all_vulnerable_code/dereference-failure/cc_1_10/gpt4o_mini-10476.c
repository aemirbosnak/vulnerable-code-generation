//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_JSON_SIZE 8192
#define MAX_STACK_SIZE 1024

typedef enum {
    JSON_NULL,
    JSON_BOOL,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} json_type;

typedef struct json_value {
    json_type type;
    union {
        int boolean;
        double number;
        char *string;
        struct json_value **array; // Dynamic array
    } data;
    size_t array_size;
} json_value;

typedef struct json_parser {
    const char *json;
    size_t pos;
} json_parser;

void skip_whitespace(json_parser *parser) {
    while (isspace(parser->json[parser->pos])) {
        parser->pos++;
    }
}

json_value* parse_value(json_parser *parser);
json_value* parse_string(json_parser *parser);
json_value* parse_number(json_parser *parser);
json_value* parse_array(json_parser *parser);
json_value* parse_object(json_parser *parser);

// Initialize a new JSON value
json_value* create_value(json_type type) {
    json_value *value = (json_value *)malloc(sizeof(json_value));
    value->type = type;
    if (type == JSON_STRING) {
        value->data.string = NULL;
    } else if (type == JSON_ARRAY) {
        value->data.array = NULL;
        value->array_size = 0;
    }
    return value;
}

// Free a JSON value
void free_value(json_value *value) {
    if (value) {
        if (value->type == JSON_STRING && value->data.string) {
            free(value->data.string);
        } else if (value->type == JSON_ARRAY) {
            for (size_t i = 0; i < value->array_size; i++) {
                free_value(value->data.array[i]);
            }
            free(value->data.array);
        }
        free(value);
    }
}

json_value* parse_value(json_parser *parser) {
    skip_whitespace(parser);
    char c = parser->json[parser->pos];

    if (c == '"') return parse_string(parser);
    if (isdigit(c) || c == '-') return parse_number(parser);
    if (strncmp(&parser->json[parser->pos], "true", 4) == 0) {
        parser->pos += 4;
        json_value *value = create_value(JSON_BOOL);
        value->data.boolean = 1;
        return value;
    }
    if (strncmp(&parser->json[parser->pos], "false", 5) == 0) {
        parser->pos += 5;
        json_value *value = create_value(JSON_BOOL);
        value->data.boolean = 0;
        return value;
    }
    if (strncmp(&parser->json[parser->pos], "null", 4) == 0) {
        parser->pos += 4;
        return create_value(JSON_NULL);
    }
    if (c == '[') return parse_array(parser);
    if (c == '{') return parse_object(parser);

    return NULL; // This indicates an error in parsing
}

json_value* parse_string(json_parser *parser) {
    parser->pos++; // Skip opening quote
    char *start = (char*)&parser->json[parser->pos];
    size_t length = 0;

    while (parser->json[parser->pos] != '"') {
        if (parser->json[parser->pos] == '\\') {
            parser->pos++; // Skip the escape character
        }
        length++;
        parser->pos++;

        // Check buffer overflow
        if (length > MAX_JSON_SIZE - 1) {
            return NULL; // String too long
        }
    }

    // Allocate and copy string
    json_value *value = create_value(JSON_STRING);
    value->data.string = (char *)malloc(length + 1);
    strncpy(value->data.string, start, length);
    value->data.string[length] = '\0'; // Add null terminator
    parser->pos++; // Skip closing quote
    return value;
}

json_value* parse_number(json_parser *parser) {
    char *end;
    json_value *value = create_value(JSON_NUMBER);
    value->data.number = strtod(&parser->json[parser->pos], &end);
    parser->pos = end - parser->json; // Update position
    return value;
}

json_value* parse_array(json_parser *parser) {
    parser->pos++; // Skip opening bracket
    json_value *array = create_value(JSON_ARRAY);
    size_t capacity = 4; // Initial capacity
    array->data.array = (json_value **)malloc(capacity * sizeof(json_value *));
    array->array_size = 0;

    while (1) {
        skip_whitespace(parser);
        if (parser->json[parser->pos] == ']') {
            parser->pos++;
            break;
        }
        json_value *value = parse_value(parser);
        if (!value) {
            free_value(array);
            return NULL; // Parsing error
        }
        array->data.array[array->array_size++] = value;

        // Resize array if necessary
        if (array->array_size >= capacity) {
            capacity *= 2;
            array->data.array = realloc(array->data.array, capacity * sizeof(json_value *));
        }
        skip_whitespace(parser);
        if (parser->json[parser->pos] == ',') {
            parser->pos++; // Skip comma
        } else if (parser->json[parser->pos] == ']') {
            parser->pos++;
            break;
        } else {
            free_value(array);
            return NULL; // Incorrect format
        }
    }
    return array;
}

json_value* parse_object(json_parser *parser) {
    // We will not implement this in our lively example for brevity
    printf("Object parsing is not implemented yet! Stay tuned!\n");
    return NULL;
}

int main() {
    char json_string[MAX_JSON_SIZE];

    printf("Enter JSON data (end with a newline):\n");
    fgets(json_string, MAX_JSON_SIZE, stdin);

    json_parser parser = {json_string, 0};
    json_value *result = parse_value(&parser);

    if (result) {
        printf("JSON parsed successfully!\n");
        // Optionally handle result here
        free_value(result);
    } else {
        printf("Failed to parse JSON.\n");
    }

    return 0;
}