//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define INDENT_SIZE 4

void beautify_html(const char *input_file, const char *output_file);
void indent(FILE *output, int level);
int is_opening_tag(const char *tag);
int is_closing_tag(const char *tag);

int main() {
    const char *input_file = "input.html";  // Input HTML file
    const char *output_file = "output.html"; // Output beautified HTML file

    beautify_html(input_file, output_file);
    printf("Beautification complete! Check '%s' for the results.\n", output_file);
    
    return 0;
}

void beautify_html(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");
    char buffer[BUFFER_SIZE];
    int indent_level = 0;

    if (input == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", input_file);
        return;
    }
    
    if (output == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", output_file);
        fclose(input);
        return;
    }

    while (fgets(buffer, BUFFER_SIZE, input) != NULL) {
        char *token = strtok(buffer, " \t\n");
        while (token != NULL) {
            // Handle indentation before the tag
            if (is_opening_tag(token)) {
                indent(output, indent_level);
                fprintf(output, "%s\n", token);
                indent_level++;
            } else if (is_closing_tag(token)) {
                indent_level--;
                indent(output, indent_level);
                fprintf(output, "%s\n", token);
            } else {
                indent(output, indent_level);
                fprintf(output, "%s ", token);
            }
            token = strtok(NULL, " \t\n");
        }
    }

    fclose(input);
    fclose(output);
}

void indent(FILE *output, int level) {
    for (int i = 0; i < level * INDENT_SIZE; i++) {
        fputc(' ', output);
    }
}

int is_opening_tag(const char *tag) {
    return tag[0] == '<' && tag[1] != '/' && tag[strlen(tag) - 1] == '>';
}

int is_closing_tag(const char *tag) {
    return tag[0] == '<' && tag[1] == '/' && tag[strlen(tag) - 1] == '>';
}