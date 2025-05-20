//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to count words in a string
int countWords(char* str) {
    int count = 0;
    char* wordStart = str;
    while (*str) {
        if (isspace(*str)) {
            count++;
            wordStart = str + 1;
        }
        str++;
    }
    if (wordStart!= str) {
        count++;
    }
    return count;
}

// Function to print the word count
void printWordCount(FILE* file, int count) {
    fprintf(file, "Word count: %d\n", count);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Error opening input file.\n");
        return 1;
    }

    FILE* outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening output file.\n");
        return 1;
    }

    char line[1024];
    while (fgets(line, sizeof(line), inputFile)) {
        int wordCount = countWords(line);
        printWordCount(outputFile, wordCount);
    }

    fclose(inputFile);
    fclose(outputFile);
    return 0;
}