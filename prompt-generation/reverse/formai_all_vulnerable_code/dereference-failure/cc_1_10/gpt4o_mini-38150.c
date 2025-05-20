//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUFFER 1024
#define MAX_STACK 1024
#define JSON_STRING 1
#define JSON_NUMBER 2
#define JSON_OBJECT 3
#define JSON_ARRAY 4
#define JSON_BOOL 5
#define JSON_NULL 6

typedef struct JsonValue {
    int type;
    union {
        char *string;
        double number;
        struct JsonValue *array;
        struct JsonValue *object;
    } value;
} JsonValue;

typedef struct Parser {
    const char *json;
    size_t index;
} Parser;

void ignore_whitespace(Parser *parser) {
    while (isspace(parser->json[parser->index])) {
        parser->index++;
    }
}

JsonValue *parse_string(Parser *parser) {
    if (parser->json[parser->index] != '\"') {
        return NULL;
    }

    parser->index++;
    size_t start = parser->index;
    
    while (parser->json[parser->index] != '\"' && parser->json[parser->index] != '\0') {
        parser->index++;
    }

    if (parser->json[parser->index] != '\"') {
        return NULL; // Error: unclosed string
    }

    size_t length = parser->index - start;
    JsonValue *value = malloc(sizeof(JsonValue));
    value->type = JSON_STRING;
    value->value.string = malloc(length + 1);
    strncpy(value->value.string, &parser->json[start], length);
    value->value.string[length] = '\0';
    
    parser->index++; // Move past the closing quote
    return value;
}

JsonValue *parse_number(Parser *parser) {
    size_t start = parser->index;

    while (isdigit(parser->json[parser->index]) || parser->json[parser->index] == '.') {
        parser->index++;
    }

    size_t length = parser->index - start;
    char *number_str = malloc(length + 1);
    strncpy(number_str, &parser->json[start], length);
    number_str[length] = '\0';

    JsonValue *value = malloc(sizeof(JsonValue));
    value->type = JSON_NUMBER;
    value->value.number = atof(number_str);
    free(number_str);
    return value;
}

JsonValue *parse_value(Parser *parser);

JsonValue *parse_object(Parser *parser) {
    if (parser->json[parser->index] != '{') {
        return NULL;
    }

    parser->index++;
    JsonValue *obj = malloc(sizeof(JsonValue));
    obj->type = JSON_OBJECT;
    // Assume any additional logic for storing key-values is implemented here
    
    ignore_whitespace(parser);
    if (parser->json[parser->index] == '}') {
        parser->index++; // Empty object
        return obj;
    }
    
    // More parsing logic would be implemented here for object properties

    return obj;
}

JsonValue *parse_array(Parser *parser) {
    if (parser->json[parser->index] != '[') {
        return NULL;
    }

    parser->index++;
    JsonValue *arr = malloc(sizeof(JsonValue));
    arr->type = JSON_ARRAY;
    // Assume any additional logic for storing elements is implemented here
    
    ignore_whitespace(parser);
    if (parser->json[parser->index] == ']') {
        parser->index++;
        return arr; // Empty array
    }
    
    // Additional parsing logic would be here

    return arr;
}

JsonValue *parse_value(Parser *parser) {
    ignore_whitespace(parser);
    char current = parser->json[parser->index];

    if (current == '\"') {
        return parse_string(parser);
    } else if (isdigit(current) || current == '-') {
        return parse_number(parser);
    } else if (current == '{') {
        return parse_object(parser);
    } else if (current == '[') {
        return parse_array(parser);
    }
    
    return NULL; // Unsupported value type
}

JsonValue *parse_json(const char *json) {
    Parser parser = {json, 0};
    return parse_value(&parser);
}

void free_json(JsonValue *value) {
    if (!value) return;

    switch (value->type) {
        case JSON_STRING:
            free(value->value.string);
            break;
        case JSON_OBJECT:
            // Free object contents
            break;
        case JSON_ARRAY:
            // Free array elements
            break;
        case JSON_NUMBER:
            // Optional: other cleanup
            break;
        // Handle other types as necessary
    }
    free(value);
}

int main() {
    const char *json_example = "{\"name\": \"John Doe\", \"age\": 30}";
    JsonValue *parsed = parse_json(json_example);

    if (parsed) {
        // Display or use parsed JSON values
        free_json(parsed);
    } else {
        fprintf(stderr, "Failed to parse JSON.\n");
    }

    return 0;
}