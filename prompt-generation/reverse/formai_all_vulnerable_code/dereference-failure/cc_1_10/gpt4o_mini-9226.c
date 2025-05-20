//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT 256

void beautify_html(FILE *input, FILE *output) {
    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    int inside_tag = 0;

    while (fgets(line, sizeof(line), input) != NULL) {
        char *ptr = line;
        // Adjust the indentation level
        while (*ptr) {
            if (*ptr == '<') {
                inside_tag = 1;
                
                // If it's a closing tag, decrease the indent level before printing
                if (*(ptr + 1) == '/') {
                    indent_level--;
                }

                // Add indentations before printing the tag
                for (int i = 0; i < indent_level; i++)
                    fputs("    ", output);  // Use 4 spaces for indentation
                
                fputs(ptr, output);
                break;  // No need to process the rest of the line
            } else if (inside_tag && *ptr == '>') {
                inside_tag = 0;
                
                // Check if it's a single line tag or opening tag for future indentation
                if (*(ptr - 1) != '/') {
                    if (strstr(line, "</") == NULL) {
                        indent_level++;
                    }
                }
            }
            ptr++;
        }
        // Print a newline character after each processed line
        fputs("\n", output);
    }
}

void trim_whitespace(char *line) {
    char *end;

    // Trim leading whitespace
    while (isspace((unsigned char)*line)) line++;

    // Trim trailing whitespace
    end = line + strlen(line) - 1;
    while (end > line && isspace((unsigned char)*end)) end--;

    // Null terminate
    end[1] = '\0';
}

void process_html_file(const char *input_file, const char *output_file) {
    FILE *input = fopen(input_file, "r");
    if (!input) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
    
    FILE *output = fopen(output_file, "w");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        exit(EXIT_FAILURE);
    }

    beautify_html(input, output);
    
    fclose(input);
    fclose(output);
    
    printf("HTML beautification complete! Output saved to %s\n", output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Process the HTML file
    process_html_file(argv[1], argv[2]);
    
    return EXIT_SUCCESS;
}