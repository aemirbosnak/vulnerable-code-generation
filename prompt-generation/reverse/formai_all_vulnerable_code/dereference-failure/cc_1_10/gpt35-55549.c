//FormAI DATASET v1.0 Category: HTML beautifier ; Style: scientific
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char **argv) {

    FILE *file_in, *file_out;
    int indent_level = 0;
    char ch;

    // Open the input and output files
    file_in = fopen(argv[1], "r");
    file_out = fopen(argv[2], "w");

    // Check if files are successfully opened
    if (file_in == NULL || file_out == NULL) {
        printf("Error opening input or output file.\n");
        exit(1);
    }

    // loop through the input file character by character
    while ((ch = fgetc(file_in)) != EOF) {

        // new line after a closing tag
        if (ch == '>') {
            fprintf(file_out, "%c\n", ch);
            indent_level++;
        }

        // indent next line
        else if (ch == '<') {
            fprintf(file_out, "\n");
            for (int i = 0; i < indent_level; i++) {
                fprintf(file_out, "    ");
            }
        }

        // write character to output file
        fprintf(file_out, "%c", ch);

        // decrease indent level if closing tag is detected
        if (ch == '/') {
            indent_level--;
        }
    }

    // close the files
    fclose(file_in);
    fclose(file_out);

    return 0;
}