//FormAI DATASET v1.0 Category: HTML beautifier ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *fp, *fp_out;
    char c, last_c;
    int indent_level = 0;

    // Open the input file
    fp = fopen("input.html", "r");
    if (fp == NULL) {
        printf("Failed to open input file.");
        exit(1);
    }

    // Create the output file
    fp_out = fopen("output.html", "w");
    if (fp_out == NULL) {
        printf("Failed to create output file.");
        exit(1);
    }

    // Start reading input file character by character
    while ((c = fgetc(fp)) != EOF) {
        // Handle newline
        if (c == '\n') {
            fputc(c, fp_out);
            last_c = c;
            // Output indent spaces
            for (int i = 0; i < indent_level * 4; i++) {
                fputc(' ', fp_out);
            }
            continue;
        }

        // Handle tag start
        if (c == '<' && last_c != '>') {
            indent_level++;
        }

        // Output the character
        fputc(c, fp_out);

        // Handle tag end
        if (c == '>' && last_c != '<') {
            indent_level--;
        }

        last_c = c;
    }

    // Close the input and output files
    fclose(fp);
    fclose(fp_out);

    return 0;
}