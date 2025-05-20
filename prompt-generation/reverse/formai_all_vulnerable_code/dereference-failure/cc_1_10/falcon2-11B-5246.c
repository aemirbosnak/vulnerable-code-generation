//Falcon2-11B DATASET v1.0 Category: Text processing ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to count the number of occurrences of a word in a text file
int countWordOccurrences(FILE* inputFile, FILE* outputFile, const char* word) {
    int count = 0;
    char c;
    while ((c = fgetc(inputFile))!= EOF) {
        if (isalpha(c)) {
            c = tolower(c);
            if (strcmp(word, &c) == 0) {
                count++;
            }
        }
        fputc(c, outputFile);
    }
    fputc('\n', outputFile);
    return count;
}

// Function to count the number of occurrences of each word in a text file
int countWordOccurrencesFile(FILE* inputFile, FILE* outputFile) {
    char word[256];
    while (fgets(word, sizeof(word), inputFile)!= NULL) {
        countWordOccurrences(inputFile, outputFile, word);
    }
    fclose(inputFile);
    fclose(outputFile);
}

// Function to print the word count to stdout
void printWordCount(FILE* inputFile) {
    char word[256];
    while (fgets(word, sizeof(word), inputFile)!= NULL) {
        fprintf(stdout, "%s\n", word);
    }
    fclose(inputFile);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        exit(1);
    }

    FILE* inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Could not open input file: %s\n", argv[1]);
        exit(1);
    }

    FILE* outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Could not create output file: %s\n", argv[2]);
        exit(1);
    }

    countWordOccurrencesFile(inputFile, outputFile);
    fclose(inputFile);
    fclose(outputFile);

    printWordCount(outputFile);
    fclose(outputFile);

    return 0;
}