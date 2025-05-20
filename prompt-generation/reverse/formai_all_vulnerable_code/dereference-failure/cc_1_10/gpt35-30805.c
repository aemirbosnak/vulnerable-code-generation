//FormAI DATASET v1.0 Category: HTML beautifier ; Style: energetic
#include<stdio.h>
#include<stdlib.h>

void beautifyHTML(char* filename1, char* filename2) {
    FILE *inputFile, *outputFile;
    char ch;
    int indentLevel = 0;

    inputFile = fopen(filename1, "r");
    if (inputFile == NULL) {
        printf("Error opening input file!\n");
        exit(1);
    }

    outputFile = fopen(filename2, "w");
    if (outputFile == NULL) {
        printf("Error opening output file!\n");
        exit(1);
    }

    while ((ch = fgetc(inputFile)) != EOF) {
        if (ch == '<') {
            if (fgetc(inputFile) == '/') {
                indentLevel--;
            }
            for (int i = 0; i < indentLevel; i++) {
                fprintf(outputFile, "\t");
            }
            fprintf(outputFile, "<");
            if (fgetc(inputFile) == '/') {
                indentLevel--;
            }
            else {
                indentLevel++;
            }
        }
        fprintf(outputFile, "%c", ch);
        if (ch == '\n') {
            for (int j = 0; j < indentLevel; j++) {
                fprintf(outputFile, "\t");
            }
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("HTML Beautified successfully!");
}

int main() {
    beautifyHTML("index.html", "beautified.html");
    return 0;
}