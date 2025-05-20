//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char *ptr;
    int len;
} buffer;

void initBuffer(buffer *buf) {
    buf->ptr = malloc(MAX_LINE_LENGTH);
    buf->len = 0;
}

void freeBuffer(buffer *buf) {
    free(buf->ptr);
}

void appendChar(buffer *buf, char c) {
    if (buf->len >= MAX_LINE_LENGTH) {
        buf->ptr = realloc(buf->ptr, buf->len + MAX_LINE_LENGTH);
    }
    buf->ptr[buf->len++] = c;
}

int isWhitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

int isPunctuation(char c) {
    return c == ',' || c == '.' || c == ';' || c == ':' || c == '!' || c == '?' || c == '"';
}

int isNewline(char c) {
    return c == '\n' || c == '\r';
}

int isTag(char *str) {
    return str[0] == '<' && str[1] != '/';
}

int isClosingTag(char *str) {
    return str[0] == '<' && str[1] == '/';
}

int isSelfClosingTag(char *str) {
    return str[0] == '<' && str[1] != '/' && str[strlen(str) - 1] == '/';
}

void beautify(buffer *buf) {
    int indentLevel = 0;
    for (int i = 0; i < buf->len; i++) {
        char c = buf->ptr[i];
        if (isWhitespace(c)) {
            if (!isNewline(c)) {
                appendChar(buf, c);
            }
        } else if (isPunctuation(c)) {
            appendChar(buf, c);
            if (!isNewline(buf->ptr[i + 1])) {
                appendChar(buf, ' ');
            }
        } else if (isNewline(c)) {
            appendChar(buf, '\n');
            for (int j = 0; j < indentLevel; j++) {
                appendChar(buf, ' ');
            }
        } else if (isTag(buf->ptr + i)) {
            int len = strcspn(buf->ptr + i, ">");
            if (isClosingTag(buf->ptr + i)) {
                indentLevel--;
            }
            for (int j = 0; j < len; j++) {
                appendChar(buf, buf->ptr[i + j]);
            }
            if (!isSelfClosingTag(buf->ptr + i)) {
                indentLevel++;
            }
            i += len - 1;
        } else {
            appendChar(buf, c);
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", argv[1]);
        return 1;
    }

    buffer buf;
    initBuffer(&buf);

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        for (int i = 0; i < strlen(line); i++) {
            appendChar(&buf, line[i]);
        }
    }

    fclose(fp);

    beautify(&buf);

    printf("%s", buf.ptr);

    freeBuffer(&buf);

    return 0;
}