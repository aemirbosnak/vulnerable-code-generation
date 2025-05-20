//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Token types
#define TOKEN_EOF 0
#define TOKEN_TAG_START 1
#define TOKEN_TAG_END 2
#define TOKEN_TAG_NAME 3
#define TOKEN_TAG_ATTR_NAME 4
#define TOKEN_TAG_ATTR_VALUE 5
#define TOKEN_TEXT 6

// Token struct
typedef struct token {
    int type;
    char *value;
} token_t;

// Tokenizer struct
typedef struct tokenizer {
    char *input;
    int pos;
    int len;
    token_t *current_token;
} tokenizer_t;

// Create a new tokenizer
tokenizer_t *tokenizer_new(char *input) {
    tokenizer_t *tokenizer = malloc(sizeof(tokenizer_t));
    tokenizer->input = input;
    tokenizer->pos = 0;
    tokenizer->len = strlen(input);
    tokenizer->current_token = NULL;
    return tokenizer;
}

// Free a tokenizer
void tokenizer_free(tokenizer_t *tokenizer) {
    if (tokenizer->current_token) {
        free(tokenizer->current_token->value);
        free(tokenizer->current_token);
    }
    free(tokenizer);
}

// Get the next token
token_t *tokenizer_next_token(tokenizer_t *tokenizer) {
    if (tokenizer->pos >= tokenizer->len) {
        return NULL;
    }

    // Skip whitespace
    while (tokenizer->pos < tokenizer->len && isspace(tokenizer->input[tokenizer->pos])) {
        tokenizer->pos++;
    }

    // Check for end of file
    if (tokenizer->pos >= tokenizer->len) {
        return NULL;
    }

    // Create a new token
    token_t *token = malloc(sizeof(token_t));

    // Get the token type
    if (tokenizer->input[tokenizer->pos] == '<') {
        tokenizer->pos++;
        if (tokenizer->input[tokenizer->pos] == '/') {
            tokenizer->pos++;
            token->type = TOKEN_TAG_END;
        } else {
            token->type = TOKEN_TAG_START;
        }
    } else if (tokenizer->input[tokenizer->pos] == '/') {
        tokenizer->pos++;
        if (tokenizer->input[tokenizer->pos] == '>') {
            tokenizer->pos++;
            token->type = TOKEN_TAG_END;
        } else {
            token->type = TOKEN_TAG_NAME;
        }
    } else {
        token->type = TOKEN_TEXT;
    }

    // Get the token value
    int start_pos = tokenizer->pos;
    while (tokenizer->pos < tokenizer->len && !isspace(tokenizer->input[tokenizer->pos]) && tokenizer->input[tokenizer->pos] != '<' && tokenizer->input[tokenizer->pos] != '/') {
        tokenizer->pos++;
    }
    int end_pos = tokenizer->pos;
    token->value = malloc(end_pos - start_pos + 1);
    strncpy(token->value, tokenizer->input + start_pos, end_pos - start_pos);
    token->value[end_pos - start_pos] = '\0';

    // Return the token
    return token;
}

// Beautify HTML
char *beautify_html(char *input) {
    // Create a tokenizer
    tokenizer_t *tokenizer = tokenizer_new(input);

    // Create a buffer to store the beautified HTML
    int buffer_size = 1024;
    char *buffer = malloc(buffer_size);
    int buffer_pos = 0;

    // Iterate over the tokens
    token_t *token;
    while ((token = tokenizer_next_token(tokenizer)) != NULL) {
        // Add the token to the buffer
        switch (token->type) {
            case TOKEN_TAG_START:
                buffer_pos += snprintf(buffer + buffer_pos, buffer_size - buffer_pos, "<%s>", token->value);
                break;
            case TOKEN_TAG_END:
                buffer_pos += snprintf(buffer + buffer_pos, buffer_size - buffer_pos, "</%s>", token->value);
                break;
            case TOKEN_TAG_NAME:
                buffer_pos += snprintf(buffer + buffer_pos, buffer_size - buffer_pos, "%s", token->value);
                break;
            case TOKEN_TAG_ATTR_NAME:
                buffer_pos += snprintf(buffer + buffer_pos, buffer_size - buffer_pos, " %s", token->value);
                break;
            case TOKEN_TAG_ATTR_VALUE:
                buffer_pos += snprintf(buffer + buffer_pos, buffer_size - buffer_pos, "=\"%s\"", token->value);
                break;
            case TOKEN_TEXT:
                buffer_pos += snprintf(buffer + buffer_pos, buffer_size - buffer_pos, "%s", token->value);
                break;
        }

        // Free the token
        free(token->value);
        free(token);
    }

    // Free the tokenizer
    tokenizer_free(tokenizer);

    // Resize the buffer to the correct size
    buffer = realloc(buffer, buffer_pos + 1);
    buffer[buffer_pos] = '\0';

    // Return the beautified HTML
    return buffer;
}

// Main function
int main() {
    // Get the input HTML
    char *input = "<html><body><h1>Hello, world!</h1></body></html>";

    // Beautify the HTML
    char *beautified_html = beautify_html(input);

    // Print the beautified HTML
    printf("%s\n", beautified_html);

    // Free the beautified HTML
    free(beautified_html);

    return 0;
}