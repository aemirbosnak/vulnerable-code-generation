//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT_LEVEL 100

// Function prototypes
void beautify_html(const char *input, const char *output);
void process_tag(const char *line, FILE *out_file, int *indent_level);
bool is_opening_tag(const char *tag);
bool is_closing_tag(const char *tag);
void trim_whitespace(char *str);
void add_indent_to_file(FILE *file, int indent_level);

int main(int argc, char *argv[]) {
    // Artistic inspiration at the start of the program
    printf("~~~~~~~~~~~ HTML Beautifier ~~~~~~~~~~~\n");
    printf("        By Your Creative Name\n");
    printf("***************************************\n");

    // Check for the right number of arguments
    if (argc != 3) {
        printf("Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Beautify the HTML file
    beautify_html(argv[1], argv[2]);

    printf("Beautification complete! Check your output file.\n");
    return EXIT_SUCCESS;
}

void beautify_html(const char *input, const char *output) {
    FILE *in_file = fopen(input, "r");
    FILE *out_file = fopen(output, "w");
    
    if (!in_file || !out_file) {
        perror("File open error");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;

    while (fgets(line, sizeof(line), in_file)) {
        trim_whitespace(line);
        process_tag(line, out_file, &indent_level);
    }

    fclose(in_file);
    fclose(out_file);
}

void process_tag(const char *line, FILE *out_file, int *indent_level) {
    char tag[MAX_LINE_LENGTH];
    sscanf(line, "%s", tag);

    if (is_opening_tag(tag)) {
        add_indent_to_file(out_file, *indent_level);
        fprintf(out_file, "%s\n", line);
        (*indent_level)++;
    } else if (is_closing_tag(tag)) {
        (*indent_level)--;
        add_indent_to_file(out_file, *indent_level);
        fprintf(out_file, "%s\n", line);
    } else {
        add_indent_to_file(out_file, *indent_level);
        fprintf(out_file, "%s\n", line);
    }
}

bool is_opening_tag(const char *tag) {
    return tag[0] == '<' && tag[1] != '/' && tag[strlen(tag) - 1] == '>';
}

bool is_closing_tag(const char *tag) {
    return tag[0] == '<' && tag[1] == '/' && tag[strlen(tag) - 1] == '>';
}

void trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    end[1] = '\0'; // Null terminate after last non-space character
}

void add_indent_to_file(FILE *file, int indent_level) {
    for (int i = 0; i < indent_level; i++) {
        fprintf(file, "    "); // Four spaces for indentation
    }
}