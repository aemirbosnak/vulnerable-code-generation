//FormAI DATASET v1.0 Category: HTML beautifier ; Style: invasive
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define MAX_LINE_SIZE 1024

/* Function declaration */
void beautifyHtml(FILE *input, FILE *output);

/* Main function */
int main(int argc, char *argv[]) {

    char *inputFile = argv[1];
    char *outputFile = argv[2];

    FILE *input = fopen(inputFile, "r");
    if (!input) {
        perror("Error opening input file.");
        return EXIT_FAILURE;
    }

    FILE *output = fopen(outputFile, "w");
    if (!output) {
        fclose(input);
        perror("Error opening output file.");
        return EXIT_FAILURE;
    }

    beautifyHtml(input, output);
    fclose(input);
    fclose(output);

    return EXIT_SUCCESS;
}

/* Function definition */
void beautifyHtml(FILE *input, FILE *output) {

    char line[MAX_LINE_SIZE];
    int indentLevel = 0;
    int shouldIndentNextLine = 0;

    while (fgets(line, MAX_LINE_SIZE, input)) {
        int i = 0;
        while (isspace(line[i])) {
            i++;
        }
        if (line[i] == '<') {
            if (shouldIndentNextLine) {
                indentLevel++;
                shouldIndentNextLine = 0;
            }
            fprintf(output, "%*s%s", indentLevel * 4, "", line + i);
            if (line[strlen(line) - 2] == '/') {
                shouldIndentNextLine = 0;
            } else {
                shouldIndentNextLine = 1;
            }
        } else if (line[i] == '>') {
            fprintf(output, "%s", line + i);
            if (shouldIndentNextLine) {
                indentLevel--;
                shouldIndentNextLine = 0;
            }
        } else {
            fprintf(output, "%*s%s", indentLevel * 4, "", line + i);
            shouldIndentNextLine = 0;
        }
    }
}