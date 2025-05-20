//GPT-4o-mini DATASET v1.0 Category: Building a JSON Parser ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TOKEN_SIZE 256
#define MAX_JSON_SIZE 1024

typedef enum {
    TOKEN_NONE,
    TOKEN_STRING,
    TOKEN_NUMBER,
    TOKEN_OBJECT_START,
    TOKEN_OBJECT_END,
    TOKEN_ARRAY_START,
    TOKEN_ARRAY_END,
    TOKEN_COLON,
    TOKEN_COMMA,
    TOKEN_TRUE,
    TOKEN_FALSE,
    TOKEN_NULL,
} TokenType;

typedef struct {
    TokenType type;
    char value[MAX_TOKEN_SIZE];
} Token;

char *json;
size_t json_length;
size_t pos;

void skip_whitespace() {
    while (pos < json_length && isspace(json[pos])) {
        pos++;
    }
}

int is_end() {
    return pos >= json_length;
}

Token next_token() {
    Token token;
    skip_whitespace();

    if (is_end()) {
        token.type = TOKEN_NONE;
        return token;
    }

    char current = json[pos];

    if (current == '{') {
        token.type = TOKEN_OBJECT_START;
        pos++;
    } else if (current == '}') {
        token.type = TOKEN_OBJECT_END;
        pos++;
    } else if (current == '[') {
        token.type = TOKEN_ARRAY_START;
        pos++;
    } else if (current == ']') {
        token.type = TOKEN_ARRAY_END;
        pos++;
    } else if (current == ':') {
        token.type = TOKEN_COLON;
        pos++;
    } else if (current == ',') {
        token.type = TOKEN_COMMA;
        pos++;
    } else if (current == '"') {
        pos++;
        size_t start = pos;
        while (pos < json_length && json[pos] != '"') {
            if (json[pos] == '\\') {
                pos++; // Skip the escape character
            }
            pos++;
        }
        size_t length = pos - start;
        strncpy(token.value, &json[start], length);
        token.value[length] = '\0';
        token.type = TOKEN_STRING;
        pos++; // Skip the closing quote
    } else if (isdigit(current) || current == '-') {
        size_t start = pos;
        while (pos < json_length && (isdigit(json[pos]) || json[pos] == '.')) {
            pos++;
        }
        size_t length = pos - start;
        strncpy(token.value, &json[start], length);
        token.value[length] = '\0';
        token.type = TOKEN_NUMBER;
    } else if (strncmp(&json[pos], "true", 4) == 0) {
        strcpy(token.value, "true");
        token.type = TOKEN_TRUE;
        pos += 4;
    } else if (strncmp(&json[pos], "false", 5) == 0) {
        strcpy(token.value, "false");
        token.type = TOKEN_FALSE;
        pos += 5;
    } else if (strncmp(&json[pos], "null", 4) == 0) {
        strcpy(token.value, "null");
        token.type = TOKEN_NULL;
        pos += 4;
    } else {
        token.type = TOKEN_NONE;
    }

    return token;
}

void parse_json() {
    Token token;
    while ((token = next_token()).type != TOKEN_NONE) {
        switch (token.type) {
            case TOKEN_OBJECT_START: 
                printf("Start of Object\n"); 
                break;
            case TOKEN_OBJECT_END: 
                printf("End of Object\n"); 
                break;
            case TOKEN_ARRAY_START: 
                printf("Start of Array\n"); 
                break;
            case TOKEN_ARRAY_END: 
                printf("End of Array\n"); 
                break;
            case TOKEN_STRING: 
                printf("String: %s\n", token.value); 
                break;
            case TOKEN_NUMBER: 
                printf("Number: %s\n", token.value); 
                break;
            case TOKEN_TRUE: 
            case TOKEN_FALSE:
            case TOKEN_NULL:
                printf("Keyword: %s\n", token.value); 
                break;
            default:
                break;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <json_string>\n", argv[0]);
        return EXIT_FAILURE;
    }

    json = argv[1];
    json_length = strlen(json);
    pos = 0;

    parse_json();

    return EXIT_SUCCESS;
}