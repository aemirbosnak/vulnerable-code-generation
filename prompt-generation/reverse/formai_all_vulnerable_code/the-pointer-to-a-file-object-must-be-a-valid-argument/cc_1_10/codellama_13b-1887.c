//Code Llama-13B DATASET v1.0 Category: HTML beautifier ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

void print_usage(char *program_name) {
    printf("Usage: %s [FILE]\n", program_name);
    printf("Beautify the given HTML file.\n");
}

void beautify_html(char *input_file, char *output_file) {
    FILE *in_file = fopen(input_file, "r");
    FILE *out_file = fopen(output_file, "w");

    char line[MAX_LINE_LENGTH];
    char *p, *q;
    int line_number = 1;

    while (fgets(line, MAX_LINE_LENGTH, in_file)) {
        p = line;
        q = line;

        while (*p) {
            if (*p == '<') {
                *q++ = '\n';
                *q++ = ' ';
                *q++ = '<';
                *q++ = ' ';
            } else if (*p == '>') {
                *q++ = ' ';
                *q++ = '>';
                *q++ = '\n';
            } else if (*p == '\n') {
                *q++ = '\n';
                *q++ = ' ';
            } else {
                *q++ = *p;
            }
            p++;
        }

        fprintf(out_file, "%s", line);

        line_number++;
    }

    fclose(in_file);
    fclose(out_file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return 1;
    }

    beautify_html(argv[1], "output.html");

    return 0;
}