//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4

void beautifyLine(const char *line, FILE *output, int indentLevel) {
    char indent[INDENT_SIZE + 1];
    memset(indent, ' ', INDENT_SIZE);
    indent[INDENT_SIZE] = '\0';

    bool inTag = false;
    bool newLineRequired = false;
    int length = strlen(line);
    
    for (int i = 0; i < length; i++) {
        if (line[i] == '<') {
            if (inTag) {
                fputs("\n", output);
                for (int j = 0; j < indentLevel; j++) {
                    fputs(indent, output);
                }
            }
            inTag = true;
            fputc(line[i], output);
            if (line[i + 1] == '/') {
                indentLevel--;
                newLineRequired = true;
            } else if (line[i] == '<' && line[i + 1] != '/') {
                if (i == 0 || (line[i - 1] != '{' && line[i - 1] != '}' && line[i - 1] != '<'))  {
                    newLineRequired = true;
                }
                indentLevel++;
            }
        } else if (line[i] == '>') {
            inTag = false;
            fputc(line[i], output);
            if (newLineRequired) {
                fputs("\n", output);
                for (int j = 0; j < indentLevel; j++) {
                    fputs(indent, output);
                }
                newLineRequired = false;
            }
        } else {
            fputc(line[i], output);
        }
    }
}

void beautifyFile(const char *inputFilename, const char *outputFilename) {
    FILE *input = fopen(inputFilename, "r");
    FILE *output = fopen(outputFilename, "w");

    if (!input || !output) {
        fprintf(stderr, "Error opening files.\n");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indentLevel = 0;

    while (fgets(line, sizeof(line), input)) {
        beautifyLine(line, output, indentLevel);
    }

    fclose(input);
    fclose(output);
}

void printUsage(const char *progName) {
    printf("Usage: %s <input_file> <output_file>\n", progName);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printUsage(argv[0]);
        return EXIT_FAILURE;
    }

    beautifyFile(argv[1], argv[2]);
    printf("HTML beautification completed. Output written to %s.\n", argv[2]);

    return EXIT_SUCCESS;
}