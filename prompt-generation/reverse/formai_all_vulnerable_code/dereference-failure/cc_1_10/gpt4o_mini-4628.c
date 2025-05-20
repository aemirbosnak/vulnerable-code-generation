//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT 10

typedef struct {
    int level;                   // Current indentation level
    char indent[MAX_INDENT];     // String for indentation spaces
} Beautifier;

void initialize_beautifier(Beautifier *b) {
    b->level = 0;
    memset(b->indent, ' ', sizeof(b->indent));
    b->indent[MAX_INDENT - 1] = '\0';
}

void print_indented_line(FILE *output, Beautifier *b, const char *line) {
    if (line[0] != '\0') {
        fprintf(output, "%.*s%s\n", b->level * 4, b->indent, line);
    }
}

void process_line(Beautifier *b, const char *line, FILE *output) {
    int len = strlen(line);
    char *trimmed_line = malloc(len + 1);
    strcpy(trimmed_line, line);
    
    // Trim whitespace characters from both ends
    while (*trimmed_line == ' ' || *trimmed_line == '\t') trimmed_line++;
    while (len > 0 && (trimmed_line[len - 1] == ' ' || trimmed_line[len - 1] == '\t')) trimmed_line[--len] = '\0';
    
    // Process opening and closing tags
    if (strstr(trimmed_line, "<") != NULL) {
        if (trimmed_line[0] == '<' && trimmed_line[1] != '/') { // Opening tag
            print_indented_line(output, b, trimmed_line);
            b->level++;
        } else if (trimmed_line[0] == '<' && trimmed_line[1] == '/') { // Closing tag
            b->level--;
            print_indented_line(output, b, trimmed_line);
        } else { // Self-closing tag or other cases
            print_indented_line(output, b, trimmed_line);
        }
    } else {
        print_indented_line(output, b, trimmed_line); // Non-tag lines
    }
    
    free(trimmed_line);
}

void beautify_html(FILE *input, FILE *output) {
    Beautifier b;
    initialize_beautifier(&b);
    
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), input)) {
        process_line(&b, line, output);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (!input) {
        perror("Error opening input file");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return 1;
    }

    beautify_html(input, output);

    fclose(input);
    fclose(output);
    
    printf("HTML beautification completed successfully.\n");
    return 0;
}