//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024
#define INDENT_SIZE 4

typedef struct {
    char line[MAX_LENGTH];
    int indent_level;
} Line;

void beautify_html(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");
    if (input_file == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        exit(EXIT_FAILURE);
    }

    Line line;
    line.indent_level = 0;
    
    while (fgets(line.line, MAX_LENGTH, input_file)) {
        char *ptr = line.line;
        while (*ptr == ' ' || *ptr == '\t') {
            ptr++;
        }

        // Check for end tags
        if (strstr(ptr, "</") == ptr) {
            line.indent_level--;
        }

        // Print indentation
        for (int i = 0; i < line.indent_level * INDENT_SIZE; i++) {
            fputc(' ', output_file);
        }

        // Print the line
        fputs(line.line, output_file);
        
        // Check for start tags
        if (strstr(ptr, "<") == ptr && strstr(ptr, "/>") == NULL && strstr(ptr, "</") == NULL) {
            line.indent_level++;
        }
    }

    fclose(input_file);
    fclose(output_file);
}

void print_usage(const char *program_name) {
    printf("Usage: %s <input_file> <output_file>\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);
    printf("HTML beautification completed!\n");

    return EXIT_SUCCESS;
}