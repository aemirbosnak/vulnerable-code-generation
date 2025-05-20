//Falcon-180B DATASET v1.0 Category: Performance-Critical Component ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the maximum length of a line */
#define MAX_LINE_LENGTH 1024

/* Prototype for the function that reads a line from the input file */
int read_line(FILE *in_file, char *line);

/* Prototype for the function that writes a line to the output file */
int write_line(FILE *out_file, char *line);

/* Prototype for the function that reverses a string */
void reverse_string(char *str);

int main(int argc, char *argv[]) {
    FILE *in_file, *out_file;
    char line[MAX_LINE_LENGTH];
    char reversed_line[MAX_LINE_LENGTH];

    /* Check if the correct number of arguments were provided */
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        exit(1);
    }

    /* Open the input and output files */
    in_file = fopen(argv[1], "r");
    if (in_file == NULL) {
        fprintf(stderr, "Error: could not open input file '%s'\n", argv[1]);
        exit(1);
    }

    out_file = fopen(argv[2], "w");
    if (out_file == NULL) {
        fprintf(stderr, "Error: could not open output file '%s'\n", argv[2]);
        exit(1);
    }

    /* Loop through the input file, reversing each line and writing it to the output file */
    while (read_line(in_file, line)!= EOF) {
        reverse_string(line);
        write_line(out_file, line);
    }

    /* Close the input and output files */
    fclose(in_file);
    fclose(out_file);

    return 0;
}

/* Read a line from the input file */
int read_line(FILE *in_file, char *line) {
    return fscanf(in_file, "%[^\n]", line);
}

/* Write a line to the output file */
int write_line(FILE *out_file, char *line) {
    return fprintf(out_file, "%s\n", line);
}

/* Reverse a string */
void reverse_string(char *str) {
    int i, j;
    char temp;

    /* Reverse the string in place */
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}