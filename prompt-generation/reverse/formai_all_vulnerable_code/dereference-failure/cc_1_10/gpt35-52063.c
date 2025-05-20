//FormAI DATASET v1.0 Category: HTML beautifier ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 200
#define MAX_INDENT_LEVEL 10

typedef struct {
    char content[MAX_LINE_LENGTH];
    int indent_level;
} Line;

void indent(Line *line, int indentation) {
    line->indent_level += indentation;
    if (line->indent_level < 0) line->indent_level = 0;
}

void beautify(char *input_file, char *output_file, int indent_spaces) {
    FILE *in_fp, *out_fp;
    Line line;
    char buffer[MAX_LINE_LENGTH];
    Line stack[MAX_INDENT_LEVEL];
    int line_no = 1, top = 0, i; //initialize top
    int whitespace_only;

    // open files
    in_fp = fopen(input_file, "r");
    if (in_fp == NULL) {
        printf("Cannot open input file %s\n", input_file);
        exit(1);
    }

    out_fp = fopen(output_file, "w");
    if (out_fp == NULL) {
        printf("Cannot open output file %s\n", output_file);
        exit(1);
    }

    // read lines and beautify
    while (fgets(buffer, sizeof(buffer), in_fp) != NULL) {
        whitespace_only = 1;
        for (i = 0; i < strlen(buffer); i++) {
            // check if the line is not empty or only whitespace,
            // and update flag accordingly
            if (buffer[i] != '\n' && buffer[i] != '\r' && buffer[i] != ' ') {
                whitespace_only = 0;
                break;
            }
        }
        if (whitespace_only) {
            fprintf(out_fp, "\n");
            continue;
        }

        // remove trailing whitespace
        for (i = strlen(buffer) - 1; i >= 0; i--) {
            if (buffer[i] == '\n' || buffer[i] == '\r' || buffer[i] == ' ') {
                buffer[i] = '\0';
            } else break;
        }

        // initialize line
        strcpy(line.content, buffer);
        line.indent_level = 0;

        // check if stack needs to be adjusted
        while (top > 0 && line.indent_level <= stack[top-1].indent_level) {
            top--;
        }

        // print lines in stack
        for (i = 0; i < top; i++) {
            fprintf(out_fp, "%*s%s\n", stack[i].indent_level * indent_spaces, "", stack[i].content);
        }

        // print current line with indentation
        fprintf(out_fp, "%*s%s\n", line.indent_level * indent_spaces, "", line.content);

        // push current line to stack
        if (top < MAX_INDENT_LEVEL) {
            strcpy(stack[top].content, line.content);
            stack[top].indent_level = line.indent_level;
            top++;
        }

        line_no++;
    }

    // close files
    fclose(in_fp);
    fclose(out_fp);
}

int main() {
    beautify("input.html", "output.html", 4);
    return 0;
}