//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4
#define BUFFER_SIZE 4096

void indent_line(char *line, int indent_level, char *output) {
    for (int i = 0; i < indent_level * INDENT_SIZE; i++) {
        output[i] = ' ';
    }
    strcpy(&output[indent_level * INDENT_SIZE], line);
}

int is_opening_tag(const char *line) {
    return (strstr(line, "<html") || strstr(line, "<body") || 
            strstr(line, "<div") || strstr(line, "<p") || 
            strstr(line, "<h1") || strstr(line, "<h2") || 
            strstr(line, "<h3") || strstr(line, "<ul") || 
            strstr(line, "<ol"));
}

int is_closing_tag(const char *line) {
    return (strstr(line, "</html>") || strstr(line, "</body>") || 
            strstr(line, "</div>") || strstr(line, "</p>") || 
            strstr(line, "</h1>") || strstr(line, "</h2>") || 
            strstr(line, "</h3>") || strstr(line, "</ul>") || 
            strstr(line, "</ol>"));
}

void trim_whitespace(char *line) {
    char *end;

    while (isspace((unsigned char)*line)) line++;

    if (*line == 0) return;

    end = line + strlen(line) - 1;
    while (end > line && isspace((unsigned char)*end)) end--;

    end[1] = '\0';
}

void beautify_html(FILE *input_file, FILE *output_file) {
    char line[MAX_LINE_LENGTH];
    char formatted_line[MAX_LINE_LENGTH];
    int indent_level = 0;

    while (fgets(line, sizeof(line), input_file)) {
        char *trim_line_ptr = strdup(line);
        trim_whitespace(trim_line_ptr);

        if (is_closing_tag(trim_line_ptr)) {
            indent_level--;
        }

        indent_line(trim_line_ptr, indent_level, formatted_line);
        fprintf(output_file, "%s\n", formatted_line);

        if (is_opening_tag(trim_line_ptr)) {
            indent_level++;
        }

        free(trim_line_ptr);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.html> <output.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (!output_file) {
        fclose(input_file);
        fprintf(stderr, "Error opening output file: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    beautify_html(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("HTML beautification complete! Check the output in %s.\n", argv[2]);
    return EXIT_SUCCESS;
}