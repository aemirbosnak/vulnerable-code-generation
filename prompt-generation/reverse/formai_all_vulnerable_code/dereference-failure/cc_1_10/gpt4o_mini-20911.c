//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    JSON_NONE,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOL,
    JSON_NULL
} JsonType;

typedef struct JsonValue {
    JsonType type;
    union {
        char *string;
        double number;
        int boolean;
        struct JsonValue *children; // For objects and arrays
    } value;
} JsonValue;

typedef struct JsonParser {
    const char *input;
    size_t position;
} JsonParser;

void skip_whitespace(JsonParser *parser) {
    while (parser->input[parser->position] == ' ' ||
           parser->input[parser->position] == '\n' ||
           parser->input[parser->position] == '\t') {
        parser->position++;
    }
}

JsonValue *parse_value(JsonParser *parser);
JsonValue *parse_string(JsonParser *parser);

JsonValue *parse_number(JsonParser *parser) {
    JsonValue *json_value = malloc(sizeof(JsonValue));
    json_value->type = JSON_NUMBER;
    char *end;
    json_value->value.number = strtod(&parser->input[parser->position], &end);
    if (end == &parser->input[parser->position]) {
        free(json_value);
        return NULL; // Not a valid number
    }
    parser->position = end - parser->input;
    return json_value;
}

JsonValue *parse_string(JsonParser *parser) {
    JsonValue *json_value = malloc(sizeof(JsonValue));
    json_value->type = JSON_STRING;
    
    parser->position++; // Skip opening quote
    size_t start = parser->position;

    while (parser->input[parser->position] != '"') {
        if (parser->input[parser->position] == '\\') {
            parser->position++; // Skip escape character
        }
        parser->position++;
    }

    size_t length = parser->position - start;
    json_value->value.string = malloc(length + 1);
    strncpy(json_value->value.string, &parser->input[start], length);
    json_value->value.string[length] = '\0';
    
    parser->position++; // Skip closing quote
    return json_value;
}

JsonValue *parse_array(JsonParser *parser) {
    // Implementation of array parsing
    JsonValue *json_value = malloc(sizeof(JsonValue));
    json_value->type = JSON_ARRAY;
    // Implementation for storing array values goes here
    return json_value;
}

JsonValue *parse_object(JsonParser *parser) {
    // Implementation of object parsing
    JsonValue *json_value = malloc(sizeof(JsonValue));
    json_value->type = JSON_OBJECT;
    // Implementation for storing object key/value pairs goes here
    return json_value;
}

JsonValue *parse_value(JsonParser *parser) {
    skip_whitespace(parser);
    char c = parser->input[parser->position];
    if (c == '"') {
        return parse_string(parser);
    } else if ((c >= '0' && c <= '9') || c == '-') {
        return parse_number(parser);
    } else if (c == '{') {
        return parse_object(parser);
    } else if (c == '[') {
        return parse_array(parser);
    } else if (strncmp(&parser->input[parser->position], "true", 4) == 0) {
        parser->position += 4;
        JsonValue *json_value = malloc(sizeof(JsonValue));
        json_value->type = JSON_BOOL;
        json_value->value.boolean = 1;
        return json_value;
    } else if (strncmp(&parser->input[parser->position], "false", 5) == 0) {
        parser->position += 5;
        JsonValue *json_value = malloc(sizeof(JsonValue));
        json_value->type = JSON_BOOL;
        json_value->value.boolean = 0;
        return json_value;
    } else if (strncmp(&parser->input[parser->position], "null", 4) == 0) {
        parser->position += 4;
        JsonValue *json_value = malloc(sizeof(JsonValue));
        json_value->type = JSON_NULL;
        return json_value;
    }
    return NULL; // Invalid value
}

JsonValue *json_parse(const char *input) {
    JsonParser parser = {input, 0};
    return parse_value(&parser);
}

void free_json_value(JsonValue *json_value) {
    if (!json_value) return;
    if (json_value->type == JSON_STRING) {
        free(json_value->value.string);
    } // Handle other types as needed
    free(json_value);
}

int main() {
    const char *json_text = "{\"name\":\"Sir Lancelot\",\"age\":27,\"isKnight\":true,\"quests\":null}";
    JsonValue *parsed_json = json_parse(json_text);
    
    if (parsed_json != NULL) {
        printf("Parsed JSON successfully!\n");
    } else {
        printf("Failed to parse JSON!\n");
    }

    free_json_value(parsed_json);
    return 0;
}