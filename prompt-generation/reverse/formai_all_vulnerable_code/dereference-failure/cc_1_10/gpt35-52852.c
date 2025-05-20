//FormAI DATASET v1.0 Category: HTML beautifier ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char c, d;
    FILE *file1, *file2;

    file1 = fopen("input.html", "r");
    file2 = fopen("output.html", "w");

    if (file1 == NULL) {
        printf("Error opening input file.\n");
        exit(1);
     }

    if (file2 == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    while ((c = fgetc(file1)) != EOF) {
        if (c == '<') {
            fputc(c, file2);

            do {
                d = fgetc(file1);
                fputc(d, file2);
            } while (d != '>' && d != EOF);
        }
        else if (isspace(c)) {
            fputc(' ', file2);

            while (isspace(c)) {
                c = fgetc(file1);
            }
            ungetc(c, file1);
        }
        else {
            fputc(c, file2);
        }
    }

    fclose(file1);
    fclose(file2);

    printf("HTML Beautifier executed successfully.\n");

    return 0;
}