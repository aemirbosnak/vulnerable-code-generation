//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_IN "input.txt"
#define FILE_OUT "output.txt"

// Function to read a line from a file
char *readline(FILE *fp) {
    size_t len = 0;
    size_t cap = 0;
    char *line = malloc(1);
    int c;

    while ((c = getc(fp)) != EOF && c != '\n') {
        line[len++] = (char)c;

        if (len == cap) {
            cap *= 2;
            line = realloc(line, cap + 1);
        }
    }

    if (c == '\n') {
        line[len++] = '\n';
        line[len] = '\0';

        while (getc(fp) != EOF)
            ;

        rewind(fp);
    } else {
        free(line);
        return NULL;
    }

    return line;
}

// Function to write a line to a file
void writeline(FILE *fp, char *line) {
    size_t len = strlen(line);

    for (int i = len; i >= 0; i--) {
        putc(fp, line[i]);
    }

    putc(fp, '\n');
}

int main() {
    FILE *fp_in, *fp_out;
    char *line;

    // Open input and output files
    fp_in = fopen(FILE_IN, "r");
    fp_out = fopen(FILE_OUT, "w");

    // Check if files were opened successfully
    if (fp_in == NULL || fp_out == NULL) {
        perror("Error opening file(s)");
        exit(EXIT_FAILURE);
    }

    // Read each line from input file and write it reversed to output file
    while ((line = readline(fp_in)) != NULL) {
        writeline(fp_out, line);
        free(line);
    }

    // Close input and output files
    fclose(fp_in);
    fclose(fp_out);

    return EXIT_SUCCESS;
}