//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold information about an HTML element
typedef struct {
    char *tag;
    int indent_level;
} HtmlElement;

// Function prototypes
void beautify_html(const char *input_file, const char *output_file);
void process_element(FILE *output, HtmlElement element);
void print_indent(FILE *output, int level);
void free_element(HtmlElement element);

int main() {
    char *input_file = "input.html";   // Input HTML file
    char *output_file = "output.html"; // Output beautified HTML file

    printf("Elementary, my dear Watson! Starting to beautify the HTML...\n");
    beautify_html(input_file, output_file);
    printf("The beautified HTML has been saved in '%s'.\n", output_file);

    return 0;
}

// Function to beautify the HTML
void beautify_html(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "r");
    FILE *output = fopen(output_file, "w");

    if (!input) {
        fprintf(stderr, "Could not open input file: %s\n", input_file);
        exit(EXIT_FAILURE);
    }
    if (!output) {
        fprintf(stderr, "Could not create output file: %s\n", output_file);
        fclose(input);
        exit(EXIT_FAILURE);
    }

    char c;
    HtmlElement current_element = {NULL, 0};
    while ((c = fgetc(input)) != EOF) {
        // Check for opening tag
        if (c == '<') {
            if ((c = fgetc(input)) == '/') {
                // Closing tag
                if (current_element.indent_level > 0) {
                    current_element.indent_level--;
                }
                while ((c != '>') && (c != EOF)) {
                    c = fgetc(input);
                }
                fputc('\n', output);
                print_indent(output, current_element.indent_level);
                fputc('>', output);
                continue;
            } else {
                // Opening tag
                ungetc(c, input);
                int size = 0;
                char buffer[256];
                while ((c = fgetc(input)) != ' ' && c != '>' && c != EOF) {
                    buffer[size++] = c;
                }
                buffer[size] = '\0';
                current_element.tag = strdup(buffer);
                
                // Write the tag
                print_indent(output, current_element.indent_level);
                fputc('<', output);
                fputs(current_element.tag, output);
                fputc(' ', output);

                // Increase indent level for nesting
                current_element.indent_level++;
                if (c == '>') {
                    fputc('>', output);
                } else {
                    ungetc(c, input);
                    fputc('>', output);
                }
            }
        }
        fputc(c, output);
    }

    free_element(current_element);
    fclose(input);
    fclose(output);
}

// Function to process specific HTML elements (a placeholder for advanced features)
void process_element(FILE *output, HtmlElement element) {
    // Currently does nothing, but could be enhanced for various HTML processing actions
}

// Function to print indentation
void print_indent(FILE *output, int level) {
    for (int i = 0; i < level; i++) {
        fputs("    ", output);
    }
}

// Function to free the HTML element's resources
void free_element(HtmlElement element) {
    if (element.tag) {
        free(element.tag);
    }
}