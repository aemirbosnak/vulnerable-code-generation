//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define INDENT_SIZE 4

typedef struct {
    FILE *input;
    FILE *output;
    char *buffer;
    size_t buffer_length;
    size_t indentation_level;
} HTMLBeautifier;

void initialize_beautifier(HTMLBeautifier *beautifier, const char *input_file, const char *output_file) {
    beautifier->input = fopen(input_file, "r");
    if (!beautifier->input) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    beautifier->output = fopen(output_file, "w");
    if (!beautifier->output) {
        perror("Failed to open output file");
        fclose(beautifier->input);
        exit(EXIT_FAILURE);
    }

    beautifier->buffer = (char *)malloc(BUFFER_SIZE);
    beautifier->buffer_length = BUFFER_SIZE;
    beautifier->indentation_level = 0;
}

void free_beautifier(HTMLBeautifier *beautifier) {
    fclose(beautifier->input);
    fclose(beautifier->output);
    free(beautifier->buffer);
}

void print_indent(HTMLBeautifier *beautifier) {
    for (size_t i = 0; i < beautifier->indentation_level; ++i) {
        fputs(" ", beautifier->output);
    }
}

void beautify_line(HTMLBeautifier *beautifier, const char *line) {
    size_t line_length = strlen(line);
    int in_tag = 0;

    for (size_t i = 0; i < line_length; ++i) {
        if (line[i] == '<') {
            if (i > 0 && line[i - 1] != '\n') {
                fputs("\n", beautifier->output);
            }
            print_indent(beautifier);
            in_tag = 1;
            fputc(line[i], beautifier->output);
        } else if (line[i] == '>') {
            fputc(line[i], beautifier->output);
            in_tag = 0;
            if (line[i + 1] == '\0' || line[i + 1] == '\n') {
                fputc('\n', beautifier->output);
            }
        } else {
            fputc(line[i], beautifier->output);
        }

        if (in_tag && line[i] == '/') {
            --beautifier->indentation_level;
        } else if (in_tag && line[i] == '<' && line[i + 1] != '/') {
            ++beautifier->indentation_level;
        }
    }
}

void beautify_html(HTMLBeautifier *beautifier) {
    while (fgets(beautifier->buffer, beautifier->buffer_length, beautifier->input)) {
        beautify_line(beautifier, beautifier->buffer);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.html> <output.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    HTMLBeautifier beautifier;
    initialize_beautifier(&beautifier, argv[1], argv[2]);
    beautify_html(&beautifier);
    free_beautifier(&beautifier);

    printf("HTML beautification completed. See %s for output.\n", argv[2]);
    return EXIT_SUCCESS;
}