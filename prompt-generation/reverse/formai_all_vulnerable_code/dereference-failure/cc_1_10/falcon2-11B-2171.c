//Falcon2-11B DATASET v1.0 Category: Text processing ; Style: expert-level
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to reverse the order of words in a line
void reverseLine(char *line, int maxLen) {
    int i, j;
    char c;

    // Reverse the line
    for (i = 0, j = maxLen - 1; i < j; i++, j--) {
        c = line[i];
        line[i] = line[j];
        line[j] = c;
    }
}

int main(int argc, char *argv[]) {
    FILE *inFile, *outFile;
    char line[1024];
    char word[1024];
    int maxLen;

    // Check command line arguments
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s inputFile\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open input file
    if ((inFile = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error opening input file\n");
        exit(EXIT_FAILURE);
    }

    // Open output file
    if ((outFile = fopen("output.txt", "w")) == NULL) {
        fprintf(stderr, "Error opening output file\n");
        exit(EXIT_FAILURE);
    }

    // Read input file
    while (fgets(line, sizeof(line), inFile)!= NULL) {
        // Get maximum length of words in the line
        maxLen = strlen(line);

        // Reverse the order of words in the line
        reverseLine(line, maxLen);

        // Write reversed line to output file
        fprintf(outFile, "%s\n", line);
    }

    // Close input and output files
    fclose(inFile);
    fclose(outFile);

    return 0;
}