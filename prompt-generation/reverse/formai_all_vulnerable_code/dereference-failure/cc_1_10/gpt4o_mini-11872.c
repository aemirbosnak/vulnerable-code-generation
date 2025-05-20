//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4
#define MAX_INDENT_DEPTH 20

void indent(int level) {
    for (int i = 0; i < level * INDENT_SIZE; i++) {
        putchar(' ');
    }
}

void beautify_line(char *line, int *indent_level) {
    char *trimmed_line = strdup(line);
    trimmed_line[strcspn(trimmed_line, "\n")] = 0; // Remove newline character

    // Trim leading whitespace
    while (isspace((unsigned char) *trimmed_line)) {
        trimmed_line++;
    }

    // Handle '{' opening braces
    if (strchr(trimmed_line, '{')) {
        indent(*indent_level);
        printf("%s\n", trimmed_line);

        (*indent_level)++;
    } 
    // Handle '}' closing braces
    else if (strchr(trimmed_line, '}')) {
        (*indent_level)--;
        indent(*indent_level);
        printf("%s\n", trimmed_line);
    } 
    // Just print the line for other content
    else {
        indent(*indent_level);
        printf("%s\n", trimmed_line);
    }

    free(trimmed_line);
}

void beautify_html(FILE *input_file, FILE *output_file) {
    char line[MAX_LINE_LENGTH];
    int indent_level = 0;

    while (fgets(line, sizeof(line), input_file) != NULL) {
        beautify_line(line, &indent_level);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file.html> <output_file.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Could not open input file");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (!output_file) {
        perror("Could not open output file");
        fclose(input_file);
        return EXIT_FAILURE;
    }

    beautify_html(input_file, output_file);

    fclose(input_file);
    fclose(output_file);

    printf("Beautification complete. Output saved to %s\n", argv[2]);
    return EXIT_SUCCESS;
}