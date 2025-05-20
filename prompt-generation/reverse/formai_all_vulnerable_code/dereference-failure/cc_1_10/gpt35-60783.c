//FormAI DATASET v1.0 Category: HTML beautifier ; Style: modular
#include <stdio.h>
#include <stdlib.h>

void remove_comment(char in_file[], char out_file[]);
void indent_html(char in_file[], char out_file[]);

int main() {
    char in_file[] = "input.html";
    char intermediate_file[] = "intermediate.html";
    char out_file[] = "output.html";

    printf("Removing comments from HTML file...\n");
    remove_comment(in_file, intermediate_file);

    printf("Indenting HTML code...\n");
    indent_html(intermediate_file, out_file);

    printf("HTML beautifier program completed successfully.\n");

    return 0;
}

// function to remove comments from HTML code
void remove_comment(char in_file[], char out_file[]) {
    FILE *in_fp, *out_fp;
    in_fp = fopen(in_file, "r");
    out_fp = fopen(out_file, "w");

    if (in_fp == NULL || out_fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int c;
    char prev_char = '\0';
    while ((c = fgetc(in_fp)) != EOF) {
        if (c == '>' && prev_char == '-') {
            fprintf(out_fp, "");
        } else if (prev_char != '-') {
            fputc(c, out_fp);
        }

        prev_char = c;
    }

    fclose(in_fp);
    fclose(out_fp);
}

// function to indent HTML code
void indent_html(char in_file[], char out_file[]) {
    FILE *in_fp, *out_fp;
    in_fp = fopen(in_file, "r");
    out_fp = fopen(out_file, "w");

    if (in_fp == NULL || out_fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    int indent_level = 0;
    int c;
    while ((c = fgetc(in_fp)) != EOF) {
        if (c == '<') {
            fputc(c, out_fp);

            char next_char = fgetc(in_fp);
            if (next_char == '/') {
                indent_level--;
            }

            fputc('\n', out_fp);
            for (int i = 0; i < indent_level; i++) {
                fprintf(out_fp, "  ");
            }

            fputc(next_char, out_fp);
            if (next_char != '/') {
                indent_level++;
            }
        } else if (c == '>') {
            fputc(c, out_fp);
            fputc('\n', out_fp);
        } else {
            fputc(c, out_fp);
        }
    }

    fclose(in_fp);
    fclose(out_fp);
}