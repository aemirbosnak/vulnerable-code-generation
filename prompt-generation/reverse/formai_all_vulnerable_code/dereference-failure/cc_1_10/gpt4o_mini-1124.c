//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_WIDTH 4

typedef struct {
    char line[MAX_LINE_LENGTH];
    int indent_level;
} Line;

void trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while (*str == ' ') str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\n' || *end == '\r')) end--;
    *(end + 1) = '\0';
}

void beautify_html(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");
    if (!input_file || !output_file) {
        perror("Error opening file");
        if (input_file) fclose(input_file);
        if (output_file) fclose(output_file);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indent_level = 0;
    int is_inside_tag = 0;

    while (fgets(line, sizeof(line), input_file)) {
        trim_whitespace(line);

        // Check if line starts with a closing tag
        if (line[0] == '/') {
            indent_level--;
            if (indent_level < 0) indent_level = 0;  // Prevent negative indentation
        }

        // Print indentation
        for (int i = 0; i < indent_level; ++i) {
            fprintf(output_file, "%*s", INDENT_WIDTH, "");
        }

        // Write the trimmed line to the output file
        fprintf(output_file, "%s\n", line);

        // Check if line contains an opening tag
        if (strchr(line, '<') && strchr(line, '>')) {
            if (line[1] != '/') {
                indent_level++;
            }
        }
    }

    fclose(input_file);
    fclose(output_file);
}

void display_usage(const char *program_name) {
    printf("Usage: %s <input_file> <output_file>\n", program_name);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    beautify_html(argv[1], argv[2]);
    
    printf("HTML beautification completed. Output saved to %s\n", argv[2]);
    return EXIT_SUCCESS;
}