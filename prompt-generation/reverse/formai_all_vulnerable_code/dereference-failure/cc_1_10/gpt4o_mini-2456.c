//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4

void beautify_html_line(char *line, FILE *output_file) {
    int indent_level = 0;
    int in_tag = 0;
    char *token;
    char formatted_line[MAX_LINE_LENGTH];

    // Initialize formatted line
    formatted_line[0] = '\0';

    // Tokenize the line by spaces
    token = strtok(line, " ");
    while (token != NULL) {
        if (token[0] == '<') {
            if (token[1] != '/') {
                // Opening tag
                indent_level++;
            } else {
                // Closing tag
                indent_level--;
            }
            in_tag = 1;
        } else if (in_tag && token[strlen(token) - 1] == '>') {
            in_tag = 0;
        }

        // Append indentation
        for (int i = 0; i < indent_level * INDENT_SIZE; i++) {
            strncat(formatted_line, " ", 1);
        }
        strncat(formatted_line, token, strlen(token));
        strncat(formatted_line, " ", 1);

        // Get next token
        token = strtok(NULL, " ");
    }

    // Remove trailing space
    if (strlen(formatted_line) > 0) {
        formatted_line[strlen(formatted_line) - 1] = '\0';
    }

    // Write formatted line to output file
    fprintf(output_file, "%s\n", formatted_line);
}

void beautify_html_file(const char *input_file_name, const char *output_file_name) {
    FILE *input_file = fopen(input_file_name, "r");
    FILE *output_file = fopen(output_file_name, "w");
    char line[MAX_LINE_LENGTH];

    if (!input_file || !output_file) {
        fprintf(stderr, "Error opening files.\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), input_file) != NULL) {
        beautify_html_line(line, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.html> <output.html>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *input_file_name = argv[1];
    const char *output_file_name = argv[2];

    beautify_html_file(input_file_name, output_file_name);

    printf("HTML beautification completed. Output written to %s\n", output_file_name);
    return 0;
}