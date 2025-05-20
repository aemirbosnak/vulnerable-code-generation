//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENTS 100

void trim_whitespace(char *line) {
    char *end;

    // Trim leading whitespace
    while (isspace((unsigned char)*line)) line++;

    // Trim trailing whitespace
    end = line + strlen(line) - 1;
    while (end > line && isspace((unsigned char)*end)) end--;
    end[1] = '\0';
}

bool is_opening_tag(const char *line) {
    return line[0] == '<' && line[1] != '/' && line[strlen(line) - 1] != '/';
}

bool is_closing_tag(const char *line) {
    return line[0] == '<' && line[1] == '/';
}

void beautify_html(FILE *input, FILE *output) {
    char line[MAX_LINE_LENGTH];
    int indent_level = 0;

    while (fgets(line, sizeof(line), input)) {
        trim_whitespace(line);
        
        if (is_closing_tag(line)) {
            indent_level--;
        }

        // Add indents
        for (int i = 0; i < indent_level; i++) {
            fprintf(output, "    "); // 4 spaces for indentation
        }

        fprintf(output, "%s\n", line);

        if (is_opening_tag(line)) {
            indent_level++;
        }
    }
}

void display_usage() {
    fprintf(stderr, "Usage: html_beautifier <input_file> <output_file>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage();
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (!output_file) {
        perror("Error opening output file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    beautify_html(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("HTML beautification completed successfully!\n");
    return EXIT_SUCCESS;
}