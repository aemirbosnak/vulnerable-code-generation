//Falcon-180B DATASET v1.0 Category: HTML beautifier ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

char *beautify_html(char *input) {
    char *output = malloc(strlen(input) + 1);
    char *p = output;
    int in_tag = 0;
    int tag_level = 0;

    for (char *q = input; *q; q++) {
        if (*q == '<') {
            in_tag = 1;
        } else if (*q == '>') {
            in_tag = 0;
        } else if (in_tag && isalpha(*q)) {
            if (*q == '/') {
                tag_level--;
            } else {
                tag_level++;
            }
        } else if (!in_tag && isspace(*q)) {
            if (tag_level == 0) {
                strncat(output, " ", MAX_LINE_LENGTH - (p - output) - 1);
            }
        } else {
            strncat(output, q, MAX_LINE_LENGTH - (p - output) - 1);
        }

        if (p - output >= MAX_LINE_LENGTH - 2) {
            strncat(output, "\n", MAX_LINE_LENGTH - (p - output) - 1);
            p = output + strlen(output);
        }
    }

    strncat(output, "\n", MAX_LINE_LENGTH - (p - output) - 1);
    return output;
}

int main() {
    FILE *input_file = fopen("input.html", "r");
    if (input_file == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    char input_buffer[MAX_LINE_LENGTH];
    char *input = NULL;
    size_t input_size = 0;

    while (fgets(input_buffer, MAX_LINE_LENGTH, input_file)!= NULL) {
        input_size += strlen(input_buffer);
        input = realloc(input, input_size + 1);
        strcat(input, input_buffer);
    }

    fclose(input_file);

    char *output = beautify_html(input);

    printf("%s", output);

    free(output);
    free(input);

    return 0;
}