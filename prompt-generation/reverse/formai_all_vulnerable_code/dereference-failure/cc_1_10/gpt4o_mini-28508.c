//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define INDENTATION_SIZE 4

void beautify_html(const char *input_file, const char *output_file);
void add_indentation(char *line, int level);
void write_to_file(FILE *fp, const char *line, int indent_level);
int is_opening_tag(const char *tag);
int is_closing_tag(const char *tag);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return 1;
    }

    beautify_html(argv[1], argv[2]);

    printf("HTML beautification completed! Check the output file: %s\n", argv[2]);
    return 0;
}

void beautify_html(const char *input_file, const char *output_file) {
    FILE *fp_input = fopen(input_file, "r");
    FILE *fp_output = fopen(output_file, "w");
    
    if (fp_input == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
    if (fp_output == NULL) {
        perror("Error opening output file");
        fclose(fp_input);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;

    while (fgets(line, MAX_LINE_LENGTH, fp_input)) {
        char *token = strtok(line, "<");
        while (token != NULL) {
            char *tag = strtok(token, ">");
            if (tag != NULL) {
                // Write the opening tag with indentation
                write_to_file(fp_output, tag, indent_level);

                // Check if it is a closing tag or an opening tag
                if (is_opening_tag(tag) && !strstr(tag, "/")) {
                    indent_level++;
                } else if (is_closing_tag(tag)) {
                    indent_level--;
                }
            }
            token = strtok(NULL, "<");
        }
    }

    fclose(fp_input);
    fclose(fp_output);
}

void add_indentation(char *line, int level) {
    for (int i = 0; i < level * INDENTATION_SIZE; ++i) {
        line[i] = ' ';
    }
}

void write_to_file(FILE *fp, const char *line, int indent_level) {
    char indented_line[MAX_LINE_LENGTH] = {0};

    add_indentation(indented_line, indent_level);
    strcat(indented_line, line);
    strcat(indented_line, "\n");

    fprintf(fp, "%s", indented_line);
}

int is_opening_tag(const char *tag) {
    return tag != NULL && tag[0] != '/';
}

int is_closing_tag(const char *tag) {
    return tag != NULL && tag[0] == '/';
}