//FormAI DATASET v1.0 Category: HTML beautifier ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void beautify(char* filename);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Invalid number of arguments. Please provide the file name to beautify.\n");
        return 1;
    }

    beautify(argv[1]);

    return 0;
}

void indent(int level) {
    for (int i = 0; i < level; i++) {
        printf("    "); // 4 spaces for each level of indentation
    }
}

void beautify(char* filename) {
    FILE* inputFile = fopen(filename, "r");
    if (inputFile == NULL) {
        printf("Could not open file %s.\n", filename);
        exit(1);
    }

    FILE* outputFile = fopen("beautified.html", "w");
    if (outputFile == NULL) {
        printf("Could not create output file.\n");
        exit(1);
    }

    int indentationLevel = 0;
    int insideTag = 0;
    int insideComment = 0;

    char currentChar, nextChar;
    while ((currentChar = fgetc(inputFile)) != EOF) {
        if (currentChar == '<') {
            nextChar = fgetc(inputFile);
            if (nextChar == '!') {
                // Inside a comment
                insideComment = 1;
            } else {
                // Inside a tag
                insideTag = 1;
                ungetc(nextChar, inputFile);
            }
        }

        if (insideComment) {
            // Don't indent inside a comment
            fputc(currentChar, outputFile);

            if (currentChar == '-' && fgetc(inputFile) == '-' && fgetc(inputFile) == '>') {
                insideComment = 0;
            }
        } else if (insideTag) {
            if (currentChar == '>') {
                // End of tag
                fputc(currentChar, outputFile);
                insideTag = 0;
            } else {
                if (isspace(currentChar)) {
                    // Ignore whitespace
                } else if (currentChar == '/') {
                    // Closing tag, decrease indentation level
                    indentationLevel--;
                    indent(indentationLevel);
                    fputc(currentChar, outputFile);
                } else {
                    // Opening tag or tag attribute, increase indentation level
                    indent(indentationLevel);
                    fputc(currentChar, outputFile);
                    indentationLevel++;
                }
            }
        } else {
            // Outside of tag
            fputc(currentChar, outputFile);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("Beautification complete! Please see 'beautified.html'.\n");
}