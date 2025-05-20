//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int indent_level;
    int indent_width;
    bool keep_newlines;
    bool keep_indentation;
} config_t;

static void print_indent(config_t *config) {
    for (int i = 0; i < config->indent_level * config->indent_width; i++) {
        putchar(' ');
    }
}

static void beautify_html(const char *input, config_t *config) {
    char *output = malloc(strlen(input) + 1);
    char *p = output;

    int state = 0;  // 0: outside tag, 1: inside tag
    int tag_indent_level = 0;

    for (const char *c = input; *c != '\0'; c++) {
        switch (state) {
            case 0:  // outside tag
                if (*c == '<') {
                    state = 1;
                    tag_indent_level = config->indent_level;
                    if (config->keep_newlines) {
                        putchar('\n');
                    }
                    print_indent(config);
                    *p++ = *c;
                } else {
                    *p++ = *c;
                }
                break;

            case 1:  // inside tag
                if (*c == '>') {
                    state = 0;
                    *p++ = *c;
                } else if (*c == '\n') {
                    if (config->keep_newlines) {
                        putchar('\n');
                    }
                    print_indent(config);
                } else if (*c == '/' && *(c + 1) == '>') {
                    config->indent_level--;
                    state = 0;
                    *p++ = *c;
                    *p++ = *(++c);
                } else {
                    *p++ = *c;
                }
                break;
        }
    }

    *p = '\0';
    printf("%s", output);

    free(output);
}

int main(int argc, char **argv) {
    config_t config = {
        .indent_level = 0,
        .indent_width = 2,
        .keep_newlines = true,
        .keep_indentation = true,
    };

    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-i") == 0) {
                config.indent_width = atoi(argv[++i]);
            } else if (strcmp(argv[i], "-n") == 0) {
                config.keep_newlines = false;
            } else if (strcmp(argv[i], "-d") == 0) {
                config.keep_indentation = false;
            }
        }
    }

    char buffer[BUFSIZ];
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        beautify_html(buffer, &config);
    }

    return 0;
}