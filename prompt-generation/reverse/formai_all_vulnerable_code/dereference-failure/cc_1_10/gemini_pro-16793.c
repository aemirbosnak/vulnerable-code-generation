//GEMINI-pro DATASET v1.0 Category: HTML beautifier ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int indent;
    int in_tag;
} state_t;

void print_html(char *html, state_t *state) {
    char *p = html;
    while (*p) {
        if (*p == '<') {
            state->in_tag = 1;
            printf("%*s%s", state->indent, "", p);
            state->indent += 2;
        } else if (*p == '>') {
            state->in_tag = 0;
            printf("%s", p);
            state->indent -= 2;
        } else if (*p == '\n') {
            if (!state->in_tag) {
                printf("%*s\n", state->indent, "");
            } else {
                printf("%s", p);
            }
        } else {
            printf("%s", p);
        }
        p++;
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <html_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    char *html = malloc(size + 1);
    if (!html) {
        perror("malloc");
        return 1;
    }

    fread(html, 1, size, fp);
    html[size] = '\0';

    state_t state = {0, 0};
    print_html(html, &state);

    free(html);
    fclose(fp);

    return 0;
}