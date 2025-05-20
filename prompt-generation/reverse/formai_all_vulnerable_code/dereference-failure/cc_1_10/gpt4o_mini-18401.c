//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT 20

void beautify_html(const char *input_file, const char *output_file);
void process_line(char *line, FILE *output_fp, int *indent_level);
void increase_indent(int *indent_level);
void decrease_indent(int *indent_level);
void print_indent(FILE *output_fp, int indent_level);
int is_opening_tag(const char *tag);
int is_closing_tag(const char *tag);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);
    return EXIT_SUCCESS;
}

void beautify_html(const char *input_file, const char *output_file) {
    FILE *input_fp = fopen(input_file, "r");
    FILE *output_fp = fopen(output_file, "w");
    if (input_fp == NULL || output_fp == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;

    while (fgets(line, sizeof(line), input_fp)) {
        process_line(line, output_fp, &indent_level);
    }

    fclose(input_fp);
    fclose(output_fp);
}

void process_line(char *line, FILE *output_fp, int *indent_level) {
    char *token;
    char *last_token = NULL;
    char *line_copy = strdup(line);
    int is_empty = 1;
    
    // Strip white spaces to check if line is empty
    for (char *ptr = line_copy; *ptr; ptr++) {
        if (!isspace(*ptr)) {
            is_empty = 0;
            break;
        }
    }

    if (is_empty) {
        free(line_copy);
        return;
    }

    // Check for opening and closing tags
    token = strtok(line_copy, " ");
    while (token != NULL) {
        if (is_opening_tag(token)) {
            print_indent(output_fp, *indent_level);
            fprintf(output_fp, "%s ", token);
            increase_indent(indent_level);
        } else if (is_closing_tag(token)) {
            decrease_indent(indent_level);
            print_indent(output_fp, *indent_level);
            fprintf(output_fp, "%s ", token);
        } else {
            print_indent(output_fp, *indent_level);
            fprintf(output_fp, "%s ", token);
        }

        last_token = token;
        token = strtok(NULL, " ");
    }

    if (last_token && is_opening_tag(last_token)) {
        decrease_indent(indent_level);
    }

    fprintf(output_fp, "\n");
    free(line_copy);
}

void increase_indent(int *indent_level) {
    if (*indent_level < MAX_INDENT) {
        (*indent_level)++;
    }
}

void decrease_indent(int *indent_level) {
    if (*indent_level > 0) {
        (*indent_level)--;
    }
}

void print_indent(FILE *output_fp, int indent_level) {
    for (int i = 0; i < indent_level; i++) {
        fprintf(output_fp, "    "); // 4 spaces for indentation
    }
}

int is_opening_tag(const char *tag) {
    return tag[0] == '<' && tag[1] != '/' && tag[strlen(tag)-1] == '>';
}

int is_closing_tag(const char *tag) {
    return tag[0] == '<' && tag[1] == '/' && tag[strlen(tag)-1] == '>';
}