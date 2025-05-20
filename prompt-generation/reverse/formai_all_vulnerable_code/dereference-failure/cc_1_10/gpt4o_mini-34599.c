//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

// Function prototypes
void beautify_html(const char *input_filename, const char *output_filename);
void process_line(char *line, FILE *output_file);
void indent_level(char *line, int *level);
void print_indented_line(FILE *output_file, char *line, int level);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input_file.html> <output_file.html>\n", argv[0]);
        return 1;
    }

    beautify_html(argv[1], argv[2]);

    printf("HTML beautification completed. Check the output file: %s\n", argv[2]);
    return 0;
}

void beautify_html(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");
    char line[MAX_LINE_LENGTH];
    int level = 0;

    if (input_file == NULL) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), input_file)) {
        process_line(line, output_file);
        indent_level(line, &level);
    }

    fclose(input_file);
    fclose(output_file);
}

void process_line(char *line, FILE *output_file) {
    char *token;
    const char delims[] = "<>";
    
    // Adjust the line to remove excessive spaces
    char *current = line;
    while (*current) {
        if (isspace(*current) && isspace(*(current + 1))) {
            memmove(current, current + 1, strlen(current));
        } else {
            current++;
        }
    }

    token = strtok(line, delims);
    while (token != NULL) {
        if (strlen(token) > 0) {
            fprintf(output_file, "%s", token);
            if (*(current + 1) == '>') {
                fprintf(output_file, ">\n");
            } else {
                fprintf(output_file, "\n");
            }
        }
        token = strtok(NULL, delims);
    }
}

void indent_level(char *line, int *level) {
    if (strstr(line, "</") != NULL) { 
        (*level)--;
    }

    for (int i = 0; i < *level; i++) {
        printf("    ");
    }
    
    if (strstr(line, "<") != NULL && strstr(line, "/>") == NULL && strstr(line, "</") == NULL) {
        (*level)++;
    }
}

void print_indented_line(FILE *output_file, char *line, int level) {
    for (int i = 0; i < level; i++) {
        fprintf(output_file, "    ");
    }
    fprintf(output_file, "%s", line);
}