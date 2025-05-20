//FormAI DATASET v1.0 Category: Text processing ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * This program will read in a text file and perform the following:
 *
 * 1. Replace all instances of a specified word with a replacement word
 * 2. Count the number of occurrences of a specified word
 * 3. Print out the number of words in the file
 * 4. Print out the longest word in the file
 * 5. Print out the shortest word in the file
 * 
 * The program takes 3 arguments in the following order:
 * 1. The filename of the input text file to process
 * 2. The word to replace
 * 3. The replacement word
 *
 */

// Function prototypes
int countOccurrences(char *str, char *word);
int countWords(char *str);
void longestShortestWord(char *str, char longest[], char shortest[]);

int main(int argc, char *argv[]) {
    // Check enough arguments were passed in
    if (argc < 4) {
        printf("Error: Not enough arguments supplied\n");
        printf("Usage: textProcessing <input_file> <word_to_replace> <replacement_word>\n");
        return EXIT_FAILURE;
    }

    // Open input file
    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error: Could not open input file\n");
        return EXIT_FAILURE;
    }

    // Get file size
    fseek(inputFile, 0L, SEEK_END);
    int fileSize = ftell(inputFile);
    fseek(inputFile, 0L, SEEK_SET);

    // Allocate memory for file content string
    char *fileContent = malloc(fileSize * sizeof(char));
    if (fileContent == NULL) {
        printf("Error: Could not allocate memory for file content\n");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    // Read file content into string
    fgets(fileContent, fileSize, inputFile);

    // Count occurrences of specified word and replace if found
    char *wordPtr = strstr(fileContent, argv[2]);
    if (wordPtr != NULL) {
        int wordLength = strlen(argv[2]);
        int replacementLength = strlen(argv[3]);
        char *tempStr = malloc((fileSize + replacementLength - wordLength) * sizeof(char));
        if (tempStr == NULL) {
            printf("Error: Could not allocate memory for replacement string\n");
            fclose(inputFile);
            free(fileContent);
            return EXIT_FAILURE;
        }
        int charsToAdd = wordPtr - fileContent;
        strncpy(tempStr, fileContent, charsToAdd);
        strcat(tempStr, argv[3]);
        strcat(tempStr, wordPtr + wordLength);
        strcpy(fileContent, tempStr);
        free(tempStr);
    }
    int numOccurrences = countOccurrences(fileContent, argv[2]);
    printf("Number of occurrences of %s: %d\n", argv[2], numOccurrences);

    // Count number of words in file
    int numWords = countWords(fileContent);
    printf("Number of words: %d\n", numWords);

    // Find the longest and shortest word in file
    char longestWord[numWords];
    char shortestWord[numWords];
    longestShortestWord(fileContent, longestWord, shortestWord);
    printf("Longest word: %s\n", longestWord);
    printf("Shortest word: %s\n", shortestWord);

    // Free memory and close files
    fclose(inputFile);
    free(fileContent);

    return EXIT_SUCCESS;
}

int countOccurrences(char *str, char *word) {
    int count = 0;
    int wordLength = strlen(word);
    char *ptr = str;
    while ((ptr = strstr(ptr, word)) != NULL) {
        count++;
        ptr += wordLength;
    }
    return count;
}

int countWords(char *str) {
    int count = 0;
    int numChars = strlen(str);
    int i = 0;
    while (i < numChars) {
        while (i < numChars && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')) {
            i++;
        }
        if (i < numChars) {
            count++;
        }
        while (i < numChars && !(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')) {
            i++;
        }
    }
    return count;
}

void longestShortestWord(char *str, char longest[], char shortest[]) {
    int numChars = strlen(str);
    int longestLength = 0;
    int shortestLength = numChars;
    int i = 0;
    int j = 0;
    while (i < numChars) {
        while (i < numChars && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')) {
            i++;
        }
        j = i;
        while (j < numChars && !(str[j] == ' ' || str[j] == '\t' || str[j] == '\n')) {
            j++;
        }
        int wordLength = j - i;
        if (wordLength > longestLength) {
            longestLength = wordLength;
            strncpy(longest, &str[i], longestLength);
            longest[longestLength] = '\0';
        }
        if (wordLength < shortestLength) {
            shortestLength = wordLength;
            strncpy(shortest, &str[i], shortestLength);
            shortest[shortestLength] = '\0';
        }
        i = j;
    }
}