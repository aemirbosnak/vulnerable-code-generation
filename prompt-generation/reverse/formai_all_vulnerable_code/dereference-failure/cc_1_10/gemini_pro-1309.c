//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the configuration options
#define INDENT_SIZE 2
#define MAX_LINE_LENGTH 80
#define WRAP_LONG_LINES 1

// Define the state of the beautifier
enum {
    STATE_NORMAL,
    STATE_IN_TAG,
    STATE_IN_COMMENT
};

// Define the token types
enum {
    TOKEN_NONE,
    TOKEN_TAG_START,
    TOKEN_TAG_END,
    TOKEN_COMMENT_START,
    TOKEN_COMMENT_END,
    TOKEN_TEXT
};

// Define the token structure
typedef struct {
    int type;
    char *value;
} token_t;

// Create a new token
token_t *new_token(int type, char *value) {
    token_t *token = malloc(sizeof(token_t));
    token->type = type;
    token->value = value;
    return token;
}

// Tokenize the HTML
token_t **tokenize_html(char *html) {
    int length = strlen(html);
    token_t **tokens = malloc(sizeof(token_t *) * length);
    int index = 0;

    int state = STATE_NORMAL;
    char *token_start = html;
    char *token_end = html;

    while (*token_end != '\0') {
        switch (*token_end) {
            case '<':
                if (state == STATE_NORMAL) {
                    state = STATE_IN_TAG;
                    token_start = token_end;
                }
                break;
            case '>':
                if (state == STATE_IN_TAG) {
                    state = STATE_NORMAL;
                    token_end++;
                    tokens[index++] = new_token(TOKEN_TAG_END, strndup(token_start, token_end - token_start));
                }
                break;
            case '/':
                if (state == STATE_IN_TAG && *(token_end + 1) == '>') {
                    state = STATE_NORMAL;
                    token_end += 2;
                    tokens[index++] = new_token(TOKEN_TAG_END, strndup(token_start, token_end - token_start));
                }
                break;
            case '!':
                if (state == STATE_NORMAL && strncmp(token_end, "<!--", 4) == 0) {
                    state = STATE_IN_COMMENT;
                    token_start = token_end;
                }
                break;
            case '-':
                if (state == STATE_IN_COMMENT && strncmp(token_end, "-->", 3) == 0) {
                    state = STATE_NORMAL;
                    token_end += 3;
                    tokens[index++] = new_token(TOKEN_COMMENT_END, strndup(token_start, token_end - token_start));
                }
                break;
            default:
                if (state == STATE_NORMAL) {
                    token_end++;
                }
                break;
        }

        if (state == STATE_NORMAL) {
            token_end++;
        }

        if (*token_end != '\0' && (token_end - token_start) >= MAX_LINE_LENGTH && WRAP_LONG_LINES) {
            tokens[index++] = new_token(TOKEN_TEXT, strndup(token_start, token_end - token_start));
            token_start = token_end;
        }
    }

    if (state == STATE_IN_TAG) {
        tokens[index++] = new_token(TOKEN_TAG_END, strndup(token_start, token_end - token_start));
    }

    if (state == STATE_IN_COMMENT) {
        tokens[index++] = new_token(TOKEN_COMMENT_END, strndup(token_start, token_end - token_start));
    }

    tokens[index] = NULL;

    return tokens;
}

// Beautify the HTML
char *beautify_html(char *html) {
    // Tokenize the HTML
    token_t **tokens = tokenize_html(html);

    // Create a new string to store the beautified HTML
    char *beautified_html = malloc(strlen(html) * 2);
    int length = 0;

    // Iterate over the tokens
    int indent_level = 0;
    for (int i = 0; tokens[i] != NULL; i++) {
        token_t *token = tokens[i];

        // Add the token to the beautified HTML
        switch (token->type) {
            case TOKEN_TAG_START:
                length += sprintf(beautified_html + length, "%*s<%s>", indent_level * INDENT_SIZE, "", token->value);
                indent_level++;
                break;
            case TOKEN_TAG_END:
                indent_level--;
                length += sprintf(beautified_html + length, "%*s</%s>", indent_level * INDENT_SIZE, "", token->value);
                break;
            case TOKEN_COMMENT_START:
                length += sprintf(beautified_html + length, "%*s<!--", indent_level * INDENT_SIZE, "");
                break;
            case TOKEN_COMMENT_END:
                length += sprintf(beautified_html + length, "%*s-->", indent_level * INDENT_SIZE, "");
                break;
            case TOKEN_TEXT:
                length += sprintf(beautified_html + length, "%*s%s", indent_level * INDENT_SIZE, "", token->value);
                break;
        }

        // Free the token
        free(token->value);
        free(token);
    }

    // Free the tokens
    free(tokens);

    // Return the beautified HTML
    return beautified_html;
}

// Main function
int main() {
    // Read the HTML from a file
    FILE *file = fopen("html.txt", "r");
    char *html = malloc(1024);
    fread(html, 1, 1024, file);
    fclose(file);

    // Beautify the HTML
    char *beautified_html = beautify_html(html);

    // Print the beautified HTML
    printf("%s", beautified_html);

    // Free the beautified HTML
    free(beautified_html);

    // Free the HTML
    free(html);

    return 0;
}