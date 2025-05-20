//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

struct token {
    char *data;
    int length;
    int line;
    int column;
};

struct token_list {
    struct token *tokens;
    int num_tokens;
    int capacity;
};

struct html_beautifier {
    struct token_list tokens;
    int current_line;
    int current_column;
    int indent_level;
    int indent_size;
};

void init_token_list(struct token_list *list) {
    list->tokens = NULL;
    list->num_tokens = 0;
    list->capacity = 0;
}

void free_token_list(struct token_list *list) {
    for (int i = 0; i < list->num_tokens; i++) {
        free(list->tokens[i].data);
    }
    free(list->tokens);
}

void add_token(struct token_list *list, char *data, int length, int line, int column) {
    if (list->num_tokens >= list->capacity) {
        list->capacity = list->capacity == 0 ? 16 : list->capacity * 2;
        list->tokens = realloc(list->tokens, list->capacity * sizeof(struct token));
    }
    list->tokens[list->num_tokens].data = malloc(length + 1);
    memcpy(list->tokens[list->num_tokens].data, data, length);
    list->tokens[list->num_tokens].data[length] = '\0';
    list->tokens[list->num_tokens].length = length;
    list->tokens[list->num_tokens].line = line;
    list->tokens[list->num_tokens].column = column;
    list->num_tokens++;
}

void init_html_beautifier(struct html_beautifier *beautifier) {
    init_token_list(&beautifier->tokens);
    beautifier->current_line = 1;
    beautifier->current_column = 1;
    beautifier->indent_level = 0;
    beautifier->indent_size = 4;
}

void free_html_beautifier(struct html_beautifier *beautifier) {
    free_token_list(&beautifier->tokens);
}

void tokenize(struct html_beautifier *beautifier, char *html) {
    char *start = html;
    while (*html) {
        if (*html == '<') {
            if (html > start) {
                add_token(&beautifier->tokens, start, html - start, beautifier->current_line, beautifier->current_column);
            }
            start = html;
            beautifier->current_column++;
            html++;
            while (*html && *html != '>') {
                html++;
                beautifier->current_column++;
            }
            if (*html == '>') {
                add_token(&beautifier->tokens, start, html - start + 1, beautifier->current_line, beautifier->current_column);
                html++;
                beautifier->current_column++;
                start = html;
            }
        } else if (*html == '\n') {
            if (html > start) {
                add_token(&beautifier->tokens, start, html - start, beautifier->current_line, beautifier->current_column);
            }
            start = html + 1;
            beautifier->current_line++;
            beautifier->current_column = 1;
            html++;
        } else {
            html++;
            beautifier->current_column++;
        }
    }
    if (html > start) {
        add_token(&beautifier->tokens, start, html - start, beautifier->current_line, beautifier->current_column);
    }
}

void beautify(struct html_beautifier *beautifier) {
    for (int i = 0; i < beautifier->tokens.num_tokens; i++) {
        struct token *token = &beautifier->tokens.tokens[i];
        if (token->data[0] == '<') {
            if (token->data[1] == '/') {
                beautifier->indent_level--;
            }
            printf("%*s%s", beautifier->indent_level * beautifier->indent_size, "", token->data);
            if (token->data[1] != '/') {
                beautifier->indent_level++;
            }
            printf("\n");
        } else {
            printf("%*s%s", beautifier->indent_level * beautifier->indent_size, "", token->data);
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s input.html\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    char *html = malloc(MAX_LINE_LENGTH);
    size_t len = 0;
    while ((len = fread(html, 1, MAX_LINE_LENGTH, fp)) > 0) {
        html[len] = '\0';
    }
    fclose(fp);

    struct html_beautifier beautifier;
    init_html_beautifier(&beautifier);
    tokenize(&beautifier, html);
    beautify(&beautifier);
    free_html_beautifier(&beautifier);
    free(html);

    return 0;
}