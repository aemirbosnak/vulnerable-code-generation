//FormAI DATASET v1.0 Category: Syntax parsing ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    TOK_NULL,
    TOK_IF,
    TOK_ELSE,
    TOK_WHILE,
    TOK_FOR,
    TOK_PLUS,
    TOK_MINUS,
    TOK_STAR,
    TOK_SLASH,
    TOK_LPAREN,
    TOK_RPAREN,
    TOK_LBRACE,
    TOK_RBRACE,
    TOK_SEMI,
    TOK_EQUALS,
    TOK_INTLIT
} TokenType;

typedef struct {
    char *text;
    size_t len;
} TokenText;

typedef struct {
    TokenType type;
    TokenText text;
} Token;

TokenText getText(char *s) {
    TokenText result;
    result.text = s;
    result.len = strlen(s);
    return result;
}

Token getTOK_NULL() {
    Token result;
    result.type = TOK_NULL;
    return result;
}

Token getTOK_IF(char *s) {
    Token result;
    result.type = TOK_IF;
    result.text = getText(s);
    return result;
}

Token getTOK_ELSE(char *s) {
    Token result;
    result.type = TOK_ELSE;
    result.text = getText(s);
    return result;
}

Token getTOK_WHILE(char *s) {
    Token result;
    result.type = TOK_WHILE;
    result.text = getText(s);
    return result;
}

Token getTOK_FOR(char *s) {
    Token result;
    result.type = TOK_FOR;
    result.text = getText(s);
    return result;
}

Token getTOK_PLUS(char *s) {
    Token result;
    result.type = TOK_PLUS;
    result.text = getText(s);
    return result;
}

Token getTOK_MINUS(char *s) {
    Token result;
    result.type = TOK_MINUS;
    result.text = getText(s);
    return result;
}

Token getTOK_STAR(char *s) {
    Token result;
    result.type = TOK_STAR;
    result.text = getText(s);
    return result;
}

Token getTOK_SLASH(char *s) {
    Token result;
    result.type = TOK_SLASH;
    result.text = getText(s);
    return result;
}

Token getTOK_LPAREN(char *s) {
    Token result;
    result.type = TOK_LPAREN;
    result.text = getText(s);
    return result;
}

Token getTOK_RPAREN(char *s) {
    Token result;
    result.type = TOK_RPAREN;
    result.text = getText(s);
    return result;
}

Token getTOK_LBRACE(char *s) {
    Token result;
    result.type = TOK_LBRACE;
    result.text = getText(s);
    return result;
}

Token getTOK_RBRACE(char *s) {
    Token result;
    result.type = TOK_RBRACE;
    result.text = getText(s);
    return result;
}

Token getTOK_SEMI(char *s) {
    Token result;
    result.type = TOK_SEMI;
    result.text = getText(s);
    return result;
}

Token getTOK_EQUALS(char *s) {
    Token result;
    result.type = TOK_EQUALS;
    result.text = getText(s);
    return result;
}

Token getTOK_INTLIT(char *s, size_t len) {
    Token result;
    result.type = TOK_INTLIT;
    result.text.text = malloc(len + 1);
    strncpy(result.text.text, s, len);
    result.text.text[len] = '\0';
    result.text.len = len;
    return result;
}

#define MAX_SOURCE_SIZE 100 * 1024

char *readFile(char *filename) {
    FILE *f;
    long size;
    char *buf;

    f = fopen(filename, "rb");
    if (f == NULL)
        return NULL;

    fseek(f, 0, SEEK_END);
    size = ftell(f);
    rewind(f);

    buf = malloc(size + 1);
    fread(buf, 1, size, f);
    buf[size] = '\0';

    fclose(f);

    return buf;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s filename.c\n", argv[0]);
        exit(1);
    }

    char *source = readFile(argv[1]);
    if (source == NULL) {
        fprintf(stderr, "could not read file: %s\n", argv[1]);
        exit(1);
    }

    size_t sourceLen = strlen(source);
    if (sourceLen > MAX_SOURCE_SIZE) {
        fprintf(stderr, "source file too large; limit is %d\n", MAX_SOURCE_SIZE);
        exit(1);
    }

    char *src = source;
    while (*src) {
        if (*src == 'i' && *(src + 1) == 'f' && !isalpha(*(src + 2))) {
            printf("if\n");
            src += 2;
        } else if (*src == 'e' && *(src + 1) == 'l' && *(src + 2) == 's' && *(src + 3) == 'e' && !isalpha(*(src + 4))) {
            printf("else\n");
            src += 4;
        } else if (*src == 'w' && *(src + 1) == 'h' && *(src + 2) == 'i' && *(src + 3) == 'l' && *(src + 4) == 'e' && !isalpha(*(src + 5))) {
            printf("while\n");
            src += 5;
        } else if (*src == 'f' && *(src + 1) == 'o' && *(src + 2) == 'r' && !isalpha(*(src + 3))) {
            printf("for\n");
            src += 3;
        } else if (*src == '+') {
            printf("+\n");
            ++src;
        } else if (*src == '-') {
            printf("-\n");
            ++src;
        } else if (*src == '*') {
            printf("*\n");
            ++src;
        } else if (*src == '/') {
            printf("/\n");
            ++src;
        } else if (*src == '(') {
            printf("(\n");
            ++src;
        } else if (*src == ')') {
            printf(")\n");
            ++src;
        } else if (*src == '{') {
            printf("{\n");
            ++src;
        } else if (*src == '}') {
            printf("}\n");
            ++src;
        } else if (*src == ';') {
            printf(";\n");
            ++src;
        } else if (isdigit(*src)) {
            char *start = src;
            size_t len = 0;
            while (isdigit(*src)) {
                ++src;
                ++len;
            }
            printf("INTLIT %.*s\n", (int) len, start);
        } else if (isspace(*src)) {
            ++src;
        } else {
            printf("ERROR: unrecognized token at %s\n", src);
            exit(1);
        }
    }

    free(source);

    return 0;
}