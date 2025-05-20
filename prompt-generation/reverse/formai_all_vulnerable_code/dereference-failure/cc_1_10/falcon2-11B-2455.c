//Falcon2-11B DATASET v1.0 Category: HTML beautifier ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 80

int main(int argc, char *argv[]) {
    char input[MAX_LINE_LENGTH + 1];
    char output[MAX_LINE_LENGTH + 1];
    FILE *input_file, *output_file;
    char *line = NULL;
    int ch;
    int num_lines = 0;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        exit(1);
    }

    input_file = fopen(argv[1], "r");
    if (!input_file) {
        fprintf(stderr, "Could not open input file: %s\n", argv[1]);
        exit(1);
    }

    output_file = fopen("output.html", "w");
    if (!output_file) {
        fprintf(stderr, "Could not create output file\n");
        exit(1);
    }

    while ((ch = getc(input_file))!= EOF) {
        if (ch == '\n') {
            fputc(ch, output_file);
            num_lines++;
        } else if (ch == '\r') {
            fputc(ch, output_file);
        } else if (isprint(ch)) {
            fputc(ch, output_file);
        } else {
            ungetc(ch, input_file);
            line = NULL;
        }
    }

    fclose(input_file);
    fclose(output_file);

    if (line) {
        fputs(line, output_file);
        fputc('\n', output_file);
    }

    return 0;
}