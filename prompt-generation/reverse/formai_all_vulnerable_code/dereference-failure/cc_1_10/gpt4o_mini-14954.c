//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENTATION 100

// Function declarations
void beautify_html(FILE *inputFile, FILE *outputFile);
void add_newline_and_indent(char *line, int indentLevel, FILE *outputFile);
int is_self_closing_tag(const char *tag);
int is_start_tag(const char *tag);
int is_end_tag(const char *tag);
void trim_whitespace(char *str);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.html> <output.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *outputFile = fopen(argv[2], "w");
    if (!outputFile) {
        perror("Error opening output file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    beautify_html(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return EXIT_SUCCESS;
}

void beautify_html(FILE *inputFile, FILE *outputFile) {
    char line[MAX_LINE_LENGTH];
    int indentLevel = 0;

    while (fgets(line, sizeof(line), inputFile)) {
        trim_whitespace(line);

        if (line[0] == '\0') {
            continue; // Skip empty lines
        }

        char *startTag = strstr(line, "<");
        char *endTag = strstr(line, ">");

        if (startTag && endTag) {
            char tag[MAX_LINE_LENGTH];
            strncpy(tag, startTag + 1, endTag - startTag - 1);
            tag[endTag - startTag - 1] = '\0';
            
            if (is_start_tag(tag)) {
                add_newline_and_indent(line, indentLevel, outputFile);
                indentLevel++;
            } else if (is_end_tag(tag)) {
                indentLevel--;
                add_newline_and_indent(line, indentLevel, outputFile);
            } else if (is_self_closing_tag(tag)) {
                add_newline_and_indent(line, indentLevel, outputFile);
            } else {
                add_newline_and_indent(line, indentLevel, outputFile);
            }
        } else {
            add_newline_and_indent(line, indentLevel, outputFile);
        }
    }
}

void add_newline_and_indent(char *line, int indentLevel, FILE *outputFile) {
    for (int i = 0; i < indentLevel; i++) {
        fprintf(outputFile, "    "); // 4 spaces for indentation
    }
    fprintf(outputFile, "%s\n", line);
}

int is_self_closing_tag(const char *tag) {
    const char *selfClosingTags[] = {"br", "hr", "img", "input", "link", "meta", "base", "param", NULL};
    
    for (int i = 0; selfClosingTags[i] != NULL; i++) {
        if (strcmp(tag, selfClosingTags[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int is_start_tag(const char *tag) {
    return tag[0] != '/' && tag[strlen(tag) - 1] != '/';
}

int is_end_tag(const char *tag) {
    return tag[0] == '/';
}

void trim_whitespace(char *str) {
    char *end;
    while (isspace((unsigned char)*str)) str++;

    if (*str == 0) return;

    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    end[1] = '\0';
}