//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4

void indent_line(char *line, int indent_level, FILE *output) {
    for (int i = 0; i < indent_level; i++)
        fprintf(output, "%*s", INDENT_SIZE, " ");
    fprintf(output, "%s\n", line);
}

void trim_whitespace(char *line) {
    char *end;

    // Trim trailing whitespace
    while (*line && (*line == ' ' || *line == '\t')) line++;
    end = line + strlen(line) - 1;

    while (end > line && (*end == ' ' || *end == '\t')) end--;
    *(end + 1) = '\0';
}

int process_html_line(char *line, FILE *output, int *indent_level) {
    trim_whitespace(line);
    
    if (strncmp(line, "<html", 5) == 0) {
        indent_line(line, *indent_level, output);
        (*indent_level)++;
    } else if (strncmp(line, "</html", 6) == 0) {
        (*indent_level)--;
        indent_line(line, *indent_level, output);
    } else if (strncmp(line, "<body", 5) == 0) {
        indent_line(line, *indent_level, output);
        (*indent_level)++;
    } else if (strncmp(line, "</body", 6) == 0) {
        (*indent_level)--;
        indent_line(line, *indent_level, output);
    } else if (strncmp(line, "<div", 4) == 0) {
        indent_line(line, *indent_level, output);
        (*indent_level)++;
    } else if (strncmp(line, "</div", 5) == 0) {
        (*indent_level)--;
        indent_line(line, *indent_level, output);
    } else if (strncmp(line, "<p", 2) == 0) {
        indent_line(line, *indent_level, output);
        (*indent_level)++;
    } else if (strncmp(line, "</p", 3) == 0) {
        (*indent_level)--;
        indent_line(line, *indent_level, output);
    } else {
        indent_line(line, *indent_level, output);
    }
    
    return 0;
}

void beautify_html(FILE *input, FILE *output) {
    char line[MAX_LINE_LENGTH];
    int indent_level = 0;

    while (fgets(line, sizeof(line), input)) {
        process_html_line(line, output, &indent_level);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.html> <output.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input = fopen(argv[1], "r");
    if (!input) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *output = fopen(argv[2], "w");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return EXIT_FAILURE;
    }

    beautify_html(input, output);

    fclose(input);
    fclose(output);

    printf("HTML beautification completed successfully!\n");
    return EXIT_SUCCESS;
}