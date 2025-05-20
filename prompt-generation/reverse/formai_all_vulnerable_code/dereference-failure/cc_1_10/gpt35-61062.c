//FormAI DATASET v1.0 Category: Text processing ; Style: thoughtful
/* A program that reads in a text file, processes it and outputs the processed text to another file */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to process the text
void processText(char *inputFile, char *outputFile) {

    // open the input file
    FILE *input = fopen(inputFile, "r");

    // check if the file was opened successfully
    if (input == NULL) {
        printf("Error opening input file");
        exit(1);
    }

    // open the output file
    FILE *output = fopen(outputFile, "w");

    // check if the file was opened successfully
    if (output == NULL) {
        printf("Error opening output file");
        exit(1);
    }

    char line[100];

    // read in each line from the input file
    while (fgets(line, 100, input) != NULL) {

        // process the line
        int len = strlen(line);

        // remove any trailing newline characters
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }

        // convert the line to uppercase
        for (int i = 0; i < len; i++) {
            if (line[i] >= 'a' && line[i] <= 'z') {
                line[i] = line[i] - ('a' - 'A');
            }
        }

        // write the processed line to the output file
        fputs(line, output);
        fputs("\n", output);
    }

    // close the files
    fclose(input);
    fclose(output);
}

int main() {

    char *inputFile = "input.txt";
    char *outputFile = "output.txt";

    // process the text
    processText(inputFile, outputFile);

    printf("Text processing complete");

    return 0;
}