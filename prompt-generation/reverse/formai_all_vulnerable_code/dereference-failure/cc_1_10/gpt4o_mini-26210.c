//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024

void trim_whitespace(char *str) {
    int start = 0, end = strlen(str) - 1;

    // Trim leading whitespace
    while (start <= end && (str[start] == ' ' || str[start] == '\t')) {
        start++;
    }

    // Trim trailing whitespace
    while (end >= start && (str[end] == ' ' || str[end] == '\t' || str[end] == '\n')) {
        end--;
    }

    // Null-terminate after the last valid character
    str[end + 1] = '\0';

    // Move the trimmed string to the front
    if (start > 0) {
        memmove(str, str + start, end - start + 2); // Include newline
    }
}

bool is_empty_line(const char *line) {
    return line[0] == '\0';
}

void beautify_html(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");

    if (!input_file || !output_file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), input_file)) {
        // Trim whitespace from both ends of the line
        trim_whitespace(line);

        // Skip empty lines
        if (is_empty_line(line)) {
            continue;
        }

        // Beautifying the HTML - here we simply add indentation for demonstrative purposes
        fprintf(output_file, "    %s\n", line);
    }

    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];

    beautify_html(input_filename, output_filename);
    
    printf("HTML beautification complete! Output saved to %s\n", output_filename);
    return EXIT_SUCCESS;
}