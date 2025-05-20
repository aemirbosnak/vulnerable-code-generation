//FormAI DATASET v1.0 Category: HTML beautifier ; Style: Cyberpunk
#include<stdio.h>
#include<stdlib.h>

int isOpened = 0;
int tabs = 0;

void printTabs(FILE* outputFile) {
    for (int i = 0; i < tabs; i++) {
        fprintf(outputFile, "    ");
    }
}

int main() {
    FILE* inputFile = fopen("input.html", "r");
    FILE* outputFile = fopen("output.html", "w");

    if (inputFile == NULL) {
        printf("Error: File not found");
        return 1;
    }

    fprintf(outputFile, "<html>\n");

    char currentChar;
    while ((currentChar = fgetc(inputFile)) != EOF) {
        if (currentChar == '<') {
            isOpened = 1;
            printTabs(outputFile);
        }

        if (isOpened) {
            fputc(currentChar, outputFile);
            if (currentChar == '>') {
                fprintf(outputFile, "\n");
                isOpened = 0;
                if (currentChar == '/') {
                    tabs--;
                }
            }
        } else {
            if (currentChar == '>') {
                fprintf(outputFile, "\n");
            } else {
                fputc(currentChar, outputFile);
            }
            if (currentChar == '/') {
                tabs--;
            }
        }

        if (currentChar == '\n') {
            printTabs(outputFile);
        }

        if (currentChar == '/') {
            tabs--;
        }

        if (currentChar == '>') {
            tabs++;
        }
    }
    fprintf(outputFile, "</html>");

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}