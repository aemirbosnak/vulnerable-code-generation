//Falcon-180B DATASET v1.0 Category: Checksum Calculator ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_LINE_LENGTH 2048 // Maximum length of input line
#define MAX_WORD_LENGTH 64 // Maximum length of a word
#define MAX_WORDS 1000 // Maximum number of words in a line

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int main() {
    char line[MAX_LINE_LENGTH];
    char *word;
    char *token;
    char *saveptr;
    WordCount words[MAX_WORDS];
    int numWords = 0;
    int i;

    // Prompt user for input
    printf("Enter a line of text: ");
    fgets(line, MAX_LINE_LENGTH, stdin);

    // Remove newline character from end of input line
    if ((token = strtok_r(line, "\n", &saveptr))!= NULL) {
        strcpy(line, token);
    }

    // Loop through each word in the input line
    word = strtok_r(line, " ", &saveptr);
    while (word!= NULL) {
        // Check if we have reached the maximum number of words
        if (numWords >= MAX_WORDS) {
            printf("Error: Maximum number of words exceeded.\n");
            exit(1);
        }

        // Convert word to lowercase
        for (i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }

        // Count the number of times the word appears in the line
        int count = 0;
        char *pos = line;
        while ((pos = strstr(pos, word))!= NULL) {
            count++;
            pos += strlen(word);
        }

        // Add the word and its count to the array
        strcpy(words[numWords].word, word);
        words[numWords].count = count;
        numWords++;

        // Get the next word
        word = strtok_r(NULL, " ", &saveptr);
    }

    // Print the results
    printf("Word\tCount\n");
    for (i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}