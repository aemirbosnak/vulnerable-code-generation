//FormAI DATASET v1.0 Category: HTML beautifier ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void output_char(FILE *out_stream, char c) {
    fputc(c, out_stream);
}

void output_spaces(FILE *out_stream, int num_spaces) {
    int i;
    for (i = 0; i < num_spaces; i++) {
        fputc(' ', out_stream);
    }
}

void beautify_html(FILE *in_stream, FILE *out_stream, int depth) {
    int c, last = '\n';
    int num_spaces = depth * 4;

    while ((c = fgetc(in_stream)) != EOF) {
        if (last == '\n') {
            output_spaces(out_stream, num_spaces);
        }

        if (c == '<') {
            output_char(out_stream, c);
            c = fgetc(in_stream);
            if (c == '!') { // Comment
                output_char(out_stream, c);
                while (c != EOF) {
                    c = fgetc(in_stream);
                    output_char(out_stream, c);
                    if (c == '-' && last == '-') {
                        break;
                    }
                    last = c;
                }
            } else {
                while (c != EOF) {
                    output_char(out_stream, c);
                    if (c == '>') {
                        break;
                    }
                    c = fgetc(in_stream);
                }
            }
            if (c == '>') {
                output_char(out_stream, c);
                last = c;
            }
        } else {
            if (!isspace(c)) {
                output_char(out_stream, c);
            } else if (last != ' ') {
                output_char(out_stream, ' ');
            }
            last = c;
        }
    }
}

int main() {
    FILE *in_stream, *out_stream;
    in_stream = fopen("input_file.html", "r");
    out_stream = fopen("output_file.html", "w");
    if (in_stream == NULL || out_stream == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }
    beautify_html(in_stream, out_stream, 0);
    fclose(in_stream);
    fclose(out_stream);
    return 0;
}