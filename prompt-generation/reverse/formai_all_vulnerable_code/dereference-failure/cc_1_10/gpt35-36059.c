//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 10000 // Maximum JSON string size
#define MAX_OBJECT_DEPTH 50 // Maximum depth of JSON object
#define MAX_TOKENS 10000 // Maximum number of tokens in JSON

/* JSON token types */
typedef enum {
    TOKEN_INVALID,
    TOKEN_OBJECT_START,
    TOKEN_OBJECT_CLOSE,
    TOKEN_ARRAY_START,
    TOKEN_ARRAY_CLOSE,
    TOKEN_STRING,
    TOKEN_NUMBER,
    TOKEN_TRUE,
    TOKEN_FALSE,
    TOKEN_NULL,
    TOKEN_COMMA,
    TOKEN_COLON
} TokenType;

/* JSON token */
typedef struct {
    TokenType type;
    char* value;
    int length;
} Token;

/* JSON parser */
typedef struct {
    char* json;
    Token tokens[MAX_TOKENS];
    int tokenIndex;
    int objectDepth;
} JSONParser;

/* Function prototypes */
JSONParser* parseJSON(char* json);
void destroyJSONParser(JSONParser* parser);
void printJSONTokens(JSONParser* parser);

/* Parse JSON string and return JSONParser */
JSONParser* parseJSON(char* json) {
    JSONParser* parser = malloc(sizeof(JSONParser));
    parser->json = json;
    parser->tokenIndex = 0;
    parser->objectDepth = 0;

    char* currentChar = parser->json;
    Token currentToken;

    while (*currentChar != '\0') {
        if (*currentChar == '{') {
            /* Object start */
            currentToken.type = TOKEN_OBJECT_START;
            currentToken.value = "{";
            currentToken.length = 1;
            parser->tokens[parser->tokenIndex++] = currentToken;
            parser->objectDepth++;
        } else if (*currentChar == '}') {
            /* Object close */
            currentToken.type = TOKEN_OBJECT_CLOSE;
            currentToken.value = "}";
            currentToken.length = 1;
            parser->tokens[parser->tokenIndex++] = currentToken;
            parser->objectDepth--;
        } else if (*currentChar == '[') {
            /* Array start */
            currentToken.type = TOKEN_ARRAY_START;
            currentToken.value = "[";
            currentToken.length = 1;
            parser->tokens[parser->tokenIndex++] = currentToken;
        } else if (*currentChar == ']') {
            /* Array close */
            currentToken.type = TOKEN_ARRAY_CLOSE;
            currentToken.value = "]";
            currentToken.length = 1;
            parser->tokens[parser->tokenIndex++] = currentToken;
        } else if (*currentChar == ',') {
            /* Comma */
            currentToken.type = TOKEN_COMMA;
            currentToken.value = ",";
            currentToken.length = 1;
            parser->tokens[parser->tokenIndex++] = currentToken;
        } else if (*currentChar == ':') {
            /* Colon */
            currentToken.type = TOKEN_COLON;
            currentToken.value = ":";
            currentToken.length = 1;
            parser->tokens[parser->tokenIndex++] = currentToken;
        } else if (*currentChar == '\"') {
            /* String */
            char* startChar = currentChar + 1;
            char* endChar = startChar;
            while (*endChar != '\"') {
                endChar++;
            }
            currentToken.type = TOKEN_STRING;
            currentToken.value = malloc(endChar - startChar + 1);
            strncpy(currentToken.value, startChar, endChar - startChar);
            currentToken.value[endChar - startChar] = '\0';
            currentToken.length = endChar - startChar + 1;
            parser->tokens[parser->tokenIndex++] = currentToken;
            currentChar = endChar;
        } else if ((*currentChar >= '0' && *currentChar <= '9') || *currentChar == '-') {
            /* Number */
            char* startChar = currentChar;
            char* endChar = startChar + 1;
            while ((*endChar >= '0' && *endChar <= '9') || *endChar == '.' || *endChar == 'e' || *endChar == 'E' || *endChar == '+' || *endChar == '-') {
                endChar++;
            }
            currentToken.type = TOKEN_NUMBER;
            currentToken.value = malloc(endChar - startChar + 1);
            strncpy(currentToken.value, startChar, endChar - startChar);
            currentToken.value[endChar - startChar] = '\0';
            currentToken.length = endChar - startChar;
            parser->tokens[parser->tokenIndex++] = currentToken;
            currentChar = endChar - 1;
        } else if (strncmp(currentChar, "true", 4) == 0) {
            /* True */
            currentToken.type = TOKEN_TRUE;
            currentToken.value = "true";
            currentToken.length = 4;
            parser->tokens[parser->tokenIndex++] = currentToken;
            currentChar += 3;
        } else if (strncmp(currentChar, "false", 5) == 0) {
            /* False */
            currentToken.type = TOKEN_FALSE;
            currentToken.value = "false";
            currentToken.length = 5;
            parser->tokens[parser->tokenIndex++] = currentToken;
            currentChar += 4;
        } else if (strncmp(currentChar, "null", 4) == 0) {
            /* Null */
            currentToken.type = TOKEN_NULL;
            currentToken.value = "null";
            currentToken.length = 4;
            parser->tokens[parser->tokenIndex++] = currentToken;
            currentChar += 3;
        }

        /* Move to next character */
        currentChar++;
    }

    return parser;
}

/* Destroy JSONParser and free memory */
void destroyJSONParser(JSONParser* parser) {
    for (int i = 0; i < parser->tokenIndex; i++) {
        if (parser->tokens[i].value != NULL) {
            free(parser->tokens[i].value);
        }
    }
    free(parser);
}

/* Print all JSON tokens */
void printJSONTokens(JSONParser* parser) {
    for (int i = 0; i < parser->tokenIndex; i++) {
        printf("{ type: %d, value: %s, length: %d }\n", parser->tokens[i].type, parser->tokens[i].value, parser->tokens[i].length);
    }
}

/* Main function */
int main() {
    char json[MAX_JSON_SIZE] = "{ \"name\": \"John Doe\", \"age\": 30, \"pets\": [\"dog\", \"cat\"], \"isMarried\": false, \"address\": { \"street\": \"123 Main St\", \"city\": \"New York\" } }";
    JSONParser* parser = parseJSON(json);
    printJSONTokens(parser);
    destroyJSONParser(parser);
    return 0;
}