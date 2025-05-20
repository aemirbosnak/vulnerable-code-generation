//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT 32

typedef struct {
    char *line;
    int indent_level;
} IndentedLine;

IndentedLine beautifyLine(const char *line, int indent_level) {
    IndentedLine indented_line;
    indented_line.line = (char *)malloc(MAX_LINE_LENGTH * sizeof(char));
    
    // Indentation
    for (int i = 0; i < indent_level; i++) {
        strcat(indented_line.line, "  ");  // 2 spaces for each indent level
    }

    // Clean up line and add to indented_line
    strcat(indented_line.line, line);
    indented_line.indent_level = indent_level;
    
    return indented_line;
}

void processHTML(FILE *input_file, FILE *output_file) {
    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    
    while (fgets(line, sizeof(line), input_file)) {
        char *ptr = line;
        
        // Check for closing tags
        if (strncmp(ptr, "</", 2) == 0) {
            indent_level--;  
        }

        // Beautify current line
        IndentedLine indented_line = beautifyLine(ptr, indent_level);
        fprintf(output_file, "%s\n", indented_line.line);
        free(indented_line.line);
        
        // Check for opening tags
        if (line[strlen(line) - 2] == '>') {
            if (line[strlen(line) - 3] != '/') {
                // Avoid incrementing if it is a self-closing tag
                indent_level++;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.html> <output.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    processHTML(input_file, output_file);

    fclose(input_file);
    fclose(output_file);
    
    printf("HTML beautification completed. Output written to %s\n", argv[2]);
    return EXIT_SUCCESS;
}