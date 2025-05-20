//FormAI DATASET v1.0 Category: HTML beautifier ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4
#define TAB_CHAR '\t'
#define NEWLINE_CHAR '\n'

void print_indent(int indent_level, char indent_char) {
    int indent = indent_level * INDENT_SIZE;
    for (int i = 0; i < indent; i++) {
        putchar(indent_char);
    }
}

void beautify(char* html_str, int indent_level, char indent_char) {
    int str_len = strlen(html_str);
    int i = 0;
    bool is_newline = false;

    while (i < str_len) {
        int j = i;
        while (j < str_len && html_str[j] != '\n') {
            j++;
        }

        int line_len = j - i;
        if (line_len == 0) {
            putchar('\n');
            i++;
            is_newline = true;
            continue;
        }

        char* line = calloc(line_len + 1, sizeof(char));
        strncpy(line, &html_str[i], line_len);
        line[line_len] = '\0';

        bool is_newtag = false;
        bool is_closetag = false;

        if (line[0] == '<') {
            if (line[1] != '/') {
                is_newtag = true;
            } else {
                is_closetag = true;
                indent_level--;
            }
        }

        if (is_newline && !is_newtag && !is_closetag) {
            print_indent(indent_level, indent_char);
        }

        printf("%s", line);
        i += line_len;
        is_newline = false;

        if (is_newtag && line[line_len - 2] != '/') {
            putchar(NEWLINE_CHAR);
            indent_level++;
            is_newline = true;
        }

        putchar('\n');
        free(line);
        i++;
    }
}

int main() {
    char html_str[MAX_LINE_LENGTH];
    fgets(html_str, MAX_LINE_LENGTH, stdin);

    int indent_level = 0;
    printf("Indentation level: %d\n", indent_level);

    printf("\nOriginal HTML:\n");
    printf(html_str);

    printf("\nBeautified HTML:\n");
    beautify(html_str, indent_level, TAB_CHAR);

    return 0;
}