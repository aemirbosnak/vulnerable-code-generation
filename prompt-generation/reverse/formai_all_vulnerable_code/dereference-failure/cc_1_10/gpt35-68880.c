//FormAI DATASET v1.0 Category: HTML beautifier ; Style: active
#include <stdio.h>
#include <stdlib.h>

void indent(FILE *input_file, FILE *output_file, int num_tabs);
void beautify(char *in_file, char *out_file);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: ./beautify input_file output_file\n");
        return 1;
    } else {
        beautify(argv[1], argv[2]);
        return 0;
    }
}

void indent(FILE *input_file, FILE *output_file, int num_tabs) {
    char c;
    int i;

    while ((c = fgetc(input_file)) != EOF) {
        if (c == '\n') {
            fputc(c, output_file);
            for (i = 0; i < num_tabs; i++)
                fputc('\t', output_file);
        } else {
            fputc(c, output_file);
        }
    }
}

void beautify(char *in_file, char *out_file) {
    FILE *input_file, *output_file;
    int curly_braces = 0, paren_count = 0, i = 0, num_tabs = 0;
    char c;

    input_file = fopen(in_file, "r");
    output_file = fopen(out_file, "w");

    if (input_file == NULL) {
        printf("Error opening input file\n");
        exit(1);
    }
    if (output_file == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }

    while ((c = fgetc(input_file)) != EOF) {
        if (c == '{') {
            curly_braces++;
            fputc('{', output_file);
            if (curly_braces == 1) {
                fputc('\n', output_file);
                num_tabs++;
                indent(input_file, output_file, num_tabs);
            }
        } else if (c == '}') {
            curly_braces--;
            if (curly_braces == 0) {
                fputc('\n', output_file);
                num_tabs--;
                indent(input_file, output_file, num_tabs);
            }
            fputc('}', output_file);
        } else if (c == '(') {
            paren_count++;
            fputc('(', output_file);
        } else if (c == ')') {
            paren_count--;
            fputc(')', output_file);
        } else {
            fputc(c, output_file);
        }
    }

    fclose(input_file);
    fclose(output_file);
}