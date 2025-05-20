//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_KEYWORDS 20

typedef struct {
    char *name;
    int color;
} Keyword;

void init_keywords() {
    static Keyword keywords[] = {
        {"<!DOCTYPE", 0x000000},
        {"<html>", 0x000080},
        {"<head>", 0x008080},
        {"<meta", 0x0080ff},
        {"<title>", 0x00ff00},
        {"<body>", 0xffff00},
        {"<h1>", 0xffffff},
        {"<p>", 0x00ffff},
        {"<a>", 0xff00ff},
        {"<img>", 0xff8000},
        {"</a>", 0x00ff00},
        {"</h1>", 0xffffff},
        {"</p>", 0x00ffff},
        {"</body>", 0xffff00},
        {"</html>", 0x000080},
        {NULL, 0}
    };
}

int is_keyword(const char *text) {
    int len = strlen(text);
    Keyword *keywords = &keywords[0];
    while (keywords->name!= NULL) {
        if (strncasecmp(text, keywords->name, len) == 0 && len == strlen(keywords->name)) {
            return 1;
        }
        keywords++;
    }
    return 0;
}

void print_html(const char *text) {
    int len = strlen(text);
    Keyword *keywords = &keywords[0];
    while (keywords->name!= NULL) {
        char *pos = strstr(text, keywords->name);
        while (pos!= NULL) {
            printf("\033[38;5;%dm%s\033[0m", keywords->color, pos);
            pos += strlen(keywords->name);
        }
        keywords++;
    }
    printf("\033[0m%s\n", text);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error: Cannot open file '%s'.\n", argv[1]);
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        print_html(line);
    }

    fclose(fp);
    return 0;
}