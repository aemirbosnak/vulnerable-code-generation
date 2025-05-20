//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define INDENT_SIZE 4

void beautify_html(FILE *input, FILE *output);
void write_with_indent(FILE *output, const char *line, int indent_level);
int is_opening_tag(const char *line);
int is_closing_tag(const char *line);
void trim_whitespace(char *str);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.html> <output.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Unable to open input file");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        perror("Unable to open output file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    beautify_html(input_file, output_file);

    fclose(input_file);
    fclose(output_file);
    return EXIT_SUCCESS;
}

void beautify_html(FILE *input, FILE *output) {
    char line[BUFFER_SIZE];
    int indent_level = 0;

    while (fgets(line, sizeof(line), input)) {
        trim_whitespace(line);

        if (is_closing_tag(line)) {
            indent_level--;
        }

        write_with_indent(output, line, indent_level);

        if (is_opening_tag(line)) {
            indent_level++;
        }
    }
}

void write_with_indent(FILE *output, const char *line, int indent_level) {
    for (int i = 0; i < indent_level * INDENT_SIZE; i++) {
        fputc(' ', output);
    }
    fputs(line, output);
}

int is_opening_tag(const char *line) {
    return (strstr(line, "<") != NULL && strstr(line, "/") == NULL && strstr(line, ">") != NULL);
}

int is_closing_tag(const char *line) {
    return (strstr(line, "</") != NULL && strstr(line, ">") != NULL);
}

void trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    // Null terminate the string
    end[1] = '\0';
}