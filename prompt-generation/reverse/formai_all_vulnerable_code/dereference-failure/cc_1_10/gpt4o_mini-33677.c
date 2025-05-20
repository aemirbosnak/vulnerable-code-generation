//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4

void trim_whitespace(char *line) {
    char *end;

    // Trim leading whitespace
    while(isspace((unsigned char)*line)) line++;
    // Trim trailing whitespace
    end = line + strlen(line) - 1;
    while(end > line && isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
}

void indent_output(FILE *output_file, int indent_level) {
    for (int i = 0; i < indent_level * INDENT_SIZE; i++) {
        fputc(' ', output_file);
    }
}

void beautify_html(FILE *input_file, FILE *output_file) {
    char line[MAX_LINE_LENGTH];
    int indent_level = 0;

    while (fgets(line, sizeof(line), input_file)) {
        trim_whitespace(line);

        // Identify opening and closing tags
        if (strstr(line, "<!DOCTYPE") != NULL || 
            strstr(line, "<html") != NULL || 
            strstr(line, "<body") != NULL || 
            strstr(line, "<div") != NULL || 
            strstr(line, "<p") != NULL || 
            strstr(line, "<h1") != NULL || 
            strstr(line, "<h2") != NULL ||
            strstr(line, "<h3") != NULL || 
            strstr(line, "<h4") != NULL || 
            strstr(line, "<h5") != NULL || 
            strstr(line, "<h6") != NULL) {
            indent_output(output_file, indent_level);
            fprintf(output_file, "%s\n", line);
            indent_level++;
        } else if (strstr(line, "</") != NULL) {
            indent_level--;
            indent_output(output_file, indent_level);
            fprintf(output_file, "%s\n", line);
        } else if (strlen(line) > 0) {
            indent_output(output_file, indent_level);
            fprintf(output_file, "%s\n", line);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (!output_file) {
        fclose(input_file);
        perror("Error opening output file");
        return EXIT_FAILURE;
    }

    beautify_html(input_file, output_file);
    
    fclose(input_file);
    fclose(output_file);
    
    printf("HTML beautification completed successfully!\n");
    
    return EXIT_SUCCESS;
}