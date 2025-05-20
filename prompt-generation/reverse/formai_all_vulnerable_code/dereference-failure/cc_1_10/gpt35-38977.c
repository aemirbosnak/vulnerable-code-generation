//FormAI DATASET v1.0 Category: HTML beautifier ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

int main() {
    char ch;
    int flag_for_space = 0, flag_for_comment = 0;

    // Open the input file
    FILE *in = fopen("input.html", "r");

    // Open the output file to store beautified HTML code
    FILE *out = fopen("output.html", "w");

    // Check if the input file exists
    if (in == NULL) {
        printf("Unable to open input file\n");
        exit(0);
    }

    // Read character by character
    while ((ch = fgetc(in)) != EOF) {
        // If space, check for flag
        if (ch == ' ') {
            if (flag_for_space == 0) {
                fprintf(out, " ");
                flag_for_space = 1;
            }
        } else if (ch == '\n') {
            // If new line, reset flag
            fprintf(out, "\n");
            flag_for_space = 0;
        } else if (ch == '<') {
            // If tag is started, print tag
            fprintf(out, "<");
            flag_for_space = 0;
            // Check for comment
            if ((ch = fgetc(in)) == '!') {
                flag_for_comment = 1;
            } else {
                fprintf(out, "%c", ch);
            }
        } else if (ch == '>') {
            // If tag is closed, print tag
            fprintf(out, ">");
            flag_for_space = 0;
            flag_for_comment = 0;
        } else if (flag_for_comment == 1) {
            // If inside comment, print comment
            fprintf(out, "%c", ch);
        } else {
            // If regular character, print character
            fprintf(out, "%c", ch);
            flag_for_space = 0;
        }
    }

    // Close input and output files
    fclose(in);
    fclose(out);

    printf("HTML Beautifier Successful!\n");

    return 0;
}