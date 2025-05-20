//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_FILE_SIZE 1000000

// Function to count the number of words in a line
int countWords(char* line) {
    int count = 0;
    char* word = strtok(line, " \t\n\r\f\v");
    while(word!= NULL) {
        count++;
        word = strtok(NULL, " \t\n\r\f\v");
    }
    return count;
}

// Function to read the file and count the number of lines, words, and characters
void countStats(FILE* file, FILE* output) {
    char line[MAX_LINE_LENGTH];
    int lineCount = 0;
    int wordCount = 0;
    int charCount = 0;
    while(fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        lineCount++;
        wordCount += countWords(line);
        charCount += strlen(line);
        if(lineCount % 100 == 0) {
            fprintf(output, "Line Count: %d\n", lineCount);
        }
    }
    fprintf(output, "Word Count: %d\n", wordCount);
    fprintf(output, "Character Count: %d\n", charCount);
}

// Function to print the usage of the program
void printUsage() {
    printf("Usage:./wordcount <filename>\n");
}

int main(int argc, char* argv[]) {
    if(argc!= 2) {
        printUsage();
        return 1;
    }

    // Open the input file
    FILE* input = fopen(argv[1], "r");
    if(input == NULL) {
        printf("Error: Could not open input file '%s'.\n", argv[1]);
        return 1;
    }

    // Open the output file
    FILE* output = fopen("output.txt", "w");
    if(output == NULL) {
        printf("Error: Could not open output file 'output.txt'.\n");
        return 1;
    }

    // Count the number of lines, words, and characters in the input file
    countStats(input, output);

    // Close the input and output files
    fclose(input);
    fclose(output);

    return 0;
}