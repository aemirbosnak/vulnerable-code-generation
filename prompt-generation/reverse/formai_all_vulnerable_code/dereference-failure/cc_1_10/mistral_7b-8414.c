//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#define MAX_LINE 1000

// Function to read a line from a file
char * readline(FILE * fp) {
    char * line = (char *) malloc(MAX_LINE * sizeof(char));
    char c;
    int i = 0;

    while (1) {
        c = fgetc(fp);
        if (c == EOF || c == '\n') {
            line[i] = '\0';
            if (c == EOF) {
                free(line);
                return NULL;
            }
            break;
        }
        line[i++] = c;
    }

    return line;
}

// Function to write a line to a file
void writeline(FILE * fp, char * line) {
    fputs(line, fp);
    fputs("\n", fp);
}

int main() {
    FILE * inputFile, * outputFile;
    char * line;

    // Open input and output files
    inputFile = fopen("input.txt", "r");
    outputFile = fopen("output.txt", "w");

    // Check if files were opened successfully
    if (inputFile == NULL || outputFile == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read a line from the input file and write it to the output file
    while ((line = readline(inputFile)) != NULL) {
        writeline(outputFile, line);
        printf("Printing line: %s\n", line);
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

// Function to free memory allocated to a string
void free_string(char * str) {
    free(str);
}