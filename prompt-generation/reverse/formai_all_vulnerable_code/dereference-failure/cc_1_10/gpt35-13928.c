//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORDS 10000 /* Maximum number of words to be counted */
#define MAX_WORD_LEN 100 /* Maximum length of a word */

/* Structure to hold a word along with its frequency count */
typedef struct WordCount {
    char word[MAX_WORD_LEN];
    int count;
} WordCount;

/* Prototypes for functions */
void countWords(char *filename, WordCount *wordCounts, int *numWords);
int isWordChar(char c);
void printResults(WordCount *wordCounts, int numWords);

/* Main function */
int main(int argc, char *argv[]) {
    /* Check if a filename has been provided */
    if (argc < 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Allocate memory for an array of WordCount structs */
    WordCount *wordCounts = malloc(MAX_WORDS * sizeof(WordCount));
    if (wordCounts == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    /* Count the frequency of words in the file */
    int numWords = 0;
    countWords(argv[1], wordCounts, &numWords);

    /* Print the results */
    printResults(wordCounts, numWords);

    /* Free memory */
    free(wordCounts);

    return 0;
}

/* Function to count the frequency of words in a file */
void countWords(char *filename, WordCount *wordCounts, int *numWords) {
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LEN];
    int i, j, len;
    char c;
    int isNewWord, index;

    while ((c = fgetc(fp)) != EOF) {
        /* Convert to lowercase */
        c = tolower(c);

        /* Check if a word character */
        if (isWordChar(c)) {
            /* Start of a new word */
            if (*numWords == 0 || 
                !isWordChar(word[strlen(word)-1])) {
                isNewWord = 1;
            } else {
                isNewWord = 0;
            }

            /* Append to word */
            word[strlen(word)] = c;

        } else {
            /* End of a word */
            if (*numWords == 0 || 
                isWordChar(word[strlen(word)-1])) {
                len = strlen(word);
                /* Check if word is too long */
                if (len > MAX_WORD_LEN) {
                    word[MAX_WORD_LEN-1] = '\0';
                    len = MAX_WORD_LEN-1;
                }
                /* Check if word already exists */
                index = -1;
                for (i = 0; i < *numWords; i++) {
                    if (strncmp(word, wordCounts[i].word, len) == 0 &&
                        len == strlen(wordCounts[i].word)) {
                        index = i;
                        break;
                    }
                }
                /* Add new word */
                if (index == -1) {
                    if (*numWords == MAX_WORDS) {
                        fprintf(stderr, "Maximum number of words reached\n");
                        exit(EXIT_FAILURE);
                    } else {
                        strncpy(wordCounts[*numWords].word, word, len);
                        wordCounts[*numWords].word[len] = '\0';
                        wordCounts[*numWords].count = 1;
                        (*numWords)++;
                    }
                }
                /* Increment word count */
                else {
                    wordCounts[index].count++;
                }
            }
            /* Clear the word array for the next word */
            memset(word, 0, sizeof(word));
        }
    }

    fclose(fp);
}

/* Function to check if a character is a word character */
int isWordChar(char c) {
    return isalpha(c) || c == '\'';
}

/* Function to print the frequency of each word */
void printResults(WordCount *wordCounts, int numWords) {
    int i;
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}