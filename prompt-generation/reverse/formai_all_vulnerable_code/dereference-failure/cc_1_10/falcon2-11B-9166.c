//Falcon2-11B DATASET v1.0 Category: Log analysis ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

int main() {
    char line[256];
    FILE *file;
    int wordCount = 0, charCount = 0, lineCount = 0, avgWordLength = 0;
    char word[256];

    // Open the input file
    file = fopen("input.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", strerror(errno));
        return 1;
    }

    // Read the file line by line
    while (fgets(line, sizeof(line), file)!= NULL) {
        // Count words, characters, and lines
        wordCount++;
        charCount += strlen(line);
        lineCount++;

        // Split the line into words
        char *word = strtok(line, " \t\n");
        while (word!= NULL) {
            // Calculate average word length
            avgWordLength += strlen(word);
            wordCount++;
            word = strtok(NULL, " \t\n");
        }
    }

    // Calculate average word length
    avgWordLength = avgWordLength / wordCount;

    // Close the input file
    fclose(file);

    // Print the results
    printf("Number of words: %d\n", wordCount);
    printf("Number of characters: %d\n", charCount);
    printf("Number of lines: %d\n", lineCount);
    printf("Average word length: %d characters\n", avgWordLength);

    return 0;
}