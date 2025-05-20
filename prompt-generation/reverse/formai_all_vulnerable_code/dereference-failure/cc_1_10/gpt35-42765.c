//FormAI DATASET v1.0 Category: HTML beautifier ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    FILE *input, *output;
    char in_name[50], out_name[50], c, curr_indent = 0;
    printf("Enter input file name (with .html extension): ");
    scanf("%s", in_name);
    printf("Enter output file name (with .html extension): ");
    scanf("%s", out_name);
    input = fopen(in_name, "r");
    output = fopen(out_name, "w");
    if (input == NULL) {
        printf("Error: Could not open input file.\n");
        return -1;
    }
    if (output == NULL) {
        printf("Error: Could not open output file.\n");
        return -1;
    }
    while ((c = fgetc(input)) != EOF) {
        if (c == '<') {
            fputc(c, output);
            c = fgetc(input);
            if (c == '/') {
                curr_indent -= 4;
            }
            else {
                curr_indent += 4;
            }
            ungetc(c, input);
            fputc('\n', output);
            for (int i = 0; i < curr_indent; i++) {
                fputc(' ', output);
            }
        }
        else if (c == '>') {
            fputc(c, output);
            fputc('\n', output);
            for (int i = 0; i < curr_indent; i++) {
                fputc(' ', output);
            }
        }
        else {
            fputc(c, output);
        }
    }
    fclose(input);
    fclose(output);
    printf("Beautification Successful!\n");
    return 0;
}