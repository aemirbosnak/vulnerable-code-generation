//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 4096
#define MAX_LINE_LENGTH 256
#define INDENT_STEP 4

// Struct to store the current state of the beautifier
typedef struct {
    int indent_level;
    char current_line[MAX_LINE_LENGTH];
} Beautifier;

// Function prototypes
void beautify_html(const char *input_file, const char *output_file);
void process_line(Beautifier *b, const char *line, FILE *output);
void print_indent(FILE *output, int level);

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./html_beautifier <input_file.html> <output_file.html>\n");
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);

    return EXIT_SUCCESS;
}

// A function to read a file and beautify its HTML content
void beautify_html(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "r");
    if (!input) {
        perror("Could not open input file");
        exit(EXIT_FAILURE);
    }

    FILE *output = fopen(output_file, "w");
    if (!output) {
        fclose(input);
        perror("Could not open output file");
        exit(EXIT_FAILURE);
    }

    Beautifier beautifier = {0, ""};

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, input)) {
        process_line(&beautifier, line, output);
    }

    fclose(input);
    fclose(output);
}

// A function to process each line of HTML
void process_line(Beautifier *b, const char *line, FILE *output) {
    char *trimmed_line;
    trimmed_line = strdup(line);
    // Trim leading and trailing whitespaces
    char *start = trimmed_line;
    while (isspace(*start)) start++;
    char *end = trimmed_line + strlen(trimmed_line) - 1;
    while (end > start && isspace(*end)) end--;
    *(end + 1) = '\0';

    // Manage indent levels based on the detected tags
    if (strstr(trimmed_line, "<!--") == trimmed_line) {
        // Comment block
        print_indent(output, b->indent_level);
        fprintf(output, "%s\n", trimmed_line);
        free(trimmed_line);
        return;
    }

    // Check for opening and closing tags
    char *current_tag = NULL;
    if ((current_tag = strstr(trimmed_line, "<")) != NULL) {
        if (*(current_tag + 1) != '/') { // Opening tag
            print_indent(output, b->indent_level);
            fprintf(output, "%s\n", trimmed_line);
            b->indent_level++;
        } else { // Closing tag
            b->indent_level--;
            print_indent(output, b->indent_level);
            fprintf(output, "%s\n", trimmed_line);
        }
    } else {
        // Empty line or text line
        print_indent(output, b->indent_level);
        fprintf(output, "%s\n", trimmed_line);
    }

    free(trimmed_line);
}

// A function to print indentation based on the current level
void print_indent(FILE *output, int level) {
    for (int i = 0; i < level * INDENT_STEP; i++) {
        fputc(' ', output);
    }
}