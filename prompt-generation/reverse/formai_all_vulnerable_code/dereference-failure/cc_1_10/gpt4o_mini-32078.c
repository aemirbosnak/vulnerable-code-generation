//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define INDENT_SIZE 4

void beautify_html(const char* input_file, const char* output_file);
void indent(int level);
void process_line(char* line, FILE* out_file, int* indent_level);
int is_opening_tag(const char* line);
int is_closing_tag(const char* line);
int is_self_closing_tag(const char* line);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_html_file> [<output_html_file>]\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char* output_file = (argc == 3) ? argv[2] : "output.html";
    
    beautify_html(argv[1], output_file);
    printf("Beautification complete. Output saved to %s\n", output_file);
    
    return EXIT_SUCCESS;
}

void beautify_html(const char* input_file, const char* output_file) {
    FILE *in_file = fopen(input_file, "r");
    FILE *out_file = fopen(output_file, "w");
    
    if (!in_file || !out_file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    
    char line[BUFFER_SIZE];
    int indent_level = 0;
    
    while (fgets(line, sizeof(line), in_file)) {
        process_line(line, out_file, &indent_level);
    }
    
    fclose(in_file);
    fclose(out_file);
}

void process_line(char* line, FILE* out_file, int* indent_level) {
    char* trimmed_line = line;
    // Trim trailing whitespace (removing new line characters for example)
    trimmed_line[strcspn(trimmed_line, "\r\n")] = 0;

    if (is_closing_tag(trimmed_line)) {
        (*indent_level)--;
    }
    
    indent(*indent_level);
    fprintf(out_file, "%s\n", trimmed_line);
    
    if (is_opening_tag(trimmed_line) && !is_self_closing_tag(trimmed_line)) {
        (*indent_level)++;
    }
}

void indent(int level) {
    for (int i = 0; i < level * INDENT_SIZE; i++) {
        printf(" ");
    }
}

int is_opening_tag(const char* line) {
    return (line[0] == '<' && line[1] != '/' && line[strlen(line) - 1] != '/');
}

int is_closing_tag(const char* line) {
    return (line[0] == '<' && line[1] == '/');
}

int is_self_closing_tag(const char* line) {
    return (line[strlen(line) - 2] == '/' && line[strlen(line) - 1] == '>');
}