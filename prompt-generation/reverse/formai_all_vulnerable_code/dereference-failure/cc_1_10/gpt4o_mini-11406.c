//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024
#define INDENT_SIZE 2

void beautify_html(const char *input_file, const char *output_file);
void indent_line(FILE *fp, int indent_level);
bool is_tag(const char *line);
bool is_closing_tag(const char *line);
void process_line(const char *line, FILE *fp, int *indent_level);
void write_indent(FILE *fp, int level);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input.html> <output.html>\n", argv[0]);
        return 1;
    }

    beautify_html(argv[1], argv[2]);
    return 0;
}

void beautify_html(const char *input_file, const char *output_file) {
    FILE *fp_in = fopen(input_file, "r");
    FILE *fp_out = fopen(output_file, "w");
    if (!fp_in || !fp_out) {
        perror("Failed to open files");
        exit(EXIT_FAILURE);
    }

    char line[BUFFER_SIZE];
    int indent_level = 0;

    while (fgets(line, sizeof(line), fp_in)) {
        process_line(line, fp_out, &indent_level);
    }

    fclose(fp_in);
    fclose(fp_out);
}

void process_line(const char *line, FILE *fp, int *indent_level) {
    char trimmed_line[BUFFER_SIZE];
    sscanf(line, "%s", trimmed_line);

    if (is_closing_tag(trimmed_line)) {
        (*indent_level)--;
    }

    write_indent(fp, *indent_level);
    fprintf(fp, "%s", line);

    if (is_tag(trimmed_line) && !is_closing_tag(trimmed_line)) {
        *indent_level += ((line[strlen(line) - 2] == '/') ? 0 : 1);
    }
}

void write_indent(FILE *fp, int level) {
    for (int i = 0; i < level * INDENT_SIZE; i++) {
        fprintf(fp, " ");
    }
}

bool is_tag(const char *line) {
    return (line[0] == '<' && line[strlen(line) - 2] == '>') || (line[0] == '<' && line[1] == '/');
}

bool is_closing_tag(const char *line) {
    return (line[0] == '<' && line[1] == '/');
}