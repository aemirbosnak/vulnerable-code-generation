//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

void trim_whitespace(char *line) {
    char *end;

    // Trim leading whitespace
    while(isspace((unsigned char)*line)) line++;

    // Trim trailing whitespace
    end = line + strlen(line) - 1;
    while(end > line && isspace((unsigned char)*end)) end--;

    // Null terminate the trimmed string
    end[1] = '\0';
}

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

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    const char *indent_string = "  "; // using 2 spaces for indentation

    while (fgets(line, sizeof(line), input_file)) {
        trim_whitespace(line);
        
        // Check for closing tags
        if (strstr(line, "</")) {
            indent_level--;
        }

        // Print indents
        for (int i = 0; i < indent_level; i++) {
            fputs(indent_string, output_file);
        }

        // Print the current line
        fputs(line, output_file);
        fputc('\n', output_file);

        // Check for opening tags
        if (strstr(line, "<") && !strstr(line, "/>") && !strstr(line, "</")) {
            indent_level++;
        }
    }
    
    fclose(input_file);
    fclose(output_file);
}

void display_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s <input_file.html> <output_file.html>\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);
    printf("HTML beautification complete! Check the output file: %s\n", argv[2]);

    return EXIT_SUCCESS;
}