//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_INDENT_LEVELS 10

typedef struct {
    char *line;
    int indent_level;
    int is_tag;
} Line;

void print_line(Line line) {
    int i;
    for (i = 0; i < line.indent_level; i++) {
        printf("  ");
    }
    if (line.is_tag) {
        printf("<%s>", line.line);
    } else {
        printf("%s", line.line);
    }
    printf("\n");
}

void indent(int *indent_level) {
    (*indent_level)++;
}

void unindent(int *indent_level) {
    if (*indent_level > 0) {
        (*indent_level)--;
    }
}

Line read_line(FILE *file) {
    char buffer[MAX_LINE_LENGTH];
    Line line = {0};
    line.line = malloc(MAX_LINE_LENGTH);
    fgets(buffer, MAX_LINE_LENGTH, file);
    strcpy(line.line, buffer);
    line.indent_level = 0;
    line.is_tag = 0;
    return line;
}

void beautify_html(FILE *input_file, FILE *output_file) {
    Line current_line = read_line(input_file);
    int indent_level = 0;
    while (current_line.line!= NULL) {
        if (strstr(current_line.line, "<") == current_line.line) {
            indent(indent_level);
            current_line.is_tag = 1;
        } else if (strstr(current_line.line, "</") == current_line.line) {
            unindent(indent_level);
            current_line.is_tag = 1;
        } else {
            current_line.is_tag = 0;
        }
        print_line(current_line);
        current_line = read_line(input_file);
    }
    fclose(input_file);
    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }
    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error: could not open output file.\n");
        fclose(input_file);
        return 1;
    }
    beautify_html(input_file, output_file);
    fclose(input_file);
    fclose(output_file);
    return 0;
}