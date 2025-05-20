//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000

void beautify(char* line);

int main(int argc, char** argv) {
    FILE* input_file;
    FILE* output_file;
    char line[MAX_LINE_LENGTH];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s [input file] [output file]\n", argv[0]);
        exit(1);
    }

    input_file = fopen(argv[1], "r");

    if (!input_file) {
        fprintf(stderr, "Failed to open input file '%s'\n", argv[1]);
        exit(1);
    }

    output_file = fopen(argv[2], "w");

    if (!output_file) {
        fprintf(stderr, "Failed to open output file '%s'\n", argv[2]);
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file)) {
        beautify(line);
        fprintf(output_file, "%s", line);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}

void beautify(char* line) {
    char beautified[MAX_LINE_LENGTH];
    char* p_beautified = beautified;
    char* p_line = line;
    bool in_tag = false;

    while (*p_line != '\0') {
        if (*p_line == '<') {
            in_tag = true;
        }

        if (in_tag) {
            *p_beautified = *p_line;
            p_beautified++;
        }
        else {
            if (isalpha(*p_line)) {
                *p_beautified = toupper(*p_line);
                p_beautified++;
            }
            else if (isspace(*p_line)) {
                // ignore consecutive spaces
                if (*(p_line + 1) != ' ') {
                    *p_beautified = ' ';
                    p_beautified++;
                }
            }
            else {
                *p_beautified = *p_line;
                p_beautified++;
            }
        }

        if (*p_line == '>') {
            in_tag = false;
        }

        p_line++;
    }

    *p_beautified = '\0';
    sprintf(line, "%s", beautified);
}