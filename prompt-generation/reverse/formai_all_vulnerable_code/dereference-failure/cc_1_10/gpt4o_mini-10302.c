//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4

// Function prototypes
void beautify_html(const char *input_file, const char *output_file);
void indent_line(char *line, int level);
void add_indentation(char *line, int level);
void trim_whitespace(char *line);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input.html output.html\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];

    beautify_html(input_file, output_file);
    printf("The document has been successfully beautified and saved to %s\n", output_file);
    
    return 0;
}

void beautify_html(const char *input_file, const char *output_file) {
    FILE *in_file = fopen(input_file, "r");
    if (in_file == NULL) {
        fprintf(stderr, "Could not open the file %s for reading.\n", input_file);
        exit(EXIT_FAILURE);
    }

    FILE *out_file = fopen(output_file, "w");
    if (out_file == NULL) {
        fclose(in_file);
        fprintf(stderr, "Could not open the file %s for writing.\n", output_file);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;

    while (fgets(line, sizeof(line), in_file)) {
        char *ptr = line;
        trim_whitespace(ptr);
        
        // Check for closing tags
        if (strncmp(ptr, "</", 2) == 0) {
            --indent_level;
        }

        // Indent the line
        indent_line(line, indent_level);
        fputs(line, out_file);
        
        // Check for opening tags
        if (strstr(ptr, "<") == ptr && strstr(ptr, "/") == NULL) {
            ++indent_level;
        }
    }

    fclose(in_file);
    fclose(out_file);
}

void indent_line(char *line, int level) {
    add_indentation(line, level);
}

void add_indentation(char *line, int level) {
    // Create the indentation string
    char indent[INDENT_SIZE + 1];
    memset(indent, ' ', INDENT_SIZE);
    indent[INDENT_SIZE] = '\0';

    // Shift existing line content
    int line_length = strlen(line);
    for (int i = line_length; i >= 0; --i) {
        line[i + INDENT_SIZE] = line[i]; // Shift line
    }

    // Insert indentation
    for (int i = 0; i < level; ++i) {
        strcat(line, indent);
    }
}

void trim_whitespace(char *line) {
    char *end;
    // Trim leading whitespace
    while (isspace((unsigned char)*line)) line++;
    // Trim trailing whitespace
    end = line + strlen(line) - 1;
    while (end > line && isspace((unsigned char)*end)) end--;
    end[1] = '\0'; // Null terminate
}