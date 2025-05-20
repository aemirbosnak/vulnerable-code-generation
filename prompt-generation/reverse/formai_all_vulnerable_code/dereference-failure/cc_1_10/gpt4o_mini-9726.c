//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 2048
#define INDENT_SIZE 4

void indent(FILE *out, int levels) {
    for (int i = 0; i < levels * INDENT_SIZE; i++)
        fputc(' ', out);
}

void beautify_line(FILE *in, FILE *out, char *line, int *indent_level) {
    char *ptr = line;
    while (*ptr != '\0') {
        // Check for opening brace
        if (*ptr == '{') {
            indent(out, *indent_level);
            fputc('{', out);
            fputc('\n', out);
            (*indent_level)++;
            indent(out, *indent_level);
            break;
        }
        // Check for closing brace
        else if (*ptr == '}') {
            (*indent_level)--;
            indent(out, *indent_level);
            fputc('}', out);
            fputc('\n', out);
            break;
        }
        // Print text as is
        else {
            fputc(*ptr, out);
        }
        ptr++;
    }
}

void beautify_html(const char *input_file, const char *output_file) {
    FILE *in = fopen(input_file, "r");
    FILE *out = fopen(output_file, "w");
    
    if (!in || !out) {
        fprintf(stderr, "Error opening files!\n");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;

    while (fgets(line, sizeof(line), in)) {
        beautify_line(in, out, line, &indent_level);
    }

    fclose(in);
    fclose(out);
}

void usage() {
    printf("Usage: beautifier <input_file> <output_file>\n");
    printf("Beautifies HTML code from the input file and writes to output file.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        usage();
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);

    printf("File beautification done. Check %s for the output.\n", argv[2]);
    return EXIT_SUCCESS;
}