//FormAI DATASET v1.0 Category: HTML beautifier ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void beautifyHTML(char *input, char *output) {
    int indentSize = 4;
    int lineLength = 80;
    int indentLevel = 0;
    int linePosition = 0;
    char currentChar;

    FILE *inputFile = fopen(input, "r");
    FILE *outputFile = fopen(output, "w");

    if (inputFile != NULL && outputFile != NULL) {
        while ((currentChar = fgetc(inputFile)) != EOF) {
            if (currentChar == '<' && fgetc(inputFile) == '/') {
                indentLevel--;
                linePosition -= indentSize;

                if (linePosition < 0)
                    linePosition = 0;
            }

            for (int i = 0; i < indentLevel * indentSize; i++) {
                fputc(' ', outputFile);
                linePosition++;
            }

            fputc(currentChar, outputFile);
            linePosition++;

            if (linePosition >= lineLength && currentChar == ' ') {
                fputc('\n', outputFile);

                for (int i = 0; i < indentLevel * indentSize; i++) {
                    fputc(' ', outputFile);
                }

                linePosition = indentLevel * indentSize;
            }

            if (currentChar == '<' && fgetc(inputFile) != '/') {
                indentLevel++;
                linePosition += indentSize;
                fputc('\n', outputFile);

                for (int i = 0; i < indentLevel * indentSize; i++) {
                    fputc(' ', outputFile);
                }
            }
        }

        fclose(inputFile);
        fclose(outputFile);
    }
}

int main() {
    char input[] = "index.html";
    char output[] = "beautified.html";
    beautifyHTML(input, output);

    printf("HTML file has been beautified and saved as %s\n", output);

    return 0;
}