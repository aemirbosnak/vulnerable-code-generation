//FormAI DATASET v1.0 Category: HTML beautifier ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// function declaration
void addIndentation(int indentLevel);
void beautifyHTML(FILE* fpIn, FILE* fpOut);

int main() {
    FILE* fpIn = fopen("input.html", "r");
    FILE* fpOut = fopen("output.html", "w");

    if(fpIn == NULL || fpOut == NULL) {
        printf("Error: Failed to open files\n");
        return 1;
    }

    beautifyHTML(fpIn, fpOut);

    fclose(fpIn);
    fclose(fpOut);

    return 0;
}

void addIndentation(int indentLevel) {
    int i;
    for(i = 1; i <= indentLevel; i++) {
        printf("\t");
    }
}

void beautifyHTML(FILE* fpIn, FILE* fpOut) {
    bool inTag = false;
    bool inAttribute = false;
    bool inValue = false;
    int indentLevel = 0;

    int c;
    while((c = fgetc(fpIn)) != EOF) {
        if(inTag) {
            if(c == '>') {
                inTag = false;
                fputc(c, fpOut);
                fputc('\n', fpOut);
            }
            else if(c == ' ' && !inAttribute) {
                inAttribute = true;
                fputc(c, fpOut);
            }
            else if(c == '=') {
                inValue = true;
                fputc(c, fpOut);
            }
            else {
                fputc(c, fpOut);
            }
        }
        else {
            if(c == '<') {
                inTag = true;
                addIndentation(indentLevel);
                fputc(c, fpOut);
                if(fgetc(fpIn) == '/') {
                    indentLevel--;
                }
                else {
                    indentLevel++;
                }
            }
            else {
                fputc(c, fpOut);
                if(c == '\n') {
                    addIndentation(indentLevel);
                }
            }
        }
    }
}