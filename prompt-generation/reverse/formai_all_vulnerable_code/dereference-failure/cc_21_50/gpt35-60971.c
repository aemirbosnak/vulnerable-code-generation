//FormAI DATASET v1.0 Category: HTML beautifier ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE_LEN 4096

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error: could not open input file '%s'\n", argv[1]);
        return EXIT_FAILURE;
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error: could not open output file '%s'\n", argv[2]);
        fclose(input_file);
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LEN];
    int in_tag = 0;
    int in_quotes = 0;
    int indent = 0;

    while (fgets(line, MAX_LINE_LEN, input_file) != NULL) {
        char *trimmed_line = line;
        while (isspace(*trimmed_line)) {
            ++trimmed_line;
        }

        if (*trimmed_line == '\0') {
            // Skip blank lines
            continue;
        }

        int len = strlen(trimmed_line);
        if (len > 0 && trimmed_line[len-1] == '\n') {
            trimmed_line[len-1] = '\0';
        }

        for (char *p = trimmed_line; *p != '\0'; ++p) {
            if (!in_quotes && *p == '<') {
                // Start of tag
                in_tag = 1;
                fprintf(output_file, "%*s%c", indent, "", *p);
                if (p[1] != '/') {
                    // Start tag
                    indent += 4;
                    fprintf(output_file, "\n%*s", indent, "");
                }
            } else if (!in_quotes && *p == '>') {
                // End of tag
                in_tag = 0;
                fprintf(output_file, "%c", *p);
                if (p[-1] != '/') {
                    // End tag
                    indent -= 4;
                    fprintf(output_file, "\n%*s", indent, "");
                }
            } else {
                fprintf(output_file, "%c", *p);
            }

            // Check for quotes
            if (*p == '"' || *p == '\'') {
                if (!in_quotes) {
                    in_quotes = *p;
                } else if (in_quotes == *p) {
                    in_quotes = 0;
                }
            }
        }

        if (!in_tag) {
            fprintf(output_file, "\n");
        }
    }

    fclose(input_file);
    fclose(output_file);

    return EXIT_SUCCESS;
}