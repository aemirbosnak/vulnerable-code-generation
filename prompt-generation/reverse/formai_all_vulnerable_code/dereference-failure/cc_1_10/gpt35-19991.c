//FormAI DATASET v1.0 Category: HTML beautifier ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABSIZE 4 // Number of spaces per tab

void beautify(char *filepath, char *outpath) {
    FILE *fp = fopen(filepath, "r"); // Open input file
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file '%s'\n", filepath);
        exit(1);
    }

    FILE *out = fopen(outpath, "w"); // Open output file
    if (out == NULL) {
        fprintf(stderr, "Failed to create file '%s'\n", outpath);
        exit(1);
    }

    int indent = 0; // Current indentation level
    int in_tag = 0; // Are we currently inside a tag
    char c, last_char = '\0';
    while ((c = fgetc(fp)) != EOF) {
        if (c == '<') {
            // If we're already inside a tag, just write the character
            if (in_tag) fputc(c, out);
            else {
                // Write newline and indent before tag
                fputc('\n', out);
                for (int i = 0; i < TABSIZE * indent; i++) {
                    fputc(' ', out);
                }
                fputc(c, out);
                in_tag = 1;
            }
        } else if (c == '>') {
            // Write character and set in_tag to false
            fputc(c, out);
            in_tag = 0;

            // If this is a closing tag, decrease indent level
            if (last_char == '/') indent--;
        } else if (c == '/') {
            // Write character and check if this is a self-closing tag
            fputc(c, out);
            if (last_char == '<') indent++;
        } else {
            // If not in a tag, write character and ignore whitespace
            if (!in_tag && (c == ' ' || c == '\t' || c == '\r' || c == '\n')) continue;
            fputc(c, out);
        }

        last_char = c;
    }

    fclose(fp);
    fclose(out);
}

int main() {
    beautify("example.html", "beautified.html");
    return 0;
}