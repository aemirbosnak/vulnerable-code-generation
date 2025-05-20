//GEMINI-pro DATASET v1.0 Category: Building a JSON Parser ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our trusty JSON parser, armed with magical decoding powers!
typedef struct json_parser_s {
    char *json;
    int pos;
    int len;
} json_parser_t;

// Create a new JSON parser with the given JSON string
json_parser_t *json_new(char *json) {
    json_parser_t *parser = malloc(sizeof(json_parser_t));
    parser->json = json;
    parser->pos = 0;
    parser->len = strlen(json);
    return parser;
}

// Advance the parser to the next non-whitespace character
void json_skip_whitespace(json_parser_t *parser) {
    while (parser->pos < parser->len && isspace(parser->json[parser->pos])) {
        parser->pos++;
    }
}

// Check if the parser has reached the end of the JSON string
int json_is_end(json_parser_t *parser) {
    return parser->pos >= parser->len;
}

// Parse a quoted string
char *json_parse_string(json_parser_t *parser) {
    char *string = NULL;
    char *escaped = NULL;
    int escaped_len = 0;

    // Skip the opening quote
    json_skip_whitespace(parser);
    if (parser->json[parser->pos] != '"') {
        printf("Error: Expected a quoted string!\n");
        return NULL;
    }
    parser->pos++;

    // Parse the string characters
    while (!json_is_end(parser) && parser->json[parser->pos] != '"') {
        // Handle escape sequences
        if (parser->json[parser->pos] == '\\') {
            parser->pos++;
            if (parser->pos >= parser->len) {
                printf("Error: Unterminated escape sequence!\n");
                return NULL;
            }
            escaped_len += 2;
        } else {
            escaped_len++;
        }
        parser->pos++;
    }

    // Allocate memory for the unescaped string
    string = malloc(escaped_len + 1);
    string[escaped_len] = '\0';

    // Unescape the string
    escaped = string;
    while (!json_is_end(parser) && parser->json[parser->pos] != '"') {
        if (parser->json[parser->pos] == '\\') {
            parser->pos++;
            switch (parser->json[parser->pos]) {
                case '"': *escaped++ = '"'; break;
                case '\\': *escaped++ = '\\'; break;
                case '/': *escaped++ = '/'; break;
                case 'b': *escaped++ = '\b'; break;
                case 'f': *escaped++ = '\f'; break;
                case 'n': *escaped++ = '\n'; break;
                case 'r': *escaped++ = '\r'; break;
                case 't': *escaped++ = '\t'; break;
                default:
                    printf("Error: Invalid escape sequence!\n");
                    free(string);
                    return NULL;
            }
        } else {
            *escaped++ = parser->json[parser->pos];
        }
        parser->pos++;
    }

    // Skip the closing quote
    parser->pos++;

    return string;
}

// Parse a JSON value
void json_parse_value(json_parser_t *parser) {
    json_skip_whitespace(parser);

    switch (parser->json[parser->pos]) {
        case 'n':
            if (strncmp(parser->json + parser->pos, "null", 4) == 0) {
                parser->pos += 4;
                printf("null\n");
            }
            break;
        case 't':
            if (strncmp(parser->json + parser->pos, "true", 4) == 0) {
                parser->pos += 4;
                printf("true\n");
            }
            break;
        case 'f':
            if (strncmp(parser->json + parser->pos, "false", 5) == 0) {
                parser->pos += 5;
                printf("false\n");
            }
            break;
        case '"':
            printf("\"%s\"\n", json_parse_string(parser));
            break;
        case '0': case '1': case '2': case '3': case '4':
        case '5': case '6': case '7': case '8': case '9':
            // TODO: Parse a number
            break;
        case '[':
            // TODO: Parse an array
            break;
        case '{':
            // TODO: Parse an object
            break;
        default:
            printf("Error: Invalid JSON value!\n");
            break;
    }
}

// Parse a JSON string
void json_parse(char *json) {
    json_parser_t *parser = json_new(json);

    json_parse_value(parser);

    free(parser);
}

int main() {
    char *json1 = "{\"name\": \"John Doe\", \"age\": 30, \"city\": \"New York\"}";
    char *json2 = "[1, 2, 3, 4, 5]";
    char *json3 = "\"Hello, world!\"";

    printf("Parsing JSON string 1:\n");
    json_parse(json1);

    printf("\nParsing JSON string 2:\n");
    json_parse(json2);

    printf("\nParsing JSON string 3:\n");
    json_parse(json3);

    return 0;
}