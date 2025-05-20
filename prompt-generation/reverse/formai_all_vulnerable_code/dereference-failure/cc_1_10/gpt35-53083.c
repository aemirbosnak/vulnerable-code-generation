//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 256

typedef enum {TOKEN_OBJECT_START, TOKEN_OBJECT_END, TOKEN_ARRAY_START, TOKEN_ARRAY_END, TOKEN_COLON, TOKEN_COMMA, TOKEN_STRING, TOKEN_NUMBER, TOKEN_TRUE, TOKEN_FALSE, TOKEN_NULL, TOKEN_UNKNOWN} token_type;

typedef struct {
    token_type type;
    char value[MAX_LENGTH];
} token;

void print_token(token t) {
    printf("Type: %d Value: %s\n", t.type, t.value);
}

int is_number(char* str) {
    int i = 0;
    if (str[0] == '-' || str[0] == '+') {
        i++;
    }
    for (; i < strlen(str); i++) {
        if (!isdigit(str[i])) {
            return 0;
        }
    }
    return 1;
}

void parse_string(char* str, char* buffer) {
    int i, j;
    for (i = 1, j = 0; str[i] != '"'; i++, j++) {
        buffer[j] = str[i];
        if (str[i] == '\\') {
            i++;
            switch (str[i]) {
                case 'n':
                    buffer[j] = '\n';
                    break;
                case 't':
                    buffer[j] = '\t';
                    break;
                case 'r':
                    buffer[j] = '\r';
                    break;
                case '"':
                    buffer[j] = '"';
                    break;
                case '\\':
                    buffer[j] = '\\';
                    break;
                default:
                    buffer[j] = str[i];
                    break;
            }
        }
    }
    buffer[j] = '\0';
}

void tokenize(char* input, token** tokens, int* num_tokens) {
    int i = 0, j = 0;
    *num_tokens = 0;
    *tokens = NULL;
    while (i < strlen(input)) {
        if (input[i] == '{') {
            (*num_tokens)++;
            *tokens = (token*)realloc(*tokens, *num_tokens * sizeof(token));
            (*tokens)[*num_tokens - 1].type = TOKEN_OBJECT_START;
        }
        else if (input[i] == '}') {
            (*num_tokens)++;
            *tokens = (token*)realloc(*tokens, *num_tokens * sizeof(token));
            (*tokens)[*num_tokens - 1].type = TOKEN_OBJECT_END;
        }
        else if (input[i] == '[') {
            (*num_tokens)++;
            *tokens = (token*)realloc(*tokens, *num_tokens * sizeof(token));
            (*tokens)[*num_tokens - 1].type = TOKEN_ARRAY_START;
        }
        else if (input[i] == ']') {
            (*num_tokens)++;
            *tokens = (token*)realloc(*tokens, *num_tokens * sizeof(token));
            (*tokens)[*num_tokens - 1].type = TOKEN_ARRAY_END;
        }
        else if (input[i] == ':') {
            (*num_tokens)++;
            *tokens = (token*)realloc(*tokens, *num_tokens * sizeof(token));
            (*tokens)[*num_tokens - 1].type = TOKEN_COLON;
        }
        else if (input[i] == ',') {
            (*num_tokens)++;
            *tokens = (token*)realloc(*tokens, *num_tokens * sizeof(token));
            (*tokens)[*num_tokens - 1].type = TOKEN_COMMA;
        }
        else if (input[i] == '"') {
            char buffer[MAX_LENGTH];
            parse_string(input + i, buffer);
            i += strlen(buffer) + 1;
            (*num_tokens)++;
            *tokens = (token*)realloc(*tokens, *num_tokens * sizeof(token));
            (*tokens)[*num_tokens - 1].type = TOKEN_STRING;
            strcpy((*tokens)[*num_tokens - 1].value, buffer);
        }
        else if (isdigit(input[i]) || input[i] == '-') {
            int n = 0;
            char buffer[MAX_LENGTH];
            while (isdigit(input[i]) || input[i] == '-' || input[i] == '+' || input[i] == 'e' || input[i] == 'E' || input[i] == '.') {
                buffer[n++] = input[i];
                i++;
            }
            buffer[n] = '\0';
            if (is_number(buffer)) {
                (*num_tokens)++;
                *tokens = (token*)realloc(*tokens, *num_tokens * sizeof(token));
                (*tokens)[*num_tokens - 1].type = TOKEN_NUMBER;
                strcpy((*tokens)[*num_tokens - 1].value, buffer);
            }
            else {
                (*num_tokens)++;
                *tokens = (token*)realloc(*tokens, *num_tokens * sizeof(token));
                (*tokens)[*num_tokens - 1].type = TOKEN_UNKNOWN;
                strcpy((*tokens)[*num_tokens - 1].value, buffer);
            }
        }
        else if (strncmp(input + i, "true", 4) == 0) {
            (*num_tokens)++;
            *tokens = (token*)realloc(*tokens, *num_tokens * sizeof(token));
            (*tokens)[*num_tokens - 1].type = TOKEN_TRUE;
            strncpy((*tokens)[*num_tokens - 1].value, input + i, 4);
            (*tokens)[*num_tokens - 1].value[4] = '\0';
            i += 4;
        }
        else if (strncmp(input + i, "false", 5) == 0) {
            (*num_tokens)++;
            *tokens = (token*)realloc(*tokens, *num_tokens * sizeof(token));
            (*tokens)[*num_tokens - 1].type = TOKEN_FALSE;
            strncpy((*tokens)[*num_tokens - 1].value, input + i, 5);
            (*tokens)[*num_tokens - 1].value[5] = '\0';
            i += 5;
        }
        else if (strncmp(input + i, "null", 4) == 0) {
            (*num_tokens)++;
            *tokens = (token*)realloc(*tokens, *num_tokens * sizeof(token));
            (*tokens)[*num_tokens - 1].type = TOKEN_NULL;
            strncpy((*tokens)[*num_tokens - 1].value, input + i, 4);
            (*tokens)[*num_tokens - 1].value[4] = '\0';
            i += 4;
        }
        else if (isspace(input[i])) {
            i++;
        }
        else {
            int n = 0;
            char buffer[MAX_LENGTH];
            while (!isspace(input[i]) && input[i] != ',' && input[i] != ':' && input[i] != '}' && input[i] != ']') {
                buffer[n++] = input[i];
                i++;
            }
            buffer[n] = '\0';
            (*num_tokens)++;
            *tokens = (token*)realloc(*tokens, *num_tokens * sizeof(token));
            (*tokens)[*num_tokens - 1].type = TOKEN_UNKNOWN;
            strcpy((*tokens)[*num_tokens - 1].value, buffer);
        }
    }
}

int main() {
    char input[] = "{ \"name\": \"John\", \"age\": 30, \"married\": false, \"children\": [\"Ann\", \"Billy\"], \"address\": {\"street\": \"123 Main St.\", \"city\": \"Anytown\", \"state\": \"CA\", \"zip\": \"12345\"} }";
    token* tokens;
    int num_tokens;
    tokenize(input, &tokens, &num_tokens);
    for (int i = 0; i < num_tokens; i++) {
        print_token(tokens[i]);
    }
    free(tokens);
    return 0;
}