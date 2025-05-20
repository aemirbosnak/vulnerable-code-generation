//FormAI DATASET v1.0 Category: HTML beautifier ; Style: optimized
#include <stdio.h>

int main() {
    FILE *fp1, *fp2;
    char c;

    // Open the input file
    fp1 = fopen("input.html", "r");
    if (fp1 == NULL) {
        perror("Unable to open input file");
        return 0;
    }

    // Open the output file
    fp2 = fopen("output.html", "w");
    if (fp2 == NULL) {
        perror("Unable to open output file");
        return 0;
    }

    int indent = 0;
    int indent_size = 2; // Use 2 spaces for indentation

    while ((c = fgetc(fp1)) != EOF) {
        if (c == '<') {
            // Start of a new tag, increase indentation level
            fputs("\n", fp2);
            for (int i = 0; i < indent; i++) {
                for (int j = 0; j < indent_size; j++) {
                    fputc(' ', fp2);
                }
            }
            indent++;

        } else if (c == '>') {
            // End of a tag, decrease indentation level
            fputc(c, fp2);
            indent--;

        } else {
            fputc(c, fp2);
        }
    }

    // Close the files
    fclose(fp1);
    fclose(fp2);

    return 0;
}