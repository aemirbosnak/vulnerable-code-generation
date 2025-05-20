//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    NONE,
    TEXT,
    TAG_START,
    TAG_END,
    COMMENT_START,
    COMMENT_END,
    ATTR_START,
    ATTR_END,
    ATTR_EQ,
    ATTR_NAME,
    ATTR_VALUE,
    DOCTYPE,
    CDATA_START,
    CDATA_END,
} Token;

typedef struct {
    Token type;
    char *content;
    int line;
    int column;
} TokenInfo;

typedef struct {
    TokenInfo *tokens;
    int num_tokens;
    int alloc_tokens;
} TokenList;

void init_token_list(TokenList *list) {
    list->tokens = NULL;
    list->num_tokens = 0;
    list->alloc_tokens = 0;
}

void free_token_list(TokenList *list) {
    for (int i = 0; i < list->num_tokens; i++) {
        free(list->tokens[i].content);
    }
    free(list->tokens);
}

int grow_token_list(TokenList *list, int new_size) {
    if (new_size > list->alloc_tokens) {
        list->tokens = realloc(list->tokens, sizeof(TokenInfo) * new_size);
        if (list->tokens == NULL) {
            return 1;
        }
        list->alloc_tokens = new_size;
    }
    return 0;
}

int add_token(TokenList *list, Token type, const char *content, int line, int column) {
    if (grow_token_list(list, list->num_tokens + 1)) {
        return 1;
    }
    list->tokens[list->num_tokens].type = type;
    list->tokens[list->num_tokens].content = strdup(content);
    list->tokens[list->num_tokens].line = line;
    list->tokens[list->num_tokens].column = column;
    list->num_tokens++;
    return 0;
}

int is_whitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

int is_alpha(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int is_digit(char c) {
    return (c >= '0' && c <= '9');
}

int is_alphanumeric(char c) {
    return (is_alpha(c) || is_digit(c));
}

int scan_html(const char *html, TokenList *list) {
    int line = 1;
    int column = 0;
    char *content = (char *)html;
    Token type = NONE;
    char *start = content;
    while (*content != '\0') {
        switch (*content) {
            case '<':
                if (type == TEXT) {
                    add_token(list, TEXT, start, line, column);
                }
                type = TAG_START;
                start = content;
                break;
            case '>':
                if (type == TAG_START) {
                    add_token(list, TAG_END, start, line, column);
                } else if (type == COMMENT_START) {
                    add_token(list, COMMENT_END, start, line, column);
                } else if (type == CDATA_START) {
                    add_token(list, CDATA_END, start, line, column);
                }
                type = NONE;
                start = content + 1;
                break;
            case '/':
                if (type == TAG_START && content[1] == '!') {
                    type = COMMENT_START;
                    start = content + 1;
                } else if (type == CDATA_START && content[1] == ']') {
                    type = CDATA_END;
                    start = content + 1;
                }
                break;
            case '!':
                if (type == TAG_START && content[1] == '[' && content[2] == 'C' && content[3] == 'D' && content[4] == 'A' && content[5] == 'T' && content[6] == 'A' && content[7] == '[') {
                    type = CDATA_START;
                    start = content + 1;
                }
                break;
            case '"':
            case '\'':
                if (type == ATTR_START) {
                    type = ATTR_VALUE;
                    start = content;
                } else if (type == ATTR_VALUE) {
                    add_token(list, ATTR_VALUE, start, line, column);
                    type = ATTR_END;
                    start = content + 1;
                }
                break;
            case '=':
                if (type == ATTR_START) {
                    type = ATTR_EQ;
                    start = content;
                }
                break;
            case ' ':
            case '\t':
            case '\n':
            case '\r':
                if (type == TEXT) {
                    add_token(list, TEXT, start, line, column);
                    type = NONE;
                    start = content + 1;
                } else if (type == ATTR_NAME) {
                    add_token(list, ATTR_NAME, start, line, column);
                    type = ATTR_END;
                    start = content + 1;
                }
                break;
            default:
                if (type == NONE) {
                    type = TEXT;
                    start = content;
                } else if (type == TAG_START) {
                    type = TAG_END;
                    start = content;
                } else if (type == ATTR_START) {
                    type = ATTR_NAME;
                    start = content;
                }
                break;
        }
        if (*content == '\n') {
            line++;
            column = 0;
        } else {
            column++;
        }
        content++;
    }
    if (type == TEXT) {
        add_token(list, TEXT, start, line, column);
    }
    return 0;
}

void print_tokens(TokenList *list) {
    for (int i = 0; i < list->num_tokens; i++) {
        TokenInfo *token = &list->tokens[i];
        printf("%s (%d, %d)\n", token->content, token->line, token->column);
    }
}

int main() {
    const char *html = "<html><head><title>Hello world</title></head><body><h1>Hello world</h1></body></html>";
    TokenList list;
    init_token_list(&list);
    scan_html(html, &list);
    print_tokens(&list);
    free_token_list(&list);
    return 0;
}