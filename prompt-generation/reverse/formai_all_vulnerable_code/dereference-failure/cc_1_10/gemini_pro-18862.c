//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define JSON_MAX_DEPTH 10
#define JSON_MAX_KEY_LEN 256
#define JSON_MAX_VALUE_LEN 1024

typedef struct {
    char key[JSON_MAX_KEY_LEN];
    char value[JSON_MAX_VALUE_LEN];
} JSONValue;

typedef struct {
    JSONValue values[JSON_MAX_DEPTH];
    int depth;
} JSONParser;

JSONParser* json_parser_init() {
    JSONParser* parser = malloc(sizeof(JSONParser));
    parser->depth = 0;
    return parser;
}

void json_parser_destroy(JSONParser* parser) {
    free(parser);
}

int json_parser_push(JSONParser* parser, const char* key, const char* value) {
    if (parser->depth >= JSON_MAX_DEPTH) {
        return -1;
    }
    strcpy(parser->values[parser->depth].key, key);
    strcpy(parser->values[parser->depth].value, value);
    parser->depth++;
    return 0;
}

int json_parser_pop(JSONParser* parser) {
    if (parser->depth <= 0) {
        return -1;
    }
    parser->depth--;
    return 0;
}

JSONValue* json_parser_get_value(JSONParser* parser, const char* key) {
    for (int i = 0; i < parser->depth; i++) {
        if (strcmp(parser->values[i].key, key) == 0) {
            return &parser->values[i];
        }
    }
    return NULL;
}

int main() {
    // Create a JSON parser
    JSONParser* parser = json_parser_init();

    // Parse a JSON string
    const char* json_string = "{\"name\": \"John Doe\", \"age\": 30, \"occupation\": \"Software Engineer\"}";
    char* token = strtok(json_string, ",");
    while (token != NULL) {
        // Split the token into key and value
        char* key = strtok(token, ":");
        char* value = strtok(NULL, "}");

        // Push the key and value into the parser
        json_parser_push(parser, key, value);

        // Get the next token
        token = strtok(NULL, ",");
    }

    // Get the value of the "name" key
    JSONValue* name_value = json_parser_get_value(parser, "name");
    printf("Name: %s\n", name_value->value);

    // Get the value of the "age" key
    JSONValue* age_value = json_parser_get_value(parser, "age");
    printf("Age: %s\n", age_value->value);

    // Get the value of the "occupation" key
    JSONValue* occupation_value = json_parser_get_value(parser, "occupation");
    printf("Occupation: %s\n", occupation_value->value);

    // Destroy the parser
    json_parser_destroy(parser);

    return 0;
}