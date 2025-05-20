//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100
#define WORD_LENGTH 50

// Function to swap two characters
void swap(char *str, int i, int j) {
    char temp;
    temp = str[i];
    str[i] = str[j];
    str[j] = temp;
}

// Function to find the length of a word
int getWordLength(char *word) {
    int len = 0;
    while (word[len] != '\0' && isalpha(word[len])) {
        len++;
    }
    return len;
}

// Function to check if two words are anagrams
int areAnagrams(char *word1, char *word2) {
    int len1 = getWordLength(word1);
    int len2 = getWordLength(word2);

    if (len1 != len2) {
        return 0;
    }

    int count[26] = {0};
    int i;

    for (i = 0; i < len1; i++) {
        count[tolower(word1[i]) - 'a']++;
        count[tolower(word2[i]) - 'a']--;
    }

    for (i = 0; i < 26; i++) {
        if (count[i] != 0) {
            return 0;
        }
    }

    return 1;
}

// Function to print anagram pairs from a list of words
void printAnagrams(char *words[MAX_WORDS]) {
    int i, j;

    for (i = 0; i < MAX_WORDS - 1; i++) {
        for (j = i + 1; j < MAX_WORDS; j++) {
            if (areAnagrams(words[i], words[j])) {
                printf("%s and %s are anagrams.\n", words[i], words[j]);
            }
        }
    }
}

int main() {
    char *words[MAX_WORDS];
    int numWords = 0;

    // Read words from standard input
    char word[WORD_LENGTH];
    while (fgets(word, WORD_LENGTH, stdin) != NULL) {
        // Remove newline character and add word to list
        word[strcspn(word, "\n")] = '\0';
        words[numWords] = malloc(getWordLength(word) + 1);
        strcpy(words[numWords], word);
        numWords++;
    }

    // Print anagram pairs
    printAnagrams(words);

    // Free memory
    for (int i = 0; i <= numWords; i++) {
        free(words[i]);
    }

    return 0;
}