//FormAI DATASET v1.0 Category: HTML beautifier ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

void beautifyHTML(char* input, char* output) {
    FILE *fileIn = fopen(input, "r");
    FILE *fileOut = fopen(output, "w");

    if (fileIn == NULL || fileOut == NULL) {
        printf("File I/O error\n");
        exit(1);
    }

    char buffer[MAX_LINE_LENGTH];
    int level = 0;

    while (fgets(buffer, MAX_LINE_LENGTH, fileIn)) {
        char *p = buffer;

        while (*p == ' ') {
            p++;
        }

        if (*p == '<') {
            for (int i = 0; i < level; i++) {
                fprintf(fileOut, "  ");
            }
            level++;
            fprintf(fileOut, "%s", buffer);
        } else if (*p == '>') {
            level--;
            for (int i = 0; i < level; i++) {
                fprintf(fileOut, "  ");
            }
            fprintf(fileOut, "%s", buffer);
        } else {
            for (int i = 0; i < level; i++) {
                fprintf(fileOut, "  ");
            }
            fprintf(fileOut, "%s", buffer);
        }
    }

    fclose(fileIn);
    fclose(fileOut);
}

int main() {
    char inFile[MAX_LINE_LENGTH], outFile[MAX_LINE_LENGTH];

    printf("Enter input file name: ");
    scanf("%s", inFile);

    printf("Enter output file name: ");
    scanf("%s", outFile);

    beautifyHTML(inFile, outFile);

    printf("File beautified successfully!\n");
    
    return 0;
}