//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

// Function to count the number of words in a string
int countWords(char* str) {
    int i, j, wordCount = 0;

    // Remove leading and trailing spaces
    i = 0;
    while (isspace(str[i])) {
        i++;
    }
    j = strlen(str) - 1;
    while (isspace(str[j])) {
        j--;
    }
    str[j+1] = '\0';

    // Count number of words
    char* token = strtok(str, " ");
    while (token!= NULL) {
        wordCount++;
        token = strtok(NULL, " ");
    }

    return wordCount;
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    char line[MAX_WORD_LENGTH];
    int lineCount = 0, wordCount = 0, charCount = 0;

    // Read file line by line
    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        lineCount++;

        // Count number of words in the line
        int wordsInLine = countWords(line);
        wordCount += wordsInLine;

        // Count number of characters in the line
        charCount += strlen(line);
    }

    fclose(file);

    // Print results
    printf("\nFile: %s\n", argv[1]);
    printf("Lines: %d\n", lineCount);
    printf("Words: %d\n", wordCount);
    printf("Characters: %d\n", charCount);

    return 0;
}