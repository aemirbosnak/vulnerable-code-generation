//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INDENT "    "

void beautify_html(char *input, char *output) {
    int level = 0;
    char *token, *prev_token = NULL;
    char *end_tag = NULL;

    FILE *in = fopen(input, "r");
    FILE *out = fopen(output, "w");

    if (in == NULL) {
        printf("Error: Cannot open file %s\n", input);
        exit(1);
    }

    if (out == NULL) {
        printf("Error: Cannot create file %s\n", output);
        exit(1);
    }

    while ((token = strtok(NULL, "<>")) != NULL) {
        if (prev_token != NULL && prev_token[0] == '<' && prev_token[1] == '/') {
            level--;
        }

        if (prev_token != NULL && prev_token[0] == '<' && prev_token[1] != '/') {
            if (end_tag != NULL && strcmp(prev_token, end_tag) == 0) {
                level--;
                end_tag = NULL;
            }
            fprintf(out, "\n");
            for (int i = 0; i < level; i++) {
                fprintf(out, INDENT);
            }
            level++;
        }

        if (token[0] == '/') {
            level--;
            end_tag = token;
        }

        fprintf(out, "%s<%s>", (prev_token != NULL && prev_token[0] == '>') ? "\n" : "", token);
        prev_token = token;
    }

    fclose(in);
    fclose(out);
}

int main() {
    char input[] = "example.html";
    char output[] = "beautified.html";
    beautify_html(input, output);
    return 0;
}