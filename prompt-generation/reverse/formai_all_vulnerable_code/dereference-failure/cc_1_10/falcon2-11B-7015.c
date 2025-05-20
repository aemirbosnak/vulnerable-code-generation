//Falcon2-11B DATASET v1.0 Category: HTML beautifier ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 80
#define MAX_WIDTH 80

int main(int argc, char **argv) {
    char html_code[MAX_WIDTH];
    int num_lines;
    int i;
    int j;

    // read html code from input
    printf("Enter HTML code: ");
    fgets(html_code, MAX_WIDTH, stdin);
    html_code[strcspn(html_code, "\n")] = '\0';

    // calculate number of lines
    num_lines = 1;
    for (i = 0; i < strlen(html_code); i++) {
        if (html_code[i] == '\n') {
            num_lines++;
        }
    }

    // create an array to hold lines
    char *lines[num_lines];

    // split html code into lines
    i = 0;
    for (j = 0; j < strlen(html_code); j++) {
        if (html_code[j] == '\n') {
            lines[i++] = &html_code[j + 1];
        }
    }

    // beautify lines
    for (i = 0; i < num_lines; i++) {
        int line_length = strlen(lines[i]);
        int spaces = MAX_LINE_LENGTH - line_length;

        // add spaces to the left of the line
        for (j = 0; j < spaces; j++) {
            printf(" ");
        }

        // add the line to the output
        printf("%s", lines[i]);

        // add a newline to the end of the line
        printf("\n");
    }

    return 0;
}