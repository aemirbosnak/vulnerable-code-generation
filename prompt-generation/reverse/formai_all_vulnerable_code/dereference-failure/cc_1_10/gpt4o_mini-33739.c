//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_INDENT 256

void beautifyHTML(const char *inputFile, const char *outputFile, int indentLevel);
void addIndentation(char *output, int indent);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input HTML file> <output HTML file> [indent level]\n", argv[0]);
        return 1;
    }

    int indentLevel = 2; // Default indent level
    if (argc == 4) {
        indentLevel = atoi(argv[3]);
        if (indentLevel < 1 || indentLevel > MAX_INDENT) {
            fprintf(stderr, "Indent level should be between 1 and %d.\n", MAX_INDENT);
            return 1;
        }
    }

    beautifyHTML(argv[1], argv[2], indentLevel);
    printf("Beautification complete. Output written to %s\n", argv[2]);
    return 0;
}

void beautifyHTML(const char *inputFile, const char *outputFile, int indentLevel) {
    FILE *in = fopen(inputFile, "r");
    if (!in) {
        perror("Failed to open input file");
        exit(EXIT_FAILURE);
    }

    FILE *out = fopen(outputFile, "w");
    if (!out) {
        perror("Failed to open output file");
        fclose(in);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int currentIndent = 0;
    int inTag = 0;

    while (fgets(line, sizeof(line), in)) {
        char *p = line;
        while (*p) {
            if (*p == '<') {
                if (*(p + 1) == '/') {
                    // Close tag
                    currentIndent--;
                    if (currentIndent < 0) currentIndent = 0; // Prevent negative indentation
                }

                addIndentation(line, currentIndent * indentLevel);
                fputs(line, out); // Write current line with indentation

                if (*(p + 1) != '/') {
                    currentIndent++; // Increase indent on opening tag
                }
                break;
            }
            p++;
        }
    }

    fclose(in);
    fclose(out);
}

void addIndentation(char *output, int indent) {
    char indentation[MAX_INDENT] = {0};
    memset(indentation, ' ', indent);
    printf("%s", indentation); // Print current indent to output
}