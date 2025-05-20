//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a token type
typedef enum {
    TOKEN_STRING,
    TOKEN_NUMBER,
    TOKEN_TRUE,
    TOKEN_FALSE,
    TOKEN_NULL,
    TOKEN_INVALID
} token_type_t;

// Define a token struct
typedef struct {
    token_type_t type;
    char* value;
} token_t;

// Define a JSON object struct
typedef struct {
    char* key;
    char* value;
} json_object_t;

// Define a JSON parser struct
typedef struct {
    char* json;
    size_t json_length;
    size_t position;
    token_t current_token;
} json_parser_t;

// Function declarations
char* parse_string(json_parser_t* parser);
double parse_number(json_parser_t* parser);
void parse_true(json_parser_t* parser);
void parse_false(json_parser_t* parser);
void parse_null(json_parser_t* parser);
void parse_value(json_parser_t* parser);
json_object_t* parse_object(json_parser_t* parser);
void skip_whitespace(json_parser_t* parser);
token_t get_next_token(json_parser_t* parser);
char get_char(json_parser_t* parser);

// Main function
int main(void) {
    char* json = "{ 'name': 'John', 'age': 30 }";
    json_parser_t* parser = malloc(sizeof(json_parser_t));
    parser->json = json;
    parser->json_length = strlen(json);
    parser->position = 0;
    parser->current_token.type = TOKEN_INVALID;
    json_object_t* object = parse_object(parser);
    printf("Key: %s, Value: %s\n", object[0].key, object[0].value);
    printf("Key: %s, Value: %s\n", object[1].key, object[1].value);
    return 0;
}

// Parse a JSON string
char* parse_string(json_parser_t* parser) {
    char* value = malloc(sizeof(char) * parser->json_length);
    size_t i = 0;
    char c = get_char(parser);
    while (c != '\"') {
        value[i] = c;
        i++;
        c = get_char(parser);
    }
    value[i] = '\0';
    return value;
}

// Parse a JSON number
double parse_number(json_parser_t* parser) {
    double value = 0;
    char c = get_char(parser);
    while (c >= '0' && c <= '9') {
        value = (value * 10) + (c - '0');
        c = get_char(parser);
    }
    if (c == '.') {
        double fraction = 0;
        int divisor = 10;
        c = get_char(parser);
        while (c >= '0' && c <= '9') {
            fraction += (double)(c - '0') / divisor;
            divisor *= 10;
            c = get_char(parser);
        }
        value += fraction;
    }
    parser->position--;
    return value;
}

// Parse a true value
void parse_true(json_parser_t* parser) {
    char c = get_char(parser);
    if (c == 't') {
        c = get_char(parser);
        if (c == 'r') {
            c = get_char(parser);
            if (c == 'u') {
                c = get_char(parser);
                if (c == 'e') {
                    parser->current_token.type = TOKEN_TRUE;
                }
            }
        }
    }
}

// Parse a false value
void parse_false(json_parser_t* parser) {
    char c = get_char(parser);
    if (c == 'f') {
        c = get_char(parser);
        if (c == 'a') {
            c = get_char(parser);
            if (c == 'l') {
                c = get_char(parser);
                if (c == 's') {
                    c = get_char(parser);
                    if (c == 'e') {
                        parser->current_token.type = TOKEN_FALSE;
                    }
                }
            }
        }
    }
}

// Parse a null value
void parse_null(json_parser_t* parser) {
    char c = get_char(parser);
    if (c == 'n') {
        c = get_char(parser);
        if (c == 'u') {
            c = get_char(parser);
            if (c == 'l') {
                c = get_char(parser);
                if (c == 'l') {
                    parser->current_token.type = TOKEN_NULL;
                }
            }
        }
    }
}

// Parse a JSON value
void parse_value(json_parser_t* parser) {
    skip_whitespace(parser);
    char c = get_char(parser);
    if (c == '\"') {
        char* value = parse_string(parser);
        parser->current_token.type = TOKEN_STRING;
        parser->current_token.value = value;
    } else if (c >= '0' && c <= '9' || c == '-') {
        double value = parse_number(parser);
        parser->current_token.type = TOKEN_NUMBER;
        parser->current_token.value = malloc(sizeof(char) * 64);
        sprintf(parser->current_token.value, "%f", value);
    } else if (c == 't') {
        parse_true(parser);
        parser->current_token.value = "true";
    } else if (c == 'f') {
        parse_false(parser);
        parser->current_token.value = "false";
    } else if (c == 'n') {
        parse_null(parser);
        parser->current_token.value = "null";
    } else {
        parser->current_token.type = TOKEN_INVALID;
    }
}

// Parse a JSON object
json_object_t* parse_object(json_parser_t* parser) {
    skip_whitespace(parser);
    char c = get_char(parser);
    if (c != '{') {
        return NULL;
    }
    json_object_t* object = malloc(sizeof(json_object_t) * 10);
    size_t index = 0;
    while (1) {
        skip_whitespace(parser);
        c = get_char(parser);
        if (c == '}') {
            break;
        } else if (c == ',') {
            skip_whitespace(parser);
        }
        // Parse key
        char* key = parse_string(parser);
        object[index].key = key;
        // Parse colon
        skip_whitespace(parser);
        c = get_char(parser);
        if (c != ':') {
            return NULL;
        }
        // Parse value
        parse_value(parser);
        char* value = parser->current_token.value;
        object[index].value = value;
        index++;
    }
    return object;
}

// Skip any whitespace in the JSON string
void skip_whitespace(json_parser_t* parser) {
    char c = get_char(parser);
    while (c == ' ' || c == '\n' || c == '\t' || c == '\r') {
        c = get_char(parser);
    }
    parser->position--;
}

// Get the next token in the JSON string
token_t get_next_token(json_parser_t* parser) {
    parse_value(parser);
    return parser->current_token;
}

// Get the character at the current position in the JSON string
char get_char(json_parser_t* parser) {
    char c = parser->json[parser->position];
    parser->position++;
    return c;
}