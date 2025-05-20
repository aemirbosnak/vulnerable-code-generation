//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_STRING_LENGTH 1024
#define MAX_JSON_TOKEN_LENGTH 256

typedef enum {
    JSON_NULL,
    JSON_OBJECT,
    JSON_ARRAY,
    JSON_STRING,
    JSON_NUMBER,
    JSON_BOOLEAN
} JsonType;

typedef struct {
    JsonType type;
    union {
        char *string;
        double number;
        int boolean;
    } value;
} JsonValue;

typedef struct {
    char token[MAX_JSON_TOKEN_LENGTH];
    int length;
} JsonToken;

typedef struct {
    char *json;
    int position;
    int length;
    JsonToken tokens[MAX_JSON_STRING_LENGTH];
    int num_tokens;
} JsonParser;

JsonParser* json_parser_create(char *json) {
    JsonParser *parser = (JsonParser*)malloc(sizeof(JsonParser));
    parser->json = json;
    parser->position = 0;
    parser->length = strlen(json);
    parser->num_tokens = 0;
    return parser;
}

void json_parser_destroy(JsonParser *parser) {
    free(parser);
}

JsonToken json_parser_next_token(JsonParser *parser) {
    JsonToken token = {0};
    while (parser->position < parser->length) {
        char c = parser->json[parser->position];
        parser->position++;

        if (c == '{' || c == '}' || c == '[' || c == ']' || c == ':' || c == ',') {
            if (token.length > 0) {
                return token;
            }
            token.token[token.length++] = c;
            return token;
        }
        else if (c == '\"') {
            if (token.length == 0) {
                parser->tokens[parser->num_tokens++] = token;
            }
            token.length = 0;
            while (parser->position < parser->length) {
                c = parser->json[parser->position++];
                if (c == '\"') {
                    parser->tokens[parser->num_tokens++] = token;
                    return token;
                }
                else {
                    token.token[token.length++] = c;
                }
            }
            return token;
        }
        else if (c >= '0' && c <= '9' || c == '-') {
            if (token.length == 0) {
                parser->tokens[parser->num_tokens++] = token;
            }
            token.token[token.length++] = c;
            while (parser->position < parser->length) {
                c = parser->json[parser->position++];
                if (c >= '0' && c <= '9' || c == '.' || c == 'e' || c == 'E' || c == '-') {
                    token.token[token.length++] = c;
                }
                else {
                    parser->position--;
                    parser->tokens[parser->num_tokens++] = token;
                    return token;
                }
            }
            return token;
        }
        else if (c == ' ' || c == '\n' || c == '\r' || c == '\t') {
            if (token.length > 0) {
                return token;
            }
        }
        else {
            printf("Unexpected character %c\n", c);
            exit(EXIT_FAILURE);
        }
    }
}

void print_json_value(JsonValue value) {
    switch (value.type) {
        case JSON_NULL:
            printf("null");
            break;
        case JSON_OBJECT:
        case JSON_ARRAY:
            printf("Not implemented");
            break;
        case JSON_STRING:
            printf("%s", value.value.string);
            break;
        case JSON_NUMBER:
            printf("%.2f", value.value.number);
            break;
        case JSON_BOOLEAN:
            printf("%s", value.value.boolean ? "true" : "false");
            break;
    }
}

void json_parser_parse(JsonParser *parser) {
    JsonToken token = {0};
    while ((token = json_parser_next_token(parser)).length > 0) {
        switch (token.token[0]) {
            case '{':
                printf("{");
                break;
            case '}':
                printf("}");
                break;
            case '[':
                printf("[");
                break;
            case ']':
                printf("]");
                break;
            case ':':
                printf(":");
                break;
            case ',':
                printf(",");
                break;
            default:
                if (parser->tokens[parser->num_tokens - 2].token[0] == ':') {
                    JsonValue value = {0};
                    if (strstr(token.token, "\"") != NULL) {
                        value.type = JSON_STRING;
                        value.value.string = token.token;
                    }
                    else {
                        value.type = JSON_NUMBER;
                        value.value.number = atof(token.token);
                    }
                    print_json_value(value);
                }
                else {
                    printf("%s", token.token);
                }
                break;
        }
    }
}

int main(void) {
    char *json = "{\"name\": \"John Doe\", \"age\": 30, \"city\": \"New York\"}";
    JsonParser *parser = json_parser_create(json);
    json_parser_parse(parser);
    json_parser_destroy(parser);
    return 0;
}