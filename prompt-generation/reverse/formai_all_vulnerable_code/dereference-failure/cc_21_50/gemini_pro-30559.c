//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_OUT_LEN 4096

int main(int argc, char **argv) {
    char *line = NULL;
    size_t line_len = 0;
    ssize_t read;
    char *out = NULL;
    size_t out_len = 0;
    int indent_level = 0;
    int in_tag = 0;
    int in_attr = 0;
    int in_comment = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    while ((read = getline(&line, &line_len, fp)) != -1) {
        char *p = line;
        while (*p != '\0') {
            if (in_comment) {
                if (*p == '*' && *(p + 1) == '/') {
                    in_comment = 0;
                    p += 2;
                } else {
                    p++;
                }
            } else if (in_attr) {
                if (*p == '"' || *p == '\'') {
                    in_attr = 0;
                    p++;
                } else {
                    p++;
                }
            } else if (in_tag) {
                if (*p == '>') {
                    in_tag = 0;
                    p++;
                } else if (*p == '/') {
                    if (*(p + 1) == '>') {
                        in_tag = 0;
                        indent_level--;
                        p += 2;
                    } else {
                        p++;
                    }
                } else {
                    p++;
                }
            } else {
                if (*p == '<') {
                    if (*(p + 1) == '!') {
                        in_comment = 1;
                        p += 2;
                    } else if (*(p + 1) == '/') {
                        in_tag = 1;
                        indent_level--;
                        p += 2;
                    } else {
                        in_tag = 1;
                        indent_level++;
                        p++;
                    }
                } else if (*p == '&') {
                    p++;
                } else if (*p == '"') {
                    in_attr = 1;
                    p++;
                } else if (*p == '\'') {
                    in_attr = 1;
                    p++;
                } else {
                    p++;
                }
            }
        }

        if (out_len + read + indent_level * 2 + 1 > MAX_OUT_LEN) {
            out = realloc(out, out_len + read + indent_level * 2 + 1);
            if (out == NULL) {
                perror("realloc");
                return EXIT_FAILURE;
            }
        }

        for (int i = 0; i < indent_level; i++) {
            out[out_len++] = ' ';
            out[out_len++] = ' ';
        }

        memcpy(out + out_len, line, read);
        out_len += read;

        out[out_len++] = '\n';
    }

    free(line);
    fclose(fp);

    printf("%s", out);
    free(out);

    return EXIT_SUCCESS;
}